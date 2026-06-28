// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ros2_interfaces:msg/UpperBodyCommand.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ros2_interfaces/msg/detail/upper_body_command__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace ros2_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void UpperBodyCommand_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ros2_interfaces::msg::UpperBodyCommand(_init);
}

void UpperBodyCommand_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ros2_interfaces::msg::UpperBodyCommand *>(message_memory);
  typed_message->~UpperBodyCommand();
}

size_t size_function__UpperBodyCommand__motor_id(const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * get_const_function__UpperBodyCommand__motor_id(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint8_t, 15> *>(untyped_member);
  return &member[index];
}

void * get_function__UpperBodyCommand__motor_id(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint8_t, 15> *>(untyped_member);
  return &member[index];
}

void fetch_function__UpperBodyCommand__motor_id(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__UpperBodyCommand__motor_id(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__UpperBodyCommand__motor_id(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__UpperBodyCommand__motor_id(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

size_t size_function__UpperBodyCommand__position(const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * get_const_function__UpperBodyCommand__position(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void * get_function__UpperBodyCommand__position(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void fetch_function__UpperBodyCommand__position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__UpperBodyCommand__position(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__UpperBodyCommand__position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__UpperBodyCommand__position(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__UpperBodyCommand__velocity(const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * get_const_function__UpperBodyCommand__velocity(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void * get_function__UpperBodyCommand__velocity(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void fetch_function__UpperBodyCommand__velocity(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__UpperBodyCommand__velocity(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__UpperBodyCommand__velocity(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__UpperBodyCommand__velocity(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__UpperBodyCommand__effort(const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * get_const_function__UpperBodyCommand__effort(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void * get_function__UpperBodyCommand__effort(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void fetch_function__UpperBodyCommand__effort(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__UpperBodyCommand__effort(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__UpperBodyCommand__effort(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__UpperBodyCommand__effort(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__UpperBodyCommand__kp(const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * get_const_function__UpperBodyCommand__kp(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void * get_function__UpperBodyCommand__kp(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void fetch_function__UpperBodyCommand__kp(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__UpperBodyCommand__kp(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__UpperBodyCommand__kp(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__UpperBodyCommand__kp(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__UpperBodyCommand__kd(const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * get_const_function__UpperBodyCommand__kd(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void * get_function__UpperBodyCommand__kd(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void fetch_function__UpperBodyCommand__kd(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__UpperBodyCommand__kd(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__UpperBodyCommand__kd(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__UpperBodyCommand__kd(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember UpperBodyCommand_message_member_array[9] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperBodyCommand, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "command_mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperBodyCommand, command_mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "motor_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperBodyCommand, motor_id),  // bytes offset in struct
    nullptr,  // default value
    size_function__UpperBodyCommand__motor_id,  // size() function pointer
    get_const_function__UpperBodyCommand__motor_id,  // get_const(index) function pointer
    get_function__UpperBodyCommand__motor_id,  // get(index) function pointer
    fetch_function__UpperBodyCommand__motor_id,  // fetch(index, &value) function pointer
    assign_function__UpperBodyCommand__motor_id,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "position",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperBodyCommand, position),  // bytes offset in struct
    nullptr,  // default value
    size_function__UpperBodyCommand__position,  // size() function pointer
    get_const_function__UpperBodyCommand__position,  // get_const(index) function pointer
    get_function__UpperBodyCommand__position,  // get(index) function pointer
    fetch_function__UpperBodyCommand__position,  // fetch(index, &value) function pointer
    assign_function__UpperBodyCommand__position,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "velocity",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperBodyCommand, velocity),  // bytes offset in struct
    nullptr,  // default value
    size_function__UpperBodyCommand__velocity,  // size() function pointer
    get_const_function__UpperBodyCommand__velocity,  // get_const(index) function pointer
    get_function__UpperBodyCommand__velocity,  // get(index) function pointer
    fetch_function__UpperBodyCommand__velocity,  // fetch(index, &value) function pointer
    assign_function__UpperBodyCommand__velocity,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "effort",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperBodyCommand, effort),  // bytes offset in struct
    nullptr,  // default value
    size_function__UpperBodyCommand__effort,  // size() function pointer
    get_const_function__UpperBodyCommand__effort,  // get_const(index) function pointer
    get_function__UpperBodyCommand__effort,  // get(index) function pointer
    fetch_function__UpperBodyCommand__effort,  // fetch(index, &value) function pointer
    assign_function__UpperBodyCommand__effort,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "kp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperBodyCommand, kp),  // bytes offset in struct
    nullptr,  // default value
    size_function__UpperBodyCommand__kp,  // size() function pointer
    get_const_function__UpperBodyCommand__kp,  // get_const(index) function pointer
    get_function__UpperBodyCommand__kp,  // get(index) function pointer
    fetch_function__UpperBodyCommand__kp,  // fetch(index, &value) function pointer
    assign_function__UpperBodyCommand__kp,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "kd",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperBodyCommand, kd),  // bytes offset in struct
    nullptr,  // default value
    size_function__UpperBodyCommand__kd,  // size() function pointer
    get_const_function__UpperBodyCommand__kd,  // get_const(index) function pointer
    get_function__UpperBodyCommand__kd,  // get(index) function pointer
    fetch_function__UpperBodyCommand__kd,  // fetch(index, &value) function pointer
    assign_function__UpperBodyCommand__kd,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "duration",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperBodyCommand, duration),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers UpperBodyCommand_message_members = {
  "ros2_interfaces::msg",  // message namespace
  "UpperBodyCommand",  // message name
  9,  // number of fields
  sizeof(ros2_interfaces::msg::UpperBodyCommand),
  UpperBodyCommand_message_member_array,  // message members
  UpperBodyCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  UpperBodyCommand_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t UpperBodyCommand_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &UpperBodyCommand_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace ros2_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2_interfaces::msg::UpperBodyCommand>()
{
  return &::ros2_interfaces::msg::rosidl_typesupport_introspection_cpp::UpperBodyCommand_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ros2_interfaces, msg, UpperBodyCommand)() {
  return &::ros2_interfaces::msg::rosidl_typesupport_introspection_cpp::UpperBodyCommand_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
