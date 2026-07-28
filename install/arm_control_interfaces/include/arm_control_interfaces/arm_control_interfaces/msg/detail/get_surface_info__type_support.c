// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from arm_control_interfaces:msg/GetSurfaceInfo.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "arm_control_interfaces/msg/detail/get_surface_info__rosidl_typesupport_introspection_c.h"
#include "arm_control_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "arm_control_interfaces/msg/detail/get_surface_info__functions.h"
#include "arm_control_interfaces/msg/detail/get_surface_info__struct.h"


// Include directives for member types
// Member `surface_centroid`
// Member `spill_centroid`
#include "geometry_msgs/msg/point.h"
// Member `surface_centroid`
// Member `spill_centroid`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `surface_normal`
// Member `spill_normal`
#include "geometry_msgs/msg/vector3.h"
// Member `surface_normal`
// Member `spill_normal`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"
// Member `point_cloud`
#include "sensor_msgs/msg/point_cloud2.h"
// Member `point_cloud`
#include "sensor_msgs/msg/detail/point_cloud2__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void arm_control_interfaces__msg__GetSurfaceInfo__rosidl_typesupport_introspection_c__GetSurfaceInfo_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  arm_control_interfaces__msg__GetSurfaceInfo__init(message_memory);
}

void arm_control_interfaces__msg__GetSurfaceInfo__rosidl_typesupport_introspection_c__GetSurfaceInfo_fini_function(void * message_memory)
{
  arm_control_interfaces__msg__GetSurfaceInfo__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember arm_control_interfaces__msg__GetSurfaceInfo__rosidl_typesupport_introspection_c__GetSurfaceInfo_message_member_array[6] = {
  {
    "surface_centroid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_control_interfaces__msg__GetSurfaceInfo, surface_centroid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "surface_normal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_control_interfaces__msg__GetSurfaceInfo, surface_normal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "spill_centroid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_control_interfaces__msg__GetSurfaceInfo, spill_centroid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "spill_normal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_control_interfaces__msg__GetSurfaceInfo, spill_normal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "point_cloud",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_control_interfaces__msg__GetSurfaceInfo, point_cloud),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_control_interfaces__msg__GetSurfaceInfo, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers arm_control_interfaces__msg__GetSurfaceInfo__rosidl_typesupport_introspection_c__GetSurfaceInfo_message_members = {
  "arm_control_interfaces__msg",  // message namespace
  "GetSurfaceInfo",  // message name
  6,  // number of fields
  sizeof(arm_control_interfaces__msg__GetSurfaceInfo),
  false,  // has_any_key_member_
  arm_control_interfaces__msg__GetSurfaceInfo__rosidl_typesupport_introspection_c__GetSurfaceInfo_message_member_array,  // message members
  arm_control_interfaces__msg__GetSurfaceInfo__rosidl_typesupport_introspection_c__GetSurfaceInfo_init_function,  // function to initialize message memory (memory has to be allocated)
  arm_control_interfaces__msg__GetSurfaceInfo__rosidl_typesupport_introspection_c__GetSurfaceInfo_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t arm_control_interfaces__msg__GetSurfaceInfo__rosidl_typesupport_introspection_c__GetSurfaceInfo_message_type_support_handle = {
  0,
  &arm_control_interfaces__msg__GetSurfaceInfo__rosidl_typesupport_introspection_c__GetSurfaceInfo_message_members,
  get_message_typesupport_handle_function,
  &arm_control_interfaces__msg__GetSurfaceInfo__get_type_hash,
  &arm_control_interfaces__msg__GetSurfaceInfo__get_type_description,
  &arm_control_interfaces__msg__GetSurfaceInfo__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_arm_control_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arm_control_interfaces, msg, GetSurfaceInfo)() {
  arm_control_interfaces__msg__GetSurfaceInfo__rosidl_typesupport_introspection_c__GetSurfaceInfo_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  arm_control_interfaces__msg__GetSurfaceInfo__rosidl_typesupport_introspection_c__GetSurfaceInfo_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  arm_control_interfaces__msg__GetSurfaceInfo__rosidl_typesupport_introspection_c__GetSurfaceInfo_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  arm_control_interfaces__msg__GetSurfaceInfo__rosidl_typesupport_introspection_c__GetSurfaceInfo_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  arm_control_interfaces__msg__GetSurfaceInfo__rosidl_typesupport_introspection_c__GetSurfaceInfo_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, PointCloud2)();
  if (!arm_control_interfaces__msg__GetSurfaceInfo__rosidl_typesupport_introspection_c__GetSurfaceInfo_message_type_support_handle.typesupport_identifier) {
    arm_control_interfaces__msg__GetSurfaceInfo__rosidl_typesupport_introspection_c__GetSurfaceInfo_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &arm_control_interfaces__msg__GetSurfaceInfo__rosidl_typesupport_introspection_c__GetSurfaceInfo_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
