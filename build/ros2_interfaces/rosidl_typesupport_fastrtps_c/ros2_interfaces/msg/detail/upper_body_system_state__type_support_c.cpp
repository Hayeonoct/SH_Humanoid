// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ros2_interfaces:msg/UpperBodySystemState.idl
// generated code does not contain a copyright notice
#include "ros2_interfaces/msg/detail/upper_body_system_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ros2_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ros2_interfaces/msg/detail/upper_body_system_state__struct.h"
#include "ros2_interfaces/msg/detail/upper_body_system_state__functions.h"
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
bool cdr_serialize_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros2_interfaces
bool cdr_deserialize_std_msgs__msg__Header(
  eprosima::fastcdr::Cdr & cdr,
  std_msgs__msg__Header * ros_message);

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
bool cdr_serialize_key_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros2_interfaces
size_t get_serialized_size_key_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros2_interfaces
size_t max_serialized_size_key_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros2_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _UpperBodySystemState__ros_msg_type = ros2_interfaces__msg__UpperBodySystemState;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_interfaces
bool cdr_serialize_ros2_interfaces__msg__UpperBodySystemState(
  const ros2_interfaces__msg__UpperBodySystemState * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: state
  {
    cdr << ros_message->state;
  }

  // Field name: run_mode
  {
    cdr << ros_message->run_mode;
  }

  // Field name: ready_motor_count
  {
    cdr << ros_message->ready_motor_count;
  }

  // Field name: enabled_motor_count
  {
    cdr << ros_message->enabled_motor_count;
  }

  // Field name: fault_motor_count
  {
    cdr << ros_message->fault_motor_count;
  }

  // Field name: is_connected
  {
    size_t size = 15;
    auto array_ptr = ros_message->is_connected;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: all_motors_enabled
  {
    cdr << (ros_message->all_motors_enabled ? true : false);
  }

  // Field name: command_accepted
  {
    cdr << (ros_message->command_accepted ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_interfaces
bool cdr_deserialize_ros2_interfaces__msg__UpperBodySystemState(
  eprosima::fastcdr::Cdr & cdr,
  ros2_interfaces__msg__UpperBodySystemState * ros_message)
{
  // Field name: header
  {
    cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: state
  {
    cdr >> ros_message->state;
  }

  // Field name: run_mode
  {
    cdr >> ros_message->run_mode;
  }

  // Field name: ready_motor_count
  {
    cdr >> ros_message->ready_motor_count;
  }

  // Field name: enabled_motor_count
  {
    cdr >> ros_message->enabled_motor_count;
  }

  // Field name: fault_motor_count
  {
    cdr >> ros_message->fault_motor_count;
  }

  // Field name: is_connected
  {
    size_t size = 15;
    auto array_ptr = ros_message->is_connected;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: all_motors_enabled
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->all_motors_enabled = tmp ? true : false;
  }

  // Field name: command_accepted
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->command_accepted = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_interfaces
size_t get_serialized_size_ros2_interfaces__msg__UpperBodySystemState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _UpperBodySystemState__ros_msg_type * ros_message = static_cast<const _UpperBodySystemState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: state
  {
    size_t item_size = sizeof(ros_message->state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: run_mode
  {
    size_t item_size = sizeof(ros_message->run_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: ready_motor_count
  {
    size_t item_size = sizeof(ros_message->ready_motor_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enabled_motor_count
  {
    size_t item_size = sizeof(ros_message->enabled_motor_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: fault_motor_count
  {
    size_t item_size = sizeof(ros_message->fault_motor_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: is_connected
  {
    size_t array_size = 15;
    auto array_ptr = ros_message->is_connected;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: all_motors_enabled
  {
    size_t item_size = sizeof(ros_message->all_motors_enabled);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: command_accepted
  {
    size_t item_size = sizeof(ros_message->command_accepted);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_interfaces
size_t max_serialized_size_ros2_interfaces__msg__UpperBodySystemState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: state
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: run_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: ready_motor_count
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: enabled_motor_count
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: fault_motor_count
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: is_connected
  {
    size_t array_size = 15;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: all_motors_enabled
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: command_accepted
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ros2_interfaces__msg__UpperBodySystemState;
    is_plain =
      (
      offsetof(DataType, command_accepted) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_interfaces
bool cdr_serialize_key_ros2_interfaces__msg__UpperBodySystemState(
  const ros2_interfaces__msg__UpperBodySystemState * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: state
  {
    cdr << ros_message->state;
  }

  // Field name: run_mode
  {
    cdr << ros_message->run_mode;
  }

  // Field name: ready_motor_count
  {
    cdr << ros_message->ready_motor_count;
  }

  // Field name: enabled_motor_count
  {
    cdr << ros_message->enabled_motor_count;
  }

  // Field name: fault_motor_count
  {
    cdr << ros_message->fault_motor_count;
  }

  // Field name: is_connected
  {
    size_t size = 15;
    auto array_ptr = ros_message->is_connected;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: all_motors_enabled
  {
    cdr << (ros_message->all_motors_enabled ? true : false);
  }

  // Field name: command_accepted
  {
    cdr << (ros_message->command_accepted ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_interfaces
size_t get_serialized_size_key_ros2_interfaces__msg__UpperBodySystemState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _UpperBodySystemState__ros_msg_type * ros_message = static_cast<const _UpperBodySystemState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: state
  {
    size_t item_size = sizeof(ros_message->state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: run_mode
  {
    size_t item_size = sizeof(ros_message->run_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: ready_motor_count
  {
    size_t item_size = sizeof(ros_message->ready_motor_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enabled_motor_count
  {
    size_t item_size = sizeof(ros_message->enabled_motor_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: fault_motor_count
  {
    size_t item_size = sizeof(ros_message->fault_motor_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: is_connected
  {
    size_t array_size = 15;
    auto array_ptr = ros_message->is_connected;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: all_motors_enabled
  {
    size_t item_size = sizeof(ros_message->all_motors_enabled);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: command_accepted
  {
    size_t item_size = sizeof(ros_message->command_accepted);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_interfaces
size_t max_serialized_size_key_ros2_interfaces__msg__UpperBodySystemState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: state
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: run_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: ready_motor_count
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: enabled_motor_count
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: fault_motor_count
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: is_connected
  {
    size_t array_size = 15;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: all_motors_enabled
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: command_accepted
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ros2_interfaces__msg__UpperBodySystemState;
    is_plain =
      (
      offsetof(DataType, command_accepted) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _UpperBodySystemState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const ros2_interfaces__msg__UpperBodySystemState * ros_message = static_cast<const ros2_interfaces__msg__UpperBodySystemState *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_ros2_interfaces__msg__UpperBodySystemState(ros_message, cdr);
}

static bool _UpperBodySystemState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  ros2_interfaces__msg__UpperBodySystemState * ros_message = static_cast<ros2_interfaces__msg__UpperBodySystemState *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_ros2_interfaces__msg__UpperBodySystemState(cdr, ros_message);
}

static uint32_t _UpperBodySystemState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ros2_interfaces__msg__UpperBodySystemState(
      untyped_ros_message, 0));
}

static size_t _UpperBodySystemState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ros2_interfaces__msg__UpperBodySystemState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_UpperBodySystemState = {
  "ros2_interfaces::msg",
  "UpperBodySystemState",
  _UpperBodySystemState__cdr_serialize,
  _UpperBodySystemState__cdr_deserialize,
  _UpperBodySystemState__get_serialized_size,
  _UpperBodySystemState__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _UpperBodySystemState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_UpperBodySystemState,
  get_message_typesupport_handle_function,
  &ros2_interfaces__msg__UpperBodySystemState__get_type_hash,
  &ros2_interfaces__msg__UpperBodySystemState__get_type_description,
  &ros2_interfaces__msg__UpperBodySystemState__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_interfaces, msg, UpperBodySystemState)() {
  return &_UpperBodySystemState__type_support;
}

#if defined(__cplusplus)
}
#endif
