// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from arm_control_interfaces:srv/GetPlaneAtPixel.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "arm_control_interfaces/srv/get_plane_at_pixel.h"


#ifndef ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_PLANE_AT_PIXEL__STRUCT_H_
#define ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_PLANE_AT_PIXEL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetPlaneAtPixel in the package arm_control_interfaces.
typedef struct arm_control_interfaces__srv__GetPlaneAtPixel_Request
{
  int32_t x;
  int32_t y;
} arm_control_interfaces__srv__GetPlaneAtPixel_Request;

// Struct for a sequence of arm_control_interfaces__srv__GetPlaneAtPixel_Request.
typedef struct arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence
{
  arm_control_interfaces__srv__GetPlaneAtPixel_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'centroid'
// Member 'boundary_points'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'normal'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in srv/GetPlaneAtPixel in the package arm_control_interfaces.
typedef struct arm_control_interfaces__srv__GetPlaneAtPixel_Response
{
  bool success;
  geometry_msgs__msg__Point centroid;
  geometry_msgs__msg__Vector3 normal;
  geometry_msgs__msg__Point__Sequence boundary_points;
  double fx;
  double fy;
  double cx;
  double cy;
} arm_control_interfaces__srv__GetPlaneAtPixel_Response;

// Struct for a sequence of arm_control_interfaces__srv__GetPlaneAtPixel_Response.
typedef struct arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence
{
  arm_control_interfaces__srv__GetPlaneAtPixel_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  arm_control_interfaces__srv__GetPlaneAtPixel_Event__request__MAX_SIZE = 1
};
// response
enum
{
  arm_control_interfaces__srv__GetPlaneAtPixel_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetPlaneAtPixel in the package arm_control_interfaces.
typedef struct arm_control_interfaces__srv__GetPlaneAtPixel_Event
{
  service_msgs__msg__ServiceEventInfo info;
  arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence request;
  arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence response;
} arm_control_interfaces__srv__GetPlaneAtPixel_Event;

// Struct for a sequence of arm_control_interfaces__srv__GetPlaneAtPixel_Event.
typedef struct arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence
{
  arm_control_interfaces__srv__GetPlaneAtPixel_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_PLANE_AT_PIXEL__STRUCT_H_
