// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from arm_control_interfaces:srv/GetPointCloud.idl
// generated code does not contain a copyright notice

#include "arm_control_interfaces/srv/detail/get_point_cloud__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_arm_control_interfaces
const rosidl_type_hash_t *
arm_control_interfaces__srv__GetPointCloud__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa7, 0x98, 0xe4, 0x5e, 0x95, 0x55, 0x6d, 0x64,
      0x23, 0xf4, 0x49, 0x34, 0xdc, 0xd7, 0x64, 0x63,
      0x43, 0xab, 0xcd, 0x5d, 0xfb, 0x93, 0x39, 0xf6,
      0xe8, 0x72, 0xa3, 0xf2, 0x08, 0x29, 0xc9, 0x2f,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_arm_control_interfaces
const rosidl_type_hash_t *
arm_control_interfaces__srv__GetPointCloud_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa6, 0x00, 0xda, 0xb9, 0x81, 0x51, 0x07, 0x04,
      0xba, 0xaf, 0x47, 0xf2, 0x3b, 0xb8, 0xcb, 0x41,
      0x06, 0x74, 0x88, 0x6c, 0xd6, 0x04, 0x1d, 0x13,
      0x97, 0xa0, 0xe1, 0x7a, 0x99, 0xe5, 0x97, 0x6d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_arm_control_interfaces
const rosidl_type_hash_t *
arm_control_interfaces__srv__GetPointCloud_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x07, 0xf0, 0x78, 0x51, 0xec, 0x3a, 0x75, 0x7d,
      0x72, 0x08, 0xe5, 0xd1, 0xea, 0xaa, 0xf4, 0x68,
      0x4a, 0xad, 0x6e, 0x38, 0x6d, 0xc2, 0x4c, 0x13,
      0x34, 0xaa, 0x92, 0xd2, 0x63, 0xee, 0x0d, 0xd5,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_arm_control_interfaces
const rosidl_type_hash_t *
arm_control_interfaces__srv__GetPointCloud_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x65, 0x73, 0x83, 0xc7, 0x62, 0x52, 0x0a, 0xf2,
      0x79, 0xd1, 0xec, 0x1d, 0x89, 0x87, 0x83, 0xbe,
      0x72, 0xeb, 0x7d, 0xc9, 0xc4, 0x4b, 0x19, 0xe2,
      0xc3, 0x75, 0x8d, 0xe9, 0xb5, 0x30, 0x82, 0x4d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "sensor_msgs/msg/detail/point_field__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "std_msgs/msg/detail/header__functions.h"
#include "sensor_msgs/msg/detail/point_cloud2__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t sensor_msgs__msg__PointCloud2__EXPECTED_HASH = {1, {
    0x91, 0x98, 0xca, 0xbf, 0x7d, 0xa3, 0x79, 0x6a,
    0xe6, 0xfe, 0x19, 0xc4, 0xcb, 0x3b, 0xdd, 0x35,
    0x25, 0x49, 0x29, 0x88, 0xc7, 0x05, 0x22, 0x62,
    0x8a, 0xf5, 0xda, 0xa1, 0x24, 0xba, 0xe2, 0xb5,
  }};
