from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    pkg = get_package_share_directory("SH_moveit_limit2_config")

    rsp = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg, "launch", "rsp.launch.py")
        )
    )
    move_group = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg, "launch", "move_group.launch.py")
        )
    )
    rviz = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg, "launch", "moveit_rviz.launch.py")
        )
    )
    tf = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg, "launch", "static_virtual_joint_tfs.launch.py")
        )
    )
    # spawn_controllers = IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource(
    #         os.path.join(pkg, "launch", "spawn_controllers.launch.py")
    #     )
    # )

    joint_state_bridge = Node(
        package="sh_motion_cpp",
        executable="joint_state_bridge",
        name="joint_state_bridge",
        output="screen",
    )

    trajectory_bridge = Node(
        package="sh_motion_cpp",
        executable="trajectory_bridge_node",
        name="trajectory_bridge_node",
        output="screen",
    )

    return LaunchDescription([
        rsp,
        move_group,
        rviz,
        tf,
        joint_state_bridge,
        trajectory_bridge,
        # spawn_controllers
    ])