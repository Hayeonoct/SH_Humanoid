// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ros2_interfaces:msg/UpperMotorState.idl
// generated code does not contain a copyright notice
#include "ros2_interfaces/msg/detail/upper_motor_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ros2_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ros2_interfaces/msg/detail/upper_motor_state__struct.h"
#include "ros2_interfaces/msg/detail/upper_motor_state__functions.h"
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


using _UpperMotorState__ros_msg_type = ros2_interfaces__msg__UpperMotorState;

static bool _UpperMotorState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _UpperMotorState__ros_msg_type * ros_message = static_cast<const _UpperMotorState__ros_msg_type *>(untyped_ros_message);
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

  // Field name: is_ready
  {
    size_t size = 15;
    auto array_ptr = ros_message->is_ready;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: is_enabled
  {
    size_t size = 15;
    auto array_ptr = ros_message->is_enabled;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: has_fault
  {
    size_t size = 15;
    auto array_ptr = ros_message->has_fault;
    cdr.serializeArray(array_ptr, size);
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

  // Field name: error_code
  {
    size_t size = 15;
    auto array_ptr = ros_message->error_code;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: temperature
  {
    size_t size = 15;
    auto array_ptr = ros_message->temperature;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: voltage
  {
    size_t size = 15;
    auto array_ptr = ros_message->voltage;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: current
  {
    size_t size = 15;
    auto array_ptr = ros_message->current;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _UpperMotorState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _UpperMotorState__ros_msg_type * ros_message = static_cast<_UpperMotorState__ros_msg_type *>(untyped_ros_message);
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

  // Field name: is_ready
  {
    size_t size = 15;
    auto array_ptr = ros_message->is_ready;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: is_enabled
  {
    size_t size = 15;
    auto array_ptr = ros_message->is_enabled;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: has_fault
  {
    size_t size = 15;
    auto array_ptr = ros_message->has_fault;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
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

  // Field name: error_code
  {
    size_t size = 15;
    auto array_ptr = ros_message->error_code;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: temperature
  {
    size_t size = 15;
    auto array_ptr = ros_message->temperature;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: voltage
  {
    size_t size = 15;
    auto array_ptr = ros_message->voltage;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: current
  {
    size_t size = 15;
    auto array_ptr = ros_message->current;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_interfaces
size_t get_serialized_size_ros2_interfaces__msg__UpperMotorState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _UpperMotorState__ros_msg_type * ros_message = static_cast<const _UpperMotorState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name is_ready
  {
    size_t array_size = 15;
    auto array_ptr = ros_message->is_ready;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_enabled
  {
    size_t array_size = 15;
    auto array_ptr = ros_message->is_enabled;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name has_fault
  {
    size_t array_size = 15;
    auto array_ptr = ros_message->has_fault;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
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
  // field.name error_code
  {
    size_t array_size = 15;
    auto array_ptr = ros_message->error_code;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name temperature
  {
    size_t array_size = 15;
    auto array_ptr = ros_message->temperature;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name voltage
  {
    size_t array_size = 15;
    auto array_ptr = ros_message->voltage;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current
  {
    size_t array_size = 15;
    auto array_ptr = ros_message->current;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _UpperMotorState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ros2_interfaces__msg__UpperMotorState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_interfaces
size_t max_serialized_size_ros2_interfaces__msg__UpperMotorState(
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
  // member: is_ready
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: is_enabled
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: has_fault
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: motor_id
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
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
  // member: error_code
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: temperature
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: voltage
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _UpperMotorState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ros2_interfaces__msg__UpperMotorState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_UpperMotorState = {
  "ros2_interfaces::msg",
  "UpperMotorState",
  _UpperMotorState__cdr_serialize,
  _UpperMotorState__cdr_deserialize,
  _UpperMotorState__get_serialized_size,
  _UpperMotorState__max_serialized_size
};

static rosidl_message_type_support_t _UpperMotorState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_UpperMotorState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_interfaces, msg, UpperMotorState)() {
  return &_UpperMotorState__type_support;
}

#if defined(__cplusplus)
}
#endif
