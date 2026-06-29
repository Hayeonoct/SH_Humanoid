import csv
import math
import os
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
            self,
            MoveGroup,
            'move_action'
        )

        self.right_client = ActionClient(
            self,
            FollowJointTrajectory,
            '/right_arm_controller/follow_joint_trajectory'
        )

        self.left_client = ActionClient(
            self,
            FollowJointTrajectory,
            '/left_arm_controller/follow_joint_trajectory'
        )

    # -------------------------------------------------------
    # Trajectory time helpers
    # -------------------------------------------------------

    def get_point_time(self, point):
        return point.time_from_start.sec + point.time_from_start.nanosec * 1e-9

    def apply_soft_landing(self, joint_trajectory, threshold_deg=5.0, max_factor=5.0):
        """
        목표 위치에 가까워지는 마지막 구간에서 시간을 늘려서 부드럽게 감속.
        """
        points = joint_trajectory.points

        if len(points) < 2:
            return joint_trajectory

        final_positions = points[-1].positions
        threshold_rad = math.radians(threshold_deg)

        original_times = [
            self.get_point_time(p)
            for p in points
        ]

        new_time = original_times[0]

        for i in range(1, len(points)):
            dt = original_times[i] - original_times[i - 1]
            curr_pt = points[i]

            if len(curr_pt.positions) == 0:
                continue

            max_dist = max(
                abs(final_positions[j] - curr_pt.positions[j])
                for j in range(len(curr_pt.positions))
            )

            if max_dist <= threshold_rad:
                ratio = 1.0 - (max_dist / threshold_rad)
                current_factor = 1.0 + (max_factor - 1.0) * ratio

                dt *= current_factor

                if curr_pt.velocities:
                    curr_pt.velocities = [
                        v / current_factor
                        for v in curr_pt.velocities
                    ]

                if curr_pt.accelerations:
                    curr_pt.accelerations = [
                        a / (current_factor ** 2)
                        for a in curr_pt.accelerations
                    ]

            new_time += dt

            curr_pt.time_from_start.sec = int(new_time)
            curr_pt.time_from_start.nanosec = int(
                (new_time - int(new_time)) * 1e9
            )

        return joint_trajectory

    def scale_trajectory_duration(self, joint_trajectory, desired_duration):
        """
        desired_duration 규칙:
        - None 또는 -1 이하: MoveIt이 만든 기본 trajectory 시간 그대로 사용
        - 양수: trajectory 전체 시간을 desired_duration 초로 스케일링
        """
        if desired_duration is None:
            return joint_trajectory

        if desired_duration < 0:
            return joint_trajectory

        if desired_duration <= 1e-6:
            return joint_trajectory

        points = joint_trajectory.points

        if len(points) < 2:
            return joint_trajectory

        last_time = self.get_point_time(points[-1])

        if last_time <= 1e-6:
            return joint_trajectory

        scale = desired_duration / last_time

        for p in points:
            old_time = self.get_point_time(p)
            new_time = old_time * scale

            p.time_from_start.sec = int(new_time)
            p.time_from_start.nanosec = int(
                (new_time - int(new_time)) * 1e9
            )

            if p.velocities:
                p.velocities = [
                    v / scale
                    for v in p.velocities
                ]

            if p.accelerations:
                p.accelerations = [
                    a / (scale ** 2)
                    for a in p.accelerations
                ]

        return joint_trajectory

    # -------------------------------------------------------
    # MoveIt planning
    # -------------------------------------------------------

    def plan_arm(self, group_name, target_joints_degrees, desired_duration=None):
        """
        MoveIt으로 한 팔의 trajectory를 planning.

        group_name:
          - 'right_arm'
          - 'left_arm'

        target_joints_degrees:
          - degree 단위
          - MoveIt/RViz 기준 각도값

        desired_duration:
          - None 또는 -1: MoveIt 기본 시간 사용
          - 양수: 해당 초로 trajectory 시간 스케일링
        """
        self.get_logger().info(
            f'MoveGroup action server 대기 중... group={group_name}'
        )
        self.move_action_client.wait_for_server()

        goal_msg = MoveGroup.Goal()
        goal_msg.request.group_name = group_name
        goal_msg.request.allowed_planning_time = 5.0
        goal_msg.planning_options.plan_only = True

        # 현재 /joint_states 기반 시작 상태 사용
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

        self.get_logger().info(
            f'{group_name} planning 요청 전송 중... '
            f'desired_duration={desired_duration}'
        )

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
            self.get_logger().error(
                f'{group_name} planning 실패. 에러코드: {result.error_code.val}'
            )
            return None

        trajectory = result.planned_trajectory.joint_trajectory

        trajectory = self.apply_soft_landing(
            trajectory,
            threshold_deg=5.0,
            max_factor=5.0
        )

        trajectory = self.scale_trajectory_duration(
            trajectory,
            desired_duration
        )

        self.get_logger().info(f'{group_name} planning 성공')

        return trajectory

    # -------------------------------------------------------
    # FollowJointTrajectory execute
    # -------------------------------------------------------

    def make_follow_goal_from_trajectory(self, joint_trajectory):
        goal = FollowJointTrajectory.Goal()
        goal.trajectory = joint_trajectory
        return goal

    def execute_both_planned_trajectories(self, right_trajectory, left_trajectory):
        """
        오른팔/왼팔 FollowJointTrajectory action server로 trajectory를 거의 동시에 전송.
        두 팔 action result가 모두 돌아와야 True 반환.
        """
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

        if right_handle is None or not right_handle.accepted:
            self.get_logger().error('Right arm Action Goal이 거부되었습니다.')
            return False

        if left_handle is None or not left_handle.accepted:
            self.get_logger().error('Left arm Action Goal이 거부되었습니다.')
            return False

        right_result_future = right_handle.get_result_async()
        left_result_future = left_handle.get_result_async()

        rclpy.spin_until_future_complete(self, right_result_future)
        rclpy.spin_until_future_complete(self, left_result_future)

        right_result = right_result_future.result().result
        left_result = left_result_future.result().result

        self.get_logger().info(
            f'Right result: error_code={right_result.error_code}, '
            f'error_string="{right_result.error_string}"'
        )

        self.get_logger().info(
            f'Left result: error_code={left_result.error_code}, '
            f'error_string="{left_result.error_string}"'
        )

        self.get_logger().info('양팔 이동 완료')

        return True


