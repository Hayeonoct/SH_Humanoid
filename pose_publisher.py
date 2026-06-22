import rclpy
from rclpy.node import Node
from control_msgs.msg import JointJog
from sensor_msgs.msg import JointState
from moveit_msgs.srv import ServoCommandType
import cv2
import mediapipe as mp
import numpy as np

class JointSpacePublisher(Node):
    def __init__(self):
        super().__init__('joint_space_publisher')
        
        # 1. 퍼블리셔: 데카르트 속도(Twist) 대신 관절 속도(JointJog) 전송
        self.publisher_ = self.create_publisher(JointJog, '/servo_node/delta_joint_cmds', 10)
        
        # 2. 서브스크라이버: 현재 로봇의 관절 각도를 읽어오기 위함
        self.subscription = self.create_subscription(
            JointState,
            '/joint_states',
            self.joint_state_callback,
            10)
        self.current_joints = {}

        # 3. MoveIt Servo 커맨드 타입 설정 (JOINT_JOG 모드로 변경)
        self.cmd_type_client = self.create_client(ServoCommandType, '/servo_node/switch_command_type')
        while not self.cmd_type_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('MoveIt Servo 커맨드 타입 설정 서비스를 기다리는 중...')
            
        req = ServoCommandType.Request()
        req.command_type = ServoCommandType.Request.JOINT_JOG # 0번이 조인트 속도 제어입니다.
        self.cmd_type_client.call_async(req)
        self.get_logger().info("MoveIt Servo 커맨드 타입을 JOINT_JOG(조인트 제어)로 설정 완료!")

        # MediaPipe 초기화
        self.mp_pose = mp.solutions.pose
        self.pose = self.mp_pose.Pose(min_detection_confidence=0.7, min_tracking_confidence=0.7)
        self.mp_drawing = mp.solutions.drawing_utils
        
        self.cap = cv2.VideoCapture(4) # 카메라 인덱스에 맞게 수정하세요 (0 또는 2)
        self.timer = self.create_timer(1.0 / 30.0, self.timer_callback)
        
        self.k_p = 2.0  # P 제어 게인 (반응 속도 조절)
        self.max_vel = 1.0 # 최대 회전 속도 제한 (rad/s)
        
        # 제어할 실제 로봇 관절 이름
        self.joint_names = ['joint1', 'joint2', 'joint3', 'joint4', 'joint5', 'joint6', 'joint7']

    def joint_state_callback(self, msg):
        # 로봇의 현재 관절 각도 업데이트
        for i, name in enumerate(msg.name):
            self.current_joints[name] = msg.position[i]

    def get_angle(self, a, b, c):
        # 세 점 사이의 사이각 계산 (b가 중심 꼭짓점)
        ba = a - b
        bc = c - b
        # 벡터 내적을 이용한 각도 계산 공식 적용
        cosine_angle = np.dot(ba, bc) / (np.linalg.norm(ba) * np.linalg.norm(bc) + 1e-6)
        angle = np.arccos(np.clip(cosine_angle, -1.0, 1.0))
        return angle

    def timer_callback(self):
        success, image = self.cap.read()
        if not success:
            return

        image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
        results = self.pose.process(image_rgb)

        if results.pose_landmarks and self.current_joints:
            landmarks = results.pose_landmarks.landmark
            
            # 오른쪽 팔과 몸통, 손가락 랜드마크 추출 (MediaPipe 기준)
            shoulder = np.array([landmarks[11].x, landmarks[11].y, landmarks[11].z])
            elbow = np.array([landmarks[13].x, landmarks[13].y, landmarks[13].z])
            wrist = np.array([landmarks[15].x, landmarks[15].y, landmarks[15].z])
            hip = np.array([landmarks[23].x, landmarks[23].y, landmarks[23].z])
            index_finger = np.array([landmarks[19].x, landmarks[19].y, landmarks[19].z])

            elbow_angle = self.get_angle(shoulder, elbow, wrist)
            target_joint4 = (np.pi - elbow_angle)
            target_joint4 = max(min(target_joint4, 1.75), -1.75) # 안전 마진 적용
            
            # 2. 어깨 벌림 (joint2) (URDF: -3.141 ~ 0.0)
            shoulder_roll_angle = self.get_angle(hip, shoulder, elbow) 
            target_joint2 = -(shoulder_roll_angle - 0.2) * 2.0
            target_joint2 = max(min(target_joint2, -0.1), -3.0) # 안전 마진 적용

            # 3. 어깨 들기 (joint1)
            dz = elbow[2] - shoulder[2] 
            target_joint1 = dz * 5.0 

            # 4. 손목 굽힘 (joint5)
            wrist_angle = self.get_angle(elbow, wrist, index_finger)
            target_joint5 = (np.pi - wrist_angle) * 0.8

            target_angles = {
                'joint1': -target_joint1,
                'joint2': target_joint2,
                'joint3': 0.0,
                'joint4': -target_joint4,
                'joint5': target_joint5,
                'joint6': 0.0,
                'joint7': 0.0
            }

            # --- [2. 명령 생성 및 데드존(Deadzone) 적용] ---
            msg = JointJog()
            msg.header.stamp = self.get_clock().now().to_msg()
            msg.header.frame_id = "base_link"
            
            for j_name in self.joint_names:
                if j_name in self.current_joints:
                    curr_angle = self.current_joints[j_name]
                    target_angle = target_angles.get(j_name, 0.0)
                    
                    error = target_angle - curr_angle
                    
                    # [핵심 추가] 오차가 0.05 라디안(약 3도) 이하일 때는 속도를 0으로 강제!
                    # 이렇게 하면 목표치에 도달했을 때 Servo에게 불필요한 명령을 보내지 않습니다.
                    if abs(error) < 0.05:
                        vel = 0.0
                    else:
                        vel = max(min(error * self.k_p, self.max_vel), -self.max_vel)
                    
                    msg.joint_names.append(j_name)
                    msg.velocities.append(float(vel))

            self.publisher_.publish(msg)

            # 시각화 덧그리기
            self.mp_drawing.draw_landmarks(
                image,
                results.pose_landmarks,
                self.mp_pose.POSE_CONNECTIONS
            )

        # 화면 출력
        image = cv2.flip(image, 1) 
        cv2.imshow("Joint Space Motion Retargeting", image)
        cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    node = JointSpacePublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.cap.release()
        cv2.destroyAllWindows()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()