// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ros2_interfaces:msg/UpperBodyCommand.idl
// generated code does not contain a copyright notice
#include "ros2_interfaces/msg/detail/upper_body_command__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ros2_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ros2_interfaces/msg/detail/upper_body_command__struct.h"
#include "ros2_interfaces/msg/detail/upper_body_command__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros2_interfaces
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros2_interfaces
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros2_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _UpperBodyCommand__ros_msg_type = ros2_interfaces__msg__UpperBodyCommand;

static bool _UpperBodyCommand__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _UpperBodyCommand__ros_msg_type * ros_message = static_cast<const _UpperBodyCommand__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: command_mode
  {
    cdr << ros_message->command_mode;
  }

  // Field name: motor_id
  {
    size_t size = 15;
    auto array_ptr = ros_message->motor_id;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: position
  {
    size_t size = 15;
    auto array_ptr = ros_message->position;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: velocity
  {
    size_t size = 15;
    auto array_ptr = ros_message->velocity;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: effort
  {
    size_t size = 15;
    auto array_ptr = ros_message->effort;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: kp
  {
    size_t size = 15;
    auto array_ptr = ros_message->kp;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: kd
  {
    size_t size = 15;
    auto array_ptr = ros_message->kd;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: duration
  {
    cdr << ros_message->duration;
  }

  return true;
}

static bool _UpperBodyCommand__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _UpperBodyCommand__ros_msg_type * ros_message = static_cast<_UpperBodyCommand__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: command_mode
  {
    cdr >> ros_message->command_mode;
  }

  // Field name: motor_id
  {
    size_t size = 15;
    auto array_ptr = ros_message->motor_id;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: position
  {
    size_t size = 15;
    auto array_ptr = ros_message->position;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: velocity
  {
    size_t size = 15;
    auto array_ptr = ros_message->velocity;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: effort
  {
    size_t size = 15;
    auto array_ptr = ros_message->effort;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: kp
  {
    size_t size = 15;
    auto array_ptr = ros_message->kp;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: kd
  {
    size_t size = 15;
    auto array_ptr = ros_message->kd;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: duration
  {
    cdr >> ros_message->duration;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_interfaces
size_t get_serialized_size_ros2_interfaces__msg__UpperBodyCommand(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _UpperBodyCommand__ros_msg_type * ros_message = static_cast<const _UpperBodyCommand__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name command_mode
  {
    size_t item_size = sizeof(ros_message->command_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name motor_id
  {
    size_t array_size = 15;
    auto array_ptr = ros_message->motor_id;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name position
  {
    size_t array_size = 15;
    auto array_ptr = ros_message->position;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name velocity
  {
    size_t array_size = 15;
    auto array_ptr = ros_message->velocity;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name effort
  {
    size_t array_size = 15;
    auto array_ptr = ros_message->effort;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name kp
  {
    size_t array_size = 15;
    auto array_ptr = ros_message->kp;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name kd
  {
    size_t array_size = 15;
    auto array_ptr = ros_message->kd;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name duration
  {
    size_t item_size = sizeof(ros_message->duration);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _UpperBodyCommand__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ros2_interfaces__msg__UpperBodyCommand(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_interfaces
size_t max_serialized_size_ros2_interfaces__msg__UpperBodyCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: command_mode
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: motor_id
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: position
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: velocity
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: effort
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: kp
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: kd
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: duration
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _UpperBodyCommand__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ros2_interfaces__msg__UpperBodyCommand(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_UpperBodyCommand = {
  "ros2_interfaces::msg",
  "UpperBodyCommand",
  _UpperBodyCommand__cdr_serialize,
  _UpperBodyCommand__cdr_deserialize,
  _UpperBodyCommand__get_serialized_size,
  _UpperBodyCommand__max_serialized_size
};

static rosidl_message_type_support_t _UpperBodyCommand__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_UpperBodyCommand,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_interfaces, msg, UpperBodyCommand)() {
  return &_UpperBodyCommand__type_support;
}

#if defined(__cplusplus)
}
#endif
