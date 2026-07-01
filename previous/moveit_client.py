import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
import math
import tkinter as tk
from tkinter import messagebox

from moveit_msgs.action import MoveGroup, ExecuteTrajectory
from moveit_msgs.msg import Constraints, JointConstraint

class MoveItPlanAndExecute(Node):
    def __init__(self):
        super().__init__('moveit_plan_and_execute_node')
        self.move_action_client = ActionClient(self, MoveGroup, 'move_action')
        self.execute_action_client = ActionClient(self, ExecuteTrajectory, 'execute_trajectory')

    def send_goal_and_plan(self, group_name, target_joints_degrees):
        self.get_logger().info(f'MoveGroup 액션 서버 대기 중... group={group_name}')
        self.move_action_client.wait_for_server()

        goal_msg = MoveGroup.Goal()
        goal_msg.request.group_name = group_name
        goal_msg.request.allowed_planning_time = 5.0
        goal_msg.planning_options.plan_only = True

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

        self.get_logger().info('플래닝 요청 전송 중...')
        future = self.move_action_client.send_goal_async(goal_msg)
        rclpy.spin_until_future_complete(self, future)
        goal_handle = future.result()

        if not goal_handle.accepted:
            self.get_logger().error('MoveIt이 플래닝 요청을 거부했습니다.')
            return None

        future_result = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, future_result)
        result = future_result.result().result

        if result.error_code.val == 1:
            self.get_logger().info('🎉 플래닝 성공! RViz에서 확인하세요.')
            return result.planned_trajectory
        else:
            self.get_logger().error(f'플래닝 실패, 에러 코드: {result.error_code.val}')
            return None

    def execute_plan(self, trajectory):
        self.get_logger().info('ExecuteTrajectory 액션 서버 대기 중...')
        self.execute_action_client.wait_for_server()

        exec_goal = ExecuteTrajectory.Goal()
        exec_goal.trajectory = trajectory

        future = self.execute_action_client.send_goal_async(exec_goal)
        rclpy.spin_until_future_complete(self, future)
        goal_handle = future.result()

        if not goal_handle.accepted:
            self.get_logger().error('ExecuteTrajectory goal이 거부되었습니다.')
            return

        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future)
        self.get_logger().info('🚀 로봇 이동 완료!')


# --- GUI 클래스 ---
class RobotControlGUI:
    def __init__(self, ros_node):
        self.node = ros_node
        self.root = tk.Tk()
        self.root.title("로봇 암 제어 패널")
        # 입력창이 추가되었으므로 가로 폭을 약간 넓혔습니다.
        self.root.geometry("450x550") 
        
        # 팔 선택 (Radio Button)
        self.arm_var = tk.StringVar(value="right_arm")
        tk.Radiobutton(self.root, text="오른팔 (Right Arm)", variable=self.arm_var, value="right_arm", command=self.update_labels).pack(pady=5)
        tk.Radiobutton(self.root, text="왼팔 (Left Arm)", variable=self.arm_var, value="left_arm", command=self.update_labels).pack(pady=5)

        self.frame = tk.Frame(self.root)
        self.frame.pack(pady=10)

        # 각 관절의 각도 값을 저장하고 UI 요소 간 연동을 담당할 변수 리스트
        self.joint_vars = []
        self.labels = []

        # 7개의 슬라이더 및 입력창 생성 (-180도 ~ 180도)
        for i in range(7):
            # 💡 DoubleVar를 사용하면 슬라이더와 텍스트 입력창이 자동으로 동기화됩니다.
            var = tk.DoubleVar(value=0.0)
            self.joint_vars.append(var)

            # 1. 라벨 (Joint 이름)
            lbl = tk.Label(self.frame, text=f"Joint {i+1}")
            lbl.grid(row=i, column=0, padx=10, pady=10)
            self.labels.append(lbl)
            
            # 2. 슬라이더 (Scale)
            # resolution=0.1로 설정하여 소수점 첫째 자리까지 세밀하게 제어 가능
            slider = tk.Scale(self.frame, from_=-180, to=180, orient="horizontal", 
                              length=200, resolution=0.1, variable=var, showvalue=False)
            slider.grid(row=i, column=1, padx=5)

            # 3. 직접 입력창 (Spinbox)
            # 키보드로 직접 숫자를 입력하거나 옆의 화살표를 눌러 1도씩 조절 가능
            entry = tk.Spinbox(self.frame, from_=-180, to=180, increment=1.0, 
                               width=8, format="%.1f", textvariable=var)
            entry.grid(row=i, column=2, padx=10)

        # Plan 버튼
        self.plan_btn = tk.Button(self.root, text="계획 생성 (Plan)", command=self.on_plan, bg="lightblue", font=("Arial", 12, "bold"))
        self.plan_btn.pack(pady=20, fill="x", padx=50)

        # 초기 라벨 세팅
        self.update_labels()

    def update_labels(self):
        # 팔 선택에 따라 라벨을 joint1~7 또는 joint8~14로 변경
        offset = 0 if self.arm_var.get() == "right_arm" else 7
        for i, lbl in enumerate(self.labels):
            lbl.config(text=f"Joint {i + 1 + offset}")

    def on_plan(self):
        group_name = self.arm_var.get()
        offset = 0 if group_name == "right_arm" else 7
        
        # DoubleVar 리스트에서 현재 각도를 읽어와 딕셔너리로 구성
        target_dict_deg = {}
        for i, var in enumerate(self.joint_vars):
            joint_name = f"joint{i + 1 + offset}"
            # get()을 호출하면 슬라이더/입력창의 현재 값이 float로 반환됨
            target_dict_deg[joint_name] = var.get()

        # MoveIt으로 플래닝 요청
        trajectory = self.node.send_goal_and_plan(group_name, target_dict_deg)

        # 플래닝에 성공하면 알림창(MessageBox) 띄우기
        if trajectory:
            if messagebox.askyesno("경로 확인", "RViz에서 경로를 확인했습니까?\n로봇을 실제로 이동시킬까요?"):
                self.node.execute_plan(trajectory)
            else:
                self.node.get_logger().info('실행이 취소되었습니다.')
        else:
            messagebox.showerror("플래닝 실패", "경로를 생성할 수 없습니다. 목표 각도를 변경해 보세요.")

def main(args=None):
    rclpy.init(args=args)
    node = MoveItPlanAndExecute()

    # GUI 실행
    gui = RobotControlGUI(node)
    gui.root.mainloop()

    # 창이 닫히면 ROS 노드 안전하게 종료
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main() 