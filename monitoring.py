import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
import math   # 파일 맨 위에 추가

class Joint1Monitor(Node):
    def __init__(self):
        super().__init__('joint1_monitor')
        self.create_subscription(
            JointState, '/joint_states', self.callback, 10)

    def callback(self, msg):
        try:
            idx = msg.name.index('joint1')
            rad = msg.position[idx]
            deg = math.degrees(rad)          # 변환
            self.get_logger().info(
                f'joint1: {rad:.4f} rad ({deg:.2f} deg)')
        except ValueError:
            self.get_logger().warn('joint1 not found in JointState')

def main():
    rclpy.init()
    rclpy.spin(Joint1Monitor())
    rclpy.shutdown()

if __name__ == '__main__':
    main()