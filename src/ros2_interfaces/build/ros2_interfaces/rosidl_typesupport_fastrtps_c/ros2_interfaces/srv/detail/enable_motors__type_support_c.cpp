// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ros2_interfaces:srv/EnableMotors.idl
// generated code does not contain a copyright notice
#include "ros2_interfaces/srv/detail/enable_motors__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ros2_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ros2_interfaces/srv/detail/enable_motors__struct.h"
#include "ros2_interfaces/srv/detail/enable_motors__functions.h"
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

#include "rosidl_runtime_c/primitives_sequence.h"  // motor_id_list
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // motor_id_list

// forward declare type support functions


using _EnableMotors_Request__ros_msg_type = ros2_interfaces__srv__EnableMotors_Request;

static bool _EnableMotors_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _EnableMotors_Request__ros_msg_type * ros_message = static_cast<const _EnableMotors_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: enable_all
  {
    cdr << (ros_message->enable_all ? true : false);
  }

  // Field name: motor_id_list
  {
    size_t size = ros_message->motor_id_list.size;
    auto array_ptr = ros_message->motor_id_list.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _EnableMotors_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _EnableMotors_Request__ros_msg_type * ros_message = static_cast<_EnableMotors_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: enable_all
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->enable_all = tmp ? true : false;
  }

  // Field name: motor_id_list
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->motor_id_list.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->motor_id_list);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->motor_id_list, size)) {
      fprintf(stderr, "failed to create array for field 'motor_id_list'");
      return false;
    }
    auto array_ptr = ros_message->motor_id_list.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_interfaces
size_t get_serialized_size_ros2_interfaces__srv__EnableMotors_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _EnableMotors_Request__ros_msg_type * ros_message = static_cast<const _EnableMotors_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name enable_all
  {
    size_t item_size = sizeof(ros_message->enable_all);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name motor_id_list
  {
    size_t array_size = ros_message->motor_id_list.size;
    auto array_ptr = ros_message->motor_id_list.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _EnableMotors_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ros2_interfaces__srv__EnableMotors_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_interfaces
size_t max_serialized_size_ros2_interfaces__srv__EnableMotors_Request(
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

  // member: enable_all
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: motor_id_list
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _EnableMotors_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ros2_interfaces__srv__EnableMotors_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_EnableMotors_Request = {
  "ros2_interfaces::srv",
  "EnableMotors_Request",
  _EnableMotors_Request__cdr_serialize,
  _EnableMotors_Request__cdr_deserialize,
  _EnableMotors_Request__get_serialized_size,
  _EnableMotors_Request__max_serialized_size
};

static rosidl_message_type_support_t _EnableMotors_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_EnableMotors_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_interfaces, srv, EnableMotors_Request)() {
  return &_EnableMotors_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "ros2_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "ros2_interfaces/srv/detail/enable_motors__struct.h"
// already included above
// #include "ros2_interfaces/srv/detail/enable_motors__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"  // enabled_motor_ids, failed_motor_ids
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"  // enabled_motor_ids, failed_motor_ids
#include "rosidl_runtime_c/string.h"  // message
#include "rosidl_runtime_c/string_functions.h"  // message

// forward declare type support functions


using _EnableMotors_Response__ros_msg_type = ros2_interfaces__srv__EnableMotors_Response;

static bool _EnableMotors_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _EnableMotors_Response__ros_msg_type * ros_message = static_cast<const _EnableMotors_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  // Field name: message
  {
    const rosidl_runtime_c__String * str = &ros_message->message;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: enabled_motor_ids
  {
    size_t size = ros_message->enabled_motor_ids.size;
    auto array_ptr = ros_message->enabled_motor_ids.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: failed_motor_ids
  {
    size_t size = ros_message->failed_motor_ids.size;
    auto array_ptr = ros_message->failed_motor_ids.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _EnableMotors_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _EnableMotors_Response__ros_msg_type * ros_message = static_cast<_EnableMotors_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->success = tmp ? true : false;
  }

  // Field name: message
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->message.data) {
      rosidl_runtime_c__String__init(&ros_message->message);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->message,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'message'\n");
      return false;
    }
  }

  // Field name: enabled_motor_ids
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->enabled_motor_ids.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->enabled_motor_ids);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->enabled_motor_ids, size)) {
      fprintf(stderr, "failed to create array for field 'enabled_motor_ids'");
      return false;
    }
    auto array_ptr = ros_message->enabled_motor_ids.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: failed_motor_ids
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->failed_motor_ids.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->failed_motor_ids);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->failed_motor_ids, size)) {
      fprintf(stderr, "failed to create array for field 'failed_motor_ids'");
      return false;
    }
    auto array_ptr = ros_message->failed_motor_ids.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_interfaces
size_t get_serialized_size_ros2_interfaces__srv__EnableMotors_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _EnableMotors_Response__ros_msg_type * ros_message = static_cast<const _EnableMotors_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name success
  {
    size_t item_size = sizeof(ros_message->success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name message
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->message.size + 1);
  // field.name enabled_motor_ids
  {
    size_t array_size = ros_message->enabled_motor_ids.size;
    auto array_ptr = ros_message->enabled_motor_ids.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name failed_motor_ids
  {
    size_t array_size = ros_message->failed_motor_ids.size;
    auto array_ptr = ros_message->failed_motor_ids.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _EnableMotors_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ros2_interfaces__srv__EnableMotors_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_interfaces
size_t max_serialized_size_ros2_interfaces__srv__EnableMotors_Response(
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

  // member: success
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: message
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: enabled_motor_ids
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: failed_motor_ids
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _EnableMotors_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ros2_interfaces__srv__EnableMotors_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_EnableMotors_Response = {
  "ros2_interfaces::srv",
  "EnableMotors_Response",
  _EnableMotors_Response__cdr_serialize,
  _EnableMotors_Response__cdr_deserialize,
  _EnableMotors_Response__get_serialized_size,
  _EnableMotors_Response__max_serialized_size
};

static rosidl_message_type_support_t _EnableMotors_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_EnableMotors_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_interfaces, srv, EnableMotors_Response)() {
  return &_EnableMotors_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "ros2_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ros2_interfaces/srv/enable_motors.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t EnableMotors__callbacks = {
  "ros2_interfaces::srv",
  "EnableMotors",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_interfaces, srv, EnableMotors_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_interfaces, srv, EnableMotors_Response)(),
};

static rosidl_service_type_support_t EnableMotors__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &EnableMotors__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_interfaces, srv, EnableMotors)() {
  return &EnableMotors__handle;
}

#if defined(__cplusplus)
}
#endif
