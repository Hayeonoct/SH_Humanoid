import rclpy
from rclpy.node import Node
import csv
import math
import os
import tkinter as tk
from tkinter import scrolledtext, messagebox
import threading

from geometry_msgs.msg import Pose
from moveit_msgs.srv import GetCartesianPath
from control_msgs.action import FollowJointTrajectory
from rclpy.action import ActionClient

# =========================================================
# [1번] 실제 모터 방향 보정용 부호 매핑
#   MoveIt이 계획한 joint_trajectory의 각 관절 값에 곱해서
#   컨트롤러로 보내기 직전에 적용한다.
#   (주의: 이렇게 하면 RViz와 실제 로봇이 해당 관절에서 서로 거울처럼 움직임)
# =========================================================
USER_TO_MOVEIT_SIGN = {
    'joint1':   1.0,
    'joint2':  -1.0,
    'joint3':  -1.0,
    'joint4':  -1.0,
    'joint5':   1.0,
    'joint6':   1.0,
    'joint7':   1.0,
    'joint8':  -1.0,
    'joint9':   1.0,
    'joint10': -1.0,
    'joint11':  1.0,
    'joint12':  1.0,
    'joint13': -1.0,
    'joint14': -1.0,
}

# =========================================================
# [2번+4번 연계] 상대 좌표 -> 절대 좌표용 어깨 위치
#   URDF: joint1 origin(오른 어깨), joint8 origin(왼 어깨), base_link 기준 [m]
#   waypoints.py가 저장하는 값은 "손목 - 어깨" 상대 벡터이므로,
#   여기에 어깨 위치를 더해야 base_link 기준 절대 타깃이 된다.
# =========================================================
RIGHT_SHOULDER_BASE = (-0.1475, 0.105, 0.112048)
LEFT_SHOULDER_BASE = (0.1556, 0.105, 0.112048)
ADD_SHOULDER_OFFSET = True


# ---------------------------------------------------------
# 1. ROS 2 Node 클래스
# ---------------------------------------------------------
class CSVMoveItExecutor(Node):
    def __init__(self):
        super().__init__('csv_moveit_executor')
        self.cartesian_client = self.create_client(GetCartesianPath, '/compute_cartesian_path')
        self.right_client = ActionClient(self, FollowJointTrajectory, '/right_arm_controller/follow_joint_trajectory')
        self.left_client = ActionClient(self, FollowJointTrajectory, '/left_arm_controller/follow_joint_trajectory')

    def normalize_q(self, x, y, z, w):
        norm = math.sqrt(x**2 + y**2 + z**2 + w**2)
        if norm == 0:
            return 0.0, 0.0, 0.0, 1.0
        return x/norm, y/norm, z/norm, w/norm

    def load_waypoints(self, filepath):
        right_waypoints = []
        left_waypoints = []
        qx, qy, qz, qw = self.normalize_q(0.0, 0.70710678, 0.0, 0.70710678)

        try:
            with open(filepath, 'r') as f:
                reader = csv.DictReader(f)
                for row in reader:
                    rx, ry, rz = float(row['rx']), float(row['ry']), float(row['rz'])
                    lx, ly, lz = float(row['lx']), float(row['ly']), float(row['lz'])

                    if any(math.isnan(val) for val in [rx, ry, rz, lx, ly, lz]):
                        continue

                    # [연계] 상대(손목-어깨) -> base_link 절대 좌표
                    if ADD_SHOULDER_OFFSET:
                        rx += RIGHT_SHOULDER_BASE[0]
                        ry += RIGHT_SHOULDER_BASE[1]
                        rz += RIGHT_SHOULDER_BASE[2]
                        lx += LEFT_SHOULDER_BASE[0]
                        ly += LEFT_SHOULDER_BASE[1]
                        lz += LEFT_SHOULDER_BASE[2]

                    r_pose = Pose()
                    r_pose.position.x, r_pose.position.y, r_pose.position.z = rx, ry, rz
                    r_pose.orientation.x, r_pose.orientation.y, r_pose.orientation.z, r_pose.orientation.w = qx, qy, qz, qw
                    right_waypoints.append(r_pose)

                    l_pose = Pose()
                    l_pose.position.x, l_pose.position.y, l_pose.position.z = lx, ly, lz
                    l_pose.orientation.x, l_pose.orientation.y, l_pose.orientation.z, l_pose.orientation.w = qx, qy, qz, qw
                    left_waypoints.append(l_pose)

            return right_waypoints, left_waypoints
        except Exception as e:
            self.get_logger().error(f"CSV 로드 실패: {e}")
            return None, None

    def plan_cartesian_path(self, group_name, waypoints):
        self.cartesian_client.wait_for_service(timeout_sec=5.0)
        req = GetCartesianPath.Request()
        req.header.frame_id = 'base_link'
        req.group_name = group_name
        req.waypoints = waypoints
        req.max_step = 0.01
        req.jump_threshold = 10.0
        req.start_state.is_diff = True

        future = self.cartesian_client.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        res = future.result()

        if res is None or res.fraction < 0.5:
            return None, 0.0
        return res.solution, res.fraction

    # -----------------------------------------------------
    # [1번] 부호 매핑 적용
    # -----------------------------------------------------
    def apply_sign_mapping(self, joint_trajectory):
        """joint_trajectory의 각 관절 위치/속도/가속도/토크에 부호를 곱한다."""
        names = list(joint_trajectory.joint_names)
        signs = [USER_TO_MOVEIT_SIGN.get(n, 1.0) for n in names]

        for pt in joint_trajectory.points:
            if pt.positions:
                pt.positions = [p * s for p, s in zip(pt.positions, signs)]
            if pt.velocities:
                pt.velocities = [v * s for v, s in zip(pt.velocities, signs)]
            if pt.accelerations:
                pt.accelerations = [a * s for a, s in zip(pt.accelerations, signs)]
            if pt.effort:
                pt.effort = [e * s for e, s in zip(pt.effort, signs)]
        return joint_trajectory

    def execute_dual_arm(self, right_traj, left_traj):
        self.right_client.wait_for_server()
        self.left_client.wait_for_server()

        # [1번] 컨트롤러로 보내기 직전 부호 보정
        r_jt = self.apply_sign_mapping(right_traj.joint_trajectory)
        l_jt = self.apply_sign_mapping(left_traj.joint_trajectory)

        r_goal = FollowJointTrajectory.Goal()
        r_goal.trajectory = r_jt
        l_goal = FollowJointTrajectory.Goal()
        l_goal.trajectory = l_jt

        r_future = self.right_client.send_goal_async(r_goal)
        l_future = self.left_client.send_goal_async(l_goal)

        rclpy.spin_until_future_complete(self, r_future)
        rclpy.spin_until_future_complete(self, l_future)

        r_handle = r_future.result()
        l_handle = l_future.result()

        if not r_handle.accepted or not l_handle.accepted:
            return False

        r_res_future = r_handle.get_result_async()
        l_res_future = l_handle.get_result_async()

        rclpy.spin_until_future_complete(self, r_res_future)
        rclpy.spin_until_future_complete(self, l_res_future)
        return True


