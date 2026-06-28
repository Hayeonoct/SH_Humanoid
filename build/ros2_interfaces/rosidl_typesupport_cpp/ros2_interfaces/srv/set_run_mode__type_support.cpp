// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from ros2_interfaces:srv/SetRunMode.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "ros2_interfaces/srv/detail/set_run_mode__functions.h"
#include "ros2_interfaces/srv/detail/set_run_mode__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace ros2_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetRunMode_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetRunMode_Request_type_support_ids_t;

static const _SetRunMode_Request_type_support_ids_t _SetRunMode_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetRunMode_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetRunMode_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetRunMode_Request_type_support_symbol_names_t _SetRunMode_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_interfaces, srv, SetRunMode_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ros2_interfaces, srv, SetRunMode_Request)),
  }
};

typedef struct _SetRunMode_Request_type_support_data_t
{
  void * data[2];
} _SetRunMode_Request_type_support_data_t;

static _SetRunMode_Request_type_support_data_t _SetRunMode_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetRunMode_Request_message_typesupport_map = {
  2,
  "ros2_interfaces",
  &_SetRunMode_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SetRunMode_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SetRunMode_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetRunMode_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetRunMode_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &ros2_interfaces__srv__SetRunMode_Request__get_type_hash,
  &ros2_interfaces__srv__SetRunMode_Request__get_type_description,
  &ros2_interfaces__srv__SetRunMode_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace ros2_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2_interfaces::srv::SetRunMode_Request>()
{
  return &::ros2_interfaces::srv::rosidl_typesupport_cpp::SetRunMode_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, ros2_interfaces, srv, SetRunMode_Request)() {
  return get_message_type_support_handle<ros2_interfaces::srv::SetRunMode_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "ros2_interfaces/srv/detail/set_run_mode__functions.h"
// already included above
// #include "ros2_interfaces/srv/detail/set_run_mode__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace ros2_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetRunMode_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetRunMode_Response_type_support_ids_t;

static const _SetRunMode_Response_type_support_ids_t _SetRunMode_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetRunMode_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetRunMode_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetRunMode_Response_type_support_symbol_names_t _SetRunMode_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_interfaces, srv, SetRunMode_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ros2_interfaces, srv, SetRunMode_Response)),
  }
};

typedef struct _SetRunMode_Response_type_support_data_t
{
  void * data[2];
} _SetRunMode_Response_type_support_data_t;

static _SetRunMode_Response_type_support_data_t _SetRunMode_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetRunMode_Response_message_typesupport_map = {
  2,
  "ros2_interfaces",
  &_SetRunMode_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SetRunMode_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SetRunMode_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetRunMode_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetRunMode_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &ros2_interfaces__srv__SetRunMode_Response__get_type_hash,
  &ros2_interfaces__srv__SetRunMode_Response__get_type_description,
  &ros2_interfaces__srv__SetRunMode_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace ros2_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2_interfaces::srv::SetRunMode_Response>()
{
  return &::ros2_interfaces::srv::rosidl_typesupport_cpp::SetRunMode_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, ros2_interfaces, srv, SetRunMode_Response)() {
  return get_message_type_support_handle<ros2_interfaces::srv::SetRunMode_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "ros2_interfaces/srv/detail/set_run_mode__functions.h"
// already included above
// #include "ros2_interfaces/srv/detail/set_run_mode__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace ros2_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetRunMode_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetRunMode_Event_type_support_ids_t;

static const _SetRunMode_Event_type_support_ids_t _SetRunMode_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetRunMode_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetRunMode_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetRunMode_Event_type_support_symbol_names_t _SetRunMode_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_interfaces, srv, SetRunMode_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ros2_interfaces, srv, SetRunMode_Event)),
  }
};

typedef struct _SetRunMode_Event_type_support_data_t
{
  void * data[2];
} _SetRunMode_Event_type_support_data_t;

static _SetRunMode_Event_type_support_data_t _SetRunMode_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetRunMode_Event_message_typesupport_map = {
  2,
  "ros2_interfaces",
  &_SetRunMode_Event_message_typesupport_ids.typesupport_identifier[0],
  &_SetRunMode_Event_message_typesupport_symbol_names.symbol_name[0],
  &_SetRunMode_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetRunMode_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetRunMode_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &ros2_interfaces__srv__SetRunMode_Event__get_type_hash,
  &ros2_interfaces__srv__SetRunMode_Event__get_type_description,
  &ros2_interfaces__srv__SetRunMode_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace ros2_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2_interfaces::srv::SetRunMode_Event>()
{
  return &::ros2_interfaces::srv::rosidl_typesupport_cpp::SetRunMode_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, ros2_interfaces, srv, SetRunMode_Event)() {
  return get_message_type_support_handle<ros2_interfaces::srv::SetRunMode_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "ros2_interfaces/srv/detail/set_run_mode__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace ros2_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetRunMode_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetRunMode_type_support_ids_t;

static const _SetRunMode_type_support_ids_t _SetRunMode_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetRunMode_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetRunMode_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetRunMode_type_support_symbol_names_t _SetRunMode_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_interfaces, srv, SetRunMode)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ros2_interfaces, srv, SetRunMode)),
  }
};

typedef struct _SetRunMode_type_support_data_t
{
  void * data[2];
} _SetRunMode_type_support_data_t;

static _SetRunMode_type_support_data_t _SetRunMode_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetRunMode_service_typesupport_map = {
  2,
  "ros2_interfaces",
  &_SetRunMode_service_typesupport_ids.typesupport_identifier[0],
  &_SetRunMode_service_typesupport_symbol_names.symbol_name[0],
  &_SetRunMode_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SetRunMode_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetRunMode_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<ros2_interfaces::srv::SetRunMode_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<ros2_interfaces::srv::SetRunMode_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<ros2_interfaces::srv::SetRunMode_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<ros2_interfaces::srv::SetRunMode>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<ros2_interfaces::srv::SetRunMode>,
  &ros2_interfaces__srv__SetRunMode__get_type_hash,
  &ros2_interfaces__srv__SetRunMode__get_type_description,
  &ros2_interfaces__srv__SetRunMode__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace ros2_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<ros2_interfaces::srv::SetRunMode>()
{
  return &::ros2_interfaces::srv::rosidl_typesupport_cpp::SetRunMode_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, ros2_interfaces, srv, SetRunMode)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<ros2_interfaces::srv::SetRunMode>();
}

#ifdef __cplusplus
}
#endif
