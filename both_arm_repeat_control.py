import math
import tkinter as tk
from tkinter import messagebox

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient

from moveit_msgs.action import MoveGroup
from moveit_msgs.msg import Constraints, JointConstraint
from moveit_msgs.msg import MoveItErrorCodes
from control_msgs.action import FollowJointTrajectory

from sensor_msgs.msg import JointState


class MoveItPlanThenBothExecute(Node):
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

    def convert_user_deg_to_moveit_deg(self, target_joints_degrees):
        return {
            joint_name: value * self.USER_TO_MOVEIT_SIGN.get(joint_name, 1.0)
            for joint_name, value in target_joints_degrees.items()
        }

    def __init__(self):
        super().__init__('moveit_manual_control_node')

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

    def plan_arm(self, group_name, target_joints_degrees, desired_duration=None, start_joints_degrees=None):
        """
        group_name:
          - right_arm
          - left_arm

        target_joints_degrees:
          - degree 단위
          - MoveIt/RViz 기준 각도
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


class ManualArmControlGUI:
    def __init__(self, ros_node):
        self.node = ros_node

        self.root = tk.Tk()
        self.root.title('Dual Arm Manual Joint Control')
        self.root.geometry('820x680')

        self.right_vars = []
        self.left_vars = []

        self.right_planned_traj = None
        self.left_planned_traj = None

        # --- 추가할 부분: 이전에 성공적으로 실행한 목표값을 기억할 변수 ---
        self.last_executed_target_right = None
        self.last_executed_target_left = None
        # --------------------------------------------------------

        self.create_gui()

    def create_gui(self):
        self.main_frame = tk.LabelFrame(
            self.root,
            text='Manual Joint Control',
            padx=10,
            pady=10
        )
        self.main_frame.pack(
            pady=10,
            padx=20,
            fill='both',
            expand=True
        )

        self.arm_frame = tk.Frame(self.main_frame)
        self.arm_frame.pack(fill='x')

        self.right_frame = tk.LabelFrame(
            self.arm_frame,
            text='오른팔 Right Arm: Joint 1~7',
            padx=10,
            pady=10
        )
        self.right_frame.pack(
            side='left',
            padx=20,
            fill='y',
            expand=True
        )

        self.left_frame = tk.LabelFrame(
            self.arm_frame,
            text='왼팔 Left Arm: Joint 8~14',
            padx=10,
            pady=10
        )
        self.left_frame.pack(
            side='right',
            padx=20,
            fill='y',
            expand=True
        )

        for i in range(7):
            var = tk.DoubleVar(value=0.0)
            var.trace_add('write', self.on_manual_value_changed)
            self.right_vars.append(var)

            self.create_joint_row(
                self.right_frame,
                f'Joint {i + 1}',
                var,
                i
            )

        for i in range(7):
            var = tk.DoubleVar(value=0.0)
            var.trace_add('write', self.on_manual_value_changed)
            self.left_vars.append(var)

            self.create_joint_row(
                self.left_frame,
                f'Joint {i + 8}',
                var,
                i
            )

        self.option_frame = tk.Frame(self.main_frame)
        self.option_frame.pack(
            pady=10,
            fill='x',
            padx=50
        )

        tk.Label(
            self.option_frame,
            text='duration [sec], -1 = MoveIt 기본 시간'
        ).pack(side='left', padx=5)

        self.duration_var = tk.DoubleVar(value=-1.0)
        self.duration_var.trace_add('write', self.on_manual_value_changed)

        self.duration_spin = tk.Spinbox(
            self.option_frame,
            from_=-1.0,
            to=20.0,
            increment=0.1,
            width=8,
            format='%.1f',
            textvariable=self.duration_var
        )
        self.duration_spin.pack(side='left', padx=5)

        tk.Label(
            self.option_frame,
            text='반복 횟수'
        ).pack(side='left', padx=(20, 5))

        self.repeat_count_var = tk.IntVar(value=1)

        self.repeat_spin = tk.Spinbox(
            self.option_frame,
            from_=1,
            to=1000,
            increment=1,
            width=6,
            textvariable=self.repeat_count_var
        )
        self.repeat_spin.pack(side='left', padx=5)

        self.btn_frame1 = tk.Frame(self.main_frame)
        self.btn_frame1.pack(
            pady=10,
            fill='x',
            padx=50
        )

        self.plan_right_btn = tk.Button(
            self.btn_frame1,
            text='1. 오른팔 미리보기',
            command=self.on_plan_right,
            bg='lightblue',
            font=('Arial', 11, 'bold'),
            height=2
        )
        self.plan_right_btn.pack(
            side='left',
            fill='x',
            expand=True,
            padx=5
        )

        self.plan_left_btn = tk.Button(
            self.btn_frame1,
            text='2. 왼팔 미리보기',
            command=self.on_plan_left,
            bg='lightpink',
            font=('Arial', 11, 'bold'),
            height=2
        )
        self.plan_left_btn.pack(
            side='right',
            fill='x',
            expand=True,
            padx=5
        )

        self.btn_frame2 = tk.Frame(self.main_frame)
        self.btn_frame2.pack(
            pady=5,
            fill='x',
            padx=50
        )

        self.exec_btn = tk.Button(
            self.btn_frame2,
            text='3. 양팔 실행',
            command=self.on_execute_manual,
            bg='lightgreen',
            font=('Arial', 12, 'bold'),
            state='disabled',
            height=2
        )
        self.exec_btn.pack(
            side='left',
            fill='x',
            expand=True,
            padx=5
        )

        self.clear_btn = tk.Button(
            self.btn_frame2,
            text='Clear 입력값 0도',
            command=self.on_clear_values,
            bg='lightgray',
            font=('Arial', 12, 'bold'),
            height=2
        )
        self.clear_btn.pack(
            side='right',
            fill='x',
            expand=True,
            padx=5
        )

        self.btn_frame3 = tk.Frame(self.main_frame)
        self.btn_frame3.pack(
            pady=5,
            fill='x',
            padx=50
        )

        self.repeat_btn = tk.Button(
            self.btn_frame3,
            text='4. 반복 실행 (목표 → 0도 반복)',
            command=self.on_repeat_execute,
            bg='#ffd27f',
            font=('Arial', 12, 'bold'),
            height=2
        )
        self.repeat_btn.pack(
            fill='x',
            expand=True,
            padx=5
        )

        self.status_text = tk.Text(
            self.main_frame,
            height=8,
            wrap='word'
        )
        self.status_text.pack(
            fill='both',
            expand=True,
            pady=10,
            padx=20
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

    def on_manual_value_changed(self, *args):
        self.right_planned_traj = None
        self.left_planned_traj = None
        self.check_ready_to_execute()

    def check_ready_to_execute(self):
        if self.right_planned_traj is not None and self.left_planned_traj is not None:
            self.exec_btn.config(state='normal')
        else:
            self.exec_btn.config(state='disabled')

    def get_duration(self):
        try:
            return float(self.duration_var.get())
        except Exception:
            return -1.0

    def get_repeat_count(self):
        try:
            n = int(self.repeat_count_var.get())
            return max(1, n)
        except Exception:
            return 1

    def get_right_target(self):
        return {
            f'joint{i + 1}': var.get()
            for i, var in enumerate(self.right_vars)
        }

    def get_left_target(self):
        return {
            f'joint{i + 8}': var.get()
            for i, var in enumerate(self.left_vars)
        }

    def get_zero_right(self):
        return {f'joint{i + 1}': 0.0 for i in range(7)}

    def get_zero_left(self):
        return {f'joint{i + 8}': 0.0 for i in range(7)}

    def on_plan_right(self):
        target_right = self.get_right_target()
        duration = self.get_duration()

        self.log_status('==== 오른팔 플래닝 생성 중 ====')

        # --- 수정할 부분: start_joints_degrees 에 이전 목표값 전달 ---
        self.right_planned_traj = self.node.plan_arm(
            'right_arm',
            target_right,
            desired_duration=duration,
            start_joints_degrees=self.last_executed_target_right
        )
        # ----------------------------------------------------

        if self.right_planned_traj is not None:
            self.log_status('오른팔 플래닝 완료')
        else:
            messagebox.showerror(
                '오른팔 플래닝 실패',
                '오른팔 경로를 생성할 수 없습니다.'
            )

        self.check_ready_to_execute()

    def on_plan_left(self):
        target_left = self.get_left_target()
        duration = self.get_duration()

        self.log_status('==== 왼팔 플래닝 생성 중 ====')

        # --- 수정할 부분: start_joints_degrees 에 이전 목표값 전달 ---
        self.left_planned_traj = self.node.plan_arm(
            'left_arm',
            target_left,
            desired_duration=duration,
            start_joints_degrees=self.last_executed_target_left
        )
        # ----------------------------------------------------

        if self.left_planned_traj is not None:
            self.log_status('왼팔 플래닝 완료')
        else:
            messagebox.showerror(
                '왼팔 플래닝 실패',
                '왼팔 경로를 생성할 수 없습니다.'
            )

        self.check_ready_to_execute()

    def on_execute_manual(self):
        if self.right_planned_traj is None or self.left_planned_traj is None:
            messagebox.showwarning(
                '실행 불가',
                '오른팔과 왼팔 미리보기를 먼저 생성하세요.'
            )
            return

        if not messagebox.askyesno(
            '최종 확인',
            'RViz에서 경로를 확인했습니까?\n실제 로봇을 구동합니다.'
        ):
            return

        self.disable_buttons()
        self.root.update()

        try:
            self.log_status('==== 수동 입력 목표 자세 실행 ====')

            success = self.node.execute_both_planned_trajectories(
                self.right_planned_traj,
                self.left_planned_traj
            )

            if success:
                self.log_status('수동 입력 목표 자세 실행 완료')

                # --- 추가할 부분: 성공적으로 이동을 마친 목표값을 다음번 출발점으로 저장 ---
                self.last_executed_target_right = self.get_right_target()
                self.last_executed_target_left = self.get_left_target()
                # -----------------------------------------------------------------

            # 실행 후에도 입력창 값은 유지.
            self.right_planned_traj = None
            self.left_planned_traj = None

        finally:
            self.enable_buttons()

    def on_repeat_execute(self):
        target_right = self.get_right_target()
        target_left = self.get_left_target()
        zero_right = self.get_zero_right()
        zero_left = self.get_zero_left()

        duration = self.get_duration()
        repeat_count = self.get_repeat_count()

        self.log_status(f'==== 반복 실행 준비 (총 {repeat_count}회) ====')
        self.log_status('목표 경로 미리보기 생성 중...')

        # 최초 1회: 이전에 마지막으로 실행했던 위치를 출발점으로 삼아 플래닝
        right_target_traj = self.node.plan_arm(
            'right_arm', target_right, desired_duration=duration,
            start_joints_degrees=self.last_executed_target_right
        )
        left_target_traj = self.node.plan_arm(
            'left_arm', target_left, desired_duration=duration,
            start_joints_degrees=self.last_executed_target_left
        )

        if right_target_traj is None or left_target_traj is None:
            messagebox.showerror('반복 실행 실패', '목표 경로를 생성할 수 없습니다.')
            return

        if not messagebox.askyesno(
            '경로 확인 (최초 1회)',
            'RViz에서 목표 경로를 확인했습니까?\n'
            f'확인을 누르면 "목표 → 0도" 동작을 {repeat_count}회 반복 실행합니다.'
        ):
            self.log_status('반복 실행이 취소되었습니다.')
            return

        self.disable_buttons()
        self.root.update()

        try:
            for i in range(repeat_count):
                # ----- 목표 자세로 이동 -----
                self.log_status(f'---- 반복 {i + 1}/{repeat_count}: 목표 자세 이동 ----')

                if i == 0:
                    rt, lt = right_target_traj, left_target_traj
                else:
                    # 2회차부터는 이전 단계의 끝 지점인 '0도(zero)'를 출발점으로 플래닝
                    rt = self.node.plan_arm(
                        'right_arm', target_right, desired_duration=duration, start_joints_degrees=zero_right
                    )
                    lt = self.node.plan_arm(
                        'left_arm', target_left, desired_duration=duration, start_joints_degrees=zero_left
                    )
                    if rt is None or lt is None:
                        self.log_status('목표 경로 재생성 실패, 반복 중단')
                        break

                if not self.node.execute_both_planned_trajectories(rt, lt):
                    self.log_status('목표 자세 실행 실패, 반복 중단')
                    break

                self.root.update()

                # ----- 전체 joint 0도로 복귀 -----
                self.log_status(f'---- 반복 {i + 1}/{repeat_count}: 0도 복귀 ----')

                # 0도로 복귀할 때는 이전 단계의 끝 지점인 '목표(target)'를 출발점으로 플래닝
                rz = self.node.plan_arm(
                    'right_arm', zero_right, desired_duration=duration, start_joints_degrees=target_right
                )
                lz = self.node.plan_arm(
                    'left_arm', zero_left, desired_duration=duration, start_joints_degrees=target_left
                )
                if rz is None or lz is None:
                    self.log_status('0도 경로 생성 실패, 반복 중단')
                    break

                if not self.node.execute_both_planned_trajectories(rz, lz):
                    self.log_status('0도 복귀 실행 실패, 반복 중단')
                    break

                self.root.update()

            self.log_status('==== 반복 실행 종료 ====')
            
            self.last_executed_target_right = zero_right
            self.last_executed_target_left = zero_left

        finally:
            self.right_planned_traj = None
            self.left_planned_traj = None
            self.enable_buttons()

    def on_clear_values(self):
        for var in self.right_vars + self.left_vars:
            var.set(0.0)

        self.right_planned_traj = None
        self.left_planned_traj = None

        self.check_ready_to_execute()

        self.log_status('입력값을 모두 0도로 초기화했습니다.')

    def disable_buttons(self):
        self.plan_right_btn.config(state='disabled')
        self.plan_left_btn.config(state='disabled')
        self.exec_btn.config(state='disabled')
        self.clear_btn.config(state='disabled')
        self.repeat_btn.config(state='disabled')

    def enable_buttons(self):
        self.plan_right_btn.config(state='normal')
        self.plan_left_btn.config(state='normal')
        self.clear_btn.config(state='normal')
        self.repeat_btn.config(state='normal')
        self.check_ready_to_execute()

    def log_status(self, text):
        self.node.get_logger().info(text)
        self.status_text.insert('end', text + '\n')
        self.status_text.see('end')
        self.root.update_idletasks()


def main(args=None):
    rclpy.init(args=args)

    node = MoveItPlanThenBothExecute()
    gui = ManualArmControlGUI(node)

    try:
        gui.root.mainloop()

    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()