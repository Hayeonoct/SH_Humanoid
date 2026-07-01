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

# --- 추가된 부분: JointState 임포트 ---
from sensor_msgs.msg import JointState


class MoveItPlanThenBothExecute(Node):
    # 부호 매핑 딕셔너리 추가
    USER_TO_MOVEIT_SIGN = {
        'joint1':  1.0,
        'joint2': -1.0,
        'joint3': -1.0,
        'joint4': -1.0,
        'joint5':  1.0,
        'joint6':  1.0,
        'joint7':  1.0,

        'joint8':  -1.0,
        'joint9':   1.0,
        'joint10': -1.0,
        'joint11':  1.0,
        'joint12':  1.0,
        'joint13': -1.0,
        'joint14': -1.0,
    }

    # 부호 변환 함수 추가
    def convert_user_deg_to_moveit_deg(self, target_joints_degrees):
        return {
            joint_name: value * self.USER_TO_MOVEIT_SIGN.get(joint_name, 1.0)
            for joint_name, value in target_joints_degrees.items()
        }

    def __init__(self):
        super().__init__('moveit_motion_csv_node')

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

    def apply_soft_landing(self, joint_trajectory, threshold_deg=10.0, max_factor=5.0):
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
        desired_duration:
          - None 또는 -1 이하: MoveIt 기본 trajectory 시간 사용
          - 양수: trajectory 전체 시간을 해당 초로 스케일링
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

    # --- 수정된 부분: start_joints_degrees 매개변수 추가 ---
    def plan_arm(self, group_name, target_joints_degrees, desired_duration=None, start_joints_degrees=None):
        self.get_logger().info(
            f'MoveGroup action server 대기 중... group={group_name}'
        )
        self.move_action_client.wait_for_server()

        goal_msg = MoveGroup.Goal()
        goal_msg.request.group_name = group_name
        goal_msg.request.allowed_planning_time = 5.0
        goal_msg.planning_options.plan_only = True

        # 현재 /joint_states 기반 시작 상태 사용 여부 (이전 값 덮어쓰기를 위해 False로 변경)
        goal_msg.request.start_state.is_diff = False

        # --- 추가된 부분: start_state를 이전 goal로 덮어씌우기 ---
        if start_joints_degrees is not None:
            start_joints_moveit = self.convert_user_deg_to_moveit_deg(start_joints_degrees)
            js = JointState()
            for j_name, j_pos_deg in start_joints_moveit.items():
                js.name.append(j_name)
                js.position.append(math.radians(j_pos_deg))
            goal_msg.request.start_state.joint_state = js
        # ----------------------------------------------------

        # 부호 매핑 적용
        target_joints_degrees = self.convert_user_deg_to_moveit_deg(
            target_joints_degrees
        )

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
            threshold_deg=10.0,
            max_factor=5.0
        )

        trajectory = self.scale_trajectory_duration(
            trajectory,
            desired_duration
        )

        self.get_logger().info(f'{group_name} planning 성공')

        return trajectory

    # -------------------------------------------------------
    # Execute
    # -------------------------------------------------------

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


