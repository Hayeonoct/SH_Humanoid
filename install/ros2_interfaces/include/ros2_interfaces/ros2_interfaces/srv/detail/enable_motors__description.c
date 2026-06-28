// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ros2_interfaces:srv/EnableMotors.idl
// generated code does not contain a copyright notice

#include "ros2_interfaces/srv/detail/enable_motors__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ros2_interfaces
const rosidl_type_hash_t *
ros2_interfaces__srv__EnableMotors__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd5, 0x03, 0xb2, 0x54, 0x2c, 0xef, 0xfd, 0x80,
      0x93, 0xb4, 0xa3, 0xae, 0xdb, 0x3d, 0x9d, 0x0f,
      0x1c, 0x0b, 0xde, 0x98, 0xee, 0x42, 0xfa, 0xa0,
      0x31, 0x7b, 0x34, 0x4f, 0xe3, 0x0f, 0x09, 0x91,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_ros2_interfaces
const rosidl_type_hash_t *
ros2_interfaces__srv__EnableMotors_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x73, 0xb4, 0x47, 0xa7, 0x0e, 0xb6, 0x58, 0x8e,
      0x7b, 0x48, 0xfa, 0x73, 0x88, 0xf1, 0xad, 0xee,
      0x99, 0xa4, 0x5a, 0x69, 0x8f, 0x8d, 0x16, 0x21,
      0xaf, 0xc5, 0xd5, 0x42, 0x3a, 0x11, 0x78, 0x26,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_ros2_interfaces
const rosidl_type_hash_t *
ros2_interfaces__srv__EnableMotors_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x3e, 0x23, 0x30, 0xa8, 0x09, 0xf2, 0x2e, 0xfa,
      0x27, 0x53, 0xf9, 0x62, 0x89, 0x89, 0x40, 0xac,
      0x33, 0xdb, 0x66, 0xca, 0xb4, 0x98, 0x0e, 0x15,
      0x88, 0xab, 0x4a, 0x6d, 0x78, 0x35, 0x52, 0xe7,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_ros2_interfaces
const rosidl_type_hash_t *
ros2_interfaces__srv__EnableMotors_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb3, 0xbc, 0x42, 0xbb, 0xab, 0x67, 0xe6, 0xca,
      0x6f, 0xc0, 0xc3, 0x5f, 0x5a, 0x54, 0x92, 0x9f,
      0x66, 0xd1, 0x05, 0x37, 0xff, 0x85, 0xec, 0x2d,
      0x76, 0xa7, 0xbf, 0xc4, 0xf6, 0xc2, 0x4e, 0xef,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char ros2_interfaces__srv__EnableMotors__TYPE_NAME[] = "ros2_interfaces/srv/EnableMotors";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char ros2_interfaces__srv__EnableMotors_Event__TYPE_NAME[] = "ros2_interfaces/srv/EnableMotors_Event";
