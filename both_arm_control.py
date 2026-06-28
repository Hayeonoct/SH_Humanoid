import math
import time
import tkinter as tk
from tkinter import messagebox

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient

from moveit_msgs.action import MoveGroup
from moveit_msgs.msg import Constraints, JointConstraint
from moveit_msgs.msg import MoveItErrorCodes
from control_msgs.action import FollowJointTrajectory


class MoveItPlanThenBothExecute(Node):
    def __init__(self):
        super().__init__('moveit_plan_then_both_execute_node')

        self.move_action_client = ActionClient(
            self, MoveGroup, 'move_action'
        )
        self.right_client = ActionClient(
            self, FollowJointTrajectory, '/right_arm_controller/follow_joint_trajectory'
        )
        self.left_client = ActionClient(
            self, FollowJointTrajectory, '/left_arm_controller/follow_joint_trajectory'
        )

    # 💡 [핵심 추가] 궤적의 마지막 5도 구간을 부드럽게 늘려주는 함수
    def apply_soft_landing(self, joint_trajectory, threshold_deg=10.0, max_factor=4.0):
        """
        목표까지 남은 거리가 threshold_deg 이하일 때, 
        시간(dt)을 점진적으로 늘려 최대 max_factor 배까지 감속시킵니다.
        """
        points = joint_trajectory.points
        if len(points) < 2:
            return joint_trajectory

        final_positions = points[-1].positions
        threshold_rad = math.radians(threshold_deg)

        # 원본 시간(dt) 계산을 위해 시간 데이터 추출
        orig_times = [p.time_from_start.sec + p.time_from_start.nanosec * 1e-9 for p in points]
        new_time = orig_times[0]

        for i in range(1, len(points)):
            dt = orig_times[i] - orig_times[i-1]
            curr_pt = points[i]

            # 목표까지 가장 많이 남은 관절의 남은 각도(rad) 계산
            max_dist = max([abs(final_positions[j] - curr_pt.positions[j]) for j in range(len(curr_pt.positions))])

            # 남은 거리가 5도 이하 구간에 진입했다면 감속 시작!
            if max_dist <= threshold_rad:
                # 거리가 가까워질수록 factor를 1.0에서 max_factor까지 부드럽게 증가시킴 (급브레이크 방지)
                ratio = 1.0 - (max_dist / threshold_rad)  # 0.0 (5도 남음) -> 1.0 (도달)
                current_factor = 1.0 + (max_factor - 1.0) * ratio
                
                # 시간(dt)을 고무줄처럼 늘림
                dt *= current_factor

                # 늘어난 시간에 맞춰 속도와 가속도 값도 줄여줌 (하드웨어 보호)
                if curr_pt.velocities:
                    curr_pt.velocities = [v / current_factor for v in curr_pt.velocities]
                if curr_pt.accelerations:
                    curr_pt.accelerations = [a / (current_factor**2) for a in curr_pt.accelerations]

            new_time += dt

            # 계산된 새로운 시간을 초와 나노초로 변환하여 적용
            curr_pt.time_from_start.sec = int(new_time)
            curr_pt.time_from_start.nanosec = int((new_time - int(new_time)) * 1e9)

        return joint_trajectory

    def plan_arm(self, group_name, target_joints_degrees):
        self.get_logger().info(f'MoveGroup action server 대기 중... group={group_name}')
        self.move_action_client.wait_for_server()

        goal_msg = MoveGroup.Goal()
        goal_msg.request.group_name = group_name
        goal_msg.request.allowed_planning_time = 5.0
        goal_msg.planning_options.plan_only = True
        goal_msg.request.start_state.is_diff = True

        constraints = Constraints()
        for joint_name, pos_degree in target_joints_degrees.items():
            jc = JointConstraint()
            jc.joint_name = joint_name
            jc.position = math.radians(pos_degree)
            jc.tolerance_above = 0.01
            jc.tolerance_below = 0.01
            jc.weight = 1.0
            constraints.joint_constraints.append(jc)

        goal_msg.request.goal_constraints.append(constraints)

        self.get_logger().info(f'{group_name} planning 요청 전송 중...')
        send_future = self.move_action_client.send_goal_async(goal_msg)
        rclpy.spin_until_future_complete(self, send_future)

        goal_handle = send_future.result()
        if goal_handle is None or not goal_handle.accepted:
            self.get_logger().error(f'{group_name} planning goal 거부됨.')
            return None

        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future)
        result = result_future.result().result

        if result.error_code.val != MoveItErrorCodes.SUCCESS:
            self.get_logger().error(f'{group_name} planning 실패. 에러코드: {result.error_code.val}')
            return None

        # 💡 원본 궤적을 가져와서 소프트 랜딩 필터를 거친 뒤 반환합니다.
        raw_trajectory = result.planned_trajectory.joint_trajectory
        smoothed_trajectory = self.apply_soft_landing(raw_trajectory, threshold_deg=5.0, max_factor=5.0)

        return smoothed_trajectory

    def make_follow_goal_from_trajectory(self, joint_trajectory):
        goal = FollowJointTrajectory.Goal()
        goal.trajectory = joint_trajectory
        return goal

    def execute_both_planned_trajectories(self, right_trajectory, left_trajectory):
        self.right_client.wait_for_server()
        self.left_client.wait_for_server()

        right_goal = self.make_follow_goal_from_trajectory(right_trajectory)
        left_goal = self.make_follow_goal_from_trajectory(left_trajectory)

        self.get_logger().info('오른팔/왼팔 trajectory 동시 전송 중...')

        right_send_future = self.right_client.send_goal_async(right_goal)
        left_send_future = self.left_client.send_goal_async(left_goal)

        rclpy.spin_until_future_complete(self, right_send_future)
        rclpy.spin_until_future_complete(self, left_send_future)

        right_handle = right_send_future.result()
        left_handle = left_send_future.result()

        if not right_handle or not right_handle.accepted or not left_handle or not left_handle.accepted:
            self.get_logger().error('Action Goal이 거부되었습니다.')
            return False

        right_result_future = right_handle.get_result_async()
        left_result_future = left_handle.get_result_async()

        rclpy.spin_until_future_complete(self, right_result_future)
        rclpy.spin_until_future_complete(self, left_result_future)

        self.get_logger().info('양팔 이동 완료!')
        return True


