cmake_minimum_required(VERSION 3.8)
project(ros2_interfaces)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/UpperBodyCommand.msg"
  "msg/UpperBodySystemState.msg"
  "msg/UpperMotorState.msg"
  "srv/EnableMotors.srv"
  "srv/SetRunMode.srv"
  "srv/SimpleMotorResult.srv"
  DEPENDENCIES std_msgs
)

ament_export_dependencies(rosidl_default_runtime)
ament_package()