# ---------------------------------------------------------
# 2. 다중 모션 관리 GUI 클래스 (폴더 자동 스캔)
# ---------------------------------------------------------
class MoveItGUI:
    def __init__(self, root, executor):
        self.root = root
        self.executor = executor
        self.root.title("Multi-Motion Dual Arm Controller")
        self.root.geometry("550x550")

        self.motions_folder = "motions"
        self.ensure_motions_folder()

        self.motions = {}

        self.create_widgets()
        self.scan_folder()

    def ensure_motions_folder(self):
        if not os.path.exists(self.motions_folder):
            os.makedirs(self.motions_folder)
            print(f"[{self.motions_folder}] 폴더가 생성되었습니다. 여기에 CSV 파일을 넣어주세요.")

    def create_widgets(self):
        tk.Label(self.root, text="Multi-Motion Library", font=("Arial", 16, "bold")).pack(pady=10)

        list_frame = tk.Frame(self.root)
        list_frame.pack(pady=5, padx=20, fill=tk.BOTH, expand=True)

        tk.Label(list_frame, text=f"📂 {self.motions_folder}/ 폴더 내 모션:").pack(anchor="w")

        scroll = tk.Scrollbar(list_frame)
        scroll.pack(side=tk.RIGHT, fill=tk.Y)

        self.motion_listbox = tk.Listbox(list_frame, yscrollcommand=scroll.set, height=6, font=("Arial", 11))
        self.motion_listbox.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        scroll.config(command=self.motion_listbox.yview)

        self.motion_listbox.bind('<<ListboxSelect>>', self.on_list_select)

        btn_frame = tk.Frame(self.root)
        btn_frame.pack(pady=10)

        self.btn_load = tk.Button(btn_frame, text="1. Refresh Folder", width=15, command=self.scan_folder, bg="lightblue")
        self.btn_load.grid(row=0, column=0, padx=5)

        self.btn_plan = tk.Button(btn_frame, text="2. Plan Selected", width=15, command=self.start_planning, state=tk.DISABLED, bg="lightyellow")
        self.btn_plan.grid(row=0, column=1, padx=5)

        self.btn_exec = tk.Button(btn_frame, text="3. Execute", width=15, command=self.start_execution, state=tk.DISABLED, bg="lightgreen")
        self.btn_exec.grid(row=0, column=2, padx=5)

        tk.Label(self.root, text="System Log:").pack(anchor="w", padx=20)
        self.log_area = scrolledtext.ScrolledText(self.root, width=65, height=10, state='disabled', bg="#f4f4f4")
        self.log_area.pack(pady=5, padx=20)

    def log(self, message):
        self.log_area.config(state='normal')
        self.log_area.insert(tk.END, message + "\n")
        self.log_area.see(tk.END)
        self.log_area.config(state='disabled')

    def scan_folder(self):
        self.log(f"[시스템] '{self.motions_folder}' 폴더를 스캔합니다...")

        csv_files = [f for f in os.listdir(self.motions_folder) if f.endswith('.csv')]

        if not csv_files:
            self.log("⚠️ 폴더에 CSV 파일이 없습니다.")
            return

        new_files_count = 0
        for filename in sorted(csv_files):
            if filename in self.motions:
                continue

            filepath = os.path.join(self.motions_folder, filename)
            r_wp, l_wp = self.executor.load_waypoints(filepath)

            if r_wp and l_wp:
                self.motions[filename] = {
                    'r_wp': r_wp, 'l_wp': l_wp,
                    'r_traj': None, 'l_traj': None
                }
                self.motion_listbox.insert(tk.END, filename)
                new_files_count += 1
            else:
                self.log(f"❌ 실패: '{filename}' 데이터를 분석할 수 없습니다.")

        if new_files_count > 0:
            self.log(f"✅ {new_files_count}개의 새로운 모션을 불러왔습니다.")
        else:
            self.log("ℹ️ 새로운 모션이 없습니다. (모두 로드됨)")

    def on_list_select(self, event):
        selection = self.motion_listbox.curselection()
        if not selection:
            return

        selected_name = self.motion_listbox.get(selection[0])
        motion_data = self.motions[selected_name]

        self.btn_plan.config(state=tk.NORMAL)

        if motion_data['r_traj'] is not None and motion_data['l_traj'] is not None:
            self.btn_exec.config(state=tk.NORMAL)
        else:
            self.btn_exec.config(state=tk.DISABLED)

    def start_planning(self):
        selection = self.motion_listbox.curselection()
        if not selection:
            return

        selected_name = self.motion_listbox.get(selection[0])

        self.btn_plan.config(state=tk.DISABLED)
        self.btn_exec.config(state=tk.DISABLED)
        threading.Thread(target=self.run_planning_thread, args=(selected_name,), daemon=True).start()

    def run_planning_thread(self, name):
        self.log(f"\n[시스템] '{name}' MoveIt Planning 시작...")
        motion = self.motions[name]

        self.log("오른팔 경로 계산 중...")
        r_traj, r_frac = self.executor.plan_cartesian_path('right_arm', motion['r_wp'])

        self.log("왼팔 경로 계산 중...")
        l_traj, l_frac = self.executor.plan_cartesian_path('left_arm', motion['l_wp'])

        motion['r_traj'] = r_traj
        motion['l_traj'] = l_traj

        self.root.after(0, lambda: self.btn_plan.config(state=tk.NORMAL))

        if r_traj and l_traj:
            self.log(f"🎉 양팔 Planning 완료! RViz 확인 후 Execute를 누르세요. (R:{r_frac*100:.1f}%, L:{l_frac*100:.1f}%)")
            self.root.after(0, lambda: self.btn_exec.config(state=tk.NORMAL))
        else:
            self.log("❌ 경로 생성 실패. (팔이 닿지 않는 범위이거나 충돌 발생)")

    def start_execution(self):
        selection = self.motion_listbox.curselection()
        if not selection:
            return

        selected_name = self.motion_listbox.get(selection[0])

        answer = messagebox.askyesno("실행 확인", f"'{selected_name}' 모션을 실행하시겠습니까?")
        if answer:
            self.btn_exec.config(state=tk.DISABLED)
            self.btn_plan.config(state=tk.DISABLED)
            threading.Thread(target=self.run_execution_thread, args=(selected_name,), daemon=True).start()

    def run_execution_thread(self, name):
        self.log(f"\n[시스템] '{name}' 로봇으로 전송 중...")
        motion = self.motions[name]

        success = self.executor.execute_dual_arm(motion['r_traj'], motion['l_traj'])

        if success:
            self.log(f"✅ '{name}' 이동 완료!")
        else:
            self.log("❌ 실행이 거부되었거나 실패했습니다.")

        self.root.after(0, lambda: self.btn_plan.config(state=tk.NORMAL))
        self.root.after(0, lambda: self.btn_exec.config(state=tk.NORMAL))


def main(args=None):
    rclpy.init(args=args)
    executor = CSVMoveItExecutor()

    root = tk.Tk()
    app = MoveItGUI(root, executor)

    def on_closing():
        executor.destroy_node()
        rclpy.shutdown()
        root.destroy()

    root.protocol("WM_DELETE_WINDOW", on_closing)
    root.mainloop()


if __name__ == '__main__':
    main()