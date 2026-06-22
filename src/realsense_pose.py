import cv2
import numpy as np
import mediapipe as mp
import pyrealsense2 as rs

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

#angle calculator
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


pipeline.start(config)

pose = mp_pose.Pose(
    static_image_mode=False,
    model_complexity=1,
    min_detection_confidence=0.5,
    min_tracking_confidence=0.5
)

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
            lm = result.pose_landmarks.landmark

            # right shoulder, elbow, wrist
            r_shoulder = lm[12]
            r_elbow    = lm[14]
            r_wrist    = lm[16]

            # left shoulder, elbow, wrist
            l_shoulder = lm[11]
            l_elbow    = lm[13]
            l_wrist    = lm[15]
            
            #calculate angle
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

            #terminal print
            print(
                f"L={left_elbow_angle:.1f} ({joint11_target:.2f}rad)  "
                f"R={right_elbow_angle:.1f} ({joint4_target:.2f}rad)"
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

        if key == 27:  # ESC
            break

finally:
    pipeline.stop()
    cv2.destroyAllWindows()