static const rosidl_type_hash_t sensor_msgs__msg__PointField__EXPECTED_HASH = {1, {
    0x5c, 0x6a, 0x47, 0x50, 0x72, 0x8c, 0x2b, 0xcf,
    0xbb, 0xf7, 0x03, 0x72, 0x25, 0xb2, 0x0b, 0x02,
    0xd4, 0x42, 0x96, 0x34, 0x73, 0x21, 0x46, 0xb7,
    0x42, 0xde, 0xe1, 0x72, 0x66, 0x37, 0xef, 0x01,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char arm_control_interfaces__srv__GetPointCloud__TYPE_NAME[] = "arm_control_interfaces/srv/GetPointCloud";
static char arm_control_interfaces__srv__GetPointCloud_Event__TYPE_NAME[] = "arm_control_interfaces/srv/GetPointCloud_Event";
static char arm_control_interfaces__srv__GetPointCloud_Request__TYPE_NAME[] = "arm_control_interfaces/srv/GetPointCloud_Request";
static char arm_control_interfaces__srv__GetPointCloud_Response__TYPE_NAME[] = "arm_control_interfaces/srv/GetPointCloud_Response";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char sensor_msgs__msg__PointCloud2__TYPE_NAME[] = "sensor_msgs/msg/PointCloud2";
static char sensor_msgs__msg__PointField__TYPE_NAME[] = "sensor_msgs/msg/PointField";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char arm_control_interfaces__srv__GetPointCloud__FIELD_NAME__request_message[] = "request_message";
static char arm_control_interfaces__srv__GetPointCloud__FIELD_NAME__response_message[] = "response_message";
static char arm_control_interfaces__srv__GetPointCloud__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field arm_control_interfaces__srv__GetPointCloud__FIELDS[] = {
  {
    {arm_control_interfaces__srv__GetPointCloud__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {arm_control_interfaces__srv__GetPointCloud_Request__TYPE_NAME, 48, 48},
    },
    {NULL, 0, 0},
  },
  {
    {arm_control_interfaces__srv__GetPointCloud__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {arm_control_interfaces__srv__GetPointCloud_Response__TYPE_NAME, 49, 49},
    },
    {NULL, 0, 0},
  },
  {
    {arm_control_interfaces__srv__GetPointCloud__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {arm_control_interfaces__srv__GetPointCloud_Event__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription arm_control_interfaces__srv__GetPointCloud__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {arm_control_interfaces__srv__GetPointCloud_Event__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {arm_control_interfaces__srv__GetPointCloud_Request__TYPE_NAME, 48, 48},
    {NULL, 0, 0},
  },
  {
    {arm_control_interfaces__srv__GetPointCloud_Response__TYPE_NAME, 49, 49},
    {NULL, 0, 0},
  },
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__PointCloud2__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__PointField__TYPE_NAME, 26, 26},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
arm_control_interfaces__srv__GetPointCloud__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {arm_control_interfaces__srv__GetPointCloud__TYPE_NAME, 40, 40},
      {arm_control_interfaces__srv__GetPointCloud__FIELDS, 3, 3},
    },
    {arm_control_interfaces__srv__GetPointCloud__REFERENCED_TYPE_DESCRIPTIONS, 8, 8},
  };
  if (!constructed) {
    description.referenced_type_descriptions.data[0].fields = arm_control_interfaces__srv__GetPointCloud_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = arm_control_interfaces__srv__GetPointCloud_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = arm_control_interfaces__srv__GetPointCloud_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__PointCloud2__EXPECTED_HASH, sensor_msgs__msg__PointCloud2__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = sensor_msgs__msg__PointCloud2__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__PointField__EXPECTED_HASH, sensor_msgs__msg__PointField__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = sensor_msgs__msg__PointField__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[7].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char arm_control_interfaces__srv__GetPointCloud_Request__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field arm_control_interfaces__srv__GetPointCloud_Request__FIELDS[] = {
  {
    {arm_control_interfaces__srv__GetPointCloud_Request__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
arm_control_interfaces__srv__GetPointCloud_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {arm_control_interfaces__srv__GetPointCloud_Request__TYPE_NAME, 48, 48},
      {arm_control_interfaces__srv__GetPointCloud_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char arm_control_interfaces__srv__GetPointCloud_Response__FIELD_NAME__success[] = "success";
static char arm_control_interfaces__srv__GetPointCloud_Response__FIELD_NAME__point_cloud[] = "point_cloud";

static rosidl_runtime_c__type_description__Field arm_control_interfaces__srv__GetPointCloud_Response__FIELDS[] = {
  {
    {arm_control_interfaces__srv__GetPointCloud_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {arm_control_interfaces__srv__GetPointCloud_Response__FIELD_NAME__point_cloud, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {sensor_msgs__msg__PointCloud2__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription arm_control_interfaces__srv__GetPointCloud_Response__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__PointCloud2__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__PointField__TYPE_NAME, 26, 26},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
arm_control_interfaces__srv__GetPointCloud_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {arm_control_interfaces__srv__GetPointCloud_Response__TYPE_NAME, 49, 49},
      {arm_control_interfaces__srv__GetPointCloud_Response__FIELDS, 2, 2},
    },
    {arm_control_interfaces__srv__GetPointCloud_Response__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__PointCloud2__EXPECTED_HASH, sensor_msgs__msg__PointCloud2__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = sensor_msgs__msg__PointCloud2__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__PointField__EXPECTED_HASH, sensor_msgs__msg__PointField__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = sensor_msgs__msg__PointField__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char arm_control_interfaces__srv__GetPointCloud_Event__FIELD_NAME__info[] = "info";
static char arm_control_interfaces__srv__GetPointCloud_Event__FIELD_NAME__request[] = "request";
static char arm_control_interfaces__srv__GetPointCloud_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field arm_control_interfaces__srv__GetPointCloud_Event__FIELDS[] = {
  {
    {arm_control_interfaces__srv__GetPointCloud_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {arm_control_interfaces__srv__GetPointCloud_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {arm_control_interfaces__srv__GetPointCloud_Request__TYPE_NAME, 48, 48},
    },
    {NULL, 0, 0},
  },
  {
    {arm_control_interfaces__srv__GetPointCloud_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {arm_control_interfaces__srv__GetPointCloud_Response__TYPE_NAME, 49, 49},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription arm_control_interfaces__srv__GetPointCloud_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {arm_control_interfaces__srv__GetPointCloud_Request__TYPE_NAME, 48, 48},
    {NULL, 0, 0},
  },
  {
    {arm_control_interfaces__srv__GetPointCloud_Response__TYPE_NAME, 49, 49},
    {NULL, 0, 0},
  },
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__PointCloud2__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__PointField__TYPE_NAME, 26, 26},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
arm_control_interfaces__srv__GetPointCloud_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {arm_control_interfaces__srv__GetPointCloud_Event__TYPE_NAME, 46, 46},
      {arm_control_interfaces__srv__GetPointCloud_Event__FIELDS, 3, 3},
    },
    {arm_control_interfaces__srv__GetPointCloud_Event__REFERENCED_TYPE_DESCRIPTIONS, 7, 7},
  };
  if (!constructed) {
    description.referenced_type_descriptions.data[0].fields = arm_control_interfaces__srv__GetPointCloud_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = arm_control_interfaces__srv__GetPointCloud_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__PointCloud2__EXPECTED_HASH, sensor_msgs__msg__PointCloud2__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = sensor_msgs__msg__PointCloud2__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__PointField__EXPECTED_HASH, sensor_msgs__msg__PointField__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = sensor_msgs__msg__PointField__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "---\n"
  "bool success\n"
  "sensor_msgs/PointCloud2 point_cloud";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
arm_control_interfaces__srv__GetPointCloud__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {arm_control_interfaces__srv__GetPointCloud__TYPE_NAME, 40, 40},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 52, 52},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
arm_control_interfaces__srv__GetPointCloud_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {arm_control_interfaces__srv__GetPointCloud_Request__TYPE_NAME, 48, 48},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
arm_control_interfaces__srv__GetPointCloud_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {arm_control_interfaces__srv__GetPointCloud_Response__TYPE_NAME, 49, 49},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
arm_control_interfaces__srv__GetPointCloud_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {arm_control_interfaces__srv__GetPointCloud_Event__TYPE_NAME, 46, 46},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
arm_control_interfaces__srv__GetPointCloud__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[9];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 9, 9};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *arm_control_interfaces__srv__GetPointCloud__get_individual_type_description_source(NULL),
    sources[1] = *arm_control_interfaces__srv__GetPointCloud_Event__get_individual_type_description_source(NULL);
    sources[2] = *arm_control_interfaces__srv__GetPointCloud_Request__get_individual_type_description_source(NULL);
    sources[3] = *arm_control_interfaces__srv__GetPointCloud_Response__get_individual_type_description_source(NULL);
    sources[4] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[5] = *sensor_msgs__msg__PointCloud2__get_individual_type_description_source(NULL);
    sources[6] = *sensor_msgs__msg__PointField__get_individual_type_description_source(NULL);
    sources[7] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[8] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
arm_control_interfaces__srv__GetPointCloud_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *arm_control_interfaces__srv__GetPointCloud_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
arm_control_interfaces__srv__GetPointCloud_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *arm_control_interfaces__srv__GetPointCloud_Response__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *sensor_msgs__msg__PointCloud2__get_individual_type_description_source(NULL);
    sources[3] = *sensor_msgs__msg__PointField__get_individual_type_description_source(NULL);
    sources[4] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
arm_control_interfaces__srv__GetPointCloud_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[8];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 8, 8};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *arm_control_interfaces__srv__GetPointCloud_Event__get_individual_type_description_source(NULL),
    sources[1] = *arm_control_interfaces__srv__GetPointCloud_Request__get_individual_type_description_source(NULL);
    sources[2] = *arm_control_interfaces__srv__GetPointCloud_Response__get_individual_type_description_source(NULL);
    sources[3] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[4] = *sensor_msgs__msg__PointCloud2__get_individual_type_description_source(NULL);
    sources[5] = *sensor_msgs__msg__PointField__get_individual_type_description_source(NULL);
    sources[6] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[7] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
