// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from arm_control_interfaces:msg/GetSurfaceInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "arm_control_interfaces/msg/get_surface_info.h"


#ifndef ARM_CONTROL_INTERFACES__MSG__DETAIL__GET_SURFACE_INFO__STRUCT_H_
#define ARM_CONTROL_INTERFACES__MSG__DETAIL__GET_SURFACE_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

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

/// Struct defined in msg/GetSurfaceInfo in the package arm_control_interfaces.
/**
  * msg/GetSurfaceInfo.msg
 */
typedef struct arm_control_interfaces__msg__GetSurfaceInfo
{
  geometry_msgs__msg__Point surface_centroid;
  geometry_msgs__msg__Vector3 surface_normal;
  geometry_msgs__msg__Point spill_centroid;
  geometry_msgs__msg__Vector3 spill_normal;
  sensor_msgs__msg__PointCloud2 point_cloud;
  bool success;
} arm_control_interfaces__msg__GetSurfaceInfo;

// Struct for a sequence of arm_control_interfaces__msg__GetSurfaceInfo.
typedef struct arm_control_interfaces__msg__GetSurfaceInfo__Sequence
{
  arm_control_interfaces__msg__GetSurfaceInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arm_control_interfaces__msg__GetSurfaceInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARM_CONTROL_INTERFACES__MSG__DETAIL__GET_SURFACE_INFO__STRUCT_H_
