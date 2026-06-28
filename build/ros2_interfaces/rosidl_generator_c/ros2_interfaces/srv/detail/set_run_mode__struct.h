// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_interfaces:srv/SetRunMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros2_interfaces/srv/set_run_mode.h"


#ifndef ROS2_INTERFACES__SRV__DETAIL__SET_RUN_MODE__STRUCT_H_
#define ROS2_INTERFACES__SRV__DETAIL__SET_RUN_MODE__STRUCT_H_

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

/// Struct defined in srv/SetRunMode in the package ros2_interfaces.
typedef struct ros2_interfaces__srv__SetRunMode_Request
{
  uint8_t mode;
  rosidl_runtime_c__uint8__Sequence motor_id_list;
} ros2_interfaces__srv__SetRunMode_Request;

// Struct for a sequence of ros2_interfaces__srv__SetRunMode_Request.
typedef struct ros2_interfaces__srv__SetRunMode_Request__Sequence
{
  ros2_interfaces__srv__SetRunMode_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_interfaces__srv__SetRunMode_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"
// Member 'applied_motor_ids'
// Member 'failed_motor_ids'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/SetRunMode in the package ros2_interfaces.
typedef struct ros2_interfaces__srv__SetRunMode_Response
{
  bool success;
  rosidl_runtime_c__String message;
  rosidl_runtime_c__uint8__Sequence applied_motor_ids;
  rosidl_runtime_c__uint8__Sequence failed_motor_ids;
} ros2_interfaces__srv__SetRunMode_Response;

// Struct for a sequence of ros2_interfaces__srv__SetRunMode_Response.
typedef struct ros2_interfaces__srv__SetRunMode_Response__Sequence
{
  ros2_interfaces__srv__SetRunMode_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_interfaces__srv__SetRunMode_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  ros2_interfaces__srv__SetRunMode_Event__request__MAX_SIZE = 1
};
// response
enum
{
  ros2_interfaces__srv__SetRunMode_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SetRunMode in the package ros2_interfaces.
typedef struct ros2_interfaces__srv__SetRunMode_Event
{
  service_msgs__msg__ServiceEventInfo info;
  ros2_interfaces__srv__SetRunMode_Request__Sequence request;
  ros2_interfaces__srv__SetRunMode_Response__Sequence response;
} ros2_interfaces__srv__SetRunMode_Event;

// Struct for a sequence of ros2_interfaces__srv__SetRunMode_Event.
typedef struct ros2_interfaces__srv__SetRunMode_Event__Sequence
{
  ros2_interfaces__srv__SetRunMode_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_interfaces__srv__SetRunMode_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_INTERFACES__SRV__DETAIL__SET_RUN_MODE__STRUCT_H_
