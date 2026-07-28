// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from arm_control_interfaces:msg/GetSurfaceInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "arm_control_interfaces/msg/get_surface_info.hpp"


#ifndef ARM_CONTROL_INTERFACES__MSG__DETAIL__GET_SURFACE_INFO__BUILDER_HPP_
#define ARM_CONTROL_INTERFACES__MSG__DETAIL__GET_SURFACE_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "arm_control_interfaces/msg/detail/get_surface_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace arm_control_interfaces
{

namespace msg
{

namespace builder
{

class Init_GetSurfaceInfo_success
{
public:
  explicit Init_GetSurfaceInfo_success(::arm_control_interfaces::msg::GetSurfaceInfo & msg)
  : msg_(msg)
  {}
  ::arm_control_interfaces::msg::GetSurfaceInfo success(::arm_control_interfaces::msg::GetSurfaceInfo::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arm_control_interfaces::msg::GetSurfaceInfo msg_;
};

class Init_GetSurfaceInfo_point_cloud
{
public:
  explicit Init_GetSurfaceInfo_point_cloud(::arm_control_interfaces::msg::GetSurfaceInfo & msg)
  : msg_(msg)
  {}
  Init_GetSurfaceInfo_success point_cloud(::arm_control_interfaces::msg::GetSurfaceInfo::_point_cloud_type arg)
  {
    msg_.point_cloud = std::move(arg);
    return Init_GetSurfaceInfo_success(msg_);
  }

private:
  ::arm_control_interfaces::msg::GetSurfaceInfo msg_;
};

class Init_GetSurfaceInfo_spill_normal
{
public:
  explicit Init_GetSurfaceInfo_spill_normal(::arm_control_interfaces::msg::GetSurfaceInfo & msg)
  : msg_(msg)
  {}
  Init_GetSurfaceInfo_point_cloud spill_normal(::arm_control_interfaces::msg::GetSurfaceInfo::_spill_normal_type arg)
  {
    msg_.spill_normal = std::move(arg);
    return Init_GetSurfaceInfo_point_cloud(msg_);
  }

private:
  ::arm_control_interfaces::msg::GetSurfaceInfo msg_;
};

class Init_GetSurfaceInfo_spill_centroid
{
public:
  explicit Init_GetSurfaceInfo_spill_centroid(::arm_control_interfaces::msg::GetSurfaceInfo & msg)
  : msg_(msg)
  {}
  Init_GetSurfaceInfo_spill_normal spill_centroid(::arm_control_interfaces::msg::GetSurfaceInfo::_spill_centroid_type arg)
  {
    msg_.spill_centroid = std::move(arg);
    return Init_GetSurfaceInfo_spill_normal(msg_);
  }

private:
  ::arm_control_interfaces::msg::GetSurfaceInfo msg_;
};

class Init_GetSurfaceInfo_surface_normal
{
public:
  explicit Init_GetSurfaceInfo_surface_normal(::arm_control_interfaces::msg::GetSurfaceInfo & msg)
  : msg_(msg)
  {}
  Init_GetSurfaceInfo_spill_centroid surface_normal(::arm_control_interfaces::msg::GetSurfaceInfo::_surface_normal_type arg)
  {
    msg_.surface_normal = std::move(arg);
    return Init_GetSurfaceInfo_spill_centroid(msg_);
  }

private:
  ::arm_control_interfaces::msg::GetSurfaceInfo msg_;
};

class Init_GetSurfaceInfo_surface_centroid
{
public:
  Init_GetSurfaceInfo_surface_centroid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetSurfaceInfo_surface_normal surface_centroid(::arm_control_interfaces::msg::GetSurfaceInfo::_surface_centroid_type arg)
  {
    msg_.surface_centroid = std::move(arg);
    return Init_GetSurfaceInfo_surface_normal(msg_);
  }

private:
  ::arm_control_interfaces::msg::GetSurfaceInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::arm_control_interfaces::msg::GetSurfaceInfo>()
{
  return arm_control_interfaces::msg::builder::Init_GetSurfaceInfo_surface_centroid();
}

}  // namespace arm_control_interfaces

#endif  // ARM_CONTROL_INTERFACES__MSG__DETAIL__GET_SURFACE_INFO__BUILDER_HPP_
