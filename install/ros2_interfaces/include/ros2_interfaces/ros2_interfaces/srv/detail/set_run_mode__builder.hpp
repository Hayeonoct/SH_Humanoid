// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_interfaces:srv/SetRunMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros2_interfaces/srv/set_run_mode.hpp"


#ifndef ROS2_INTERFACES__SRV__DETAIL__SET_RUN_MODE__BUILDER_HPP_
#define ROS2_INTERFACES__SRV__DETAIL__SET_RUN_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_interfaces/srv/detail/set_run_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetRunMode_Request_motor_id_list
{
public:
  explicit Init_SetRunMode_Request_motor_id_list(::ros2_interfaces::srv::SetRunMode_Request & msg)
  : msg_(msg)
  {}
  ::ros2_interfaces::srv::SetRunMode_Request motor_id_list(::ros2_interfaces::srv::SetRunMode_Request::_motor_id_list_type arg)
  {
    msg_.motor_id_list = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interfaces::srv::SetRunMode_Request msg_;
};

class Init_SetRunMode_Request_mode
{
public:
  Init_SetRunMode_Request_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetRunMode_Request_motor_id_list mode(::ros2_interfaces::srv::SetRunMode_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_SetRunMode_Request_motor_id_list(msg_);
  }

private:
  ::ros2_interfaces::srv::SetRunMode_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interfaces::srv::SetRunMode_Request>()
{
  return ros2_interfaces::srv::builder::Init_SetRunMode_Request_mode();
}

}  // namespace ros2_interfaces


namespace ros2_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetRunMode_Response_failed_motor_ids
{
public:
  explicit Init_SetRunMode_Response_failed_motor_ids(::ros2_interfaces::srv::SetRunMode_Response & msg)
  : msg_(msg)
  {}
  ::ros2_interfaces::srv::SetRunMode_Response failed_motor_ids(::ros2_interfaces::srv::SetRunMode_Response::_failed_motor_ids_type arg)
  {
    msg_.failed_motor_ids = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interfaces::srv::SetRunMode_Response msg_;
};

class Init_SetRunMode_Response_applied_motor_ids
{
public:
  explicit Init_SetRunMode_Response_applied_motor_ids(::ros2_interfaces::srv::SetRunMode_Response & msg)
  : msg_(msg)
  {}
  Init_SetRunMode_Response_failed_motor_ids applied_motor_ids(::ros2_interfaces::srv::SetRunMode_Response::_applied_motor_ids_type arg)
  {
    msg_.applied_motor_ids = std::move(arg);
    return Init_SetRunMode_Response_failed_motor_ids(msg_);
  }

private:
  ::ros2_interfaces::srv::SetRunMode_Response msg_;
};

class Init_SetRunMode_Response_message
{
public:
  explicit Init_SetRunMode_Response_message(::ros2_interfaces::srv::SetRunMode_Response & msg)
  : msg_(msg)
  {}
  Init_SetRunMode_Response_applied_motor_ids message(::ros2_interfaces::srv::SetRunMode_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_SetRunMode_Response_applied_motor_ids(msg_);
  }

private:
  ::ros2_interfaces::srv::SetRunMode_Response msg_;
};

class Init_SetRunMode_Response_success
{
public:
  Init_SetRunMode_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetRunMode_Response_message success(::ros2_interfaces::srv::SetRunMode_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetRunMode_Response_message(msg_);
  }

private:
  ::ros2_interfaces::srv::SetRunMode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interfaces::srv::SetRunMode_Response>()
{
  return ros2_interfaces::srv::builder::Init_SetRunMode_Response_success();
}

}  // namespace ros2_interfaces


namespace ros2_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetRunMode_Event_response
{
public:
  explicit Init_SetRunMode_Event_response(::ros2_interfaces::srv::SetRunMode_Event & msg)
  : msg_(msg)
  {}
  ::ros2_interfaces::srv::SetRunMode_Event response(::ros2_interfaces::srv::SetRunMode_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interfaces::srv::SetRunMode_Event msg_;
};

class Init_SetRunMode_Event_request
{
public:
  explicit Init_SetRunMode_Event_request(::ros2_interfaces::srv::SetRunMode_Event & msg)
  : msg_(msg)
  {}
  Init_SetRunMode_Event_response request(::ros2_interfaces::srv::SetRunMode_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetRunMode_Event_response(msg_);
  }

private:
  ::ros2_interfaces::srv::SetRunMode_Event msg_;
};

class Init_SetRunMode_Event_info
{
public:
  Init_SetRunMode_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetRunMode_Event_request info(::ros2_interfaces::srv::SetRunMode_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetRunMode_Event_request(msg_);
  }

private:
  ::ros2_interfaces::srv::SetRunMode_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interfaces::srv::SetRunMode_Event>()
{
  return ros2_interfaces::srv::builder::Init_SetRunMode_Event_info();
}

}  // namespace ros2_interfaces

#endif  // ROS2_INTERFACES__SRV__DETAIL__SET_RUN_MODE__BUILDER_HPP_
