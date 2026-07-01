import cv2
import csv
import numpy as np
import mediapipe as mp
import pyrealsense2 as rs
import math

# =========================================================
# 캘리브레이션 / 좌표계 설정
# =========================================================

# [2번] 로봇 팔 길이 [m]. 좌우 팔 길이는 동일하므로 단일 값 사용 (80cm 가정)
ROBOT_ARM_LENGTH = 0.80

# [4번] 사람이 "카메라를 마주보고" 모션을 찍는다는 전제의 좌표 변환.
#   카메라 광학계: x=화면오른쪽, y=화면아래, z=정면(카메라에서 멀어지는 방향)
#   사람을 마주보면 사람 기준 좌표는 카메라계에서 다음과 같다:
#     사람 앞(=카메라로 다가옴) = -z_cam
#     사람 왼쪽               = +x_cam   (마주보면 사람 왼손이 화면 오른쪽)
#     사람 위                 = -y_cam
#   결과가 거꾸로면 아래 부호만 -1.0 으로 뒤집어 미세조정하세요.
AXIS_FORWARD_SIGN = +1.0
AXIS_LEFT_SIGN = +1.0
AXIS_UP_SIGN = +1.0

# [3번] 깊이 중앙값을 구할 패치 크기(픽셀). 7 -> 7x7 = 49픽셀 ≈ 50픽셀
DEPTH_PATCH = 7

# MediaPipe Pose 랜드마크 인덱스
R_SH, R_EL, R_WR = 12, 14, 16   # 오른쪽 어깨/팔꿈치/손목
L_SH, L_EL, L_WR = 11, 13, 15   # 왼쪽 어깨/팔꿈치/손목


