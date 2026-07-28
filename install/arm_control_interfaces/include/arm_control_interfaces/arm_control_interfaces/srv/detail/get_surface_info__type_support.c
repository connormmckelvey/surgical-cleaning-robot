// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from arm_control_interfaces:srv/GetSurfaceInfo.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "arm_control_interfaces/srv/detail/get_surface_info__rosidl_typesupport_introspection_c.h"
#include "arm_control_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "arm_control_interfaces/srv/detail/get_surface_info__functions.h"
#include "arm_control_interfaces/srv/detail/get_surface_info__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void arm_control_interfaces__srv__GetSurfaceInfo_Request__rosidl_typesupport_introspection_c__GetSurfaceInfo_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  arm_control_interfaces__srv__GetSurfaceInfo_Request__init(message_memory);
}

void arm_control_interfaces__srv__GetSurfaceInfo_Request__rosidl_typesupport_introspection_c__GetSurfaceInfo_Request_fini_function(void * message_memory)
{
  arm_control_interfaces__srv__GetSurfaceInfo_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember arm_control_interfaces__srv__GetSurfaceInfo_Request__rosidl_typesupport_introspection_c__GetSurfaceInfo_Request_message_member_array[2] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_control_interfaces__srv__GetSurfaceInfo_Request, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_control_interfaces__srv__GetSurfaceInfo_Request, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers arm_control_interfaces__srv__GetSurfaceInfo_Request__rosidl_typesupport_introspection_c__GetSurfaceInfo_Request_message_members = {
  "arm_control_interfaces__srv",  // message namespace
  "GetSurfaceInfo_Request",  // message name
  2,  // number of fields
  sizeof(arm_control_interfaces__srv__GetSurfaceInfo_Request),
  false,  // has_any_key_member_
  arm_control_interfaces__srv__GetSurfaceInfo_Request__rosidl_typesupport_introspection_c__GetSurfaceInfo_Request_message_member_array,  // message members
  arm_control_interfaces__srv__GetSurfaceInfo_Request__rosidl_typesupport_introspection_c__GetSurfaceInfo_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  arm_control_interfaces__srv__GetSurfaceInfo_Request__rosidl_typesupport_introspection_c__GetSurfaceInfo_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t arm_control_interfaces__srv__GetSurfaceInfo_Request__rosidl_typesupport_introspection_c__GetSurfaceInfo_Request_message_type_support_handle = {
  0,
  &arm_control_interfaces__srv__GetSurfaceInfo_Request__rosidl_typesupport_introspection_c__GetSurfaceInfo_Request_message_members,
  get_message_typesupport_handle_function,
  &arm_control_interfaces__srv__GetSurfaceInfo_Request__get_type_hash,
  &arm_control_interfaces__srv__GetSurfaceInfo_Request__get_type_description,
  &arm_control_interfaces__srv__GetSurfaceInfo_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_arm_control_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arm_control_interfaces, srv, GetSurfaceInfo_Request)() {
  if (!arm_control_interfaces__srv__GetSurfaceInfo_Request__rosidl_typesupport_introspection_c__GetSurfaceInfo_Request_message_type_support_handle.typesupport_identifier) {
    arm_control_interfaces__srv__GetSurfaceInfo_Request__rosidl_typesupport_introspection_c__GetSurfaceInfo_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &arm_control_interfaces__srv__GetSurfaceInfo_Request__rosidl_typesupport_introspection_c__GetSurfaceInfo_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "arm_control_interfaces/srv/detail/get_surface_info__rosidl_typesupport_introspection_c.h"
// already included above
// #include "arm_control_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "arm_control_interfaces/srv/detail/get_surface_info__functions.h"
// already included above
// #include "arm_control_interfaces/srv/detail/get_surface_info__struct.h"


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

void arm_control_interfaces__srv__GetSurfaceInfo_Response__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  arm_control_interfaces__srv__GetSurfaceInfo_Response__init(message_memory);
}

void arm_control_interfaces__srv__GetSurfaceInfo_Response__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_fini_function(void * message_memory)
{
  arm_control_interfaces__srv__GetSurfaceInfo_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember arm_control_interfaces__srv__GetSurfaceInfo_Response__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_message_member_array[6] = {
  {
    "surface_centroid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_control_interfaces__srv__GetSurfaceInfo_Response, surface_centroid),  // bytes offset in struct
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
    offsetof(arm_control_interfaces__srv__GetSurfaceInfo_Response, surface_normal),  // bytes offset in struct
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
    offsetof(arm_control_interfaces__srv__GetSurfaceInfo_Response, spill_centroid),  // bytes offset in struct
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
    offsetof(arm_control_interfaces__srv__GetSurfaceInfo_Response, spill_normal),  // bytes offset in struct
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
    offsetof(arm_control_interfaces__srv__GetSurfaceInfo_Response, point_cloud),  // bytes offset in struct
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
    offsetof(arm_control_interfaces__srv__GetSurfaceInfo_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers arm_control_interfaces__srv__GetSurfaceInfo_Response__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_message_members = {
  "arm_control_interfaces__srv",  // message namespace
  "GetSurfaceInfo_Response",  // message name
  6,  // number of fields
  sizeof(arm_control_interfaces__srv__GetSurfaceInfo_Response),
  false,  // has_any_key_member_
  arm_control_interfaces__srv__GetSurfaceInfo_Response__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_message_member_array,  // message members
  arm_control_interfaces__srv__GetSurfaceInfo_Response__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  arm_control_interfaces__srv__GetSurfaceInfo_Response__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t arm_control_interfaces__srv__GetSurfaceInfo_Response__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_message_type_support_handle = {
  0,
  &arm_control_interfaces__srv__GetSurfaceInfo_Response__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_message_members,
  get_message_typesupport_handle_function,
  &arm_control_interfaces__srv__GetSurfaceInfo_Response__get_type_hash,
  &arm_control_interfaces__srv__GetSurfaceInfo_Response__get_type_description,
  &arm_control_interfaces__srv__GetSurfaceInfo_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_arm_control_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arm_control_interfaces, srv, GetSurfaceInfo_Response)() {
  arm_control_interfaces__srv__GetSurfaceInfo_Response__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  arm_control_interfaces__srv__GetSurfaceInfo_Response__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  arm_control_interfaces__srv__GetSurfaceInfo_Response__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  arm_control_interfaces__srv__GetSurfaceInfo_Response__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  arm_control_interfaces__srv__GetSurfaceInfo_Response__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, PointCloud2)();
  if (!arm_control_interfaces__srv__GetSurfaceInfo_Response__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_message_type_support_handle.typesupport_identifier) {
    arm_control_interfaces__srv__GetSurfaceInfo_Response__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &arm_control_interfaces__srv__GetSurfaceInfo_Response__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "arm_control_interfaces/srv/detail/get_surface_info__rosidl_typesupport_introspection_c.h"
// already included above
// #include "arm_control_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "arm_control_interfaces/srv/detail/get_surface_info__functions.h"
// already included above
// #include "arm_control_interfaces/srv/detail/get_surface_info__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "arm_control_interfaces/srv/get_surface_info.h"
// Member `request`
// Member `response`
// already included above
// #include "arm_control_interfaces/srv/detail/get_surface_info__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__GetSurfaceInfo_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  arm_control_interfaces__srv__GetSurfaceInfo_Event__init(message_memory);
}

void arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__GetSurfaceInfo_Event_fini_function(void * message_memory)
{
  arm_control_interfaces__srv__GetSurfaceInfo_Event__fini(message_memory);
}

size_t arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__size_function__GetSurfaceInfo_Event__request(
  const void * untyped_member)
{
  const arm_control_interfaces__srv__GetSurfaceInfo_Request__Sequence * member =
    (const arm_control_interfaces__srv__GetSurfaceInfo_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__get_const_function__GetSurfaceInfo_Event__request(
  const void * untyped_member, size_t index)
{
  const arm_control_interfaces__srv__GetSurfaceInfo_Request__Sequence * member =
    (const arm_control_interfaces__srv__GetSurfaceInfo_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__get_function__GetSurfaceInfo_Event__request(
  void * untyped_member, size_t index)
{
  arm_control_interfaces__srv__GetSurfaceInfo_Request__Sequence * member =
    (arm_control_interfaces__srv__GetSurfaceInfo_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__fetch_function__GetSurfaceInfo_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const arm_control_interfaces__srv__GetSurfaceInfo_Request * item =
    ((const arm_control_interfaces__srv__GetSurfaceInfo_Request *)
    arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__get_const_function__GetSurfaceInfo_Event__request(untyped_member, index));
  arm_control_interfaces__srv__GetSurfaceInfo_Request * value =
    (arm_control_interfaces__srv__GetSurfaceInfo_Request *)(untyped_value);
  *value = *item;
}

void arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__assign_function__GetSurfaceInfo_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  arm_control_interfaces__srv__GetSurfaceInfo_Request * item =
    ((arm_control_interfaces__srv__GetSurfaceInfo_Request *)
    arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__get_function__GetSurfaceInfo_Event__request(untyped_member, index));
  const arm_control_interfaces__srv__GetSurfaceInfo_Request * value =
    (const arm_control_interfaces__srv__GetSurfaceInfo_Request *)(untyped_value);
  *item = *value;
}

bool arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__resize_function__GetSurfaceInfo_Event__request(
  void * untyped_member, size_t size)
{
  arm_control_interfaces__srv__GetSurfaceInfo_Request__Sequence * member =
    (arm_control_interfaces__srv__GetSurfaceInfo_Request__Sequence *)(untyped_member);
  arm_control_interfaces__srv__GetSurfaceInfo_Request__Sequence__fini(member);
  return arm_control_interfaces__srv__GetSurfaceInfo_Request__Sequence__init(member, size);
}

size_t arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__size_function__GetSurfaceInfo_Event__response(
  const void * untyped_member)
{
  const arm_control_interfaces__srv__GetSurfaceInfo_Response__Sequence * member =
    (const arm_control_interfaces__srv__GetSurfaceInfo_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__get_const_function__GetSurfaceInfo_Event__response(
  const void * untyped_member, size_t index)
{
  const arm_control_interfaces__srv__GetSurfaceInfo_Response__Sequence * member =
    (const arm_control_interfaces__srv__GetSurfaceInfo_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__get_function__GetSurfaceInfo_Event__response(
  void * untyped_member, size_t index)
{
  arm_control_interfaces__srv__GetSurfaceInfo_Response__Sequence * member =
    (arm_control_interfaces__srv__GetSurfaceInfo_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__fetch_function__GetSurfaceInfo_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const arm_control_interfaces__srv__GetSurfaceInfo_Response * item =
    ((const arm_control_interfaces__srv__GetSurfaceInfo_Response *)
    arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__get_const_function__GetSurfaceInfo_Event__response(untyped_member, index));
  arm_control_interfaces__srv__GetSurfaceInfo_Response * value =
    (arm_control_interfaces__srv__GetSurfaceInfo_Response *)(untyped_value);
  *value = *item;
}

void arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__assign_function__GetSurfaceInfo_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  arm_control_interfaces__srv__GetSurfaceInfo_Response * item =
    ((arm_control_interfaces__srv__GetSurfaceInfo_Response *)
    arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__get_function__GetSurfaceInfo_Event__response(untyped_member, index));
  const arm_control_interfaces__srv__GetSurfaceInfo_Response * value =
    (const arm_control_interfaces__srv__GetSurfaceInfo_Response *)(untyped_value);
  *item = *value;
}

bool arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__resize_function__GetSurfaceInfo_Event__response(
  void * untyped_member, size_t size)
{
  arm_control_interfaces__srv__GetSurfaceInfo_Response__Sequence * member =
    (arm_control_interfaces__srv__GetSurfaceInfo_Response__Sequence *)(untyped_member);
  arm_control_interfaces__srv__GetSurfaceInfo_Response__Sequence__fini(member);
  return arm_control_interfaces__srv__GetSurfaceInfo_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__GetSurfaceInfo_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_control_interfaces__srv__GetSurfaceInfo_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(arm_control_interfaces__srv__GetSurfaceInfo_Event, request),  // bytes offset in struct
    NULL,  // default value
    arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__size_function__GetSurfaceInfo_Event__request,  // size() function pointer
    arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__get_const_function__GetSurfaceInfo_Event__request,  // get_const(index) function pointer
    arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__get_function__GetSurfaceInfo_Event__request,  // get(index) function pointer
    arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__fetch_function__GetSurfaceInfo_Event__request,  // fetch(index, &value) function pointer
    arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__assign_function__GetSurfaceInfo_Event__request,  // assign(index, value) function pointer
    arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__resize_function__GetSurfaceInfo_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(arm_control_interfaces__srv__GetSurfaceInfo_Event, response),  // bytes offset in struct
    NULL,  // default value
    arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__size_function__GetSurfaceInfo_Event__response,  // size() function pointer
    arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__get_const_function__GetSurfaceInfo_Event__response,  // get_const(index) function pointer
    arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__get_function__GetSurfaceInfo_Event__response,  // get(index) function pointer
    arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__fetch_function__GetSurfaceInfo_Event__response,  // fetch(index, &value) function pointer
    arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__assign_function__GetSurfaceInfo_Event__response,  // assign(index, value) function pointer
    arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__resize_function__GetSurfaceInfo_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__GetSurfaceInfo_Event_message_members = {
  "arm_control_interfaces__srv",  // message namespace
  "GetSurfaceInfo_Event",  // message name
  3,  // number of fields
  sizeof(arm_control_interfaces__srv__GetSurfaceInfo_Event),
  false,  // has_any_key_member_
  arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__GetSurfaceInfo_Event_message_member_array,  // message members
  arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__GetSurfaceInfo_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__GetSurfaceInfo_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__GetSurfaceInfo_Event_message_type_support_handle = {
  0,
  &arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__GetSurfaceInfo_Event_message_members,
  get_message_typesupport_handle_function,
  &arm_control_interfaces__srv__GetSurfaceInfo_Event__get_type_hash,
  &arm_control_interfaces__srv__GetSurfaceInfo_Event__get_type_description,
  &arm_control_interfaces__srv__GetSurfaceInfo_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_arm_control_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arm_control_interfaces, srv, GetSurfaceInfo_Event)() {
  arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__GetSurfaceInfo_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__GetSurfaceInfo_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arm_control_interfaces, srv, GetSurfaceInfo_Request)();
  arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__GetSurfaceInfo_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arm_control_interfaces, srv, GetSurfaceInfo_Response)();
  if (!arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__GetSurfaceInfo_Event_message_type_support_handle.typesupport_identifier) {
    arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__GetSurfaceInfo_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__GetSurfaceInfo_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "arm_control_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "arm_control_interfaces/srv/detail/get_surface_info__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers arm_control_interfaces__srv__detail__get_surface_info__rosidl_typesupport_introspection_c__GetSurfaceInfo_service_members = {
  "arm_control_interfaces__srv",  // service namespace
  "GetSurfaceInfo",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // arm_control_interfaces__srv__detail__get_surface_info__rosidl_typesupport_introspection_c__GetSurfaceInfo_Request_message_type_support_handle,
  NULL,  // response message
  // arm_control_interfaces__srv__detail__get_surface_info__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_message_type_support_handle
  NULL  // event_message
  // arm_control_interfaces__srv__detail__get_surface_info__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_message_type_support_handle
};


static rosidl_service_type_support_t arm_control_interfaces__srv__detail__get_surface_info__rosidl_typesupport_introspection_c__GetSurfaceInfo_service_type_support_handle = {
  0,
  &arm_control_interfaces__srv__detail__get_surface_info__rosidl_typesupport_introspection_c__GetSurfaceInfo_service_members,
  get_service_typesupport_handle_function,
  &arm_control_interfaces__srv__GetSurfaceInfo_Request__rosidl_typesupport_introspection_c__GetSurfaceInfo_Request_message_type_support_handle,
  &arm_control_interfaces__srv__GetSurfaceInfo_Response__rosidl_typesupport_introspection_c__GetSurfaceInfo_Response_message_type_support_handle,
  &arm_control_interfaces__srv__GetSurfaceInfo_Event__rosidl_typesupport_introspection_c__GetSurfaceInfo_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    arm_control_interfaces,
    srv,
    GetSurfaceInfo
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    arm_control_interfaces,
    srv,
    GetSurfaceInfo
  ),
  &arm_control_interfaces__srv__GetSurfaceInfo__get_type_hash,
  &arm_control_interfaces__srv__GetSurfaceInfo__get_type_description,
  &arm_control_interfaces__srv__GetSurfaceInfo__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arm_control_interfaces, srv, GetSurfaceInfo_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arm_control_interfaces, srv, GetSurfaceInfo_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arm_control_interfaces, srv, GetSurfaceInfo_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_arm_control_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arm_control_interfaces, srv, GetSurfaceInfo)(void) {
  if (!arm_control_interfaces__srv__detail__get_surface_info__rosidl_typesupport_introspection_c__GetSurfaceInfo_service_type_support_handle.typesupport_identifier) {
    arm_control_interfaces__srv__detail__get_surface_info__rosidl_typesupport_introspection_c__GetSurfaceInfo_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)arm_control_interfaces__srv__detail__get_surface_info__rosidl_typesupport_introspection_c__GetSurfaceInfo_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arm_control_interfaces, srv, GetSurfaceInfo_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arm_control_interfaces, srv, GetSurfaceInfo_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arm_control_interfaces, srv, GetSurfaceInfo_Event)()->data;
  }

  return &arm_control_interfaces__srv__detail__get_surface_info__rosidl_typesupport_introspection_c__GetSurfaceInfo_service_type_support_handle;
}