# --- GUI 클래스 ---
class DualArmControlGUI:
    def __init__(self, ros_node):
        self.node = ros_node
        self.root = tk.Tk()
        self.root.title("Dual Arm 제어 패널 (소프트 랜딩 적용)")
        self.root.geometry("800x650") 
        
        # 부호 매핑 배열 (UI 입력값 * 부호)
        self.right_signs = [1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0]
        self.left_signs = [-1.0, 1.0, -1.0, 1.0, 1.0, -1.0, -1.0]

        self.main_frame = tk.Frame(self.root)
        self.main_frame.pack(pady=10, fill="both", expand=True)

        self.right_frame = tk.LabelFrame(self.main_frame, text="오른팔 (Right Arm: Joint 1~7)", padx=10, pady=10)
        self.right_frame.pack(side="left", padx=20, fill="y")

        self.left_frame = tk.LabelFrame(self.main_frame, text="왼팔 (Left Arm: Joint 8~14)", padx=10, pady=10)
        self.left_frame.pack(side="right", padx=20, fill="y")

        self.right_vars = []
        self.left_vars = []

        for i in range(7):
            var = tk.DoubleVar(value=0.0)
            self.right_vars.append(var)
            self.create_joint_row(self.right_frame, f"Joint {i+1}", var, i)

        for i in range(7):
            var = tk.DoubleVar(value=0.0)
            self.left_vars.append(var)
            self.create_joint_row(self.left_frame, f"Joint {i+8}", var, i)

        self.right_planned_traj = None
        self.left_planned_traj = None

        self.btn_frame1 = tk.Frame(self.root)
        self.btn_frame1.pack(pady=10, fill="x", padx=50)

        self.plan_right_btn = tk.Button(
            self.btn_frame1, text="1. 오른팔 미리보기", command=self.on_plan_right, 
            bg="lightblue", font=("Arial", 11, "bold"), height=2
        )
        self.plan_right_btn.pack(side="left", fill="x", expand=True, padx=5)

        self.plan_left_btn = tk.Button(
            self.btn_frame1, text="2. 왼팔 미리보기", command=self.on_plan_left, 
            bg="lightpink", font=("Arial", 11, "bold"), height=2
        )
        self.plan_left_btn.pack(side="right", fill="x", expand=True, padx=5)

        self.btn_frame2 = tk.Frame(self.root)
        self.btn_frame2.pack(pady=5, fill="x", padx=50)

        self.exec_btn = tk.Button(
            self.btn_frame2, text="3. 양팔 시퀀스 실행 (이동 후 0도 복귀)", command=self.on_execute_sequence, 
            bg="lightgreen", font=("Arial", 12, "bold"), state="disabled", height=2
        )
        self.exec_btn.pack(fill="x", expand=True, padx=5)

    def create_joint_row(self, parent, label_text, var, row_idx):
        tk.Label(parent, text=label_text, width=8).grid(row=row_idx, column=0, pady=5)
        slider = tk.Scale(parent, from_=-180, to=180, orient="horizontal", 
                          length=150, resolution=0.1, variable=var, showvalue=False)
        slider.grid(row=row_idx, column=1, padx=5)
        entry = tk.Spinbox(parent, from_=-180, to=180, increment=1.0, 
                           width=6, format="%.1f", textvariable=var)
        entry.grid(row=row_idx, column=2, padx=5)

    def check_ready_to_execute(self):
        if self.right_planned_traj and self.left_planned_traj:
            self.exec_btn.config(state="normal")
        else:
            self.exec_btn.config(state="disabled")

    def on_plan_right(self):
        target_right = {f'joint{i+1}': var.get() * self.right_signs[i] for i, var in enumerate(self.right_vars)}
        self.node.get_logger().info(f"==== 오른팔 플래닝 생성 중 ====")
        self.right_planned_traj = self.node.plan_arm('right_arm', target_right)
        if self.right_planned_traj:
            self.node.get_logger().info("✅ 오른팔 플래닝 완료!")
        else:
            messagebox.showerror("오른팔 플래닝 실패", "경로를 생성할 수 없습니다.")
        self.check_ready_to_execute()

    def on_plan_left(self):
        target_left = {f'joint{i+8}': var.get() * self.left_signs[i] for i, var in enumerate(self.left_vars)}
        self.node.get_logger().info(f"==== 왼팔 플래닝 생성 중 ====")
        self.left_planned_traj = self.node.plan_arm('left_arm', target_left)
        if self.left_planned_traj:
            self.node.get_logger().info("✅ 왼팔 플래닝 완료!")
        else:
            messagebox.showerror("왼팔 플래닝 실패", "경로를 생성할 수 없습니다.")
        self.check_ready_to_execute()

    def on_execute_sequence(self):
        if not messagebox.askyesno("최종 확인", "RViz에서 경로를 확인했습니까?\n실제 로봇을 구동합니다."):
            return

        self.plan_right_btn.config(state="disabled")
        self.plan_left_btn.config(state="disabled")
        self.exec_btn.config(state="disabled")
        self.root.update()

        self.node.get_logger().info("==== [1단계] 목표 지점으로 실행 ====")
        success = self.node.execute_both_planned_trajectories(self.right_planned_traj, self.left_planned_traj)
        if not success:
            self.reset_ui_buttons()
            return

        self.node.get_logger().info("목표 도달. 1.5초 대기...")
        time.sleep(1.5) 

        self.node.get_logger().info("==== [2단계] 0도 복귀 지점 플래닝 ====")
        zero_right = {f'joint{i+1}': 0.0 for i in range(7)}
        zero_left = {f'joint{i+8}': 0.0 for i in range(7)}

        right_zero_traj = self.node.plan_arm('right_arm', zero_right)
        left_zero_traj = self.node.plan_arm('left_arm', zero_left)

        if right_zero_traj and left_zero_traj:
            self.node.get_logger().info("==== [3단계] 즉시 0도로 복귀 실행 ====")
            self.node.execute_both_planned_trajectories(right_zero_traj, left_zero_traj)
        else:
            messagebox.showwarning("오류", "0도로 돌아오는 경로 생성에 실패했습니다.")

        self.node.get_logger().info("==== 시퀀스 완전 종료 ====")
        # for var in self.right_vars + self.left_vars:
        #     var.set(0.0)
        self.right_planned_traj = None
        self.left_planned_traj = None
        self.reset_ui_buttons()

    def reset_ui_buttons(self):
        self.plan_right_btn.config(state="normal")
        self.plan_left_btn.config(state="normal")
        self.exec_btn.config(state="disabled")


def main(args=None):
    rclpy.init(args=args)
    node = MoveItPlanThenBothExecute()
    gui = DualArmControlGUI(node)
    gui.root.mainloop()
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()