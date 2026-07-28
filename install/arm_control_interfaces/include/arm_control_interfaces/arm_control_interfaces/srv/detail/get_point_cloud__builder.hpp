// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from arm_control_interfaces:srv/GetPointCloud.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "arm_control_interfaces/srv/get_point_cloud.hpp"


#ifndef ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_POINT_CLOUD__BUILDER_HPP_
#define ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_POINT_CLOUD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "arm_control_interfaces/srv/detail/get_point_cloud__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace arm_control_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::arm_control_interfaces::srv::GetPointCloud_Request>()
{
  return ::arm_control_interfaces::srv::GetPointCloud_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace arm_control_interfaces


namespace arm_control_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetPointCloud_Response_point_cloud
{
public:
  explicit Init_GetPointCloud_Response_point_cloud(::arm_control_interfaces::srv::GetPointCloud_Response & msg)
  : msg_(msg)
  {}
  ::arm_control_interfaces::srv::GetPointCloud_Response point_cloud(::arm_control_interfaces::srv::GetPointCloud_Response::_point_cloud_type arg)
  {
    msg_.point_cloud = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetPointCloud_Response msg_;
};

class Init_GetPointCloud_Response_success
{
public:
  Init_GetPointCloud_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetPointCloud_Response_point_cloud success(::arm_control_interfaces::srv::GetPointCloud_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GetPointCloud_Response_point_cloud(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetPointCloud_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::arm_control_interfaces::srv::GetPointCloud_Response>()
{
  return arm_control_interfaces::srv::builder::Init_GetPointCloud_Response_success();
}

}  // namespace arm_control_interfaces


namespace arm_control_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetPointCloud_Event_response
{
public:
  explicit Init_GetPointCloud_Event_response(::arm_control_interfaces::srv::GetPointCloud_Event & msg)
  : msg_(msg)
  {}
  ::arm_control_interfaces::srv::GetPointCloud_Event response(::arm_control_interfaces::srv::GetPointCloud_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetPointCloud_Event msg_;
};

class Init_GetPointCloud_Event_request
{
public:
  explicit Init_GetPointCloud_Event_request(::arm_control_interfaces::srv::GetPointCloud_Event & msg)
  : msg_(msg)
  {}
  Init_GetPointCloud_Event_response request(::arm_control_interfaces::srv::GetPointCloud_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetPointCloud_Event_response(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetPointCloud_Event msg_;
};

class Init_GetPointCloud_Event_info
{
public:
  Init_GetPointCloud_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetPointCloud_Event_request info(::arm_control_interfaces::srv::GetPointCloud_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetPointCloud_Event_request(msg_);
  }

private:
  ::arm_control_interfaces::srv::GetPointCloud_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::arm_control_interfaces::srv::GetPointCloud_Event>()
{
  return arm_control_interfaces::srv::builder::Init_GetPointCloud_Event_info();
}

}  // namespace arm_control_interfaces

#endif  // ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_POINT_CLOUD__BUILDER_HPP_
