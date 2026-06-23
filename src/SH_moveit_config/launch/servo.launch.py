import os
import yaml
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch.substitutions import Command
from launch_ros.parameter_descriptions import ParameterValue

# 1. YAML 파일 로드 함수 (기존)
def load_yaml(package_name, file_path):
    package_path = get_package_share_directory(package_name)
    absolute_file_path = os.path.join(package_path, file_path)
    with open(absolute_file_path, 'r') as file:
        return yaml.safe_load(file)

# 2. SRDF 등 일반 텍스트(XML) 파일 로드 함수 (추가)
def load_text(package_name, file_path):
    package_path = get_package_share_directory(package_name)
    absolute_file_path = os.path.join(package_path, file_path)
    with open(absolute_file_path, 'r') as file:
        return file.read()

def generate_launch_description():
    my_robot_pkg = 'SH_moveit_config'
    
    # [중요] MoveIt Setup Assistant에서 지은 로봇 이름을 입력하세요!
    # 보통 config 폴더 안의 파일명(예: SH.srdf, SH.urdf.xacro)의 앞부분입니다.
    robot_name = 'SH_Humanoid' 

    # 3. URDF (robot_description) 로드
    # Xacro 파일 렌더링을 위해 Command를 사용합니다.
    urdf_xacro_path = os.path.join(get_package_share_directory(my_robot_pkg), 'config', f'{robot_name}.urdf.xacro')
    robot_description_content = Command(['xacro ', urdf_xacro_path])
    robot_description = {'robot_description': ParameterValue(robot_description_content, value_type=str)}

    # 4. SRDF (robot_description_semantic) 로드
    srdf_content = load_text(my_robot_pkg, f'config/{robot_name}.srdf')
    robot_description_semantic = {'robot_description_semantic': srdf_content}

    # 5. 기존 YAML 파일 로드
    servo_yaml = load_yaml(my_robot_pkg, 'config/servo.yaml')
    servo_params = {'moveit_servo': servo_yaml}
    kinematics_yaml = load_yaml(my_robot_pkg, 'config/kinematics.yaml')

    # 6. Servo 노드 실행 (모든 파라미터 통합)
    servo_node = Node(
        package='moveit_servo',
        executable='servo_node',
        parameters=[
            servo_params,
            robot_description,
            robot_description_semantic,
            {'robot_description_kinematics': kinematics_yaml}
        ],
        output='screen'
    )

    return LaunchDescription([servo_node])