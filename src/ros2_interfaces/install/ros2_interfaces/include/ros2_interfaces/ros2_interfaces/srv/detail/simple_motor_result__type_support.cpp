// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ros2_interfaces:srv/SimpleMotorResult.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ros2_interfaces/srv/detail/simple_motor_result__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace ros2_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void SimpleMotorResult_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ros2_interfaces::srv::SimpleMotorResult_Request(_init);
}

void SimpleMotorResult_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ros2_interfaces::srv::SimpleMotorResult_Request *>(message_memory);
  typed_message->~SimpleMotorResult_Request();
}

size_t size_function__SimpleMotorResult_Request__motor_id_list(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SimpleMotorResult_Request__motor_id_list(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void * get_function__SimpleMotorResult_Request__motor_id_list(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__SimpleMotorResult_Request__motor_id_list(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__SimpleMotorResult_Request__motor_id_list(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__SimpleMotorResult_Request__motor_id_list(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__SimpleMotorResult_Request__motor_id_list(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

void resize_function__SimpleMotorResult_Request__motor_id_list(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SimpleMotorResult_Request_message_member_array[1] = {
  {
    "motor_id_list",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::srv::SimpleMotorResult_Request, motor_id_list),  // bytes offset in struct
    nullptr,  // default value
    size_function__SimpleMotorResult_Request__motor_id_list,  // size() function pointer
    get_const_function__SimpleMotorResult_Request__motor_id_list,  // get_const(index) function pointer
    get_function__SimpleMotorResult_Request__motor_id_list,  // get(index) function pointer
    fetch_function__SimpleMotorResult_Request__motor_id_list,  // fetch(index, &value) function pointer
    assign_function__SimpleMotorResult_Request__motor_id_list,  // assign(index, value) function pointer
    resize_function__SimpleMotorResult_Request__motor_id_list  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SimpleMotorResult_Request_message_members = {
  "ros2_interfaces::srv",  // message namespace
  "SimpleMotorResult_Request",  // message name
  1,  // number of fields
  sizeof(ros2_interfaces::srv::SimpleMotorResult_Request),
  SimpleMotorResult_Request_message_member_array,  // message members
  SimpleMotorResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  SimpleMotorResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SimpleMotorResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SimpleMotorResult_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace ros2_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2_interfaces::srv::SimpleMotorResult_Request>()
{
  return &::ros2_interfaces::srv::rosidl_typesupport_introspection_cpp::SimpleMotorResult_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ros2_interfaces, srv, SimpleMotorResult_Request)() {
  return &::ros2_interfaces::srv::rosidl_typesupport_introspection_cpp::SimpleMotorResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "ros2_interfaces/srv/detail/simple_motor_result__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace ros2_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void SimpleMotorResult_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ros2_interfaces::srv::SimpleMotorResult_Response(_init);
}

void SimpleMotorResult_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ros2_interfaces::srv::SimpleMotorResult_Response *>(message_memory);
  typed_message->~SimpleMotorResult_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SimpleMotorResult_Response_message_member_array[2] = {
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::srv::SimpleMotorResult_Response, success),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "message",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::srv::SimpleMotorResult_Response, message),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SimpleMotorResult_Response_message_members = {
  "ros2_interfaces::srv",  // message namespace
  "SimpleMotorResult_Response",  // message name
  2,  // number of fields
  sizeof(ros2_interfaces::srv::SimpleMotorResult_Response),
  SimpleMotorResult_Response_message_member_array,  // message members
  SimpleMotorResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  SimpleMotorResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SimpleMotorResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SimpleMotorResult_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace ros2_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2_interfaces::srv::SimpleMotorResult_Response>()
{
  return &::ros2_interfaces::srv::rosidl_typesupport_introspection_cpp::SimpleMotorResult_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ros2_interfaces, srv, SimpleMotorResult_Response)() {
  return &::ros2_interfaces::srv::rosidl_typesupport_introspection_cpp::SimpleMotorResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "ros2_interfaces/srv/detail/simple_motor_result__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace ros2_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers SimpleMotorResult_service_members = {
  "ros2_interfaces::srv",  // service namespace
  "SimpleMotorResult",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<ros2_interfaces::srv::SimpleMotorResult>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t SimpleMotorResult_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SimpleMotorResult_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace ros2_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<ros2_interfaces::srv::SimpleMotorResult>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::ros2_interfaces::srv::rosidl_typesupport_introspection_cpp::SimpleMotorResult_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::ros2_interfaces::srv::SimpleMotorResult_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::ros2_interfaces::srv::SimpleMotorResult_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ros2_interfaces, srv, SimpleMotorResult)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<ros2_interfaces::srv::SimpleMotorResult>();
}

#ifdef __cplusplus
}
#endif
