// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_interfaces:srv/SimpleMotorResult.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__SRV__DETAIL__SIMPLE_MOTOR_RESULT__BUILDER_HPP_
#define ROS2_INTERFACES__SRV__DETAIL__SIMPLE_MOTOR_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_interfaces/srv/detail/simple_motor_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_interfaces
{

namespace srv
{

namespace builder
{

class Init_SimpleMotorResult_Request_motor_id_list
{
public:
  Init_SimpleMotorResult_Request_motor_id_list()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2_interfaces::srv::SimpleMotorResult_Request motor_id_list(::ros2_interfaces::srv::SimpleMotorResult_Request::_motor_id_list_type arg)
  {
    msg_.motor_id_list = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interfaces::srv::SimpleMotorResult_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interfaces::srv::SimpleMotorResult_Request>()
{
  return ros2_interfaces::srv::builder::Init_SimpleMotorResult_Request_motor_id_list();
}

}  // namespace ros2_interfaces


namespace ros2_interfaces
{

namespace srv
{

namespace builder
{

class Init_SimpleMotorResult_Response_message
{
public:
  explicit Init_SimpleMotorResult_Response_message(::ros2_interfaces::srv::SimpleMotorResult_Response & msg)
  : msg_(msg)
  {}
  ::ros2_interfaces::srv::SimpleMotorResult_Response message(::ros2_interfaces::srv::SimpleMotorResult_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interfaces::srv::SimpleMotorResult_Response msg_;
};

class Init_SimpleMotorResult_Response_success
{
public:
  Init_SimpleMotorResult_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SimpleMotorResult_Response_message success(::ros2_interfaces::srv::SimpleMotorResult_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SimpleMotorResult_Response_message(msg_);
  }

private:
  ::ros2_interfaces::srv::SimpleMotorResult_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interfaces::srv::SimpleMotorResult_Response>()
{
  return ros2_interfaces::srv::builder::Init_SimpleMotorResult_Response_success();
}

}  // namespace ros2_interfaces

#endif  // ROS2_INTERFACES__SRV__DETAIL__SIMPLE_MOTOR_RESULT__BUILDER_HPP_
