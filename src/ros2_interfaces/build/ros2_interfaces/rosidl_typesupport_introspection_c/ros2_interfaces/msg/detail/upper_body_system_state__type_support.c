// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ros2_interfaces:msg/UpperBodySystemState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ros2_interfaces/msg/detail/upper_body_system_state__rosidl_typesupport_introspection_c.h"
#include "ros2_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ros2_interfaces/msg/detail/upper_body_system_state__functions.h"
#include "ros2_interfaces/msg/detail/upper_body_system_state__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__UpperBodySystemState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ros2_interfaces__msg__UpperBodySystemState__init(message_memory);
}

void ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__UpperBodySystemState_fini_function(void * message_memory)
{
  ros2_interfaces__msg__UpperBodySystemState__fini(message_memory);
}

size_t ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__size_function__UpperBodySystemState__is_connected(
  const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__get_const_function__UpperBodySystemState__is_connected(
  const void * untyped_member, size_t index)
{
  const bool * member =
    (const bool *)(untyped_member);
  return &member[index];
}

void * ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__get_function__UpperBodySystemState__is_connected(
  void * untyped_member, size_t index)
{
  bool * member =
    (bool *)(untyped_member);
  return &member[index];
}

void ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__fetch_function__UpperBodySystemState__is_connected(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const bool * item =
    ((const bool *)
    ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__get_const_function__UpperBodySystemState__is_connected(untyped_member, index));
  bool * value =
    (bool *)(untyped_value);
  *value = *item;
}

void ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__assign_function__UpperBodySystemState__is_connected(
  void * untyped_member, size_t index, const void * untyped_value)
{
  bool * item =
    ((bool *)
    ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__get_function__UpperBodySystemState__is_connected(untyped_member, index));
  const bool * value =
    (const bool *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__UpperBodySystemState_message_member_array[9] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperBodySystemState, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperBodySystemState, state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "run_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperBodySystemState, run_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ready_motor_count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperBodySystemState, ready_motor_count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "enabled_motor_count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperBodySystemState, enabled_motor_count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "fault_motor_count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperBodySystemState, fault_motor_count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_connected",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperBodySystemState, is_connected),  // bytes offset in struct
    NULL,  // default value
    ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__size_function__UpperBodySystemState__is_connected,  // size() function pointer
    ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__get_const_function__UpperBodySystemState__is_connected,  // get_const(index) function pointer
    ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__get_function__UpperBodySystemState__is_connected,  // get(index) function pointer
    ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__fetch_function__UpperBodySystemState__is_connected,  // fetch(index, &value) function pointer
    ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__assign_function__UpperBodySystemState__is_connected,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "all_motors_enabled",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperBodySystemState, all_motors_enabled),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "command_accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperBodySystemState, command_accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__UpperBodySystemState_message_members = {
  "ros2_interfaces__msg",  // message namespace
  "UpperBodySystemState",  // message name
  9,  // number of fields
  sizeof(ros2_interfaces__msg__UpperBodySystemState),
  ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__UpperBodySystemState_message_member_array,  // message members
  ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__UpperBodySystemState_init_function,  // function to initialize message memory (memory has to be allocated)
  ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__UpperBodySystemState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__UpperBodySystemState_message_type_support_handle = {
  0,
  &ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__UpperBodySystemState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_interfaces, msg, UpperBodySystemState)() {
  ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__UpperBodySystemState_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__UpperBodySystemState_message_type_support_handle.typesupport_identifier) {
    ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__UpperBodySystemState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ros2_interfaces__msg__UpperBodySystemState__rosidl_typesupport_introspection_c__UpperBodySystemState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
