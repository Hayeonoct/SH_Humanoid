cmake_minimum_required(VERSION 3.8)
project(sh_motion_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

############################
# Dependencies
############################

find_package(ament_cmake REQUIRED)

find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)

find_package(control_msgs REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)

find_package(moveit_ros_planning_interface REQUIRED)

find_package(ros2_interfaces REQUIRED)

find_package(ament_index_cpp REQUIRED)

############################
# Testing
############################

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

############################
# wave
############################

add_executable(
  wave
  src/wave.cpp
)

ament_target_dependencies(
  wave
  rclcpp
  moveit_ros_planning_interface
)

############################
# trajectory bridge
############################

add_executable(
  trajectory_bridge_node
  src/trajectory_bridge_node.cpp
)

ament_target_dependencies(
  trajectory_bridge_node
  rclcpp
  rclcpp_action
  control_msgs
  trajectory_msgs
  ros2_interfaces
)

############################
# joint_state_bridge
############################

add_executable(
  joint_state_bridge
  src/joint_state_bridge.cpp
)

ament_target_dependencies(
  joint_state_bridge
  rclcpp
  sensor_msgs
  ros2_interfaces
)

target_link_libraries(
  joint_state_bridge
)

############################
# Install
############################

install(
  TARGETS
    wave
    trajectory_bridge_node
    joint_state_bridge
  DESTINATION
    lib/${PROJECT_NAME}
)

ament_package()