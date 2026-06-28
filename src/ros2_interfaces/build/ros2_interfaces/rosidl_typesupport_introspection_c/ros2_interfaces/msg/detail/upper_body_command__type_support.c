// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ros2_interfaces:msg/UpperBodyCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ros2_interfaces/msg/detail/upper_body_command__rosidl_typesupport_introspection_c.h"
#include "ros2_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ros2_interfaces/msg/detail/upper_body_command__functions.h"
#include "ros2_interfaces/msg/detail/upper_body_command__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__UpperBodyCommand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ros2_interfaces__msg__UpperBodyCommand__init(message_memory);
}

void ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__UpperBodyCommand_fini_function(void * message_memory)
{
  ros2_interfaces__msg__UpperBodyCommand__fini(message_memory);
}

size_t ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__size_function__UpperBodyCommand__motor_id(
  const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_const_function__UpperBodyCommand__motor_id(
  const void * untyped_member, size_t index)
{
  const uint8_t * member =
    (const uint8_t *)(untyped_member);
  return &member[index];
}

void * ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_function__UpperBodyCommand__motor_id(
  void * untyped_member, size_t index)
{
  uint8_t * member =
    (uint8_t *)(untyped_member);
  return &member[index];
}

void ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__fetch_function__UpperBodyCommand__motor_id(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_const_function__UpperBodyCommand__motor_id(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__assign_function__UpperBodyCommand__motor_id(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_function__UpperBodyCommand__motor_id(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

size_t ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__size_function__UpperBodyCommand__position(
  const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_const_function__UpperBodyCommand__position(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_function__UpperBodyCommand__position(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__fetch_function__UpperBodyCommand__position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_const_function__UpperBodyCommand__position(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__assign_function__UpperBodyCommand__position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_function__UpperBodyCommand__position(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__size_function__UpperBodyCommand__velocity(
  const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_const_function__UpperBodyCommand__velocity(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_function__UpperBodyCommand__velocity(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__fetch_function__UpperBodyCommand__velocity(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_const_function__UpperBodyCommand__velocity(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__assign_function__UpperBodyCommand__velocity(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_function__UpperBodyCommand__velocity(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__size_function__UpperBodyCommand__effort(
  const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_const_function__UpperBodyCommand__effort(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_function__UpperBodyCommand__effort(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__fetch_function__UpperBodyCommand__effort(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_const_function__UpperBodyCommand__effort(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__assign_function__UpperBodyCommand__effort(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_function__UpperBodyCommand__effort(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__size_function__UpperBodyCommand__kp(
  const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_const_function__UpperBodyCommand__kp(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_function__UpperBodyCommand__kp(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__fetch_function__UpperBodyCommand__kp(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_const_function__UpperBodyCommand__kp(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__assign_function__UpperBodyCommand__kp(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_function__UpperBodyCommand__kp(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__size_function__UpperBodyCommand__kd(
  const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_const_function__UpperBodyCommand__kd(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_function__UpperBodyCommand__kd(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__fetch_function__UpperBodyCommand__kd(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_const_function__UpperBodyCommand__kd(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__assign_function__UpperBodyCommand__kd(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_function__UpperBodyCommand__kd(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__UpperBodyCommand_message_member_array[9] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperBodyCommand, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "command_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperBodyCommand, command_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "motor_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperBodyCommand, motor_id),  // bytes offset in struct
    NULL,  // default value
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__size_function__UpperBodyCommand__motor_id,  // size() function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_const_function__UpperBodyCommand__motor_id,  // get_const(index) function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_function__UpperBodyCommand__motor_id,  // get(index) function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__fetch_function__UpperBodyCommand__motor_id,  // fetch(index, &value) function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__assign_function__UpperBodyCommand__motor_id,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperBodyCommand, position),  // bytes offset in struct
    NULL,  // default value
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__size_function__UpperBodyCommand__position,  // size() function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_const_function__UpperBodyCommand__position,  // get_const(index) function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_function__UpperBodyCommand__position,  // get(index) function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__fetch_function__UpperBodyCommand__position,  // fetch(index, &value) function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__assign_function__UpperBodyCommand__position,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperBodyCommand, velocity),  // bytes offset in struct
    NULL,  // default value
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__size_function__UpperBodyCommand__velocity,  // size() function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_const_function__UpperBodyCommand__velocity,  // get_const(index) function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_function__UpperBodyCommand__velocity,  // get(index) function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__fetch_function__UpperBodyCommand__velocity,  // fetch(index, &value) function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__assign_function__UpperBodyCommand__velocity,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "effort",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperBodyCommand, effort),  // bytes offset in struct
    NULL,  // default value
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__size_function__UpperBodyCommand__effort,  // size() function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_const_function__UpperBodyCommand__effort,  // get_const(index) function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_function__UpperBodyCommand__effort,  // get(index) function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__fetch_function__UpperBodyCommand__effort,  // fetch(index, &value) function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__assign_function__UpperBodyCommand__effort,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "kp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperBodyCommand, kp),  // bytes offset in struct
    NULL,  // default value
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__size_function__UpperBodyCommand__kp,  // size() function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_const_function__UpperBodyCommand__kp,  // get_const(index) function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_function__UpperBodyCommand__kp,  // get(index) function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__fetch_function__UpperBodyCommand__kp,  // fetch(index, &value) function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__assign_function__UpperBodyCommand__kp,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "kd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperBodyCommand, kd),  // bytes offset in struct
    NULL,  // default value
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__size_function__UpperBodyCommand__kd,  // size() function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_const_function__UpperBodyCommand__kd,  // get_const(index) function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__get_function__UpperBodyCommand__kd,  // get(index) function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__fetch_function__UpperBodyCommand__kd,  // fetch(index, &value) function pointer
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__assign_function__UpperBodyCommand__kd,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "duration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperBodyCommand, duration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__UpperBodyCommand_message_members = {
  "ros2_interfaces__msg",  // message namespace
  "UpperBodyCommand",  // message name
  9,  // number of fields
  sizeof(ros2_interfaces__msg__UpperBodyCommand),
  ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__UpperBodyCommand_message_member_array,  // message members
  ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__UpperBodyCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__UpperBodyCommand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__UpperBodyCommand_message_type_support_handle = {
  0,
  &ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__UpperBodyCommand_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_interfaces, msg, UpperBodyCommand)() {
  ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__UpperBodyCommand_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__UpperBodyCommand_message_type_support_handle.typesupport_identifier) {
    ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__UpperBodyCommand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ros2_interfaces__msg__UpperBodyCommand__rosidl_typesupport_introspection_c__UpperBodyCommand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
