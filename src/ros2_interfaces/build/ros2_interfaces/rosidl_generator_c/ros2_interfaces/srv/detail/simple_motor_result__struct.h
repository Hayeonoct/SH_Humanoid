// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_interfaces:srv/SimpleMotorResult.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__SRV__DETAIL__SIMPLE_MOTOR_RESULT__STRUCT_H_
#define ROS2_INTERFACES__SRV__DETAIL__SIMPLE_MOTOR_RESULT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'motor_id_list'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/SimpleMotorResult in the package ros2_interfaces.
typedef struct ros2_interfaces__srv__SimpleMotorResult_Request
{
  rosidl_runtime_c__uint8__Sequence motor_id_list;
} ros2_interfaces__srv__SimpleMotorResult_Request;

// Struct for a sequence of ros2_interfaces__srv__SimpleMotorResult_Request.
typedef struct ros2_interfaces__srv__SimpleMotorResult_Request__Sequence
{
  ros2_interfaces__srv__SimpleMotorResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_interfaces__srv__SimpleMotorResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SimpleMotorResult in the package ros2_interfaces.
typedef struct ros2_interfaces__srv__SimpleMotorResult_Response
{
  bool success;
  rosidl_runtime_c__String message;
} ros2_interfaces__srv__SimpleMotorResult_Response;

// Struct for a sequence of ros2_interfaces__srv__SimpleMotorResult_Response.
typedef struct ros2_interfaces__srv__SimpleMotorResult_Response__Sequence
{
  ros2_interfaces__srv__SimpleMotorResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_interfaces__srv__SimpleMotorResult_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_INTERFACES__SRV__DETAIL__SIMPLE_MOTOR_RESULT__STRUCT_H_
