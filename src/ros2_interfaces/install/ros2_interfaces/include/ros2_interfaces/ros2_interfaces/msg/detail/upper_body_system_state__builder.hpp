// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_interfaces:msg/UpperBodySystemState.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_SYSTEM_STATE__BUILDER_HPP_
#define ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_SYSTEM_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_interfaces/msg/detail/upper_body_system_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_interfaces
{

namespace msg
{

namespace builder
{

class Init_UpperBodySystemState_command_accepted
{
public:
  explicit Init_UpperBodySystemState_command_accepted(::ros2_interfaces::msg::UpperBodySystemState & msg)
  : msg_(msg)
  {}
  ::ros2_interfaces::msg::UpperBodySystemState command_accepted(::ros2_interfaces::msg::UpperBodySystemState::_command_accepted_type arg)
  {
    msg_.command_accepted = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperBodySystemState msg_;
};

class Init_UpperBodySystemState_all_motors_enabled
{
public:
  explicit Init_UpperBodySystemState_all_motors_enabled(::ros2_interfaces::msg::UpperBodySystemState & msg)
  : msg_(msg)
  {}
  Init_UpperBodySystemState_command_accepted all_motors_enabled(::ros2_interfaces::msg::UpperBodySystemState::_all_motors_enabled_type arg)
  {
    msg_.all_motors_enabled = std::move(arg);
    return Init_UpperBodySystemState_command_accepted(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperBodySystemState msg_;
};

class Init_UpperBodySystemState_is_connected
{
public:
  explicit Init_UpperBodySystemState_is_connected(::ros2_interfaces::msg::UpperBodySystemState & msg)
  : msg_(msg)
  {}
  Init_UpperBodySystemState_all_motors_enabled is_connected(::ros2_interfaces::msg::UpperBodySystemState::_is_connected_type arg)
  {
    msg_.is_connected = std::move(arg);
    return Init_UpperBodySystemState_all_motors_enabled(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperBodySystemState msg_;
};

class Init_UpperBodySystemState_fault_motor_count
{
public:
  explicit Init_UpperBodySystemState_fault_motor_count(::ros2_interfaces::msg::UpperBodySystemState & msg)
  : msg_(msg)
  {}
  Init_UpperBodySystemState_is_connected fault_motor_count(::ros2_interfaces::msg::UpperBodySystemState::_fault_motor_count_type arg)
  {
    msg_.fault_motor_count = std::move(arg);
    return Init_UpperBodySystemState_is_connected(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperBodySystemState msg_;
};

class Init_UpperBodySystemState_enabled_motor_count
{
public:
  explicit Init_UpperBodySystemState_enabled_motor_count(::ros2_interfaces::msg::UpperBodySystemState & msg)
  : msg_(msg)
  {}
  Init_UpperBodySystemState_fault_motor_count enabled_motor_count(::ros2_interfaces::msg::UpperBodySystemState::_enabled_motor_count_type arg)
  {
    msg_.enabled_motor_count = std::move(arg);
    return Init_UpperBodySystemState_fault_motor_count(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperBodySystemState msg_;
};

class Init_UpperBodySystemState_ready_motor_count
{
public:
  explicit Init_UpperBodySystemState_ready_motor_count(::ros2_interfaces::msg::UpperBodySystemState & msg)
  : msg_(msg)
  {}
  Init_UpperBodySystemState_enabled_motor_count ready_motor_count(::ros2_interfaces::msg::UpperBodySystemState::_ready_motor_count_type arg)
  {
    msg_.ready_motor_count = std::move(arg);
    return Init_UpperBodySystemState_enabled_motor_count(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperBodySystemState msg_;
};

class Init_UpperBodySystemState_run_mode
{
public:
  explicit Init_UpperBodySystemState_run_mode(::ros2_interfaces::msg::UpperBodySystemState & msg)
  : msg_(msg)
  {}
  Init_UpperBodySystemState_ready_motor_count run_mode(::ros2_interfaces::msg::UpperBodySystemState::_run_mode_type arg)
  {
    msg_.run_mode = std::move(arg);
    return Init_UpperBodySystemState_ready_motor_count(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperBodySystemState msg_;
};

class Init_UpperBodySystemState_state
{
public:
  explicit Init_UpperBodySystemState_state(::ros2_interfaces::msg::UpperBodySystemState & msg)
  : msg_(msg)
  {}
  Init_UpperBodySystemState_run_mode state(::ros2_interfaces::msg::UpperBodySystemState::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_UpperBodySystemState_run_mode(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperBodySystemState msg_;
};

class Init_UpperBodySystemState_header
{
public:
  Init_UpperBodySystemState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UpperBodySystemState_state header(::ros2_interfaces::msg::UpperBodySystemState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_UpperBodySystemState_state(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperBodySystemState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interfaces::msg::UpperBodySystemState>()
{
  return ros2_interfaces::msg::builder::Init_UpperBodySystemState_header();
}

}  // namespace ros2_interfaces

#endif  // ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_SYSTEM_STATE__BUILDER_HPP_
