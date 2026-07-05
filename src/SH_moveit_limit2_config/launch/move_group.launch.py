import os

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from moveit_configs_utils import MoveItConfigsBuilder
from moveit_configs_utils.launch_utils import DeclareBooleanLaunchArg


def generate_launch_description():
    moveit_config = MoveItConfigsBuilder(
        "SH_Humanoid", package_name="SH_moveit_limit2_config"
    ).to_moveit_configs()

    # generate_move_group_launch 와 동일하게 구성하되,
    # start_state_max_bounds_error 파라미터를 추가한다.
    ld = LaunchDescription()
    ld.add_action(DeclareBooleanLaunchArg("debug", default_value=False))
    ld.add_action(DeclareBooleanLaunchArg("allow_trajectory_execution", default_value=True))
    ld.add_action(DeclareBooleanLaunchArg("publish_monitored_planning_scene", default_value=True))
    ld.add_action(DeclareLaunchArgument(
        "capabilities", default_value=moveit_config.move_group_capabilities["capabilities"]))
    ld.add_action(DeclareLaunchArgument(
        "disable_capabilities", default_value=moveit_config.move_group_capabilities["disable_capabilities"]))
    ld.add_action(DeclareBooleanLaunchArg("monitor_dynamics", default_value=False))

    should_publish = LaunchConfiguration("publish_monitored_planning_scene")

    move_group_configuration = {
        "publish_robot_description_semantic": True,
        "allow_trajectory_execution": LaunchConfiguration("allow_trajectory_execution"),
        "capabilities": ParameterValue(LaunchConfiguration("capabilities"), value_type=str),
        "disable_capabilities": ParameterValue(
            LaunchConfiguration("disable_capabilities"), value_type=str),
        "publish_planning_scene": should_publish,
        "publish_geometry_updates": should_publish,
        "publish_state_updates": should_publish,
        "publish_transforms_updates": should_publish,
        "monitor_dynamics": False,
        # [FIX] 시작 자세가 관절 리밋을 미세하게(하드웨어 영점 오차 등) 벗어나도 planning 허용.
        #       특히 한쪽 팔을 planning 할 때 반대쪽 팔 관절이 센서값으로 남아 리밋을 살짝
        #       넘는 경우(joint2 상한 0 vs 센서 +0.0147)를 봐준다. 실제 리밋은 그대로 지킴.
        "start_state_max_bounds_error": 0.1,
    }

    move_group_node = Node(
        package="moveit_ros_move_group",
        executable="move_group",
        output="screen",
        parameters=[moveit_config.to_dict(), move_group_configuration],
        additional_env={"DISPLAY": os.environ.get("DISPLAY", "")},
    )
    ld.add_action(move_group_node)
    return ld
