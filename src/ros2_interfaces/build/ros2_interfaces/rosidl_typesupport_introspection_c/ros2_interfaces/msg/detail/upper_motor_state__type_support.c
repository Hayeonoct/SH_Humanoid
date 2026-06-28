// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ros2_interfaces:msg/UpperMotorState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ros2_interfaces/msg/detail/upper_motor_state__rosidl_typesupport_introspection_c.h"
#include "ros2_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ros2_interfaces/msg/detail/upper_motor_state__functions.h"
#include "ros2_interfaces/msg/detail/upper_motor_state__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__UpperMotorState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ros2_interfaces__msg__UpperMotorState__init(message_memory);
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__UpperMotorState_fini_function(void * message_memory)
{
  ros2_interfaces__msg__UpperMotorState__fini(message_memory);
}

size_t ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__is_ready(
  const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__is_ready(
  const void * untyped_member, size_t index)
{
  const bool * member =
    (const bool *)(untyped_member);
  return &member[index];
}

void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__is_ready(
  void * untyped_member, size_t index)
{
  bool * member =
    (bool *)(untyped_member);
  return &member[index];
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__is_ready(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const bool * item =
    ((const bool *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__is_ready(untyped_member, index));
  bool * value =
    (bool *)(untyped_value);
  *value = *item;
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__is_ready(
  void * untyped_member, size_t index, const void * untyped_value)
{
  bool * item =
    ((bool *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__is_ready(untyped_member, index));
  const bool * value =
    (const bool *)(untyped_value);
  *item = *value;
}

size_t ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__is_enabled(
  const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__is_enabled(
  const void * untyped_member, size_t index)
{
  const bool * member =
    (const bool *)(untyped_member);
  return &member[index];
}

void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__is_enabled(
  void * untyped_member, size_t index)
{
  bool * member =
    (bool *)(untyped_member);
  return &member[index];
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__is_enabled(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const bool * item =
    ((const bool *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__is_enabled(untyped_member, index));
  bool * value =
    (bool *)(untyped_value);
  *value = *item;
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__is_enabled(
  void * untyped_member, size_t index, const void * untyped_value)
{
  bool * item =
    ((bool *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__is_enabled(untyped_member, index));
  const bool * value =
    (const bool *)(untyped_value);
  *item = *value;
}

size_t ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__has_fault(
  const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__has_fault(
  const void * untyped_member, size_t index)
{
  const bool * member =
    (const bool *)(untyped_member);
  return &member[index];
}

void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__has_fault(
  void * untyped_member, size_t index)
{
  bool * member =
    (bool *)(untyped_member);
  return &member[index];
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__has_fault(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const bool * item =
    ((const bool *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__has_fault(untyped_member, index));
  bool * value =
    (bool *)(untyped_value);
  *value = *item;
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__has_fault(
  void * untyped_member, size_t index, const void * untyped_value)
{
  bool * item =
    ((bool *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__has_fault(untyped_member, index));
  const bool * value =
    (const bool *)(untyped_value);
  *item = *value;
}

size_t ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__motor_id(
  const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__motor_id(
  const void * untyped_member, size_t index)
{
  const uint16_t * member =
    (const uint16_t *)(untyped_member);
  return &member[index];
}

void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__motor_id(
  void * untyped_member, size_t index)
{
  uint16_t * member =
    (uint16_t *)(untyped_member);
  return &member[index];
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__motor_id(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint16_t * item =
    ((const uint16_t *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__motor_id(untyped_member, index));
  uint16_t * value =
    (uint16_t *)(untyped_value);
  *value = *item;
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__motor_id(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint16_t * item =
    ((uint16_t *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__motor_id(untyped_member, index));
  const uint16_t * value =
    (const uint16_t *)(untyped_value);
  *item = *value;
}

size_t ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__position(
  const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__position(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__position(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__position(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__position(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__velocity(
  const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__velocity(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__velocity(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__velocity(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__velocity(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__velocity(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__velocity(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__effort(
  const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__effort(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__effort(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__effort(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__effort(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__effort(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__effort(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__error_code(
  const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__error_code(
  const void * untyped_member, size_t index)
{
  const uint16_t * member =
    (const uint16_t *)(untyped_member);
  return &member[index];
}

void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__error_code(
  void * untyped_member, size_t index)
{
  uint16_t * member =
    (uint16_t *)(untyped_member);
  return &member[index];
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__error_code(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint16_t * item =
    ((const uint16_t *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__error_code(untyped_member, index));
  uint16_t * value =
    (uint16_t *)(untyped_value);
  *value = *item;
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__error_code(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint16_t * item =
    ((uint16_t *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__error_code(untyped_member, index));
  const uint16_t * value =
    (const uint16_t *)(untyped_value);
  *item = *value;
}

size_t ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__temperature(
  const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__temperature(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__temperature(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__temperature(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__temperature(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__temperature(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__temperature(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__voltage(
  const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__voltage(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__voltage(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__voltage(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__voltage(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__voltage(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__voltage(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__current(
  const void * untyped_member)
{
  (void)untyped_member;
  return 15;
}

const void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__current(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__current(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__current(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__current(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__current(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__current(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__UpperMotorState_message_member_array[12] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperMotorState, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_ready",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperMotorState, is_ready),  // bytes offset in struct
    NULL,  // default value
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__is_ready,  // size() function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__is_ready,  // get_const(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__is_ready,  // get(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__is_ready,  // fetch(index, &value) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__is_ready,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_enabled",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperMotorState, is_enabled),  // bytes offset in struct
    NULL,  // default value
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__is_enabled,  // size() function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__is_enabled,  // get_const(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__is_enabled,  // get(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__is_enabled,  // fetch(index, &value) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__is_enabled,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "has_fault",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperMotorState, has_fault),  // bytes offset in struct
    NULL,  // default value
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__has_fault,  // size() function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__has_fault,  // get_const(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__has_fault,  // get(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__has_fault,  // fetch(index, &value) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__has_fault,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "motor_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperMotorState, motor_id),  // bytes offset in struct
    NULL,  // default value
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__motor_id,  // size() function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__motor_id,  // get_const(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__motor_id,  // get(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__motor_id,  // fetch(index, &value) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__motor_id,  // assign(index, value) function pointer
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
    offsetof(ros2_interfaces__msg__UpperMotorState, position),  // bytes offset in struct
    NULL,  // default value
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__position,  // size() function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__position,  // get_const(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__position,  // get(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__position,  // fetch(index, &value) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__position,  // assign(index, value) function pointer
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
    offsetof(ros2_interfaces__msg__UpperMotorState, velocity),  // bytes offset in struct
    NULL,  // default value
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__velocity,  // size() function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__velocity,  // get_const(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__velocity,  // get(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__velocity,  // fetch(index, &value) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__velocity,  // assign(index, value) function pointer
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
    offsetof(ros2_interfaces__msg__UpperMotorState, effort),  // bytes offset in struct
    NULL,  // default value
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__effort,  // size() function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__effort,  // get_const(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__effort,  // get(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__effort,  // fetch(index, &value) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__effort,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error_code",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperMotorState, error_code),  // bytes offset in struct
    NULL,  // default value
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__error_code,  // size() function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__error_code,  // get_const(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__error_code,  // get(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__error_code,  // fetch(index, &value) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__error_code,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "temperature",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperMotorState, temperature),  // bytes offset in struct
    NULL,  // default value
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__temperature,  // size() function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__temperature,  // get_const(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__temperature,  // get(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__temperature,  // fetch(index, &value) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__temperature,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "voltage",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperMotorState, voltage),  // bytes offset in struct
    NULL,  // default value
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__voltage,  // size() function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__voltage,  // get_const(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__voltage,  // get(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__voltage,  // fetch(index, &value) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__voltage,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__UpperMotorState, current),  // bytes offset in struct
    NULL,  // default value
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__size_function__UpperMotorState__current,  // size() function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_const_function__UpperMotorState__current,  // get_const(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__get_function__UpperMotorState__current,  // get(index) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__fetch_function__UpperMotorState__current,  // fetch(index, &value) function pointer
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__assign_function__UpperMotorState__current,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__UpperMotorState_message_members = {
  "ros2_interfaces__msg",  // message namespace
  "UpperMotorState",  // message name
  12,  // number of fields
  sizeof(ros2_interfaces__msg__UpperMotorState),
  ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__UpperMotorState_message_member_array,  // message members
  ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__UpperMotorState_init_function,  // function to initialize message memory (memory has to be allocated)
  ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__UpperMotorState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__UpperMotorState_message_type_support_handle = {
  0,
  &ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__UpperMotorState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_interfaces, msg, UpperMotorState)() {
  ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__UpperMotorState_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__UpperMotorState_message_type_support_handle.typesupport_identifier) {
    ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__UpperMotorState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ros2_interfaces__msg__UpperMotorState__rosidl_typesupport_introspection_c__UpperMotorState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
