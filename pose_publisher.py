import rclpy
from rclpy.node import Node
from control_msgs.msg import JointJog
from sensor_msgs.msg import JointState
from moveit_msgs.srv import ServoCommandType
import cv2
import mediapipe as mp
import numpy as np
import pyrealsense2 as rs

class RealSenseJointPublisher(Node):
    def __init__(self):
        super().__init__('realsense_joint_publisher')
        
        self.publisher_ = self.create_publisher(JointJog, '/servo_node/delta_joint_cmds', 10)
        self.subscription = self.create_subscription(JointState, '/joint_states', self.joint_state_callback, 10)
        self.current_joints = {}

        # Servo JOINT_JOG 모드 설정
        self.cmd_type_client = self.create_client(ServoCommandType, '/servo_node/switch_command_type')
        while not self.cmd_type_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('MoveIt Servo 서비스를 기다리는 중...')
        req = ServoCommandType.Request()
        req.command_type = ServoCommandType.Request.JOINT_JOG
        self.cmd_type_client.call_async(req)

        # RealSense 카메라 설정
        self.pipeline = rs.pipeline()
        config = rs.config()
        config.enable_stream(rs.stream.depth, 1280, 720, rs.format.z16, 30)
        config.enable_stream(rs.stream.color, 1280, 720, rs.format.bgr8, 30)
        
        self.profile = self.pipeline.start(config)
        self.align = rs.align(rs.stream.color)
        infra_stream = self.profile.get_stream(rs.stream.color)
        self.intrinsics = infra_stream.as_video_stream_profile().get_intrinsics()

        # MediaPipe 초기화
        self.mp_pose = mp.solutions.pose
        self.pose = self.mp_pose.Pose(min_detection_confidence=0.7, min_tracking_confidence=0.7)
        self.mp_drawing = mp.solutions.drawing_utils
        
        self.timer = self.create_timer(1.0 / 30.0, self.timer_callback)
        self.k_p = 2.0
        self.max_vel = 0.6
        self.joint_names = ['joint1', 'joint2', 'joint3', 'joint4', 'joint5', 'joint6', 'joint7']

        # --- [추가됨] 부드러운 움직임을 위한 EMA 필터 변수 ---
        self.filtered_targets = {name: 0.0 for name in self.joint_names}
        self.alpha = 0.6  # 필터 강도 (0.01 ~ 1.0). 낮을수록 엄청 부드럽고(느림), 높을수록 빠르고(틱톡거림)

    def joint_state_callback(self, msg):
        for i, name in enumerate(msg.name):
            self.current_joints[name] = msg.position[i]

    def get_pixel_3d_point(self, depth_frame, u, v, box_size=5):
        """1픽셀의 오차로 배경(벽) 깊이를 읽는 것을 방지하기 위한 Median 필터 적용"""
        u = int(max(0, min(u, 639)))
        v = int(max(0, min(v, 449)))
        
        depths = []
        half_box = box_size // 2
        
        # 랜드마크 주변 5x5 픽셀(총 25개)의 깊이값을 모두 수집
        for i in range(-half_box, half_box + 1):
            for j in range(-half_box, half_box + 1):
                cur_u = int(max(0, min(u + i, 639)))
                cur_v = int(max(0, min(v + j, 449)))
                d = depth_frame.get_distance(cur_u, cur_v)
                
                # 깊이가 0이 아니고, 너무 멀지 않은 값(예: 2.5m 이내)만 유효한 값으로 취급
                if 0.1 < d < 2.5: 
                    depths.append(d)
        
        # 유효한 깊이값이 주변에 하나도 없으면 에러 방지를 위해 None 반환
        if not depths:
            return None
            
        # 수집된 값들 중 중앙값(Median) 추출 (노이즈와 배경 깊이 완벽 차단)
        median_depth = np.median(depths)
        
        # 필터링된 깊이값으로 3D 물리 좌표 변환
        point3d = rs.rs2_deproject_pixel_to_point(self.intrinsics, [u, v], median_depth)
        return np.array(point3d)

    def normalize(self, v):
        norm = np.linalg.norm(v)
        return v / norm if norm > 0 else v

    def timer_callback(self):
        frames = self.pipeline.wait_for_frames()
        aligned_frames = self.align.process(frames)
        depth_frame = aligned_frames.get_depth_frame()
        color_frame = aligned_frames.get_color_frame()
        
        if not depth_frame or not color_frame: return

        image = np.asanyarray(color_frame.get_data())
        image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
        results = self.pose.process(image_rgb)

        if results.pose_landmarks and self.current_joints:
            h, w, _ = image.shape
            landmarks = results.pose_landmarks.landmark
            
            # 오른팔 랜드마크 추출 (어깨:12, 팔꿈치:14, 손목:16, 검지:20)
            sh_u, sh_v = int(landmarks[12].x * w), int(landmarks[12].y * h)
            el_u, el_v = int(landmarks[14].x * w), int(landmarks[14].y * h)
            wr_u, wr_v = int(landmarks[16].x * w), int(landmarks[16].y * h)
            idx_u, idx_v = int(landmarks[20].x * w), int(landmarks[20].y * h)

            # RealSense 기반 3D 물리 좌표 변환
            p_sh = self.get_pixel_3d_point(depth_frame, sh_u, sh_v)
            p_el = self.get_pixel_3d_point(depth_frame, el_u, el_v)
            p_wr = self.get_pixel_3d_point(depth_frame, wr_u, wr_v)
            p_idx = self.get_pixel_3d_point(depth_frame, idx_u, idx_v)

            if p_sh is not None and p_el is not None and p_wr is not None and p_idx is not None:
                v_upper = self.normalize(p_el - p_sh)
                v_lower = self.normalize(p_wr - p_el)
                v_hand = self.normalize(p_idx - p_wr)

                # ==========================================
                # 🛠️ 거울 상 반전 교정 및 순수 기구학 매핑
                # ==========================================

                # [교정 핵심] 사용자가 오른팔을 뻗으면 카메라 좌표계에서는 -X축으로 측정되므로,
                # 이를 로봇의 우측 플러스 방향(+90도)과 일치시키기 위해 부호를 반전합니다.
                user_right_x = -v_upper[0] 

                # 1. joint1: 어깨 회전 (Yaw)
                # 이제 오른팔을 펼치면 정확히 +1.57 rad (90도)가 계산됩니다.
                target_joint1 = np.arctan2(user_right_x, v_upper[2])

                # 2. joint2: 팔 들어올림 (Pitch)
                # 수평으로 들면 90도(1.57 rad), 위로 올릴수록 마이너스 변위 적용
                lift_angle = np.arccos(np.clip(v_upper[1], -1.0, 1.0))
                target_joint2 = -lift_angle

                # 3. joint3: 고정
                target_joint3 = target_joint2 * 0.35

                # 4. joint4: 팔꿈치 관절
                # 손목이 팔꿈치보다 위(카메라 -Y 방향)에 있을 때만 음수 각도(-90도)를 갖도록
                # 3D 공간 상의 수직 방향성을 판별하여 부호를 부여합니다.
                elbow_flex = np.arccos(np.clip(np.dot(v_upper, v_lower), -1.0, 1.0))
                if p_wr[1] < p_el[1]: # 손이 팔꿈치보다 위에 있음 (선서 자세)
                    target_joint4 = -elbow_flex
                else:                 # 손이 팔꿈치보다 아래에 있음
                    target_joint4 = elbow_flex

                # 5. joint5: 고정
                target_joint5 = target_joint4 * -0.2

                # 6. joint6: 손목 관절
                wrist_flex = np.arccos(np.clip(np.dot(v_lower, v_hand), -1.0, 1.0))
                target_joint6 = wrist_flex if (p_idx[1] > p_wr[1]) else -wrist_flex

                cross_wrist = np.cross(v_lower, v_hand)
                
                # 외적 벡터의 크기가 너무 작으면(팔이 거의 일자로 펴짐) 억지로 계산하지 않고 0.0 고정
                if np.linalg.norm(cross_wrist) < 1e-3:
                    target_joint7 = 0.0
                else:
                    target_joint7 = np.arcsin(np.clip(cross_wrist[1], -1.0, 1.0))

                scale = 0.9

                # --- 목표 각도 빌드 ---
                target_angles = {
                    'joint1': target_joint1*scale,
                    'joint2': max(min(target_joint2*scale, 0.0), -3.14),
                    'joint3': target_joint3*scale,
                    'joint4': max(min(target_joint4*scale, 0.0), -1.91),
                    'joint5': target_joint5*scale,
                    'joint6': target_joint6*scale,
                    'joint7': target_joint7*scale
                }

                if lift_angle < 0.3 and elbow_flex < 0.3:
                    target_angles['joint1'] = 0.0
                    target_angles['joint2'] = -0.15 # 로봇 팔이 몸통을 파고들지 않도록 살짝 띄움
                    target_angles['joint3'] = 0.0
                    target_angles['joint4'] = 0.0   # 일자로 쫙 폄
                    target_angles['joint5'] = 0.0
                    target_angles['joint6'] = 0.0
                    target_angles['joint7'] = 0.0

                # --- 속도 명령 생성 및 퍼블리시 ---
                msg = JointJog()
                msg.header.stamp = self.get_clock().now().to_msg()
                msg.header.frame_id = "base_link"
                
                for j_name in self.joint_names:
                    if j_name in self.current_joints:
                        raw_target = target_angles.get(j_name, 0.0)
                        
                        # ==========================================
                        # 🌿 근육 관성 필터 적용 (EMA Smoothing)
                        # ==========================================
                        # 이전 목표값과 현재 들어온 생 데이터를 섞어서 부드러운 곡선을 만듭니다.
                        self.filtered_targets[j_name] = (self.alpha * raw_target) + ((1.0 - self.alpha) * self.filtered_targets[j_name])
                        
                        # 필터링된 부드러운 목표값으로 오차 계산
                        error = self.filtered_targets[j_name] - self.current_joints[j_name]
                        
                        vel = 0.0 if abs(error) < 0.03 else max(min(error * self.k_p, self.max_vel), -self.max_vel)
                        
                        msg.joint_names.append(j_name)
                        msg.velocities.append(float(vel))

                self.publisher_.publish(msg)

            self.mp_drawing.draw_landmarks(image, results.pose_landmarks, self.mp_pose.POSE_CONNECTIONS)

        cv2.imshow("7-DOF Pure Joint Mapping (Fixed Axis)", cv2.flip(image, 1))
        cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    node = RealSenseJointPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.pipeline.stop()
        cv2.destroyAllWindows()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()