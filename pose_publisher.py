import rclpy
from rclpy.node import Node
from control_msgs.msg import JointJog
from sensor_msgs.msg import JointState
from moveit_msgs.srv import ServoCommandType
import cv2
import mediapipe as mp
import numpy as np
import pyrealsense2 as rs

# --- [추가] TF2 관련 라이브러리 ---
import tf2_ros
from geometry_msgs.msg import PointStamped
import tf2_geometry_msgs

class RealSenseJointPublisher(Node):
    def __init__(self):
        super().__init__('realsense_joint_publisher')
        
        # --- [추가] TF2 Buffer 및 Listener 초기화 ---
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)
        
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

        self.filtered_targets = {name: 0.0 for name in self.joint_names}
        self.alpha = 0.6  

    def joint_state_callback(self, msg):
        for i, name in enumerate(msg.name):
            self.current_joints[name] = msg.position[i]

    def get_pixel_3d_point(self, depth_frame, u, v, box_size=5):
        # 실제 depth frame 해상도 읽기
        width = depth_frame.get_width()
        height = depth_frame.get_height()

        # MediaPipe에서 나온 픽셀 좌표가 이미지 밖으로 나가지 않게 제한
        u = int(max(0, min(round(u), width - 1)))
        v = int(max(0, min(round(v), height - 1)))

        depths = []
        half_box = box_size // 2

        # 중심 픽셀 주변 box_size x box_size 영역의 depth 수집
        for du in range(-half_box, half_box + 1):
            for dv in range(-half_box, half_box + 1):
                cur_u = int(max(0, min(u + du, width - 1)))
                cur_v = int(max(0, min(v + dv, height - 1)))

                d = depth_frame.get_distance(cur_u, cur_v)

                # 너무 가깝거나 너무 먼 depth는 노이즈로 보고 제외
                if 0.1 < d < 2.5:
                    depths.append(d)

        # 유효한 depth가 없으면 3D 좌표 계산 불가
        if not depths:
            return None

        # 주변 depth의 중앙값 사용
        median_depth = float(np.median(depths))

        # 2D pixel + depth → 3D camera coordinate
        point3d = rs.rs2_deproject_pixel_to_point(
            self.intrinsics,
            [u, v],
            median_depth
        )

        return np.array(point3d, dtype=np.float32)

    # --- [핵심 추가] 카메라 좌표계를 base_link로 변환하는 함수 ---
    def transform_to_base_link(self, point3d, camera_frame="camera_color_optical_frame", target_frame="base_link"):
        if point3d is None:
            return None
            
        pt_stamped = PointStamped()
        pt_stamped.header.stamp = self.get_clock().now().to_msg()
        pt_stamped.header.frame_id = camera_frame
        pt_stamped.point.x = float(point3d[0])
        pt_stamped.point.y = float(point3d[1])
        pt_stamped.point.z = float(point3d[2])

        try:
            # timeout을 0.05초로 주어 변환 지연에 의한 제어 루프 블로킹 방지
            trans_pt = self.tf_buffer.transform(pt_stamped, target_frame, timeout=rclpy.duration.Duration(seconds=0.05))
            return np.array([trans_pt.point.x, trans_pt.point.y, trans_pt.point.z])
        except tf2_ros.TransformException as ex:
            self.get_logger().warn(f'TF Transform Error: {ex}')
            return None

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
            
            sh_u, sh_v = int(landmarks[12].x * w), int(landmarks[12].y * h)
            el_u, el_v = int(landmarks[14].x * w), int(landmarks[14].y * h)
            wr_u, wr_v = int(landmarks[16].x * w), int(landmarks[16].y * h)
            idx_u, idx_v = int(landmarks[20].x * w), int(landmarks[20].y * h)

            # 1. 카메라 좌표계 기준 3D 포인트
            p_sh_cam = self.get_pixel_3d_point(depth_frame, sh_u, sh_v)
            p_el_cam = self.get_pixel_3d_point(depth_frame, el_u, el_v)
            p_wr_cam = self.get_pixel_3d_point(depth_frame, wr_u, wr_v)
            p_idx_cam = self.get_pixel_3d_point(depth_frame, idx_u, idx_v)

            # 2. 로봇 base_link 좌표계로 변환 (거울상 반전 로직 영구 제거)
            p_sh = self.transform_to_base_link(p_sh_cam)
            p_el = self.transform_to_base_link(p_el_cam)
            p_wr = self.transform_to_base_link(p_wr_cam)
            p_idx = self.transform_to_base_link(p_idx_cam)

            pinky_u, pinky_v = int(landmarks[18].x * w), int(landmarks[18].y * h)
            p_pinky_cam = self.get_pixel_3d_point(depth_frame, pinky_u, pinky_v)
            p_pinky = self.transform_to_base_link(p_pinky_cam)

            if all(p is not None for p in [p_sh, p_el, p_wr, p_idx]):
                if np.linalg.norm(p_wr - p_sh) > 0.8:
                    return 
                
                v_upper = self.normalize(p_el - p_sh)
                v_lower = self.normalize(p_wr - p_el)
                v_hand = self.normalize(p_idx - p_wr)
                v_pinky = self.normalize(p_pinky - p_wr)
                v_palm_normal = self.normalize(np.cross(v_hand, v_pinky))


                # ==========================================
                # 🛠️ base_link 기준 순수 기구학 매핑 (atan2 기반)
                # 일반적인 ROS 로봇 (X: 전방, Y: 좌측, Z: 상단) 가정
                # ==========================================

                # 1. 앞으로 뻗을 때 로봇도 앞으로 뻗도록 (X축 반전)
                v_upper[0] = -v_upper[0]
                v_lower[0] = -v_lower[0]
                v_hand[0]  = -v_hand[0]

                # 2. 바깥(오른쪽)으로 뻗을 때 로봇도 바깥으로 (Y축 반전)
                # v_upper[1] = -v_upper[1]
                # v_lower[1] = -v_lower[1]
                # v_hand[1]  = -v_hand[1]

                # 1. joint1: 어깨 회전 (Yaw)
                # 팔이 전방(X)을 향하면 0, 좌측(Y)을 향하면 +각도, 우측을 향하면 -각도
                target_joint1 = np.arctan2(v_upper[1], v_upper[0])

                # 2. joint2: 팔 들어올림 (Pitch)
                # 수평 길이(XY_norm) 대비 수직 높이(Z)의 비율로 각도 계산
                xy_norm = np.linalg.norm([v_upper[0], v_upper[1]])
                target_joint2 = -np.arctan2(v_upper[2], xy_norm) - 1.57

                # 3. joint3: (Coupling 유지 - 추후 Twist 제어로 전환 시 제거 예정)
                roll_angle = np.arcsin(np.clip(v_lower[2], -1.0, 1.0))
                target_joint3 = roll_angle - 1.57

                # 4. joint4: 팔꿈치 관절
                elbow_flex = np.arccos(np.clip(np.dot(v_upper, v_lower), -1.0, 1.0))
                # Z축 기준 외적으로 굽힘 방향 판별  
                cross_elbow = np.cross(v_upper, v_lower)
                sign_elbow = np.sign(cross_elbow[2]) if abs(cross_elbow[2]) > 0.01 else 1.0
                target_joint4 = elbow_flex * sign_elbow

                # 5. joint5: (Coupling 유지)
                target_joint5 = np.arctan2(v_palm_normal[1], v_palm_normal[2])
                target_joint5 = np.clip(target_joint5, -1.5, 1.5)

                # 6. joint6: 손목 관절
                wrist_flex = np.arccos(np.clip(np.dot(v_lower, v_hand), -1.0, 1.0))
                cross_wrist = np.cross(v_lower, v_hand)
                sign_wrist = np.sign(cross_wrist[2]) if abs(cross_wrist[2]) > 0.01 else 1.0
                target_joint6 = wrist_flex * sign_wrist

                # 7. joint7: 손목 회전 (임시 보정)
                if np.linalg.norm(cross_wrist) < 1e-3:
                    target_joint7 = 0.0
                else:
                    target_joint7 = np.arcsin(np.clip(cross_wrist[0], -1.0, 1.0))

                scale = 0.9

                target_angles = {
                    'joint1': target_joint1*scale,
                    'joint2': max(min(target_joint2*scale, 0.0), -3.14),
                    'joint3': target_joint3*scale,
                    'joint4': max(min(target_joint4*scale, 0.0), -1.91),
                    'joint5': target_joint5*scale,
                    'joint6': target_joint6*scale,
                    'joint7': target_joint7*scale
                }

                # --- 속도 명령 생성 및 퍼블리시 ---
                msg = JointJog()
                msg.header.stamp = self.get_clock().now().to_msg()
                msg.header.frame_id = "base_link"
                
                for j_name in self.joint_names:
                    if j_name in self.current_joints:
                        raw_target = target_angles.get(j_name, 0.0)
                        
                        self.filtered_targets[j_name] = (self.alpha * raw_target) + ((1.0 - self.alpha) * self.filtered_targets[j_name])
                        error = self.filtered_targets[j_name] - self.current_joints[j_name]
                        
                        vel = 0.0 if abs(error) < 0.03 else max(min(error * self.k_p, self.max_vel), -self.max_vel)
                        
                        msg.joint_names.append(j_name)
                        msg.velocities.append(float(vel))

                self.publisher_.publish(msg)

            self.mp_drawing.draw_landmarks(image, results.pose_landmarks, self.mp_pose.POSE_CONNECTIONS)

        cv2.imshow("7-DOF Teleop (TF2 Base_link Integration)", cv2.flip(image, 1))
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