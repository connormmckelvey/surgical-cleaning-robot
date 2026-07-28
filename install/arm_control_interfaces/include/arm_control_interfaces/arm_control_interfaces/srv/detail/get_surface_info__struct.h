// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from arm_control_interfaces:srv/GetSurfaceInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "arm_control_interfaces/srv/get_surface_info.h"


#ifndef ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_SURFACE_INFO__STRUCT_H_
#define ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_SURFACE_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetSurfaceInfo in the package arm_control_interfaces.
typedef struct arm_control_interfaces__srv__GetSurfaceInfo_Request
{
  int32_t x;
  int32_t y;
} arm_control_interfaces__srv__GetSurfaceInfo_Request;

// Struct for a sequence of arm_control_interfaces__srv__GetSurfaceInfo_Request.
typedef struct arm_control_interfaces__srv__GetSurfaceInfo_Request__Sequence
{
  arm_control_interfaces__srv__GetSurfaceInfo_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arm_control_interfaces__srv__GetSurfaceInfo_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'surface_centroid'
// Member 'spill_centroid'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'surface_normal'
// Member 'spill_normal'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'point_cloud'
#include "sensor_msgs/msg/detail/point_cloud2__struct.h"

/// Struct defined in srv/GetSurfaceInfo in the package arm_control_interfaces.
typedef struct arm_control_interfaces__srv__GetSurfaceInfo_Response
{
  geometry_msgs__msg__Point surface_centroid;
  geometry_msgs__msg__Vector3 surface_normal;
  geometry_msgs__msg__Point spill_centroid;
  geometry_msgs__msg__Vector3 spill_normal;
  sensor_msgs__msg__PointCloud2 point_cloud;
  bool success;
} arm_control_interfaces__srv__GetSurfaceInfo_Response;

// Struct for a sequence of arm_control_interfaces__srv__GetSurfaceInfo_Response.
typedef struct arm_control_interfaces__srv__GetSurfaceInfo_Response__Sequence
{
  arm_control_interfaces__srv__GetSurfaceInfo_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arm_control_interfaces__srv__GetSurfaceInfo_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  arm_control_interfaces__srv__GetSurfaceInfo_Event__request__MAX_SIZE = 1
};
// response
enum
{
  arm_control_interfaces__srv__GetSurfaceInfo_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetSurfaceInfo in the package arm_control_interfaces.
typedef struct arm_control_interfaces__srv__GetSurfaceInfo_Event
{
  service_msgs__msg__ServiceEventInfo info;
  arm_control_interfaces__srv__GetSurfaceInfo_Request__Sequence request;
  arm_control_interfaces__srv__GetSurfaceInfo_Response__Sequence response;
} arm_control_interfaces__srv__GetSurfaceInfo_Event;

// Struct for a sequence of arm_control_interfaces__srv__GetSurfaceInfo_Event.
typedef struct arm_control_interfaces__srv__GetSurfaceInfo_Event__Sequence
{
  arm_control_interfaces__srv__GetSurfaceInfo_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arm_control_interfaces__srv__GetSurfaceInfo_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_SURFACE_INFO__STRUCT_H_
