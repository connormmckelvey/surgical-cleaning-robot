// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from arm_control_interfaces:srv/GetPointCloud.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "arm_control_interfaces/srv/get_point_cloud.hpp"


#ifndef ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_POINT_CLOUD__TRAITS_HPP_
#define ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_POINT_CLOUD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "arm_control_interfaces/srv/detail/get_point_cloud__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace arm_control_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetPointCloud_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetPointCloud_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetPointCloud_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace arm_control_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use arm_control_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const arm_control_interfaces::srv::GetPointCloud_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  arm_control_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use arm_control_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const arm_control_interfaces::srv::GetPointCloud_Request & msg)
{
  return arm_control_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<arm_control_interfaces::srv::GetPointCloud_Request>()
{
  return "arm_control_interfaces::srv::GetPointCloud_Request";
}

template<>
inline const char * name<arm_control_interfaces::srv::GetPointCloud_Request>()
{
  return "arm_control_interfaces/srv/GetPointCloud_Request";
}

template<>
struct has_fixed_size<arm_control_interfaces::srv::GetPointCloud_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<arm_control_interfaces::srv::GetPointCloud_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<arm_control_interfaces::srv::GetPointCloud_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'point_cloud'
#include "sensor_msgs/msg/detail/point_cloud2__traits.hpp"

namespace arm_control_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetPointCloud_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: point_cloud
  {
    out << "point_cloud: ";
    to_flow_style_yaml(msg.point_cloud, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetPointCloud_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: point_cloud
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "point_cloud:\n";
    to_block_style_yaml(msg.point_cloud, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetPointCloud_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace arm_control_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use arm_control_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const arm_control_interfaces::srv::GetPointCloud_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  arm_control_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use arm_control_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const arm_control_interfaces::srv::GetPointCloud_Response & msg)
{
  return arm_control_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<arm_control_interfaces::srv::GetPointCloud_Response>()
{
  return "arm_control_interfaces::srv::GetPointCloud_Response";
}

template<>
inline const char * name<arm_control_interfaces::srv::GetPointCloud_Response>()
{
  return "arm_control_interfaces/srv/GetPointCloud_Response";
}

template<>
struct has_fixed_size<arm_control_interfaces::srv::GetPointCloud_Response>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::PointCloud2>::value> {};

template<>
struct has_bounded_size<arm_control_interfaces::srv::GetPointCloud_Response>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::PointCloud2>::value> {};

template<>
struct is_message<arm_control_interfaces::srv::GetPointCloud_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace arm_control_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetPointCloud_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetPointCloud_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetPointCloud_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace arm_control_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use arm_control_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const arm_control_interfaces::srv::GetPointCloud_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  arm_control_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use arm_control_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const arm_control_interfaces::srv::GetPointCloud_Event & msg)
{
  return arm_control_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<arm_control_interfaces::srv::GetPointCloud_Event>()
{
  return "arm_control_interfaces::srv::GetPointCloud_Event";
}

template<>
inline const char * name<arm_control_interfaces::srv::GetPointCloud_Event>()
{
  return "arm_control_interfaces/srv/GetPointCloud_Event";
}

template<>
struct has_fixed_size<arm_control_interfaces::srv::GetPointCloud_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<arm_control_interfaces::srv::GetPointCloud_Event>
  : std::integral_constant<bool, has_bounded_size<arm_control_interfaces::srv::GetPointCloud_Request>::value && has_bounded_size<arm_control_interfaces::srv::GetPointCloud_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<arm_control_interfaces::srv::GetPointCloud_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<arm_control_interfaces::srv::GetPointCloud>()
{
  return "arm_control_interfaces::srv::GetPointCloud";
}

template<>
inline const char * name<arm_control_interfaces::srv::GetPointCloud>()
{
  return "arm_control_interfaces/srv/GetPointCloud";
}

template<>
struct has_fixed_size<arm_control_interfaces::srv::GetPointCloud>
  : std::integral_constant<
    bool,
    has_fixed_size<arm_control_interfaces::srv::GetPointCloud_Request>::value &&
    has_fixed_size<arm_control_interfaces::srv::GetPointCloud_Response>::value
  >
{
};

template<>
struct has_bounded_size<arm_control_interfaces::srv::GetPointCloud>
  : std::integral_constant<
    bool,
    has_bounded_size<arm_control_interfaces::srv::GetPointCloud_Request>::value &&
    has_bounded_size<arm_control_interfaces::srv::GetPointCloud_Response>::value
  >
{
};

template<>
struct is_service<arm_control_interfaces::srv::GetPointCloud>
  : std::true_type
{
};

template<>
struct is_service_request<arm_control_interfaces::srv::GetPointCloud_Request>
  : std::true_type
{
};

template<>
struct is_service_response<arm_control_interfaces::srv::GetPointCloud_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_POINT_CLOUD__TRAITS_HPP_
