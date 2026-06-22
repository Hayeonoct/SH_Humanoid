#!/usr/bin/env python3

import rclpy

from rclpy.node import Node

from trajectory_msgs.msg import (
    JointTrajectory,
    JointTrajectoryPoint
)

from builtin_interfaces.msg import Duration


class ElbowTest(Node):

    def __init__(self):

        super().__init__("elbow_test")

        self.pub = self.create_publisher(
            JointTrajectory,
            "/left_arm_controller/joint_trajectory",
            10
        )

        self.timer = self.create_timer(
            2.0,
            self.send_cmd
        )

        self.state = False

    def send_cmd(self):

        msg = JointTrajectory()

        msg.joint_names = [
            "joint8",
            "joint9",
            "joint10",
            "joint11",
            "joint12",
            "joint13",
            "joint14"
        ]

        pt = JointTrajectoryPoint()

        if self.state:
            elbow = 0.2
        else:
            elbow = 1.5

        pt.positions = [
            0.0,
            0.0,
            0.0,
            elbow,
            0.0,
            0.0,
            0.0
        ]

        pt.time_from_start = Duration(
            sec=1,
            nanosec=0
        )

        msg.points.append(pt)

        self.pub.publish(msg)

        self.get_logger().info(
            f"joint11 -> {elbow}"
        )

        self.state = not self.state


def main():

    rclpy.init()

    node = ElbowTest()

    rclpy.spin(node)

    node.destroy_node()

    rclpy.shutdown()


if __name__ == "__main__":
    main()