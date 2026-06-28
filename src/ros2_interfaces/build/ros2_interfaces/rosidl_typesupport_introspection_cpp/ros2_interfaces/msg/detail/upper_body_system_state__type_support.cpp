// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ros2_interfaces:msg/UpperBodySystemState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ros2_interfaces/msg/detail/upper_body_system_state__struct.hpp"
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

void UpperBodySystemState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ros2_interfaces::msg::UpperBodySystemState(_init);
}

void UpperBodySystemState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ros2_interfaces::msg::UpperBodySystemState *>(message_memory);
  typed_message->~UpperBodySystemState();
}

size_t size_function__UpperBodySystemState__is_connected(const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * get_const_function__UpperBodySystemState__is_connected(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<bool, 15> *>(untyped_member);
  return &member[index];
}

void * get_function__UpperBodySystemState__is_connected(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<bool, 15> *>(untyped_member);
  return &member[index];
}

void fetch_function__UpperBodySystemState__is_connected(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const bool *>(
    get_const_function__UpperBodySystemState__is_connected(untyped_member, index));
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = item;
}

void assign_function__UpperBodySystemState__is_connected(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<bool *>(
    get_function__UpperBodySystemState__is_connected(untyped_member, index));
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember UpperBodySystemState_message_member_array[9] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperBodySystemState, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperBodySystemState, state),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "run_mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperBodySystemState, run_mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "ready_motor_count",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperBodySystemState, ready_motor_count),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "enabled_motor_count",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperBodySystemState, enabled_motor_count),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "fault_motor_count",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperBodySystemState, fault_motor_count),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "is_connected",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperBodySystemState, is_connected),  // bytes offset in struct
    nullptr,  // default value
    size_function__UpperBodySystemState__is_connected,  // size() function pointer
    get_const_function__UpperBodySystemState__is_connected,  // get_const(index) function pointer
    get_function__UpperBodySystemState__is_connected,  // get(index) function pointer
    fetch_function__UpperBodySystemState__is_connected,  // fetch(index, &value) function pointer
    assign_function__UpperBodySystemState__is_connected,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "all_motors_enabled",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperBodySystemState, all_motors_enabled),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "command_accepted",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::UpperBodySystemState, command_accepted),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers UpperBodySystemState_message_members = {
  "ros2_interfaces::msg",  // message namespace
  "UpperBodySystemState",  // message name
  9,  // number of fields
  sizeof(ros2_interfaces::msg::UpperBodySystemState),
  UpperBodySystemState_message_member_array,  // message members
  UpperBodySystemState_init_function,  // function to initialize message memory (memory has to be allocated)
  UpperBodySystemState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t UpperBodySystemState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &UpperBodySystemState_message_members,
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
get_message_type_support_handle<ros2_interfaces::msg::UpperBodySystemState>()
{
  return &::ros2_interfaces::msg::rosidl_typesupport_introspection_cpp::UpperBodySystemState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ros2_interfaces, msg, UpperBodySystemState)() {
  return &::ros2_interfaces::msg::rosidl_typesupport_introspection_cpp::UpperBodySystemState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
