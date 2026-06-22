# --------------------------------------
# Library
# --------------------------------------
# OpenCV : 영상 출력
# NumPy : 벡터 계산
# MediaPipe : 사람 관절 검출
# RealSense : 카메라 입력
import cv2
import numpy as np
import mediapipe as mp
import pyrealsense2 as rs

# --------------------------------------
# ROS2
# MoveIt / ros2_control 로 관절 명령 전송
#ros2 topic publish
import rclpy
from rclpy.node import Node
from trajectory_msgs.msg import (
    JointTrajectory,
    JointTrajectoryPoint
)
from builtin_interfaces.msg import Duration

# --------------------------------------
# Low-pass filter parameter
# alpha가 작을수록 부드럽지만 느려짐
# alpha가 클수록 빠르지만 노이즈 증가
filtered_joint4 = 0.0
filtered_joint11 = 0.0

alpha = 0.15

# --------------------------------------
# MediaPipe Pose
# 사람의 상체 관절(어깨, 팔꿈치, 손목 등)을 검출
# MediaPipe
mp_pose = mp.solutions.pose
mp_draw = mp.solutions.drawing_utils

# RealSense
pipeline = rs.pipeline()
config = rs.config()
config.enable_stream(
    rs.stream.color,
    640,
    480,
    rs.format.bgr8,
    30
)

# --------------------------------------
# Angle Calculation
# --------------------------------------
# 세 점(A-B-C)으로 이루어진 관절 각도 계산
#
# A : Shoulder
# B : Elbow
# C : Wrist
#
# 반환값 : degree
# --------------------------------------
def calc_angle(a, b, c):

    a = np.array(a)
    b = np.array(b)
    c = np.array(c)

    ba = a - b
    bc = c - b

    cosine = np.dot(ba, bc) / (
        np.linalg.norm(ba) * np.linalg.norm(bc)
    )

    cosine = np.clip(cosine, -1.0, 1.0)
    angle = np.degrees(np.arccos(cosine))
    return angle


# --------------------------------------
# ROS2 Publisher
# --------------------------------------
rclpy.init()
node = Node("human_mocap")
left_pub = node.create_publisher(
    JointTrajectory,
    "/left_arm_controller/joint_trajectory",
    10
)

pipeline.start(config)

pose = mp_pose.Pose(
    static_image_mode=False,
    model_complexity=1,
    min_detection_confidence=0.5,
    min_tracking_confidence=0.5
)
# --------------------------------------
# Main Loop
# --------------------------------------
# 1. 카메라 이미지 획득
# 2. MediaPipe Pose 추론
# 3. 팔꿈치 각도 계산
# 4. 로봇 관절각으로 변환
# 5. Low-pass filtering
# 6. ROS2 trajectory publish
# 7. 화면 출력
# --------------------------------------

try:
    while True:
        frames = pipeline.wait_for_frames()
        color_frame = frames.get_color_frame()

        if not color_frame:
            continue

        frame = np.asanyarray(color_frame.get_data())
        rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        result = pose.process(rgb)

        if result.pose_landmarks:
            mp_draw.draw_landmarks(
                frame,
                result.pose_landmarks,
                mp_pose.POSE_CONNECTIONS
            )
            lm = result.pose_world_landmarks.landmark

            # right shoulder, elbow, wrist
            r_shoulder = lm[12]
            r_elbow    = lm[14]
            r_wrist    = lm[16]

            # left shoulder, elbow, wrist
            l_shoulder = lm[11]
            l_elbow    = lm[13]
            l_wrist    = lm[15]
            
            right_elbow_angle = calc_angle(
                [r_shoulder.x, r_shoulder.y, r_shoulder.z],
                [r_elbow.x, r_elbow.y, r_elbow.z],
                [r_wrist.x, r_wrist.y, r_wrist.z]
            )

            left_elbow_angle = calc_angle(
                [l_shoulder.x, l_shoulder.y, l_shoulder.z],
                [l_elbow.x, l_elbow.y, l_elbow.z],
                [l_wrist.x, l_wrist.y, l_wrist.z]
            )

            # MediaPipe
            # 펴진 팔 ≈ 180 deg
            # 접힌 팔 ≈ 0 deg
            #
            # Robot joint11
            # 펴진 팔 ≈ 0 rad
            # 접힌 팔 ≈ +1.9 rad
            #
            # 따라서
            # robot_angle = deg2rad(180 - human_angle)
            joint4_target = np.deg2rad(
                180 - right_elbow_angle
            )
            joint4_target = np.clip(
                joint4_target,
                -1.919,
                1.919
            )

            joint11_target = np.deg2rad(
                180 - left_elbow_angle
            )
            joint11_target = np.clip(
                joint11_target,
                -1.919,
                1.919
            )

            # Exponential Moving Average (EMA)
            #
            # filtered =
            #     alpha * current +
            #     (1-alpha) * previous
            #
            # 관절 떨림 감소 목적

            filtered_joint4 = (
                alpha * joint4_target +
                (1.0 - alpha) * filtered_joint4
            )

            filtered_joint11 = (
                alpha * joint11_target +
                (1.0 - alpha) * filtered_joint11
            )

            # joint11만 제어
            #
            # 현재는 팔꿈치 추종만 구현
            # 나머지 관절은 0으로 유지
            traj = JointTrajectory()
            traj.joint_names = [
                "joint8",
                "joint9",
                "joint10",
                "joint11",
                "joint12",
                "joint13",
                "joint14"
            ]
            pt = JointTrajectoryPoint()
            pt.positions = [
                0.0,
                0.0,
                0.0,
                float(filtered_joint11),
                0.0,
                0.0,
                0.0
            ]

            pt.time_from_start = Duration(
                sec=0,
                nanosec=100000000
            )

            traj.points.append(pt)

            left_pub.publish(traj)

            #terminal print
            print(
                f"L raw={joint11_target:.2f} "
                f"filt={filtered_joint11:.2f} "
                f"R raw={joint4_target:.2f} "
                f"filt={filtered_joint4:.2f}"
            )

            #screen print
            cv2.putText(
                frame,
                f"L Elbow: {left_elbow_angle:.1f}",
                (20,40),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.8,
                (0,255,0),
                2
            )

            cv2.putText(
                frame,
                f"R Elbow: {right_elbow_angle:.1f}",
                (20,80),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.8,
                (0,255,255),
                2
            )

        cv2.imshow("RealSense Pose Tracking", frame)

        key = cv2.waitKey(1)

        rclpy.spin_once(
            node,
            timeout_sec=0
        )

        if key == 27:  # ESC
            break

finally:
    pipeline.stop()
    node.destroy_node()
    rclpy.shutdown()
    cv2.destroyAllWindows()