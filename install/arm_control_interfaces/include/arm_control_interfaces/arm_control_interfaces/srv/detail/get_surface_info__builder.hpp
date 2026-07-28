// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from arm_control_interfaces:srv/GetSurfaceInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "arm_control_interfaces/srv/get_surface_info.hpp"


#ifndef ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_SURFACE_INFO__BUILDER_HPP_
#define ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_SURFACE_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "arm_control_interfaces/srv/detail/get_surface_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace arm_control_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetSurfaceInfo_Request_y
{
public:
  explicit Init_GetSurfaceInfo_Request_y(::arm_control_interfaces::srv::GetSurfaceInfo_Request & msg)
  : msg_(msg)
  {}
  ::arm_control_interfaces::srv::GetSurfaceInfo_Request y(::arm_control_interfaces::srv::GetSurfaceInfo_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetSurfaceInfo_Request msg_;
};

class Init_GetSurfaceInfo_Request_x
{
public:
  Init_GetSurfaceInfo_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetSurfaceInfo_Request_y x(::arm_control_interfaces::srv::GetSurfaceInfo_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_GetSurfaceInfo_Request_y(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetSurfaceInfo_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::arm_control_interfaces::srv::GetSurfaceInfo_Request>()
{
  return arm_control_interfaces::srv::builder::Init_GetSurfaceInfo_Request_x();
}

}  // namespace arm_control_interfaces


namespace arm_control_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetSurfaceInfo_Response_success
{
public:
  explicit Init_GetSurfaceInfo_Response_success(::arm_control_interfaces::srv::GetSurfaceInfo_Response & msg)
  : msg_(msg)
  {}
  ::arm_control_interfaces::srv::GetSurfaceInfo_Response success(::arm_control_interfaces::srv::GetSurfaceInfo_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetSurfaceInfo_Response msg_;
};

class Init_GetSurfaceInfo_Response_point_cloud
{
public:
  explicit Init_GetSurfaceInfo_Response_point_cloud(::arm_control_interfaces::srv::GetSurfaceInfo_Response & msg)
  : msg_(msg)
  {}
  Init_GetSurfaceInfo_Response_success point_cloud(::arm_control_interfaces::srv::GetSurfaceInfo_Response::_point_cloud_type arg)
  {
    msg_.point_cloud = std::move(arg);
    return Init_GetSurfaceInfo_Response_success(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetSurfaceInfo_Response msg_;
};

class Init_GetSurfaceInfo_Response_spill_normal
{
public:
  explicit Init_GetSurfaceInfo_Response_spill_normal(::arm_control_interfaces::srv::GetSurfaceInfo_Response & msg)
  : msg_(msg)
  {}
  Init_GetSurfaceInfo_Response_point_cloud spill_normal(::arm_control_interfaces::srv::GetSurfaceInfo_Response::_spill_normal_type arg)
  {
    msg_.spill_normal = std::move(arg);
    return Init_GetSurfaceInfo_Response_point_cloud(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetSurfaceInfo_Response msg_;
};

class Init_GetSurfaceInfo_Response_spill_centroid
{
public:
  explicit Init_GetSurfaceInfo_Response_spill_centroid(::arm_control_interfaces::srv::GetSurfaceInfo_Response & msg)
  : msg_(msg)
  {}
  Init_GetSurfaceInfo_Response_spill_normal spill_centroid(::arm_control_interfaces::srv::GetSurfaceInfo_Response::_spill_centroid_type arg)
  {
    msg_.spill_centroid = std::move(arg);
    return Init_GetSurfaceInfo_Response_spill_normal(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetSurfaceInfo_Response msg_;
};

class Init_GetSurfaceInfo_Response_surface_normal
{
public:
  explicit Init_GetSurfaceInfo_Response_surface_normal(::arm_control_interfaces::srv::GetSurfaceInfo_Response & msg)
  : msg_(msg)
  {}
  Init_GetSurfaceInfo_Response_spill_centroid surface_normal(::arm_control_interfaces::srv::GetSurfaceInfo_Response::_surface_normal_type arg)
  {
    msg_.surface_normal = std::move(arg);
    return Init_GetSurfaceInfo_Response_spill_centroid(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetSurfaceInfo_Response msg_;
};

class Init_GetSurfaceInfo_Response_surface_centroid
{
public:
  Init_GetSurfaceInfo_Response_surface_centroid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetSurfaceInfo_Response_surface_normal surface_centroid(::arm_control_interfaces::srv::GetSurfaceInfo_Response::_surface_centroid_type arg)
  {
    msg_.surface_centroid = std::move(arg);
    return Init_GetSurfaceInfo_Response_surface_normal(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetSurfaceInfo_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::arm_control_interfaces::srv::GetSurfaceInfo_Response>()
{
  return arm_control_interfaces::srv::builder::Init_GetSurfaceInfo_Response_surface_centroid();
}

}  // namespace arm_control_interfaces


namespace arm_control_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetSurfaceInfo_Event_response
{
public:
  explicit Init_GetSurfaceInfo_Event_response(::arm_control_interfaces::srv::GetSurfaceInfo_Event & msg)
  : msg_(msg)
  {}
  ::arm_control_interfaces::srv::GetSurfaceInfo_Event response(::arm_control_interfaces::srv::GetSurfaceInfo_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetSurfaceInfo_Event msg_;
};

class Init_GetSurfaceInfo_Event_request
{
public:
  explicit Init_GetSurfaceInfo_Event_request(::arm_control_interfaces::srv::GetSurfaceInfo_Event & msg)
  : msg_(msg)
  {}
  Init_GetSurfaceInfo_Event_response request(::arm_control_interfaces::srv::GetSurfaceInfo_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetSurfaceInfo_Event_response(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetSurfaceInfo_Event msg_;
};

class Init_GetSurfaceInfo_Event_info
{
public:
  Init_GetSurfaceInfo_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetSurfaceInfo_Event_request info(::arm_control_interfaces::srv::GetSurfaceInfo_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetSurfaceInfo_Event_request(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetSurfaceInfo_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::arm_control_interfaces::srv::GetSurfaceInfo_Event>()
{
  return arm_control_interfaces::srv::builder::Init_GetSurfaceInfo_Event_info();
}

}  // namespace arm_control_interfaces

#endif  // ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_SURFACE_INFO__BUILDER_HPP_
