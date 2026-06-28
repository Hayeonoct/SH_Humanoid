// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_interfaces:msg/UpperBodyCommand.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_COMMAND__BUILDER_HPP_
#define ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_interfaces/msg/detail/upper_body_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_interfaces
{

namespace msg
{

namespace builder
{

class Init_UpperBodyCommand_duration
{
public:
  explicit Init_UpperBodyCommand_duration(::ros2_interfaces::msg::UpperBodyCommand & msg)
  : msg_(msg)
  {}
  ::ros2_interfaces::msg::UpperBodyCommand duration(::ros2_interfaces::msg::UpperBodyCommand::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperBodyCommand msg_;
};

class Init_UpperBodyCommand_kd
{
public:
  explicit Init_UpperBodyCommand_kd(::ros2_interfaces::msg::UpperBodyCommand & msg)
  : msg_(msg)
  {}
  Init_UpperBodyCommand_duration kd(::ros2_interfaces::msg::UpperBodyCommand::_kd_type arg)
  {
    msg_.kd = std::move(arg);
    return Init_UpperBodyCommand_duration(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperBodyCommand msg_;
};

class Init_UpperBodyCommand_kp
{
public:
  explicit Init_UpperBodyCommand_kp(::ros2_interfaces::msg::UpperBodyCommand & msg)
  : msg_(msg)
  {}
  Init_UpperBodyCommand_kd kp(::ros2_interfaces::msg::UpperBodyCommand::_kp_type arg)
  {
    msg_.kp = std::move(arg);
    return Init_UpperBodyCommand_kd(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperBodyCommand msg_;
};

class Init_UpperBodyCommand_effort
{
public:
  explicit Init_UpperBodyCommand_effort(::ros2_interfaces::msg::UpperBodyCommand & msg)
  : msg_(msg)
  {}
  Init_UpperBodyCommand_kp effort(::ros2_interfaces::msg::UpperBodyCommand::_effort_type arg)
  {
    msg_.effort = std::move(arg);
    return Init_UpperBodyCommand_kp(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperBodyCommand msg_;
};

class Init_UpperBodyCommand_velocity
{
public:
  explicit Init_UpperBodyCommand_velocity(::ros2_interfaces::msg::UpperBodyCommand & msg)
  : msg_(msg)
  {}
  Init_UpperBodyCommand_effort velocity(::ros2_interfaces::msg::UpperBodyCommand::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_UpperBodyCommand_effort(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperBodyCommand msg_;
};

class Init_UpperBodyCommand_position
{
public:
  explicit Init_UpperBodyCommand_position(::ros2_interfaces::msg::UpperBodyCommand & msg)
  : msg_(msg)
  {}
  Init_UpperBodyCommand_velocity position(::ros2_interfaces::msg::UpperBodyCommand::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_UpperBodyCommand_velocity(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperBodyCommand msg_;
};

class Init_UpperBodyCommand_motor_id
{
public:
  explicit Init_UpperBodyCommand_motor_id(::ros2_interfaces::msg::UpperBodyCommand & msg)
  : msg_(msg)
  {}
  Init_UpperBodyCommand_position motor_id(::ros2_interfaces::msg::UpperBodyCommand::_motor_id_type arg)
  {
    msg_.motor_id = std::move(arg);
    return Init_UpperBodyCommand_position(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperBodyCommand msg_;
};

class Init_UpperBodyCommand_command_mode
{
public:
  explicit Init_UpperBodyCommand_command_mode(::ros2_interfaces::msg::UpperBodyCommand & msg)
  : msg_(msg)
  {}
  Init_UpperBodyCommand_motor_id command_mode(::ros2_interfaces::msg::UpperBodyCommand::_command_mode_type arg)
  {
    msg_.command_mode = std::move(arg);
    return Init_UpperBodyCommand_motor_id(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperBodyCommand msg_;
};

class Init_UpperBodyCommand_header
{
public:
  Init_UpperBodyCommand_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UpperBodyCommand_command_mode header(::ros2_interfaces::msg::UpperBodyCommand::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_UpperBodyCommand_command_mode(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperBodyCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interfaces::msg::UpperBodyCommand>()
{
  return ros2_interfaces::msg::builder::Init_UpperBodyCommand_header();
}

}  // namespace ros2_interfaces

#endif  // ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_COMMAND__BUILDER_HPP_
