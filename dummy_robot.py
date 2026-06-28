import rclpy
from rclpy.node import Node

# 서비스 타입 임포트
from ros2_interfaces.srv import EnableMotors, SimpleMotorResult, SetRunMode

class DummyRobot(Node):
    def __init__(self):
        super().__init__('dummy_robot_server')
        
        # 3가지 서비스 서버(전화기) 개통
        self.srv_enable = self.create_service(EnableMotors, '/upper_body/enable_motors', self.enable_cb)
        self.srv_disable = self.create_service(SimpleMotorResult, '/upper_body/disable_motors', self.disable_cb)
        self.srv_mode = self.create_service(SetRunMode, '/upper_body/set_run_mode', self.mode_cb)
        
        self.get_logger().info('🤖 가상 로봇 대기 중... (대시보드에서 버튼을 눌러보세요!)')

    # Enable 전화가 왔을 때 실행될 콜백 함수
    def enable_cb(self, request, response):
        self.get_logger().info(f'🟢 [Enable 수신] 전체 켜기: {request.enable_all} | 타겟 모터 ID: {list(request.motor_id_list)}')
        return response

    # Disable 전화가 왔을 때
    def disable_cb(self, request, response):
        self.get_logger().info(f'🔴 [Disable 수신] 끄기 대상 모터 ID: {list(request.motor_id_list)}')
        return response

    # 모드 변경(SetRunMode) 전화가 왔을 때
    def mode_cb(self, request, response):
        self.get_logger().info(f'⚙️ [Mode 변경 수신] 설정 모드: {request.mode} | 타겟 모터 ID: {list(request.motor_id_list)}')
        return response

def main(args=None):
    rclpy.init(args=args)
    node = DummyRobot()
    
    try:
        rclpy.spin(node) # 켜진 상태로 무한 대기
    except KeyboardInterrupt:
        node.get_logger().info('가상 로봇 종료됨')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()