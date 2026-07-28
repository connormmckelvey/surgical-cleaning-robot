// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from arm_control_interfaces:srv/GetPlaneAtPixel.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "arm_control_interfaces/srv/get_plane_at_pixel.hpp"


#ifndef ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_PLANE_AT_PIXEL__BUILDER_HPP_
#define ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_PLANE_AT_PIXEL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "arm_control_interfaces/srv/detail/get_plane_at_pixel__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace arm_control_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetPlaneAtPixel_Request_y
{
public:
  explicit Init_GetPlaneAtPixel_Request_y(::arm_control_interfaces::srv::GetPlaneAtPixel_Request & msg)
  : msg_(msg)
  {}
  ::arm_control_interfaces::srv::GetPlaneAtPixel_Request y(::arm_control_interfaces::srv::GetPlaneAtPixel_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetPlaneAtPixel_Request msg_;
};

class Init_GetPlaneAtPixel_Request_x
{
public:
  Init_GetPlaneAtPixel_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetPlaneAtPixel_Request_y x(::arm_control_interfaces::srv::GetPlaneAtPixel_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_GetPlaneAtPixel_Request_y(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetPlaneAtPixel_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::arm_control_interfaces::srv::GetPlaneAtPixel_Request>()
{
  return arm_control_interfaces::srv::builder::Init_GetPlaneAtPixel_Request_x();
}

}  // namespace arm_control_interfaces


namespace arm_control_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetPlaneAtPixel_Response_cy
{
public:
  explicit Init_GetPlaneAtPixel_Response_cy(::arm_control_interfaces::srv::GetPlaneAtPixel_Response & msg)
  : msg_(msg)
  {}
  ::arm_control_interfaces::srv::GetPlaneAtPixel_Response cy(::arm_control_interfaces::srv::GetPlaneAtPixel_Response::_cy_type arg)
  {
    msg_.cy = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetPlaneAtPixel_Response msg_;
};

class Init_GetPlaneAtPixel_Response_cx
{
public:
  explicit Init_GetPlaneAtPixel_Response_cx(::arm_control_interfaces::srv::GetPlaneAtPixel_Response & msg)
  : msg_(msg)
  {}
  Init_GetPlaneAtPixel_Response_cy cx(::arm_control_interfaces::srv::GetPlaneAtPixel_Response::_cx_type arg)
  {
    msg_.cx = std::move(arg);
    return Init_GetPlaneAtPixel_Response_cy(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetPlaneAtPixel_Response msg_;
};

class Init_GetPlaneAtPixel_Response_fy
{
public:
  explicit Init_GetPlaneAtPixel_Response_fy(::arm_control_interfaces::srv::GetPlaneAtPixel_Response & msg)
  : msg_(msg)
  {}
  Init_GetPlaneAtPixel_Response_cx fy(::arm_control_interfaces::srv::GetPlaneAtPixel_Response::_fy_type arg)
  {
    msg_.fy = std::move(arg);
    return Init_GetPlaneAtPixel_Response_cx(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetPlaneAtPixel_Response msg_;
};

class Init_GetPlaneAtPixel_Response_fx
{
public:
  explicit Init_GetPlaneAtPixel_Response_fx(::arm_control_interfaces::srv::GetPlaneAtPixel_Response & msg)
  : msg_(msg)
  {}
  Init_GetPlaneAtPixel_Response_fy fx(::arm_control_interfaces::srv::GetPlaneAtPixel_Response::_fx_type arg)
  {
    msg_.fx = std::move(arg);
    return Init_GetPlaneAtPixel_Response_fy(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetPlaneAtPixel_Response msg_;
};

class Init_GetPlaneAtPixel_Response_boundary_points
{
public:
  explicit Init_GetPlaneAtPixel_Response_boundary_points(::arm_control_interfaces::srv::GetPlaneAtPixel_Response & msg)
  : msg_(msg)
  {}
  Init_GetPlaneAtPixel_Response_fx boundary_points(::arm_control_interfaces::srv::GetPlaneAtPixel_Response::_boundary_points_type arg)
  {
    msg_.boundary_points = std::move(arg);
    return Init_GetPlaneAtPixel_Response_fx(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetPlaneAtPixel_Response msg_;
};

class Init_GetPlaneAtPixel_Response_normal
{
public:
  explicit Init_GetPlaneAtPixel_Response_normal(::arm_control_interfaces::srv::GetPlaneAtPixel_Response & msg)
  : msg_(msg)
  {}
  Init_GetPlaneAtPixel_Response_boundary_points normal(::arm_control_interfaces::srv::GetPlaneAtPixel_Response::_normal_type arg)
  {
    msg_.normal = std::move(arg);
    return Init_GetPlaneAtPixel_Response_boundary_points(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetPlaneAtPixel_Response msg_;
};

class Init_GetPlaneAtPixel_Response_centroid
{
public:
  explicit Init_GetPlaneAtPixel_Response_centroid(::arm_control_interfaces::srv::GetPlaneAtPixel_Response & msg)
  : msg_(msg)
  {}
  Init_GetPlaneAtPixel_Response_normal centroid(::arm_control_interfaces::srv::GetPlaneAtPixel_Response::_centroid_type arg)
  {
    msg_.centroid = std::move(arg);
    return Init_GetPlaneAtPixel_Response_normal(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetPlaneAtPixel_Response msg_;
};

class Init_GetPlaneAtPixel_Response_success
{
public:
  Init_GetPlaneAtPixel_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetPlaneAtPixel_Response_centroid success(::arm_control_interfaces::srv::GetPlaneAtPixel_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GetPlaneAtPixel_Response_centroid(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetPlaneAtPixel_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::arm_control_interfaces::srv::GetPlaneAtPixel_Response>()
{
  return arm_control_interfaces::srv::builder::Init_GetPlaneAtPixel_Response_success();
}

}  // namespace arm_control_interfaces


namespace arm_control_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetPlaneAtPixel_Event_response
{
public:
  explicit Init_GetPlaneAtPixel_Event_response(::arm_control_interfaces::srv::GetPlaneAtPixel_Event & msg)
  : msg_(msg)
  {}
  ::arm_control_interfaces::srv::GetPlaneAtPixel_Event response(::arm_control_interfaces::srv::GetPlaneAtPixel_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetPlaneAtPixel_Event msg_;
};

class Init_GetPlaneAtPixel_Event_request
{
public:
  explicit Init_GetPlaneAtPixel_Event_request(::arm_control_interfaces::srv::GetPlaneAtPixel_Event & msg)
  : msg_(msg)
  {}
  Init_GetPlaneAtPixel_Event_response request(::arm_control_interfaces::srv::GetPlaneAtPixel_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetPlaneAtPixel_Event_response(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetPlaneAtPixel_Event msg_;
};

class Init_GetPlaneAtPixel_Event_info
{
public:
  Init_GetPlaneAtPixel_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetPlaneAtPixel_Event_request info(::arm_control_interfaces::srv::GetPlaneAtPixel_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetPlaneAtPixel_Event_request(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetPlaneAtPixel_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::arm_control_interfaces::srv::GetPlaneAtPixel_Event>()
{
  return arm_control_interfaces::srv::builder::Init_GetPlaneAtPixel_Event_info();
}

}  // namespace arm_control_interfaces

#endif  // ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_PLANE_AT_PIXEL__BUILDER_HPP_