class DualArmControlGUI:
    def __init__(self, ros_node):
        self.node = ros_node

        self.script_dir = os.path.dirname(os.path.abspath(__file__))
        self.motion_csv_path = os.path.join(self.script_dir, 'motions.csv')

        self.motion_library = {}

        self.root = tk.Tk()
        self.root.title('Dual Arm 제어 패널 + CSV Motion')
        self.root.geometry('980x820')

        # self.right_vars = []
        # self.left_vars = []

        self.right_planned_traj = None
        self.left_planned_traj = None

        self.preview_sequence_index = 0

        # self.create_manual_control_area()
        self.create_motion_csv_area()

        self.load_default_motion_csv(show_message=False)

    # -------------------------------------------------------
    # GUI layout
    # -------------------------------------------------------

    def on_plan_selected_motion(self):
        """
        실행 순서 stack에서 현재 preview index에 해당하는 motion을 planning.
        이 버튼은 수동 입력창 값이 아니라 CSV motion 값을 사용합니다.
        """
        if not self.motion_library:
            messagebox.showwarning(
                '모션 없음',
                'motions.csv 파일을 먼저 로드하세요.'
            )
            return

        motion_name = self.get_selected_preview_motion_name()

        if motion_name is None:
            messagebox.showwarning(
                'Preview 불가',
                '실행 순서 stack에 모션을 먼저 추가하세요.'
            )
            return

        if motion_name not in self.motion_library:
            messagebox.showerror(
                '알 수 없는 모션',
                f'motions.csv에 없는 모션입니다: {motion_name}'
            )
            return

        steps = self.motion_library[motion_name]

        if not steps:
            messagebox.showwarning(
                '빈 모션',
                f'{motion_name}에 step이 없습니다.'
            )
            return

        self.disable_all_buttons()
        self.root.update()

        try:
            self.log_status(
                f'==== 선택 모션 Planning 시작: {motion_name} ===='
            )

            last_right_traj = None
            last_left_traj = None

            for step_data in steps:
                step = step_data['step']
                duration = step_data['duration']
                joints = step_data['joints']

                self.log_status(
                    f'{motion_name} step {step} preview planning 중... '
                    f'duration={duration}'
                )

                right_target = {
                    f'joint{i}': joints[f'joint{i}']
                    for i in range(1, 8)
                }

                left_target = {
                    f'joint{i}': joints[f'joint{i}']
                    for i in range(8, 15)
                }

                desired_duration = None if duration < 0 else duration

                right_traj = self.node.plan_arm(
                    'right_arm',
                    right_target,
                    desired_duration=desired_duration
                )

                if right_traj is None:
                    messagebox.showerror(
                        'Planning 실패',
                        f'{motion_name} step {step} 오른팔 planning 실패'
                    )
                    return

                left_traj = self.node.plan_arm(
                    'left_arm',
                    left_target,
                    desired_duration=desired_duration
                )

                if left_traj is None:
                    messagebox.showerror(
                        'Planning 실패',
                        f'{motion_name} step {step} 왼팔 planning 실패'
                    )
                    return

                last_right_traj = right_traj
                last_left_traj = left_traj

            self.log_status(
                f'==== 선택 모션 Planning 완료: {motion_name} ===='
            )

            # preview용 planning 결과를 저장해두지는 않음.
            # 실제 실행은 CSV 실행 버튼에서 다시 planning 후 실행.
            # 여기서는 RViz 확인용으로만 사용.

        finally:
            self.reset_ui_buttons()

    def select_sequence_index(self, index):
        size = self.sequence_listbox.size()

        if size == 0:
            self.preview_sequence_index = 0
            self.sequence_listbox.selection_clear(0, tk.END)
            self.update_preview_label()
            return

        index = max(0, min(index, size - 1))
        self.preview_sequence_index = index

        self.sequence_listbox.selection_clear(0, tk.END)
        self.sequence_listbox.selection_set(index)
        self.sequence_listbox.activate(index)
        self.sequence_listbox.see(index)

        self.update_preview_label()

    def on_preview_prev_motion(self):
        if self.sequence_listbox.size() == 0:
            messagebox.showwarning(
                'Preview 불가',
                '실행 순서 stack에 모션을 먼저 추가하세요.'
            )
            return

        self.select_sequence_index(self.preview_sequence_index - 1)

        motion_name = self.get_selected_preview_motion_name()
        self.log_status(f'Preview 대상 변경: {motion_name}')


    def on_preview_next_motion(self):
        if self.sequence_listbox.size() == 0:
            messagebox.showwarning(
                'Preview 불가',
                '실행 순서 stack에 모션을 먼저 추가하세요.'
            )
            return

        self.select_sequence_index(self.preview_sequence_index + 1)

        motion_name = self.get_selected_preview_motion_name()
        self.log_status(f'Preview 대상 변경: {motion_name}')
        
    def get_selected_preview_motion_name(self):
        size = self.sequence_listbox.size()

        if size == 0:
            return None

        index = max(0, min(self.preview_sequence_index, size - 1))
        return self.sequence_listbox.get(index)


    def update_preview_label(self):
        size = self.sequence_listbox.size()

        if size == 0:
            self.preview_label.config(text='Preview 대상: 없음')
            return

        motion_name = self.get_selected_preview_motion_name()

        self.preview_label.config(
            text=f'Preview 대상: {self.preview_sequence_index + 1}/{size}  {motion_name}'
        )

    def refresh_motion_buttons(self):
        # 기존 버튼 제거
        for widget in self.motion_button_frame.winfo_children():
            widget.destroy()

        motion_names = sorted(self.motion_library.keys())

        if not motion_names:
            tk.Label(
                self.motion_button_frame,
                text='로드된 모션이 없습니다.'
            ).pack(anchor='w', padx=5, pady=5)
            return

        for motion_name in motion_names:
            btn = tk.Button(
                self.motion_button_frame,
                text=motion_name,
                command=lambda name=motion_name: self.on_add_motion_to_sequence(name),
                width=12,
                bg='white',
                font=('Arial', 10, 'bold')
            )
            btn.pack(
                side='left',
                padx=4,
                pady=4
            )

    def on_add_motion_to_sequence(self, motion_name):
        """
        모션 버튼을 누를 때마다 실행 순서 stack에 추가.
        같은 motion을 여러 번 추가할 수 있음.
        """
        self.sequence_listbox.insert(tk.END, motion_name)
        self.exec_motion_btn.config(state='normal')

        # 첫 번째 모션을 추가한 경우 preview index를 0으로 맞춤
        if self.sequence_listbox.size() == 1:
            self.preview_sequence_index = 0
            self.select_sequence_index(0)

        self.update_preview_label()

        self.log_status(f'실행 순서에 추가: {motion_name}')

    def on_remove_selected_motion(self):
        selection = self.sequence_listbox.curselection()

        if not selection:
            return

        idx = selection[0]
        motion_name = self.sequence_listbox.get(idx)

        self.sequence_listbox.delete(idx)

        self.log_status(f'실행 순서에서 삭제: {motion_name}')

        size = self.sequence_listbox.size()

        if size == 0:
            self.exec_motion_btn.config(state='disabled')
            self.preview_sequence_index = 0
            self.update_preview_label()
        else:
            if self.preview_sequence_index >= size:
                self.preview_sequence_index = size - 1
            self.select_sequence_index(self.preview_sequence_index)


    def on_clear_motion_sequence(self):
        self.sequence_listbox.delete(0, tk.END)
        self.exec_motion_btn.config(state='disabled')

        self.preview_sequence_index = 0
        self.update_preview_label()

        self.log_status('실행 순서를 모두 삭제했습니다.')


    def on_move_sequence_up(self):
        selection = self.sequence_listbox.curselection()

        if not selection:
            return

        idx = selection[0]

        if idx == 0:
            return

        motion_name = self.sequence_listbox.get(idx)

        self.sequence_listbox.delete(idx)
        self.sequence_listbox.insert(idx - 1, motion_name)
        self.sequence_listbox.selection_set(idx - 1)

        self.log_status(f'순서 위로 이동: {motion_name}')

        self.preview_sequence_index = idx - 1
        self.update_preview_label() 


    def on_move_sequence_down(self):
        selection = self.sequence_listbox.curselection()

        if not selection:
            return

        idx = selection[0]

        if idx >= self.sequence_listbox.size() - 1:
            return

        motion_name = self.sequence_listbox.get(idx)

        self.sequence_listbox.delete(idx)
        self.sequence_listbox.insert(idx + 1, motion_name)
        self.sequence_listbox.selection_set(idx + 1)

        self.log_status(f'순서 아래로 이동: {motion_name}')

        self.preview_sequence_index = idx + 1
        self.update_preview_label()


    def get_motion_sequence_from_listbox(self):
        return [
            self.sequence_listbox.get(i)
            for i in range(self.sequence_listbox.size())
        ]

    # def create_manual_control_area(self):
    #     self.main_frame = tk.LabelFrame(
    #         self.root,
    #         text='Manual Joint Control',
    #         padx=10,
    #         pady=10
    #     )
    #     self.main_frame.pack(
    #         pady=10,
    #         padx=20,
    #         fill='both',
    #         expand=False
    #     )

    #     self.arm_frame = tk.Frame(self.main_frame)
    #     self.arm_frame.pack(fill='x')

    #     self.right_frame = tk.LabelFrame(
    #         self.arm_frame,
    #         text='오른팔 Right Arm: Joint 1~7',
    #         padx=10,
    #         pady=10
    #     )
    #     self.right_frame.pack(
    #         side='left',
    #         padx=20,
    #         fill='y',
    #         expand=True
    #     )

    #     self.left_frame = tk.LabelFrame(
    #         self.arm_frame,
    #         text='왼팔 Left Arm: Joint 8~14',
    #         padx=10,
    #         pady=10
    #     )
    #     self.left_frame.pack(
    #         side='right',
    #         padx=20,
    #         fill='y',
    #         expand=True
    #     )

    #     for i in range(7):
    #         var = tk.DoubleVar(value=0.0)
    #         var.trace_add('write', self.on_manual_value_changed)
    #         self.right_vars.append(var)

    #         self.create_joint_row(
    #             self.right_frame,
    #             f'Joint {i + 1}',
    #             var,
    #             i
    #         )

    #     for i in range(7):
    #         var = tk.DoubleVar(value=0.0)
    #         var.trace_add('write', self.on_manual_value_changed)
    #         self.left_vars.append(var)

    #         self.create_joint_row(
    #             self.left_frame,
    #             f'Joint {i + 8}',
    #             var,
    #             i
    #         )

    #     self.manual_option_frame = tk.Frame(self.main_frame)
    #     self.manual_option_frame.pack(
    #         pady=10,
    #         fill='x',
    #         padx=50
    #     )

    #     tk.Label(
    #         self.manual_option_frame,
    #         text='수동 실행 duration [sec], -1 = MoveIt 기본 시간'
    #     ).pack(side='left', padx=5)

    #     self.manual_duration_var = tk.DoubleVar(value=-1.0)

    #     self.manual_duration_spin = tk.Spinbox(
    #         self.manual_option_frame,
    #         from_=-1.0,
    #         to=20.0,
    #         increment=0.1,
    #         width=8,
    #         format='%.1f',
    #         textvariable=self.manual_duration_var,
    #         command=self.on_manual_value_changed
    #     )
    #     self.manual_duration_spin.pack(side='left', padx=5)

    #     self.btn_frame1 = tk.Frame(self.main_frame)
    #     self.btn_frame1.pack(
    #         pady=10,
    #         fill='x',
    #         padx=50
    #     )

    #     self.plan_right_btn = tk.Button(
    #         self.btn_frame1,
    #         text='1. 오른팔 미리보기',
    #         command=self.on_plan_right,
    #         bg='lightblue',
    #         font=('Arial', 11, 'bold'),
    #         height=2
    #     )
    #     self.plan_right_btn.pack(
    #         side='left',
    #         fill='x',
    #         expand=True,
    #         padx=5
    #     )

    #     self.plan_left_btn = tk.Button(
    #         self.btn_frame1,
    #         text='2. 왼팔 미리보기',
    #         command=self.on_plan_left,
    #         bg='lightpink',
    #         font=('Arial', 11, 'bold'),
    #         height=2
    #     )
    #     self.plan_left_btn.pack(
    #         side='right',
    #         fill='x',
    #         expand=True,
    #         padx=5
    #     )

    #     self.btn_frame2 = tk.Frame(self.main_frame)
    #     self.btn_frame2.pack(
    #         pady=5,
    #         fill='x',
    #         padx=50
    #     )

    #     self.exec_btn = tk.Button(
    #         self.btn_frame2,
    #         text='3. 양팔 실행',
    #         command=self.on_execute_manual,
    #         bg='lightgreen',
    #         font=('Arial', 12, 'bold'),
    #         state='disabled',
    #         height=2
    #     )
    #     self.exec_btn.pack(
    #         side='left',
    #         fill='x',
    #         expand=True,
    #         padx=5
    #     )

    #     self.clear_btn = tk.Button(
    #         self.btn_frame2,
    #         text='Clear 입력값 0도',
    #         command=self.on_clear_values,
    #         bg='lightgray',
    #         font=('Arial', 12, 'bold'),
    #         height=2
    #     )
    #     self.clear_btn.pack(
    #         side='right',
    #         fill='x',
    #         expand=True,
    #         padx=5
    #     )

    def create_motion_csv_area(self):
        self.motion_frame = tk.LabelFrame(
            self.root,
            text='CSV Motion Sequence',
            padx=10,
            pady=10
        )
        self.motion_frame.pack(
            pady=10,
            padx=20,
            fill='both',
            expand=True
        )

        self.csv_path_label = tk.Label(
            self.motion_frame,
            text=f'CSV 파일: {self.motion_csv_path}',
            anchor='w',
            justify='left'
        )
        self.csv_path_label.pack(fill='x', pady=3)

        self.reload_csv_btn = tk.Button(
            self.motion_frame,
            text='motions.csv 다시 불러오기',
            command=lambda: self.load_default_motion_csv(show_message=True),
            bg='khaki',
            font=('Arial', 11, 'bold'),
            height=2
        )
        self.reload_csv_btn.pack(fill='x', pady=5)

        self.motion_list_label = tk.Label(
            self.motion_frame,
            text='로드된 모션: 없음',
            anchor='w',
            justify='left'
        )
        self.motion_list_label.pack(fill='x', pady=3)

        # -------------------------------------------------------
        # 모션 버튼 영역
        # -------------------------------------------------------
        self.motion_button_frame = tk.LabelFrame(
            self.motion_frame,
            text='로드된 모션 버튼'
        )
        self.motion_button_frame.pack(fill='x', pady=5)

        # -------------------------------------------------------
        # 실행 순서 stack 영역
        # -------------------------------------------------------
        self.sequence_frame = tk.LabelFrame(
            self.motion_frame,
            text='실행 순서 Stack'
        )
        self.sequence_frame.pack(fill='both', expand=True, pady=5)

        self.sequence_listbox = tk.Listbox(
            self.sequence_frame,
            height=8,
            selectmode=tk.SINGLE,
            font=('Arial', 11)
        )
        self.sequence_listbox.pack(
            side='left',
            fill='both',
            expand=True,
            padx=5,
            pady=5
        )

        self.sequence_scrollbar = tk.Scrollbar(
            self.sequence_frame,
            orient='vertical',
            command=self.sequence_listbox.yview
        )
        self.sequence_scrollbar.pack(
            side='right',
            fill='y'
        )

        self.sequence_listbox.config(
            yscrollcommand=self.sequence_scrollbar.set
        )

        # -------------------------------------------------------
        # stack 조작 버튼
        # -------------------------------------------------------
        self.sequence_control_frame = tk.Frame(self.motion_frame)
        self.sequence_control_frame.pack(fill='x', pady=5)

        self.remove_selected_btn = tk.Button(
            self.sequence_control_frame,
            text='선택 삭제',
            command=self.on_remove_selected_motion,
            bg='mistyrose',
            font=('Arial', 10, 'bold')
        )
        self.remove_selected_btn.pack(
            side='left',
            fill='x',
            expand=True,
            padx=3
        )

        self.move_up_btn = tk.Button(
            self.sequence_control_frame,
            text='위로',
            command=self.on_move_sequence_up,
            bg='lightyellow',
            font=('Arial', 10, 'bold')
        )
        self.move_up_btn.pack(
            side='left',
            fill='x',
            expand=True,
            padx=3
        )

        self.move_down_btn = tk.Button(
            self.sequence_control_frame,
            text='아래로',
            command=self.on_move_sequence_down,
            bg='lightyellow',
            font=('Arial', 10, 'bold')
        )
        self.move_down_btn.pack(
            side='left',
            fill='x',
            expand=True,
            padx=3
        )

        self.clear_sequence_btn = tk.Button(
            self.sequence_control_frame,
            text='순서 전체 삭제',
            command=self.on_clear_motion_sequence,
            bg='lightgray',
            font=('Arial', 10, 'bold')
        )
        self.clear_sequence_btn.pack(
            side='left',
            fill='x',
            expand=True,
            padx=3
        )

        # -------------------------------------------------------
        # selected motion preview 버튼
        # -------------------------------------------------------
        self.preview_control_frame = tk.Frame(self.motion_frame)
        self.preview_control_frame.pack(fill='x', pady=5)

        self.prev_preview_btn = tk.Button(
            self.preview_control_frame,
            text='< 이전 모션 보기',
            command=self.on_preview_prev_motion,
            bg='lightcyan',
            font=('Arial', 10, 'bold')
        )
        self.prev_preview_btn.pack(
            side='left',
            fill='x',
            expand=True,
            padx=3
        )

        self.plan_selected_motion_btn = tk.Button(
            self.preview_control_frame,
            text='선택 모션 Planning',
            command=self.on_plan_selected_motion,
            bg='lightskyblue',
            font=('Arial', 10, 'bold')
        )
        self.plan_selected_motion_btn.pack(
            side='left',
            fill='x',
            expand=True,
            padx=3
        )

        self.next_preview_btn = tk.Button(
            self.preview_control_frame,
            text='다음 모션 보기 >',
            command=self.on_preview_next_motion,
            bg='lightcyan',
            font=('Arial', 10, 'bold')
        )
        self.next_preview_btn.pack(
            side='left',
            fill='x',
            expand=True,
            padx=3
        )

        self.preview_label = tk.Label(
            self.motion_frame,
            text='Preview 대상: 없음',
            anchor='w',
            justify='left'
        )
        self.preview_label.pack(fill='x', pady=3)

        # -------------------------------------------------------
        # CSV 모션 실행 버튼
        # -------------------------------------------------------
        self.exec_motion_btn = tk.Button(
            self.motion_frame,
            text='CSV 모션 시퀀스 실행',
            command=self.on_execute_motion_sequence,
            bg='orange',
            font=('Arial', 12, 'bold'),
            height=2,
            state='disabled'
        )
        self.exec_motion_btn.pack(fill='x', pady=8)

        self.status_text = tk.Text(
            self.motion_frame,
            height=8,
            wrap='word'
        )
        self.status_text.pack(
            fill='both',
            expand=True,
            pady=5
        )

    def create_joint_row(self, parent, label_text, var, row_idx):
        tk.Label(
            parent,
            text=label_text,
            width=8
        ).grid(
            row=row_idx,
            column=0,
            pady=5
        )

        slider = tk.Scale(
            parent,
            from_=-180,
            to=180,
            orient='horizontal',
            length=180,
            resolution=0.1,
            variable=var,
            showvalue=False
        )
        slider.grid(
            row=row_idx,
            column=1,
            padx=5
        )

        entry = tk.Spinbox(
            parent,
            from_=-180,
            to=180,
            increment=1.0,
            width=7,
            format='%.1f',
            textvariable=var
        )
        entry.grid(
            row=row_idx,
            column=2,
            padx=5
        )

    # # -------------------------------------------------------
    # # Manual control
    # # -------------------------------------------------------

    # def on_manual_value_changed(self, *args):
    #     self.right_planned_traj = None
    #     self.left_planned_traj = None
    #     self.check_ready_to_execute()

    # def check_ready_to_execute(self):
    #     if self.right_planned_traj is not None and self.left_planned_traj is not None:
    #         self.exec_btn.config(state='normal')
    #     else:
    #         self.exec_btn.config(state='disabled')

    # def get_manual_right_target(self):
    #     """
    #     GUI 입력값은 MoveIt/RViz 기준 degree 값 그대로 사용.
    #     실제 모터 방향 보정은 trajectory_bridge_node.cpp에서 처리.
    #     """
    #     return {
    #         f'joint{i + 1}': var.get()
    #         for i, var in enumerate(self.right_vars)
    #     }

    # def get_manual_left_target(self):
    #     """
    #     GUI 입력값은 MoveIt/RViz 기준 degree 값 그대로 사용.
    #     실제 모터 방향 보정은 trajectory_bridge_node.cpp에서 처리.
    #     """
    #     return {
    #         f'joint{i + 8}': var.get()
    #         for i, var in enumerate(self.left_vars)
    #     }

    # def get_manual_duration(self):
    #     try:
    #         duration = float(self.manual_duration_var.get())
    #     except Exception:
    #         duration = -1.0

    #     return duration

    # def on_plan_right(self):
    #     target_right = self.get_manual_right_target()
    #     duration = self.get_manual_duration()

    #     self.log_status('==== 오른팔 플래닝 생성 중 ====')

    #     self.right_planned_traj = self.node.plan_arm(
    #         'right_arm',
    #         target_right,
    #         desired_duration=duration
    #     )

    #     if self.right_planned_traj is not None:
    #         self.log_status('오른팔 플래닝 완료')
    #     else:
    #         messagebox.showerror(
    #             '오른팔 플래닝 실패',
    #             '오른팔 경로를 생성할 수 없습니다.'
    #         )

    #     self.check_ready_to_execute()

    # def on_plan_left(self):
    #     target_left = self.get_manual_left_target()
    #     duration = self.get_manual_duration()

    #     self.log_status('==== 왼팔 플래닝 생성 중 ====')

    #     self.left_planned_traj = self.node.plan_arm(
    #         'left_arm',
    #         target_left,
    #         desired_duration=duration
    #     )

    #     if self.left_planned_traj is not None:
    #         self.log_status('왼팔 플래닝 완료')
    #     else:
    #         messagebox.showerror(
    #             '왼팔 플래닝 실패',
    #             '왼팔 경로를 생성할 수 없습니다.'
    #         )

    #     self.check_ready_to_execute()

    # def on_execute_manual(self):
    #     if self.right_planned_traj is None or self.left_planned_traj is None:
    #         messagebox.showwarning(
    #             '실행 불가',
    #             '오른팔과 왼팔 미리보기를 먼저 생성하세요.'
    #         )
    #         return

    #     if not messagebox.askyesno(
    #         '최종 확인',
    #         'RViz에서 경로를 확인했습니까?\n실제 로봇을 구동합니다.'
    #     ):
    #         return

    #     self.disable_all_buttons()
    #     self.root.update()

    #     try:
    #         self.log_status('==== 수동 입력 목표 자세 실행 ====')

    #         success = self.node.execute_both_planned_trajectories(
    #             self.right_planned_traj,
    #             self.left_planned_traj
    #         )

    #         if success:
    #             self.log_status('수동 입력 목표 자세 실행 완료')

    #         # 실행 후에도 입력창 값은 유지.
    #         # planned trajectory만 비워서 이전 plan 재사용 방지.
    #         self.right_planned_traj = None
    #         self.left_planned_traj = None

    #     finally:
    #         self.reset_ui_buttons()

    # def on_clear_values(self):
    #     for var in self.right_vars + self.left_vars:
    #         var.set(0.0)

    #     self.right_planned_traj = None
    #     self.left_planned_traj = None

    #     self.check_ready_to_execute()

    #     self.log_status('입력값을 모두 0도로 초기화했습니다.')

    # -------------------------------------------------------
    # CSV motion
    # -------------------------------------------------------

    def load_default_motion_csv(self, show_message=False):
        path = self.motion_csv_path

        if not os.path.exists(path):
            self.motion_library = {}
            self.motion_list_label.config(
                text='로드된 모션: 없음 - motions.csv 파일이 없습니다.'
            )
            self.exec_motion_btn.config(state='disabled')

            if show_message:
                messagebox.showwarning(
                    'CSV 없음',
                    f'motions.csv 파일을 찾을 수 없습니다.\n\n{path}'
                )

            return

        try:
            self.motion_library = self.load_motion_csv(path)

            motion_names = sorted(self.motion_library.keys())

            if not motion_names:
                self.motion_list_label.config(
                    text='로드된 모션: 없음'
                )
                self.exec_motion_btn.config(state='disabled')

                if show_message:
                    messagebox.showwarning(
                        'CSV 로드 실패',
                        'motions.csv 안에 motion 데이터가 없습니다.'
                    )
                return

            self.motion_list_label.config(
                text='로드된 모션: ' + ', '.join(motion_names)
            )

            self.refresh_motion_buttons()

            # CSV를 다시 로드하면 기존 실행 순서는 비움.
            self.sequence_listbox.delete(0, tk.END)

            self.preview_sequence_index = 0
            self.update_preview_label()

            # 기본으로 motion0이 있으면 stack에 하나 넣어둠.
            if 'init' in self.motion_library:
                self.sequence_listbox.insert(tk.END, 'init')
                self.exec_motion_btn.config(state='normal')
            else:
                self.exec_motion_btn.config(state='disabled')

            self.log_status(f'motions.csv 로드 완료: {path}')

            if show_message:
                messagebox.showinfo(
                    'CSV 로드 완료',
                    f'로드된 모션:\n{", ".join(motion_names)}'
                )

        except Exception as e:
            self.motion_library = {}
            self.exec_motion_btn.config(state='disabled')
            self.motion_list_label.config(text='로드된 모션: CSV 로드 오류')

            messagebox.showerror(
                'CSV 로드 오류',
                str(e)
            )

    def load_motion_csv(self, path):
        motion_library = {}

        required_cols = [
            'motion',
            'step',
            'duration',
            'hold',
            'joint1',
            'joint2',
            'joint3',
            'joint4',
            'joint5',
            'joint6',
            'joint7',
            'joint8',
            'joint9',
            'joint10',
            'joint11',
            'joint12',
            'joint13',
            'joint14'
        ]

        with open(path, 'r', newline='', encoding='utf-8-sig') as f:
            reader = csv.DictReader(f)

            if reader.fieldnames is None:
                raise ValueError('CSV header가 없습니다.')

            missing = [
                col for col in required_cols
                if col not in reader.fieldnames
            ]

            if missing:
                raise ValueError(f'CSV에 필요한 column이 없습니다: {missing}')

            for row in reader:
                motion_name = row['motion'].strip()

                if motion_name == '':
                    continue

                step = int(row['step'])
                duration = float(row['duration'])
                hold = float(row['hold'])

                joints = {}

                for i in range(1, 15):
                    joint_name = f'joint{i}'
                    raw_value = row[joint_name].strip()

                    if raw_value == '':
                        raw_value = '0.0'

                    joints[joint_name] = float(raw_value)

                step_data = {
                    'step': step,
                    'duration': duration,
                    'hold': hold,
                    'joints': joints
                }

                if motion_name not in motion_library:
                    motion_library[motion_name] = []

                motion_library[motion_name].append(step_data)

        for motion_name in motion_library:
            motion_library[motion_name].sort(key=lambda x: x['step'])

        return motion_library

    def on_execute_motion_sequence(self):
        if not self.motion_library:
            messagebox.showwarning(
                '모션 없음',
                'motions.csv 파일을 먼저 로드하세요.'
            )
            return

        motion_sequence = self.get_motion_sequence_from_listbox()

        if not motion_sequence:
            messagebox.showwarning(
                '시퀀스 없음',
                '실행할 모션을 버튼으로 추가하세요.'
            )
            return

        unknown = [
            name for name in motion_sequence
            if name not in self.motion_library
        ]

        if unknown:
            messagebox.showerror(
                '알 수 없는 모션',
                f'motions.csv에 없는 모션 이름입니다:\n{unknown}'
            )
            return

        if not messagebox.askyesno(
            'CSV 모션 시퀀스 실행 확인',
            '다음 순서로 실행합니다:\n\n'
            + ' -> '.join(motion_sequence)
            + '\n\n실제 로봇을 구동할까요?'
        ):
            return

        self.disable_all_buttons()
        self.root.update()

        try:
            for motion_idx, motion_name in enumerate(motion_sequence, start=1):
                self.log_status(
                    f'==== Sequence {motion_idx}/{len(motion_sequence)}: {motion_name} 시작 ===='
                )

                steps = self.motion_library[motion_name]

                for step_data in steps:
                    step = step_data['step']
                    duration = step_data['duration']
                    hold = step_data['hold']
                    joints = step_data['joints']

                    self.log_status(
                        f'{motion_name} step {step} planning 중... '
                        f'duration={duration}, hold={hold}'
                    )

                    right_target = {
                        f'joint{i}': joints[f'joint{i}']
                        for i in range(1, 8)
                    }

                    left_target = {
                        f'joint{i}': joints[f'joint{i}']
                        for i in range(8, 15)
                    }

                    # duration = -1이면 MoveIt 기본 trajectory 시간 그대로 사용.
                    desired_duration = None if duration < 0 else duration

                    right_traj = self.node.plan_arm(
                        'right_arm',
                        right_target,
                        desired_duration=desired_duration
                    )

                    if right_traj is None:
                        messagebox.showerror(
                            'Planning 실패',
                            f'{motion_name} step {step} 오른팔 planning 실패'
                        )
                        return

                    left_traj = self.node.plan_arm(
                        'left_arm',
                        left_target,
                        desired_duration=desired_duration
                    )

                    if left_traj is None:
                        messagebox.showerror(
                            'Planning 실패',
                            f'{motion_name} step {step} 왼팔 planning 실패'
                        )
                        return

                    self.log_status(
                        f'{motion_name} step {step} 실행 중...'
                    )

                    success = self.node.execute_both_planned_trajectories(
                        right_traj,
                        left_traj
                    )

                    if not success:
                        messagebox.showerror(
                            '실행 실패',
                            f'{motion_name} step {step} 실행 실패'
                        )
                        return

                    self.log_status(
                        f'{motion_name} step {step} 실행 완료'
                    )

                    if hold > 0.0:
                        self.log_status(f'{hold}초 대기')
                        time.sleep(hold)

                self.log_status(
                    f'==== Sequence {motion_idx}/{len(motion_sequence)}: {motion_name} 종료 ===='
                )

            self.log_status('==== 전체 CSV 모션 시퀀스 완료 ====')

        finally:
            self.reset_ui_buttons()

    # -------------------------------------------------------
    # Button state / log
    # -------------------------------------------------------

    # -------------------------------------------------------
    # Button state / log
    # -------------------------------------------------------

    def disable_all_buttons(self):
        # 수동 제어 버튼 참조 주석 처리
        # self.plan_right_btn.config(state='disabled')
        # self.plan_left_btn.config(state='disabled')
        # self.exec_btn.config(state='disabled')
        # self.clear_btn.config(state='disabled')
        
        self.reload_csv_btn.config(state='disabled')
        self.exec_motion_btn.config(state='disabled')

        self.remove_selected_btn.config(state='disabled')
        self.move_up_btn.config(state='disabled')
        self.move_down_btn.config(state='disabled')
        self.clear_sequence_btn.config(state='disabled')

        self.prev_preview_btn.config(state='disabled')
        self.plan_selected_motion_btn.config(state='disabled')  
        self.next_preview_btn.config(state='disabled')

        for widget in self.motion_button_frame.winfo_children():
            if isinstance(widget, tk.Button):
                widget.config(state='disabled')

    def reset_ui_buttons(self):
        # 수동 제어 버튼 참조 주석 처리
        # self.plan_right_btn.config(state='normal')
        # self.plan_left_btn.config(state='normal')
        # self.clear_btn.config(state='normal')
        
        self.reload_csv_btn.config(state='normal')

        self.remove_selected_btn.config(state='normal')
        self.move_up_btn.config(state='normal')
        self.move_down_btn.config(state='normal')
        self.clear_sequence_btn.config(state='normal')

        self.prev_preview_btn.config(state='normal')
        self.plan_selected_motion_btn.config(state='normal')
        self.next_preview_btn.config(state='normal')
        
        for widget in self.motion_button_frame.winfo_children():
            if isinstance(widget, tk.Button):
                widget.config(state='normal')

        if self.motion_library and self.sequence_listbox.size() > 0:
            self.exec_motion_btn.config(state='normal')
        else:
            self.exec_motion_btn.config(state='disabled')

        # 이 메서드 호출도 수동 제어와 관련이 있다면 주석 처리하거나 해당 메서드 내의 로직을 확인해야 합니다.
        # self.check_ready_to_execute()

    def log_status(self, text):
        self.node.get_logger().info(text)

        self.status_text.insert('end', text + '\n')
        self.status_text.see('end')
        self.root.update_idletasks()


def main(args=None):
    rclpy.init(args=args)

    node = MoveItPlanThenBothExecute()
    gui = DualArmControlGUI(node)

    try:
        gui.root.mainloop()

    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()