class VisionRecorder:
    def __init__(self):
        self.mp_pose = mp.solutions.pose
        self.pose = self.mp_pose.Pose(min_detection_confidence=0.7,
                                      min_tracking_confidence=0.7)
        self.mp_drawing = mp.solutions.drawing_utils

        self.pipeline = rs.pipeline()
        self.config = rs.config()
        self.width, self.height = 1280, 720
        # [3번] 컬러 + 깊이 동시 스트리밍
        self.config.enable_stream(rs.stream.color, self.width, self.height, rs.format.bgr8, 30)
        self.config.enable_stream(rs.stream.depth, self.width, self.height, rs.format.z16, 30)

        # [3번] 깊이를 컬러 프레임에 정렬 (픽셀 좌표/해상도 일치)
        self.align = rs.align(rs.stream.color)
        self.depth_scale = 1.0
        self.intrinsics = None

        self.recorded_waypoints = []

    # -----------------------------------------------------
    # [3번] 깊이 -> 카메라 좌표계 3D 복원 유틸
    # -----------------------------------------------------
    def median_depth(self, depth_image, px, py, patch=DEPTH_PATCH):
        """(px,py) 주변 patch x patch 영역에서 0이 아닌 깊이의 중앙값(raw 단위) 반환."""
        h, w = depth_image.shape
        half = patch // 2
        x0, x1 = max(0, px - half), min(w, px + half + 1)
        y0, y1 = max(0, py - half), min(h, py + half + 1)
        region = depth_image[y0:y1, x0:x1].reshape(-1)
        valid = region[region > 0]
        if valid.size == 0:
            return 0.0
        return float(np.median(valid))

    def landmark_to_camera_point(self, lm, depth_image):
        """랜드마크 -> 카메라 광학 좌표계 3D 점[m]. 유효 깊이 없으면 None."""
        px = int(np.clip(lm.x * self.width, 0, self.width - 1))
        py = int(np.clip(lm.y * self.height, 0, self.height - 1))
        raw = self.median_depth(depth_image, px, py)
        if raw <= 0:
            return None
        z_m = raw * self.depth_scale
        # 픽셀 + 깊이 -> 카메라 좌표계 3D[m] (x:오른쪽, y:아래, z:정면)
        X, Y, Z = rs.rs2_deproject_pixel_to_point(self.intrinsics, [px, py], z_m)
        return np.array([X, Y, Z], dtype=float)

    # -----------------------------------------------------
    # [4번] 카메라 -> 로봇 좌표계 변환
    # -----------------------------------------------------
    @staticmethod
    def cam_to_robot(vec_cam):
        """카메라 광학 좌표계 벡터 -> 로봇 base_link 좌표계 벡터."""
        x_cam, y_cam, z_cam = vec_cam
        # 사람이 카메라를 마주본다는 전제 (사람 기준 좌표)
        x_robot = AXIS_FORWARD_SIGN * (-z_cam)   # 앞   = 카메라로 다가오는 방향
        y_robot = AXIS_LEFT_SIGN * (x_cam)       # 왼쪽 = 마주보면 사람 왼쪽 = 화면 오른쪽(+x)
        z_robot = AXIS_UP_SIGN * (-y_cam)        # 위   = 화면 위쪽(-y)
        return np.array([x_robot, y_robot, z_robot], dtype=float)

    # -----------------------------------------------------
    # [2번] 자동 스케일이 적용된 상대 좌표 계산
    # -----------------------------------------------------
    def compute_relative(self, sh, el, wr, robot_arm_len):
        """어깨/팔꿈치/손목(카메라 3D[m]) -> 로봇 스케일 상대좌표[m] 또는 None."""
        if sh is None or el is None or wr is None:
            return None
        # 사람 팔 길이(어깨->팔꿈치->손목) [m] : 자세와 무관한 신체 치수
        human_len = np.linalg.norm(el - sh) + np.linalg.norm(wr - el)
        if human_len < 1e-3:
            return None
        scale = robot_arm_len / human_len            # 사람->로봇 자동 스케일
        rel_cam = wr - sh                            # 손목 - 어깨 (카메라 frame)
        rel_robot = self.cam_to_robot(rel_cam) * scale
        return rel_robot

    # -----------------------------------------------------
    # 메인 루프
    # -----------------------------------------------------
    def run(self):
        print("RealSense 카메라 시작 중...")
        try:
            profile = self.pipeline.start(self.config)
        except Exception as e:
            print(f"❌ 에러: {e}")
            return

        # 깊이 스케일(raw -> m) 취득
        depth_sensor = profile.get_device().first_depth_sensor()
        self.depth_scale = depth_sensor.get_depth_scale()
        print(f"Depth scale: {self.depth_scale}")

        cv2.namedWindow("RealSense Recorder", cv2.WINDOW_NORMAL)
        print("\n=== 모드: 수동 캡처 ===")
        print("'c': 현재 위치 저장")
        print("'q': 저장 후 종료")

        try:
            while True:
                frames = self.pipeline.wait_for_frames()
                aligned = self.align.process(frames)            # [3번] 정렬
                color_frame = aligned.get_color_frame()
                depth_frame = aligned.get_depth_frame()
                if not color_frame or not depth_frame:
                    continue

                # 정렬된 컬러 기준 intrinsics (깊이가 컬러에 정렬되었으므로 동일)
                self.intrinsics = color_frame.profile.as_video_stream_profile().intrinsics

                image = np.asanyarray(color_frame.get_data())
                depth_image = np.asanyarray(depth_frame.get_data())
                image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
                results = self.pose.process(image_rgb)

                r_rel = None
                l_rel = None
                if results.pose_landmarks:
                    self.mp_drawing.draw_landmarks(
                        image, results.pose_landmarks, self.mp_pose.POSE_CONNECTIONS)
                    lm = results.pose_landmarks.landmark

                    # [3번] 어깨/팔꿈치/손목을 카메라 좌표계 3D[m]로 복원
                    r_sh = self.landmark_to_camera_point(lm[R_SH], depth_image)
                    r_el = self.landmark_to_camera_point(lm[R_EL], depth_image)
                    r_wr = self.landmark_to_camera_point(lm[R_WR], depth_image)
                    l_sh = self.landmark_to_camera_point(lm[L_SH], depth_image)
                    l_el = self.landmark_to_camera_point(lm[L_EL], depth_image)
                    l_wr = self.landmark_to_camera_point(lm[L_WR], depth_image)

                    # [2번+4번] 자동 스케일 + 로봇 좌표계 변환
                    r_rel = self.compute_relative(r_sh, r_el, r_wr, ROBOT_ARM_LENGTH)
                    l_rel = self.compute_relative(l_sh, l_el, l_wr, ROBOT_ARM_LENGTH)

                    # 손목 시각화
                    cv2.circle(image, (int(lm[R_WR].x * self.width), int(lm[R_WR].y * self.height)),
                               12, (0, 0, 255), -1)
                    cv2.circle(image, (int(lm[L_WR].x * self.width), int(lm[L_WR].y * self.height)),
                               12, (0, 0, 255), -1)

                key = cv2.waitKey(1) & 0xFF
                if key == ord('c'):
                    if r_rel is not None and l_rel is not None:
                        row = list(r_rel) + list(l_rel)
                        if not any(math.isnan(v) for v in row):
                            self.recorded_waypoints.append(row)
                            print(f"저장됨! (현재 {len(self.recorded_waypoints)}개)  "
                                  f"R={np.round(r_rel, 3)}  L={np.round(l_rel, 3)}")
                    else:
                        print("⚠️ 깊이/랜드마크 누락으로 저장 실패 (관절이 가려졌거나 깊이값 0)")
                elif key == ord('q'):
                    self.save_to_csv('waypoints.csv')
                    break

                image = cv2.flip(image, 1)  # 화면 표시용 좌우 반전(미러뷰)
                cv2.putText(image, f"Points: {len(self.recorded_waypoints)}",
                            (20, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 0), 2)
                cv2.imshow("RealSense Recorder", image)
        finally:
            self.pipeline.stop()
            cv2.destroyAllWindows()

    def save_to_csv(self, filename):
        with open(filename, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(['rx', 'ry', 'rz', 'lx', 'ly', 'lz'])
            writer.writerows(self.recorded_waypoints)
        print(f"✅ 저장 완료: {len(self.recorded_waypoints)}개 포인트")


if __name__ == '__main__':
    VisionRecorder().run()