class MotionCSVControlGUI:
    def __init__(self, ros_node):
        self.node = ros_node

        self.script_dir = os.path.dirname(os.path.abspath(__file__))
        self.motion_csv_path = os.path.join(self.script_dir, 'motions.csv')

        self.motion_library = {}
        self.preview_sequence_index = 0

        # --- 추가된 부분: 이전에 실행 성공한 목표값을 기억할 변수 ---
        self.last_executed_target_right = None
        self.last_executed_target_left = None
        # ------------------------------------------------------

        self.root = tk.Tk()
        self.root.title('Dual Arm CSV Motion Control')
        self.root.geometry('860x760')

        self.create_gui()
        self.load_default_motion_csv(show_message=False)

    # -------------------------------------------------------
    # GUI layout
    # -------------------------------------------------------

    def create_gui(self):
        self.main_frame = tk.LabelFrame(
            self.root,
            text='CSV Motion Control',
            padx=10,
            pady=10
        )
        self.main_frame.pack(
            pady=10,
            padx=20,
            fill='both',
            expand=True
        )

        self.csv_path_label = tk.Label(
            self.main_frame,
            text=f'CSV 파일: {self.motion_csv_path}',
            anchor='w',
            justify='left'
        )
        self.csv_path_label.pack(fill='x', pady=3)

        self.reload_csv_btn = tk.Button(
            self.main_frame,
            text='motions.csv 다시 불러오기',
            command=lambda: self.load_default_motion_csv(show_message=True),
            bg='khaki',
            font=('Arial', 11, 'bold'),
            height=2
        )
        self.reload_csv_btn.pack(fill='x', pady=5)

        self.motion_list_label = tk.Label(
            self.main_frame,
            text='로드된 모션: 없음',
            anchor='w',
            justify='left'
        )
        self.motion_list_label.pack(fill='x', pady=3)

        self.motion_button_frame = tk.LabelFrame(
            self.main_frame,
            text='로드된 모션 버튼'
        )
        self.motion_button_frame.pack(fill='x', pady=5)

        self.sequence_frame = tk.LabelFrame(
            self.main_frame,
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

        self.sequence_control_frame = tk.Frame(self.main_frame)
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

        self.preview_control_frame = tk.Frame(self.main_frame)
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
            self.main_frame,
            text='Preview 대상: 없음',
            anchor='w',
            justify='left'
        )
        self.preview_label.pack(fill='x', pady=3)

        self.exec_motion_btn = tk.Button(
            self.main_frame,
            text='CSV 모션 시퀀스 실행',
            command=self.on_execute_motion_sequence,
            bg='orange',
            font=('Arial', 12, 'bold'),
            height=2,
            state='disabled'
        )
        self.exec_motion_btn.pack(fill='x', pady=8)

        self.status_text = tk.Text(
            self.main_frame,
            height=10,
            wrap='word'
        )
        self.status_text.pack(
            fill='both',
            expand=True,
            pady=5
        )

    # -------------------------------------------------------
    # CSV load
    # -------------------------------------------------------

    def load_default_motion_csv(self, show_message=False):
        path = self.motion_csv_path

        if not os.path.exists(path):
            self.motion_library = {}
            self.motion_list_label.config(
                text='로드된 모션: 없음 - motions.csv 파일이 없습니다.'
            )
            self.exec_motion_btn.config(state='disabled')
            self.refresh_motion_buttons()
            self.update_preview_label()

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
                self.refresh_motion_buttons()
                self.update_preview_label()

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

            self.sequence_listbox.delete(0, tk.END)
            self.preview_sequence_index = 0

            # 기본 자세 모션이 있으면 자동으로 stack에 하나 넣음
            if 'motion0' in self.motion_library:
                self.sequence_listbox.insert(tk.END, 'motion0')
                self.select_sequence_index(0)
                self.exec_motion_btn.config(state='normal')

            elif 'init' in self.motion_library:
                self.sequence_listbox.insert(tk.END, 'init')
                self.select_sequence_index(0)
                self.exec_motion_btn.config(state='normal')

            else:
                self.exec_motion_btn.config(state='disabled')
                self.update_preview_label()

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
            self.refresh_motion_buttons()
            self.update_preview_label()

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

    # -------------------------------------------------------
    # Motion button / stack
    # -------------------------------------------------------

    def refresh_motion_buttons(self):
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
                width=14,
                bg='white',
                font=('Arial', 10, 'bold')
            )
            btn.pack(
                side='left',
                padx=4,
                pady=4
            )

    def on_add_motion_to_sequence(self, motion_name):
        self.sequence_listbox.insert(tk.END, motion_name)
        self.exec_motion_btn.config(state='normal')

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

        self.preview_sequence_index = idx - 1
        self.update_preview_label()

        self.log_status(f'순서 위로 이동: {motion_name}')

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

        self.preview_sequence_index = idx + 1
        self.update_preview_label()

        self.log_status(f'순서 아래로 이동: {motion_name}')

    def get_motion_sequence_from_listbox(self):
        return [
            self.sequence_listbox.get(i)
            for i in range(self.sequence_listbox.size())
        ]

    # -------------------------------------------------------
    # Preview
    # -------------------------------------------------------

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

    def on_plan_selected_motion(self):
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

            # --- 수정된 부분: 미리보기 시에도 내부에서만 연속 궤적을 잇기 위해 로컬 복사본 사용 ---
            current_start_right = self.last_executed_target_right
            current_start_left = self.last_executed_target_left
            # ------------------------------------------------------------------

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

                # --- 수정된 부분: 이전 step의 위치를 현재 step의 시작점으로 지정 ---
                right_traj = self.node.plan_arm(
                    'right_arm',
                    right_target,
                    desired_duration=desired_duration,
                    start_joints_degrees=current_start_right
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
                    desired_duration=desired_duration,
                    start_joints_degrees=current_start_left
                )
                if left_traj is None:
                    messagebox.showerror(
                        'Planning 실패',
                        f'{motion_name} step {step} 왼팔 planning 실패'
                    )
                    return

                # 다음 스텝을 위해 목표 지점을 새 시작점으로 갱신
                current_start_right = right_target
                current_start_left = left_target
                # --------------------------------------------------------

            self.log_status(
                f'==== 선택 모션 Planning 완료: {motion_name} ===='
            )

        finally:
            self.reset_ui_buttons()

    # -------------------------------------------------------
    # Execute sequence
    # -------------------------------------------------------

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
                    f'==== Sequence {motion_idx}/{len(motion_sequence)}: '
                    f'{motion_name} 시작 ===='
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

                    desired_duration = None if duration < 0 else duration

                    # --- 수정된 부분: 이전에 성공적으로 도착한 위치를 출발 위치로 지정 ---
                    right_traj = self.node.plan_arm(
                        'right_arm',
                        right_target,
                        desired_duration=desired_duration,
                        start_joints_degrees=self.last_executed_target_right
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
                        desired_duration=desired_duration,
                        start_joints_degrees=self.last_executed_target_left
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

                    # 실행이 성공하면, 다음 step 또는 모션의 출발점을 위해 현재 목표값을 저장
                    self.last_executed_target_right = right_target
                    self.last_executed_target_left = left_target
                    # -------------------------------------------------------------

                    self.log_status(
                        f'{motion_name} step {step} 실행 완료'
                    )

                    if hold > 0.0:
                        self.log_status(f'{hold}초 대기')
                        time.sleep(hold)

                self.log_status(
                    f'==== Sequence {motion_idx}/{len(motion_sequence)}: '
                    f'{motion_name} 종료 ===='
                )

            self.log_status('==== 전체 CSV 모션 시퀀스 완료 ====')

        finally:
            self.reset_ui_buttons()

    # -------------------------------------------------------
    # Button state / log
    # -------------------------------------------------------

    def disable_all_buttons(self):
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

        self.update_preview_label()

    def log_status(self, text):
        self.node.get_logger().info(text)

        self.status_text.insert('end', text + '\n')
        self.status_text.see('end')
        self.root.update_idletasks()


def main(args=None):
    rclpy.init(args=args)

    node = MoveItPlanThenBothExecute()
    gui = MotionCSVControlGUI(node)

    try:
        gui.root.mainloop()

    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()