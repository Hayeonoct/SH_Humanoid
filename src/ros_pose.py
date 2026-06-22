import cv2
import rclpy

from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge

import mediapipe as mp

mp_pose = mp.solutions.pose
mp_draw = mp.solutions.drawing_utils


class PoseTracker(Node):

    def __init__(self):
        super().__init__("pose_tracker")

        self.bridge = CvBridge()

        self.subscription = self.create_subscription(
            Image,
            "/camera/camera/color/image_raw",
            self.image_callback,
            10,
        )

        self.pose = mp_pose.Pose(
            static_image_mode=False,
            model_complexity=1,
            min_detection_confidence=0.5,
            min_tracking_confidence=0.5,
        )

    def image_callback(self, msg):

        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

        rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

        result = self.pose.process(rgb)

        if result.pose_landmarks:

            mp_draw.draw_landmarks(
                frame,
                result.pose_landmarks,
                mp_pose.POSE_CONNECTIONS,
            )

            lm = result.pose_landmarks.landmark

            ls = lm[11]
            le = lm[13]
            lw = lm[15]

            cv2.putText(
                frame,
                f"LS ({ls.x:.2f},{ls.y:.2f})",
                (10, 30),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.7,
                (0, 255, 0),
                2,
            )

            cv2.putText(
                frame,
                f"LE ({le.x:.2f},{le.y:.2f})",
                (10, 60),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.7,
                (0, 255, 0),
                2,
            )

        cv2.imshow("Pose Tracking", frame)
        cv2.waitKey(1)


def main():

    rclpy.init()

    node = PoseTracker()

    rclpy.spin(node)

    node.destroy_node()

    rclpy.shutdown()


if __name__ == "__main__":
    main()