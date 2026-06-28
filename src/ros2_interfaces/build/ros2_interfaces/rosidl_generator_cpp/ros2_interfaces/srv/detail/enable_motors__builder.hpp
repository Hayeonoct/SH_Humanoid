// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_interfaces:srv/EnableMotors.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__SRV__DETAIL__ENABLE_MOTORS__BUILDER_HPP_
#define ROS2_INTERFACES__SRV__DETAIL__ENABLE_MOTORS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_interfaces/srv/detail/enable_motors__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_interfaces
{

namespace srv
{

namespace builder
{

class Init_EnableMotors_Request_motor_id_list
{
public:
  explicit Init_EnableMotors_Request_motor_id_list(::ros2_interfaces::srv::EnableMotors_Request & msg)
  : msg_(msg)
  {}
  ::ros2_interfaces::srv::EnableMotors_Request motor_id_list(::ros2_interfaces::srv::EnableMotors_Request::_motor_id_list_type arg)
  {
    msg_.motor_id_list = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interfaces::srv::EnableMotors_Request msg_;
};

class Init_EnableMotors_Request_enable_all
{
public:
  Init_EnableMotors_Request_enable_all()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EnableMotors_Request_motor_id_list enable_all(::ros2_interfaces::srv::EnableMotors_Request::_enable_all_type arg)
  {
    msg_.enable_all = std::move(arg);
    return Init_EnableMotors_Request_motor_id_list(msg_);
  }

private:
  ::ros2_interfaces::srv::EnableMotors_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interfaces::srv::EnableMotors_Request>()
{
  return ros2_interfaces::srv::builder::Init_EnableMotors_Request_enable_all();
}

}  // namespace ros2_interfaces


namespace ros2_interfaces
{

namespace srv
{

namespace builder
{

class Init_EnableMotors_Response_failed_motor_ids
{
public:
  explicit Init_EnableMotors_Response_failed_motor_ids(::ros2_interfaces::srv::EnableMotors_Response & msg)
  : msg_(msg)
  {}
  ::ros2_interfaces::srv::EnableMotors_Response failed_motor_ids(::ros2_interfaces::srv::EnableMotors_Response::_failed_motor_ids_type arg)
  {
    msg_.failed_motor_ids = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interfaces::srv::EnableMotors_Response msg_;
};

class Init_EnableMotors_Response_enabled_motor_ids
{
public:
  explicit Init_EnableMotors_Response_enabled_motor_ids(::ros2_interfaces::srv::EnableMotors_Response & msg)
  : msg_(msg)
  {}
  Init_EnableMotors_Response_failed_motor_ids enabled_motor_ids(::ros2_interfaces::srv::EnableMotors_Response::_enabled_motor_ids_type arg)
  {
    msg_.enabled_motor_ids = std::move(arg);
    return Init_EnableMotors_Response_failed_motor_ids(msg_);
  }

private:
  ::ros2_interfaces::srv::EnableMotors_Response msg_;
};

class Init_EnableMotors_Response_message
{
public:
  explicit Init_EnableMotors_Response_message(::ros2_interfaces::srv::EnableMotors_Response & msg)
  : msg_(msg)
  {}
  Init_EnableMotors_Response_enabled_motor_ids message(::ros2_interfaces::srv::EnableMotors_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_EnableMotors_Response_enabled_motor_ids(msg_);
  }

private:
  ::ros2_interfaces::srv::EnableMotors_Response msg_;
};

class Init_EnableMotors_Response_success
{
public:
  Init_EnableMotors_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EnableMotors_Response_message success(::ros2_interfaces::srv::EnableMotors_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_EnableMotors_Response_message(msg_);
  }

private:
  ::ros2_interfaces::srv::EnableMotors_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interfaces::srv::EnableMotors_Response>()
{
  return ros2_interfaces::srv::builder::Init_EnableMotors_Response_success();
}

}  // namespace ros2_interfaces

#endif  // ROS2_INTERFACES__SRV__DETAIL__ENABLE_MOTORS__BUILDER_HPP_