static char ros2_interfaces__srv__EnableMotors_Request__TYPE_NAME[] = "ros2_interfaces/srv/EnableMotors_Request";
static char ros2_interfaces__srv__EnableMotors_Response__TYPE_NAME[] = "ros2_interfaces/srv/EnableMotors_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char ros2_interfaces__srv__EnableMotors__FIELD_NAME__request_message[] = "request_message";
static char ros2_interfaces__srv__EnableMotors__FIELD_NAME__response_message[] = "response_message";
static char ros2_interfaces__srv__EnableMotors__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field ros2_interfaces__srv__EnableMotors__FIELDS[] = {
  {
    {ros2_interfaces__srv__EnableMotors__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros2_interfaces__srv__EnableMotors_Request__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__srv__EnableMotors__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros2_interfaces__srv__EnableMotors_Response__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__srv__EnableMotors__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros2_interfaces__srv__EnableMotors_Event__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ros2_interfaces__srv__EnableMotors__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__srv__EnableMotors_Event__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__srv__EnableMotors_Request__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__srv__EnableMotors_Response__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros2_interfaces__srv__EnableMotors__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros2_interfaces__srv__EnableMotors__TYPE_NAME, 32, 32},
      {ros2_interfaces__srv__EnableMotors__FIELDS, 3, 3},
    },
    {ros2_interfaces__srv__EnableMotors__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = ros2_interfaces__srv__EnableMotors_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = ros2_interfaces__srv__EnableMotors_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = ros2_interfaces__srv__EnableMotors_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char ros2_interfaces__srv__EnableMotors_Request__FIELD_NAME__enable_all[] = "enable_all";
static char ros2_interfaces__srv__EnableMotors_Request__FIELD_NAME__motor_id_list[] = "motor_id_list";

static rosidl_runtime_c__type_description__Field ros2_interfaces__srv__EnableMotors_Request__FIELDS[] = {
  {
    {ros2_interfaces__srv__EnableMotors_Request__FIELD_NAME__enable_all, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__srv__EnableMotors_Request__FIELD_NAME__motor_id_list, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros2_interfaces__srv__EnableMotors_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros2_interfaces__srv__EnableMotors_Request__TYPE_NAME, 40, 40},
      {ros2_interfaces__srv__EnableMotors_Request__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char ros2_interfaces__srv__EnableMotors_Response__FIELD_NAME__success[] = "success";
static char ros2_interfaces__srv__EnableMotors_Response__FIELD_NAME__message[] = "message";
static char ros2_interfaces__srv__EnableMotors_Response__FIELD_NAME__enabled_motor_ids[] = "enabled_motor_ids";
static char ros2_interfaces__srv__EnableMotors_Response__FIELD_NAME__failed_motor_ids[] = "failed_motor_ids";

static rosidl_runtime_c__type_description__Field ros2_interfaces__srv__EnableMotors_Response__FIELDS[] = {
  {
    {ros2_interfaces__srv__EnableMotors_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__srv__EnableMotors_Response__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__srv__EnableMotors_Response__FIELD_NAME__enabled_motor_ids, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__srv__EnableMotors_Response__FIELD_NAME__failed_motor_ids, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros2_interfaces__srv__EnableMotors_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros2_interfaces__srv__EnableMotors_Response__TYPE_NAME, 41, 41},
      {ros2_interfaces__srv__EnableMotors_Response__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char ros2_interfaces__srv__EnableMotors_Event__FIELD_NAME__info[] = "info";
static char ros2_interfaces__srv__EnableMotors_Event__FIELD_NAME__request[] = "request";
static char ros2_interfaces__srv__EnableMotors_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field ros2_interfaces__srv__EnableMotors_Event__FIELDS[] = {
  {
    {ros2_interfaces__srv__EnableMotors_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__srv__EnableMotors_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {ros2_interfaces__srv__EnableMotors_Request__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__srv__EnableMotors_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {ros2_interfaces__srv__EnableMotors_Response__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ros2_interfaces__srv__EnableMotors_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__srv__EnableMotors_Request__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__srv__EnableMotors_Response__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros2_interfaces__srv__EnableMotors_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros2_interfaces__srv__EnableMotors_Event__TYPE_NAME, 38, 38},
      {ros2_interfaces__srv__EnableMotors_Event__FIELDS, 3, 3},
    },
    {ros2_interfaces__srv__EnableMotors_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = ros2_interfaces__srv__EnableMotors_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = ros2_interfaces__srv__EnableMotors_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Request\n"
  "bool enable_all\n"
  "uint8[] motor_id_list\n"
  "---\n"
  "# Response\n"
  "bool success\n"
  "string message\n"
  "uint8[] enabled_motor_ids\n"
  "uint8[] failed_motor_ids";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ros2_interfaces__srv__EnableMotors__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros2_interfaces__srv__EnableMotors__TYPE_NAME, 32, 32},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 142, 142},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
ros2_interfaces__srv__EnableMotors_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros2_interfaces__srv__EnableMotors_Request__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
ros2_interfaces__srv__EnableMotors_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros2_interfaces__srv__EnableMotors_Response__TYPE_NAME, 41, 41},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
ros2_interfaces__srv__EnableMotors_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros2_interfaces__srv__EnableMotors_Event__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros2_interfaces__srv__EnableMotors__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros2_interfaces__srv__EnableMotors__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *ros2_interfaces__srv__EnableMotors_Event__get_individual_type_description_source(NULL);
    sources[3] = *ros2_interfaces__srv__EnableMotors_Request__get_individual_type_description_source(NULL);
    sources[4] = *ros2_interfaces__srv__EnableMotors_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros2_interfaces__srv__EnableMotors_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros2_interfaces__srv__EnableMotors_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros2_interfaces__srv__EnableMotors_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros2_interfaces__srv__EnableMotors_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros2_interfaces__srv__EnableMotors_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros2_interfaces__srv__EnableMotors_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *ros2_interfaces__srv__EnableMotors_Request__get_individual_type_description_source(NULL);
    sources[3] = *ros2_interfaces__srv__EnableMotors_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
