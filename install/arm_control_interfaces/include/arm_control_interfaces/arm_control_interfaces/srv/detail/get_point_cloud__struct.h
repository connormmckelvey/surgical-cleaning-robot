// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from arm_control_interfaces:srv/GetPointCloud.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "arm_control_interfaces/srv/get_point_cloud.h"


#ifndef ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_POINT_CLOUD__STRUCT_H_
#define ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_POINT_CLOUD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetPointCloud in the package arm_control_interfaces.
typedef struct arm_control_interfaces__srv__GetPointCloud_Request
{
  uint8_t structure_needs_at_least_one_member;
} arm_control_interfaces__srv__GetPointCloud_Request;

// Struct for a sequence of arm_control_interfaces__srv__GetPointCloud_Request.
typedef struct arm_control_interfaces__srv__GetPointCloud_Request__Sequence
{
  arm_control_interfaces__srv__GetPointCloud_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arm_control_interfaces__srv__GetPointCloud_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'point_cloud'
#include "sensor_msgs/msg/detail/point_cloud2__struct.h"

/// Struct defined in srv/GetPointCloud in the package arm_control_interfaces.
typedef struct arm_control_interfaces__srv__GetPointCloud_Response
{
  bool success;
  sensor_msgs__msg__PointCloud2 point_cloud;
} arm_control_interfaces__srv__GetPointCloud_Response;

// Struct for a sequence of arm_control_interfaces__srv__GetPointCloud_Response.
typedef struct arm_control_interfaces__srv__GetPointCloud_Response__Sequence
{
  arm_control_interfaces__srv__GetPointCloud_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arm_control_interfaces__srv__GetPointCloud_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  arm_control_interfaces__srv__GetPointCloud_Event__request__MAX_SIZE = 1
};
// response
enum
{
  arm_control_interfaces__srv__GetPointCloud_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetPointCloud in the package arm_control_interfaces.
typedef struct arm_control_interfaces__srv__GetPointCloud_Event
{
  service_msgs__msg__ServiceEventInfo info;
  arm_control_interfaces__srv__GetPointCloud_Request__Sequence request;
  arm_control_interfaces__srv__GetPointCloud_Response__Sequence response;
} arm_control_interfaces__srv__GetPointCloud_Event;

// Struct for a sequence of arm_control_interfaces__srv__GetPointCloud_Event.
typedef struct arm_control_interfaces__srv__GetPointCloud_Event__Sequence
{
  arm_control_interfaces__srv__GetPointCloud_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arm_control_interfaces__srv__GetPointCloud_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_POINT_CLOUD__STRUCT_H_
