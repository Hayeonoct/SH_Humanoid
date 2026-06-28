import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from control_msgs.action import FollowJointTrajectory
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from builtin_interfaces.msg import Duration
import threading


class BothArmsCommander(Node):

    def __init__(self):
        super().__init__('both_arms_commander')

        self.right_client = ActionClient(
            self,
            FollowJointTrajectory,
            '/right_arm_controller/follow_joint_trajectory')

        self.left_client = ActionClient(
            self,
            FollowJointTrajectory,
            '/left_arm_controller/follow_joint_trajectory')

		def send_both(self, right_goal, left_goal):
        """양팔 동시 전송 (실행 완료까지 대기하도록 수정)"""
        right_done = threading.Event()
        left_done  = threading.Event()

        # 목표 수락 후 결과(Result)를 기다리는 콜백
        def right_result_cb(future):
            right_done.set()

        def right_goal_cb(future):
            handle = future.result()
            if not handle.accepted:
                right_done.set() # 거절당하면 종료
                return
            # 수락되면 결과가 나올 때까지 대기
            handle.get_result_async().add_done_callback(right_result_cb)

        def left_result_cb(future):
            left_done.set()

        def left_goal_cb(future):
            handle = future.result()
            if not handle.accepted:
                left_done.set()
                return
            handle.get_result_async().add_done_callback(left_result_cb)

        self.right_client.wait_for_server()
        self.left_client.wait_for_server()

        self.right_client.send_goal_async(right_goal).add_done_callback(right_goal_cb)
        self.left_client.send_goal_async(left_goal).add_done_callback(left_goal_cb)

        # 두 팔이 2초 동안 움직임을 완전히 끝낼 때까지 여기서 대기합니다.
        right_done.wait()
        left_done.wait()

        self.get_logger().info('Both arms trajectory execution finished')


def make_goal(joint_names, positions, duration_sec):
    """goal 생성 헬퍼"""
    goal = FollowJointTrajectory.Goal()
    goal.trajectory.joint_names = joint_names

    point = JointTrajectoryPoint()
    point.positions = positions
    point.velocities = [0.0] * len(positions)
    point.time_from_start = Duration(
        sec=int(duration_sec),
        nanosec=int((duration_sec % 1) * 1e9))

    goal.trajectory.points = [point]
    return goal


def main():
    rclpy.init()
    node = BothArmsCommander()

    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(node)
    thread = threading.Thread(target=executor.spin, daemon=True)
    thread.start()

    # -------------------------------------------------------
    # 여기에 원하는 포지션 입력
    # joint1~7: 오른팔, joint8~14: 왼팔
    # -------------------------------------------------------

    right_goal = make_goal(
        joint_names=['joint1', 'joint2', 'joint3',
                     'joint4', 'joint5', 'joint6', 'joint7'],
        positions=[0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
        duration_sec=2.0)

    left_goal = make_goal(
        joint_names=['joint8', 'joint9', 'joint10',
                     'joint11', 'joint12', 'joint13', 'joint14'],
        positions=[0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
        duration_sec=2.0)

    node.send_both(right_goal, left_goal)

    rclpy.shutdown()


if __name__ == '__main__':
    main()