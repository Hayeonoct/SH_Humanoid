// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ros2_interfaces:msg/UpperMotorState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ros2_interfaces/msg/detail/upper_motor_state__struct.hpp"
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

void UpperMotorState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ros2_interfaces::msg::UpperMotorState(_init);
}

void UpperMotorState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ros2_interfaces::msg::UpperMotorState *>(message_memory);
  typed_message->~UpperMotorState();
}

size_t size_function__UpperMotorState__is_ready(const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * get_const_function__UpperMotorState__is_ready(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<bool, 15> *>(untyped_member);
  return &member[index];
}

void * get_function__UpperMotorState__is_ready(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<bool, 15> *>(untyped_member);
  return &member[index];
}

void fetch_function__UpperMotorState__is_ready(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const bool *>(
    get_const_function__UpperMotorState__is_ready(untyped_member, index));
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = item;
}

void assign_function__UpperMotorState__is_ready(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<bool *>(
    get_function__UpperMotorState__is_ready(untyped_member, index));
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  item = value;
}

size_t size_function__UpperMotorState__is_enabled(const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * get_const_function__UpperMotorState__is_enabled(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<bool, 15> *>(untyped_member);
  return &member[index];
}

void * get_function__UpperMotorState__is_enabled(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<bool, 15> *>(untyped_member);
  return &member[index];
}

void fetch_function__UpperMotorState__is_enabled(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const bool *>(
    get_const_function__UpperMotorState__is_enabled(untyped_member, index));
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = item;
}

void assign_function__UpperMotorState__is_enabled(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<bool *>(
    get_function__UpperMotorState__is_enabled(untyped_member, index));
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  item = value;
}

size_t size_function__UpperMotorState__has_fault(const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * get_const_function__UpperMotorState__has_fault(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<bool, 15> *>(untyped_member);
  return &member[index];
}

void * get_function__UpperMotorState__has_fault(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<bool, 15> *>(untyped_member);
  return &member[index];
}

void fetch_function__UpperMotorState__has_fault(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const bool *>(
    get_const_function__UpperMotorState__has_fault(untyped_member, index));
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = item;
}

void assign_function__UpperMotorState__has_fault(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<bool *>(
    get_function__UpperMotorState__has_fault(untyped_member, index));
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  item = value;
}

size_t size_function__UpperMotorState__motor_id(const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * get_const_function__UpperMotorState__motor_id(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint16_t, 15> *>(untyped_member);
  return &member[index];
}

void * get_function__UpperMotorState__motor_id(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint16_t, 15> *>(untyped_member);
  return &member[index];
}

void fetch_function__UpperMotorState__motor_id(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint16_t *>(
    get_const_function__UpperMotorState__motor_id(untyped_member, index));
  auto & value = *reinterpret_cast<uint16_t *>(untyped_value);
  value = item;
}

void assign_function__UpperMotorState__motor_id(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint16_t *>(
    get_function__UpperMotorState__motor_id(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint16_t *>(untyped_value);
  item = value;
}

size_t size_function__UpperMotorState__position(const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * get_const_function__UpperMotorState__position(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void * get_function__UpperMotorState__position(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void fetch_function__UpperMotorState__position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__UpperMotorState__position(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__UpperMotorState__position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__UpperMotorState__position(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__UpperMotorState__velocity(const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * get_const_function__UpperMotorState__velocity(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void * get_function__UpperMotorState__velocity(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void fetch_function__UpperMotorState__velocity(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__UpperMotorState__velocity(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__UpperMotorState__velocity(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__UpperMotorState__velocity(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__UpperMotorState__effort(const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * get_const_function__UpperMotorState__effort(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void * get_function__UpperMotorState__effort(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void fetch_function__UpperMotorState__effort(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__UpperMotorState__effort(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__UpperMotorState__effort(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__UpperMotorState__effort(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__UpperMotorState__error_code(const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * get_const_function__UpperMotorState__error_code(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint16_t, 15> *>(untyped_member);
  return &member[index];
}

void * get_function__UpperMotorState__error_code(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint16_t, 15> *>(untyped_member);
  return &member[index];
}

void fetch_function__UpperMotorState__error_code(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint16_t *>(
    get_const_function__UpperMotorState__error_code(untyped_member, index));
  auto & value = *reinterpret_cast<uint16_t *>(untyped_value);
  value = item;
}

void assign_function__UpperMotorState__error_code(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint16_t *>(
    get_function__UpperMotorState__error_code(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint16_t *>(untyped_value);
  item = value;
}

size_t size_function__UpperMotorState__temperature(const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * get_const_function__UpperMotorState__temperature(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void * get_function__UpperMotorState__temperature(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void fetch_function__UpperMotorState__temperature(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__UpperMotorState__temperature(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__UpperMotorState__temperature(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__UpperMotorState__temperature(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__UpperMotorState__voltage(const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * get_const_function__UpperMotorState__voltage(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void * get_function__UpperMotorState__voltage(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void fetch_function__UpperMotorState__voltage(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__UpperMotorState__voltage(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__UpperMotorState__voltage(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__UpperMotorState__voltage(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__UpperMotorState__current(const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * get_const_function__UpperMotorState__current(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void * get_function__UpperMotorState__current(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 15> *>(untyped_member);
  return &member[index];
}

void fetch_function__UpperMotorState__current(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__UpperMotorState__current(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__UpperMotorState__current(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__UpperMotorState__current(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember UpperMotorState_message_member_array[12] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperMotorState, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "is_ready",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperMotorState, is_ready),  // bytes offset in struct
    nullptr,  // default value
    size_function__UpperMotorState__is_ready,  // size() function pointer
    get_const_function__UpperMotorState__is_ready,  // get_const(index) function pointer
    get_function__UpperMotorState__is_ready,  // get(index) function pointer
    fetch_function__UpperMotorState__is_ready,  // fetch(index, &value) function pointer
    assign_function__UpperMotorState__is_ready,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "is_enabled",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperMotorState, is_enabled),  // bytes offset in struct
    nullptr,  // default value
    size_function__UpperMotorState__is_enabled,  // size() function pointer
    get_const_function__UpperMotorState__is_enabled,  // get_const(index) function pointer
    get_function__UpperMotorState__is_enabled,  // get(index) function pointer
    fetch_function__UpperMotorState__is_enabled,  // fetch(index, &value) function pointer
    assign_function__UpperMotorState__is_enabled,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "has_fault",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperMotorState, has_fault),  // bytes offset in struct
    nullptr,  // default value
    size_function__UpperMotorState__has_fault,  // size() function pointer
    get_const_function__UpperMotorState__has_fault,  // get_const(index) function pointer
    get_function__UpperMotorState__has_fault,  // get(index) function pointer
    fetch_function__UpperMotorState__has_fault,  // fetch(index, &value) function pointer
    assign_function__UpperMotorState__has_fault,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "motor_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperMotorState, motor_id),  // bytes offset in struct
    nullptr,  // default value
    size_function__UpperMotorState__motor_id,  // size() function pointer
    get_const_function__UpperMotorState__motor_id,  // get_const(index) function pointer
    get_function__UpperMotorState__motor_id,  // get(index) function pointer
    fetch_function__UpperMotorState__motor_id,  // fetch(index, &value) function pointer
    assign_function__UpperMotorState__motor_id,  // assign(index, value) function pointer
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
    offsetof(ros2_interfaces::msg::UpperMotorState, position),  // bytes offset in struct
    nullptr,  // default value
    size_function__UpperMotorState__position,  // size() function pointer
    get_const_function__UpperMotorState__position,  // get_const(index) function pointer
    get_function__UpperMotorState__position,  // get(index) function pointer
    fetch_function__UpperMotorState__position,  // fetch(index, &value) function pointer
    assign_function__UpperMotorState__position,  // assign(index, value) function pointer
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
    offsetof(ros2_interfaces::msg::UpperMotorState, velocity),  // bytes offset in struct
    nullptr,  // default value
    size_function__UpperMotorState__velocity,  // size() function pointer
    get_const_function__UpperMotorState__velocity,  // get_const(index) function pointer
    get_function__UpperMotorState__velocity,  // get(index) function pointer
    fetch_function__UpperMotorState__velocity,  // fetch(index, &value) function pointer
    assign_function__UpperMotorState__velocity,  // assign(index, value) function pointer
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
    offsetof(ros2_interfaces::msg::UpperMotorState, effort),  // bytes offset in struct
    nullptr,  // default value
    size_function__UpperMotorState__effort,  // size() function pointer
    get_const_function__UpperMotorState__effort,  // get_const(index) function pointer
    get_function__UpperMotorState__effort,  // get(index) function pointer
    fetch_function__UpperMotorState__effort,  // fetch(index, &value) function pointer
    assign_function__UpperMotorState__effort,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "error_code",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperMotorState, error_code),  // bytes offset in struct
    nullptr,  // default value
    size_function__UpperMotorState__error_code,  // size() function pointer
    get_const_function__UpperMotorState__error_code,  // get_const(index) function pointer
    get_function__UpperMotorState__error_code,  // get(index) function pointer
    fetch_function__UpperMotorState__error_code,  // fetch(index, &value) function pointer
    assign_function__UpperMotorState__error_code,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "temperature",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperMotorState, temperature),  // bytes offset in struct
    nullptr,  // default value
    size_function__UpperMotorState__temperature,  // size() function pointer
    get_const_function__UpperMotorState__temperature,  // get_const(index) function pointer
    get_function__UpperMotorState__temperature,  // get(index) function pointer
    fetch_function__UpperMotorState__temperature,  // fetch(index, &value) function pointer
    assign_function__UpperMotorState__temperature,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "voltage",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperMotorState, voltage),  // bytes offset in struct
    nullptr,  // default value
    size_function__UpperMotorState__voltage,  // size() function pointer
    get_const_function__UpperMotorState__voltage,  // get_const(index) function pointer
    get_function__UpperMotorState__voltage,  // get(index) function pointer
    fetch_function__UpperMotorState__voltage,  // fetch(index, &value) function pointer
    assign_function__UpperMotorState__voltage,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "current",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperMotorState, current),  // bytes offset in struct
    nullptr,  // default value
    size_function__UpperMotorState__current,  // size() function pointer
    get_const_function__UpperMotorState__current,  // get_const(index) function pointer
    get_function__UpperMotorState__current,  // get(index) function pointer
    fetch_function__UpperMotorState__current,  // fetch(index, &value) function pointer
    assign_function__UpperMotorState__current,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers UpperMotorState_message_members = {
  "ros2_interfaces::msg",  // message namespace
  "UpperMotorState",  // message name
  12,  // number of fields
  sizeof(ros2_interfaces::msg::UpperMotorState),
  UpperMotorState_message_member_array,  // message members
  UpperMotorState_init_function,  // function to initialize message memory (memory has to be allocated)
  UpperMotorState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t UpperMotorState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &UpperMotorState_message_members,
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
get_message_type_support_handle<ros2_interfaces::msg::UpperMotorState>()
{
  return &::ros2_interfaces::msg::rosidl_typesupport_introspection_cpp::UpperMotorState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ros2_interfaces, msg, UpperMotorState)() {
  return &::ros2_interfaces::msg::rosidl_typesupport_introspection_cpp::UpperMotorState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
