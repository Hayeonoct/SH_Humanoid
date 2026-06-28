// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_interfaces:msg/UpperMotorState.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__MSG__DETAIL__UPPER_MOTOR_STATE__STRUCT_H_
#define ROS2_INTERFACES__MSG__DETAIL__UPPER_MOTOR_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/UpperMotorState in the package ros2_interfaces.
/**
  * Upper motor state feedback for 15 motors.
 */
typedef struct ros2_interfaces__msg__UpperMotorState
{
  std_msgs__msg__Header header;
  bool is_ready[15];
  bool is_enabled[15];
  bool has_fault[15];
  uint16_t motor_id[15];
  float position[15];
  float velocity[15];
  float effort[15];
  uint16_t error_code[15];
  float temperature[15];
  float voltage[15];
  float current[15];
} ros2_interfaces__msg__UpperMotorState;

// Struct for a sequence of ros2_interfaces__msg__UpperMotorState.
typedef struct ros2_interfaces__msg__UpperMotorState__Sequence
{
  ros2_interfaces__msg__UpperMotorState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_interfaces__msg__UpperMotorState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_INTERFACES__MSG__DETAIL__UPPER_MOTOR_STATE__STRUCT_H_
