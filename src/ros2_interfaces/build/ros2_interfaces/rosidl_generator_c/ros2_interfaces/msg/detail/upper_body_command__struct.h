// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_interfaces:msg/UpperBodyCommand.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_COMMAND__STRUCT_H_
#define ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'STOP'.
/**
  * Command modes
 */
enum
{
  ros2_interfaces__msg__UpperBodyCommand__STOP = 0
};

/// Constant 'POSITION'.
enum
{
  ros2_interfaces__msg__UpperBodyCommand__POSITION = 1
};

/// Constant 'VELOCITY'.
enum
{
  ros2_interfaces__msg__UpperBodyCommand__VELOCITY = 2
};

/// Constant 'TORQUE'.
enum
{
  ros2_interfaces__msg__UpperBodyCommand__TORQUE = 3
};

/// Constant 'POSITION_VELOCITY'.
enum
{
  ros2_interfaces__msg__UpperBodyCommand__POSITION_VELOCITY = 4
};

/// Constant 'IMPEDANCE'.
enum
{
  ros2_interfaces__msg__UpperBodyCommand__IMPEDANCE = 5
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/UpperBodyCommand in the package ros2_interfaces.
/**
  * Upper body command for 15 motors.
 */
typedef struct ros2_interfaces__msg__UpperBodyCommand
{
  std_msgs__msg__Header header;
  uint8_t command_mode;
  uint8_t motor_id[15];
  float position[15];
  float velocity[15];
  float effort[15];
  float kp[15];
  float kd[15];
  float duration;
} ros2_interfaces__msg__UpperBodyCommand;

// Struct for a sequence of ros2_interfaces__msg__UpperBodyCommand.
typedef struct ros2_interfaces__msg__UpperBodyCommand__Sequence
{
  ros2_interfaces__msg__UpperBodyCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_interfaces__msg__UpperBodyCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_COMMAND__STRUCT_H_
