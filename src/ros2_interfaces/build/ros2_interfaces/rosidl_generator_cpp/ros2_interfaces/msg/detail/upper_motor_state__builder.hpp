// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_interfaces:msg/UpperMotorState.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__MSG__DETAIL__UPPER_MOTOR_STATE__BUILDER_HPP_
#define ROS2_INTERFACES__MSG__DETAIL__UPPER_MOTOR_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_interfaces/msg/detail/upper_motor_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_interfaces
{

namespace msg
{

namespace builder
{

class Init_UpperMotorState_current
{
public:
  explicit Init_UpperMotorState_current(::ros2_interfaces::msg::UpperMotorState & msg)
  : msg_(msg)
  {}
  ::ros2_interfaces::msg::UpperMotorState current(::ros2_interfaces::msg::UpperMotorState::_current_type arg)
  {
    msg_.current = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperMotorState msg_;
};

class Init_UpperMotorState_voltage
{
public:
  explicit Init_UpperMotorState_voltage(::ros2_interfaces::msg::UpperMotorState & msg)
  : msg_(msg)
  {}
  Init_UpperMotorState_current voltage(::ros2_interfaces::msg::UpperMotorState::_voltage_type arg)
  {
    msg_.voltage = std::move(arg);
    return Init_UpperMotorState_current(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperMotorState msg_;
};

class Init_UpperMotorState_temperature
{
public:
  explicit Init_UpperMotorState_temperature(::ros2_interfaces::msg::UpperMotorState & msg)
  : msg_(msg)
  {}
  Init_UpperMotorState_voltage temperature(::ros2_interfaces::msg::UpperMotorState::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_UpperMotorState_voltage(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperMotorState msg_;
};

class Init_UpperMotorState_error_code
{
public:
  explicit Init_UpperMotorState_error_code(::ros2_interfaces::msg::UpperMotorState & msg)
  : msg_(msg)
  {}
  Init_UpperMotorState_temperature error_code(::ros2_interfaces::msg::UpperMotorState::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return Init_UpperMotorState_temperature(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperMotorState msg_;
};

class Init_UpperMotorState_effort
{
public:
  explicit Init_UpperMotorState_effort(::ros2_interfaces::msg::UpperMotorState & msg)
  : msg_(msg)
  {}
  Init_UpperMotorState_error_code effort(::ros2_interfaces::msg::UpperMotorState::_effort_type arg)
  {
    msg_.effort = std::move(arg);
    return Init_UpperMotorState_error_code(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperMotorState msg_;
};

class Init_UpperMotorState_velocity
{
public:
  explicit Init_UpperMotorState_velocity(::ros2_interfaces::msg::UpperMotorState & msg)
  : msg_(msg)
  {}
  Init_UpperMotorState_effort velocity(::ros2_interfaces::msg::UpperMotorState::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_UpperMotorState_effort(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperMotorState msg_;
};

class Init_UpperMotorState_position
{
public:
  explicit Init_UpperMotorState_position(::ros2_interfaces::msg::UpperMotorState & msg)
  : msg_(msg)
  {}
  Init_UpperMotorState_velocity position(::ros2_interfaces::msg::UpperMotorState::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_UpperMotorState_velocity(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperMotorState msg_;
};

class Init_UpperMotorState_motor_id
{
public:
  explicit Init_UpperMotorState_motor_id(::ros2_interfaces::msg::UpperMotorState & msg)
  : msg_(msg)
  {}
  Init_UpperMotorState_position motor_id(::ros2_interfaces::msg::UpperMotorState::_motor_id_type arg)
  {
    msg_.motor_id = std::move(arg);
    return Init_UpperMotorState_position(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperMotorState msg_;
};

class Init_UpperMotorState_has_fault
{
public:
  explicit Init_UpperMotorState_has_fault(::ros2_interfaces::msg::UpperMotorState & msg)
  : msg_(msg)
  {}
  Init_UpperMotorState_motor_id has_fault(::ros2_interfaces::msg::UpperMotorState::_has_fault_type arg)
  {
    msg_.has_fault = std::move(arg);
    return Init_UpperMotorState_motor_id(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperMotorState msg_;
};

class Init_UpperMotorState_is_enabled
{
public:
  explicit Init_UpperMotorState_is_enabled(::ros2_interfaces::msg::UpperMotorState & msg)
  : msg_(msg)
  {}
  Init_UpperMotorState_has_fault is_enabled(::ros2_interfaces::msg::UpperMotorState::_is_enabled_type arg)
  {
    msg_.is_enabled = std::move(arg);
    return Init_UpperMotorState_has_fault(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperMotorState msg_;
};

class Init_UpperMotorState_is_ready
{
public:
  explicit Init_UpperMotorState_is_ready(::ros2_interfaces::msg::UpperMotorState & msg)
  : msg_(msg)
  {}
  Init_UpperMotorState_is_enabled is_ready(::ros2_interfaces::msg::UpperMotorState::_is_ready_type arg)
  {
    msg_.is_ready = std::move(arg);
    return Init_UpperMotorState_is_enabled(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperMotorState msg_;
};

class Init_UpperMotorState_header
{
public:
  Init_UpperMotorState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UpperMotorState_is_ready header(::ros2_interfaces::msg::UpperMotorState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_UpperMotorState_is_ready(msg_);
  }

private:
  ::ros2_interfaces::msg::UpperMotorState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interfaces::msg::UpperMotorState>()
{
  return ros2_interfaces::msg::builder::Init_UpperMotorState_header();
}

}  // namespace ros2_interfaces

#endif  // ROS2_INTERFACES__MSG__DETAIL__UPPER_MOTOR_STATE__BUILDER_HPP_
