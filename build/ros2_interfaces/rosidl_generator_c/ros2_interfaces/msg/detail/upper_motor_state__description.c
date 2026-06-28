// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ros2_interfaces:msg/UpperMotorState.idl
// generated code does not contain a copyright notice

#include "ros2_interfaces/msg/detail/upper_motor_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ros2_interfaces
const rosidl_type_hash_t *
ros2_interfaces__msg__UpperMotorState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xcb, 0x9b, 0x7b, 0x03, 0x84, 0xe5, 0xee, 0x80,
      0x71, 0x5c, 0x4c, 0x23, 0x7e, 0xca, 0x7b, 0x58,
      0x42, 0x8d, 0x58, 0xff, 0xea, 0x1f, 0xe0, 0x94,
      0xc0, 0x34, 0x20, 0x09, 0x6e, 0x1d, 0x58, 0xcf,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "std_msgs/msg/detail/header__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char ros2_interfaces__msg__UpperMotorState__TYPE_NAME[] = "ros2_interfaces/msg/UpperMotorState";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char ros2_interfaces__msg__UpperMotorState__FIELD_NAME__header[] = "header";
static char ros2_interfaces__msg__UpperMotorState__FIELD_NAME__is_ready[] = "is_ready";
static char ros2_interfaces__msg__UpperMotorState__FIELD_NAME__is_enabled[] = "is_enabled";
static char ros2_interfaces__msg__UpperMotorState__FIELD_NAME__has_fault[] = "has_fault";
static char ros2_interfaces__msg__UpperMotorState__FIELD_NAME__motor_id[] = "motor_id";
static char ros2_interfaces__msg__UpperMotorState__FIELD_NAME__position[] = "position";
static char ros2_interfaces__msg__UpperMotorState__FIELD_NAME__velocity[] = "velocity";
static char ros2_interfaces__msg__UpperMotorState__FIELD_NAME__effort[] = "effort";
static char ros2_interfaces__msg__UpperMotorState__FIELD_NAME__error_code[] = "error_code";
static char ros2_interfaces__msg__UpperMotorState__FIELD_NAME__temperature[] = "temperature";
static char ros2_interfaces__msg__UpperMotorState__FIELD_NAME__voltage[] = "voltage";
static char ros2_interfaces__msg__UpperMotorState__FIELD_NAME__current[] = "current";

static rosidl_runtime_c__type_description__Field ros2_interfaces__msg__UpperMotorState__FIELDS[] = {
  {
    {ros2_interfaces__msg__UpperMotorState__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__msg__UpperMotorState__FIELD_NAME__is_ready, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN_ARRAY,
      15,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__msg__UpperMotorState__FIELD_NAME__is_enabled, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN_ARRAY,
      15,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__msg__UpperMotorState__FIELD_NAME__has_fault, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN_ARRAY,
      15,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__msg__UpperMotorState__FIELD_NAME__motor_id, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16_ARRAY,
      15,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__msg__UpperMotorState__FIELD_NAME__position, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      15,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__msg__UpperMotorState__FIELD_NAME__velocity, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      15,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__msg__UpperMotorState__FIELD_NAME__effort, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      15,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__msg__UpperMotorState__FIELD_NAME__error_code, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16_ARRAY,
      15,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__msg__UpperMotorState__FIELD_NAME__temperature, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      15,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__msg__UpperMotorState__FIELD_NAME__voltage, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      15,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_interfaces__msg__UpperMotorState__FIELD_NAME__current, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      15,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ros2_interfaces__msg__UpperMotorState__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros2_interfaces__msg__UpperMotorState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros2_interfaces__msg__UpperMotorState__TYPE_NAME, 35, 35},
      {ros2_interfaces__msg__UpperMotorState__FIELDS, 12, 12},
    },
    {ros2_interfaces__msg__UpperMotorState__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Upper motor state feedback for 15 motors.\n"
  "std_msgs/Header header\n"
  "\n"
  "bool[15] is_ready\n"
  "bool[15] is_enabled\n"
  "bool[15] has_fault\n"
  "uint16[15] motor_id\n"
  "\n"
  "float32[15] position\n"
  "float32[15] velocity\n"
  "float32[15] effort\n"
  "\n"
  "uint16[15] error_code\n"
  "float32[15] temperature\n"
  "float32[15] voltage\n"
  "float32[15] current";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ros2_interfaces__msg__UpperMotorState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros2_interfaces__msg__UpperMotorState__TYPE_NAME, 35, 35},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 294, 294},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros2_interfaces__msg__UpperMotorState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros2_interfaces__msg__UpperMotorState__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
