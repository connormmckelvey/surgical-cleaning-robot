// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from arm_control_interfaces:srv/GetSurfaceInfo.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "arm_control_interfaces/srv/detail/get_surface_info__functions.h"
#include "arm_control_interfaces/srv/detail/get_surface_info__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace arm_control_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void GetSurfaceInfo_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) arm_control_interfaces::srv::GetSurfaceInfo_Request(_init);
}

void GetSurfaceInfo_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<arm_control_interfaces::srv::GetSurfaceInfo_Request *>(message_memory);
  typed_message->~GetSurfaceInfo_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetSurfaceInfo_Request_message_member_array[2] = {
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_control_interfaces::srv::GetSurfaceInfo_Request, x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_control_interfaces::srv::GetSurfaceInfo_Request, y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetSurfaceInfo_Request_message_members = {
  "arm_control_interfaces::srv",  // message namespace
  "GetSurfaceInfo_Request",  // message name
  2,  // number of fields
  sizeof(arm_control_interfaces::srv::GetSurfaceInfo_Request),
  false,  // has_any_key_member_
  GetSurfaceInfo_Request_message_member_array,  // message members
  GetSurfaceInfo_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  GetSurfaceInfo_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetSurfaceInfo_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetSurfaceInfo_Request_message_members,
  get_message_typesupport_handle_function,
  &arm_control_interfaces__srv__GetSurfaceInfo_Request__get_type_hash,
  &arm_control_interfaces__srv__GetSurfaceInfo_Request__get_type_description,
  &arm_control_interfaces__srv__GetSurfaceInfo_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace arm_control_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<arm_control_interfaces::srv::GetSurfaceInfo_Request>()
{
  return &::arm_control_interfaces::srv::rosidl_typesupport_introspection_cpp::GetSurfaceInfo_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, arm_control_interfaces, srv, GetSurfaceInfo_Request)() {
  return &::arm_control_interfaces::srv::rosidl_typesupport_introspection_cpp::GetSurfaceInfo_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "arm_control_interfaces/srv/detail/get_surface_info__functions.h"
// already included above
// #include "arm_control_interfaces/srv/detail/get_surface_info__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace arm_control_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void GetSurfaceInfo_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) arm_control_interfaces::srv::GetSurfaceInfo_Response(_init);
}

void GetSurfaceInfo_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<arm_control_interfaces::srv::GetSurfaceInfo_Response *>(message_memory);
  typed_message->~GetSurfaceInfo_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetSurfaceInfo_Response_message_member_array[6] = {
  {
    "surface_centroid",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_control_interfaces::srv::GetSurfaceInfo_Response, surface_centroid),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "surface_normal",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Vector3>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_control_interfaces::srv::GetSurfaceInfo_Response, surface_normal),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "spill_centroid",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_control_interfaces::srv::GetSurfaceInfo_Response, spill_centroid),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "spill_normal",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Vector3>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_control_interfaces::srv::GetSurfaceInfo_Response, spill_normal),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "point_cloud",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::PointCloud2>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_control_interfaces::srv::GetSurfaceInfo_Response, point_cloud),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_control_interfaces::srv::GetSurfaceInfo_Response, success),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetSurfaceInfo_Response_message_members = {
  "arm_control_interfaces::srv",  // message namespace
  "GetSurfaceInfo_Response",  // message name
  6,  // number of fields
  sizeof(arm_control_interfaces::srv::GetSurfaceInfo_Response),
  false,  // has_any_key_member_
  GetSurfaceInfo_Response_message_member_array,  // message members
  GetSurfaceInfo_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  GetSurfaceInfo_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetSurfaceInfo_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetSurfaceInfo_Response_message_members,
  get_message_typesupport_handle_function,
  &arm_control_interfaces__srv__GetSurfaceInfo_Response__get_type_hash,
  &arm_control_interfaces__srv__GetSurfaceInfo_Response__get_type_description,
  &arm_control_interfaces__srv__GetSurfaceInfo_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace arm_control_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<arm_control_interfaces::srv::GetSurfaceInfo_Response>()
{
  return &::arm_control_interfaces::srv::rosidl_typesupport_introspection_cpp::GetSurfaceInfo_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, arm_control_interfaces, srv, GetSurfaceInfo_Response)() {
  return &::arm_control_interfaces::srv::rosidl_typesupport_introspection_cpp::GetSurfaceInfo_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "arm_control_interfaces/srv/detail/get_surface_info__functions.h"
// already included above
// #include "arm_control_interfaces/srv/detail/get_surface_info__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace arm_control_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void GetSurfaceInfo_Event_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) arm_control_interfaces::srv::GetSurfaceInfo_Event(_init);
}

void GetSurfaceInfo_Event_fini_function(void * message_memory)
{
  auto typed_message = static_cast<arm_control_interfaces::srv::GetSurfaceInfo_Event *>(message_memory);
  typed_message->~GetSurfaceInfo_Event();
}

size_t size_function__GetSurfaceInfo_Event__request(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<arm_control_interfaces::srv::GetSurfaceInfo_Request> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetSurfaceInfo_Event__request(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<arm_control_interfaces::srv::GetSurfaceInfo_Request> *>(untyped_member);
  return &member[index];
}

void * get_function__GetSurfaceInfo_Event__request(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<arm_control_interfaces::srv::GetSurfaceInfo_Request> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetSurfaceInfo_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const arm_control_interfaces::srv::GetSurfaceInfo_Request *>(
    get_const_function__GetSurfaceInfo_Event__request(untyped_member, index));
  auto & value = *reinterpret_cast<arm_control_interfaces::srv::GetSurfaceInfo_Request *>(untyped_value);
  value = item;
}

void assign_function__GetSurfaceInfo_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<arm_control_interfaces::srv::GetSurfaceInfo_Request *>(
    get_function__GetSurfaceInfo_Event__request(untyped_member, index));
  const auto & value = *reinterpret_cast<const arm_control_interfaces::srv::GetSurfaceInfo_Request *>(untyped_value);
  item = value;
}

void resize_function__GetSurfaceInfo_Event__request(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<arm_control_interfaces::srv::GetSurfaceInfo_Request> *>(untyped_member);
  member->resize(size);
}

size_t size_function__GetSurfaceInfo_Event__response(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<arm_control_interfaces::srv::GetSurfaceInfo_Response> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetSurfaceInfo_Event__response(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<arm_control_interfaces::srv::GetSurfaceInfo_Response> *>(untyped_member);
  return &member[index];
}

void * get_function__GetSurfaceInfo_Event__response(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<arm_control_interfaces::srv::GetSurfaceInfo_Response> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetSurfaceInfo_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const arm_control_interfaces::srv::GetSurfaceInfo_Response *>(
    get_const_function__GetSurfaceInfo_Event__response(untyped_member, index));
  auto & value = *reinterpret_cast<arm_control_interfaces::srv::GetSurfaceInfo_Response *>(untyped_value);
  value = item;
}

void assign_function__GetSurfaceInfo_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<arm_control_interfaces::srv::GetSurfaceInfo_Response *>(
    get_function__GetSurfaceInfo_Event__response(untyped_member, index));
  const auto & value = *reinterpret_cast<const arm_control_interfaces::srv::GetSurfaceInfo_Response *>(untyped_value);
  item = value;
}

void resize_function__GetSurfaceInfo_Event__response(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<arm_control_interfaces::srv::GetSurfaceInfo_Response> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetSurfaceInfo_Event_message_member_array[3] = {
  {
    "info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<service_msgs::msg::ServiceEventInfo>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_control_interfaces::srv::GetSurfaceInfo_Event, info),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "request",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<arm_control_interfaces::srv::GetSurfaceInfo_Request>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(arm_control_interfaces::srv::GetSurfaceInfo_Event, request),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetSurfaceInfo_Event__request,  // size() function pointer
    get_const_function__GetSurfaceInfo_Event__request,  // get_const(index) function pointer
    get_function__GetSurfaceInfo_Event__request,  // get(index) function pointer
    fetch_function__GetSurfaceInfo_Event__request,  // fetch(index, &value) function pointer
    assign_function__GetSurfaceInfo_Event__request,  // assign(index, value) function pointer
    resize_function__GetSurfaceInfo_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<arm_control_interfaces::srv::GetSurfaceInfo_Response>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(arm_control_interfaces::srv::GetSurfaceInfo_Event, response),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetSurfaceInfo_Event__response,  // size() function pointer
    get_const_function__GetSurfaceInfo_Event__response,  // get_const(index) function pointer
    get_function__GetSurfaceInfo_Event__response,  // get(index) function pointer
    fetch_function__GetSurfaceInfo_Event__response,  // fetch(index, &value) function pointer
    assign_function__GetSurfaceInfo_Event__response,  // assign(index, value) function pointer
    resize_function__GetSurfaceInfo_Event__response  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetSurfaceInfo_Event_message_members = {
  "arm_control_interfaces::srv",  // message namespace
  "GetSurfaceInfo_Event",  // message name
  3,  // number of fields
  sizeof(arm_control_interfaces::srv::GetSurfaceInfo_Event),
  false,  // has_any_key_member_
  GetSurfaceInfo_Event_message_member_array,  // message members
  GetSurfaceInfo_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  GetSurfaceInfo_Event_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetSurfaceInfo_Event_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetSurfaceInfo_Event_message_members,
  get_message_typesupport_handle_function,
  &arm_control_interfaces__srv__GetSurfaceInfo_Event__get_type_hash,
  &arm_control_interfaces__srv__GetSurfaceInfo_Event__get_type_description,
  &arm_control_interfaces__srv__GetSurfaceInfo_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace arm_control_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<arm_control_interfaces::srv::GetSurfaceInfo_Event>()
{
  return &::arm_control_interfaces::srv::rosidl_typesupport_introspection_cpp::GetSurfaceInfo_Event_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, arm_control_interfaces, srv, GetSurfaceInfo_Event)() {
  return &::arm_control_interfaces::srv::rosidl_typesupport_introspection_cpp::GetSurfaceInfo_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "arm_control_interfaces/srv/detail/get_surface_info__functions.h"
// already included above
// #include "arm_control_interfaces/srv/detail/get_surface_info__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace arm_control_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers GetSurfaceInfo_service_members = {
  "arm_control_interfaces::srv",  // service namespace
  "GetSurfaceInfo",  // service name
  // the following fields are initialized below on first access
  // see get_service_type_support_handle<arm_control_interfaces::srv::GetSurfaceInfo>()
  nullptr,  // request message
  nullptr,  // response message
  nullptr,  // event message
};

static const rosidl_service_type_support_t GetSurfaceInfo_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetSurfaceInfo_service_members,
  get_service_typesupport_handle_function,
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<arm_control_interfaces::srv::GetSurfaceInfo_Request>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<arm_control_interfaces::srv::GetSurfaceInfo_Response>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<arm_control_interfaces::srv::GetSurfaceInfo_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<arm_control_interfaces::srv::GetSurfaceInfo>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<arm_control_interfaces::srv::GetSurfaceInfo>,
  &arm_control_interfaces__srv__GetSurfaceInfo__get_type_hash,
  &arm_control_interfaces__srv__GetSurfaceInfo__get_type_description,
  &arm_control_interfaces__srv__GetSurfaceInfo__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace arm_control_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<arm_control_interfaces::srv::GetSurfaceInfo>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::arm_control_interfaces::srv::rosidl_typesupport_introspection_cpp::GetSurfaceInfo_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure all of the service_members are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr ||
    service_members->event_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::arm_control_interfaces::srv::GetSurfaceInfo_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::arm_control_interfaces::srv::GetSurfaceInfo_Response
      >()->data
      );
    // initialize the event_members_ with the static function from the external library
    service_members->event_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::arm_control_interfaces::srv::GetSurfaceInfo_Event
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, arm_control_interfaces, srv, GetSurfaceInfo)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<arm_control_interfaces::srv::GetSurfaceInfo>();
}

#ifdef __cplusplus
}
#endif
