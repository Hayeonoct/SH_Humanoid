// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_interfaces:msg/UpperBodySystemState.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_SYSTEM_STATE__STRUCT_H_
#define ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_SYSTEM_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'POWER_OFF'.
/**
  * FSM states
 */
enum
{
  ros2_interfaces__msg__UpperBodySystemState__POWER_OFF = 0
};

/// Constant 'DRIVER_INIT'.
enum
{
  ros2_interfaces__msg__UpperBodySystemState__DRIVER_INIT = 1
};

/// Constant 'READY'.
enum
{
  ros2_interfaces__msg__UpperBodySystemState__READY = 2
};

/// Constant 'ENABLING'.
enum
{
  ros2_interfaces__msg__UpperBodySystemState__ENABLING = 3
};

/// Constant 'ENABLED'.
enum
{
  ros2_interfaces__msg__UpperBodySystemState__ENABLED = 4
};

/// Constant 'RUNNING'.
enum
{
  ros2_interfaces__msg__UpperBodySystemState__RUNNING = 5
};

/// Constant 'FAULT'.
enum
{
  ros2_interfaces__msg__UpperBodySystemState__FAULT = 6
};

/// Constant 'MODE_IDLE'.
/**
  * Run mode values (SamHyun OD 0x7005)
 */
enum
{
  ros2_interfaces__msg__UpperBodySystemState__MODE_IDLE = 0
};

/// Constant 'MODE_TORQUE'.
enum
{
  ros2_interfaces__msg__UpperBodySystemState__MODE_TORQUE = 1
};

/// Constant 'MODE_VELOCITY'.
enum
{
  ros2_interfaces__msg__UpperBodySystemState__MODE_VELOCITY = 2
};

/// Constant 'MODE_POSITION'.
enum
{
  ros2_interfaces__msg__UpperBodySystemState__MODE_POSITION = 3
};

/// Constant 'MODE_IMPEDANCE'.
enum
{
  ros2_interfaces__msg__UpperBodySystemState__MODE_IMPEDANCE = 4
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/UpperBodySystemState in the package ros2_interfaces.
/**
  * Upper body system-level state.
 */
typedef struct ros2_interfaces__msg__UpperBodySystemState
{
  std_msgs__msg__Header header;
  uint8_t state;
  uint8_t run_mode;
  uint8_t ready_motor_count;
  uint8_t enabled_motor_count;
  uint8_t fault_motor_count;
  bool is_connected[15];
  bool all_motors_enabled;
  bool command_accepted;
} ros2_interfaces__msg__UpperBodySystemState;

// Struct for a sequence of ros2_interfaces__msg__UpperBodySystemState.
typedef struct ros2_interfaces__msg__UpperBodySystemState__Sequence
{
  ros2_interfaces__msg__UpperBodySystemState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_interfaces__msg__UpperBodySystemState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_SYSTEM_STATE__STRUCT_H_
