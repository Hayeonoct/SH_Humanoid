import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import yaml

def load_yaml(package_name, file_path):
    package_path = get_package_share_directory(package_name)
    absolute_file_path = os.path.join(package_path, file_path)
    with open(absolute_file_path, 'r') as file:
        return yaml.safe_load(file)

def generate_launch_description():
    # 내 로봇 패키지 이름으로 변경하세요!
    my_robot_pkg = 'SH_moveit_config'
    
    # servo.yaml 파라미터 불러오기
    servo_yaml = load_yaml(my_robot_pkg, 'config/servo.yaml')
    servo_params = {'moveit_servo': servo_yaml}

    kinematics_yaml = load_yaml(my_robot_pkg, 'config/kinematics.yaml')

    # Servo 노드 실행
    servo_node = Node(
        package='moveit_servo',
        executable='servo_node',
        parameters=[
            servo_params,
            {'robot_description_kinematics': kinematics_yaml}
            ],
        output='screen'
    )

    return LaunchDescription([servo_node])