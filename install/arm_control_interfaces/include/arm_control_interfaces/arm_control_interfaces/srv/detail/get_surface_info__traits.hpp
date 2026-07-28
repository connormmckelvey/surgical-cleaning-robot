// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from arm_control_interfaces:srv/GetSurfaceInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "arm_control_interfaces/srv/get_surface_info.hpp"


#ifndef ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_SURFACE_INFO__TRAITS_HPP_
#define ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_SURFACE_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "arm_control_interfaces/srv/detail/get_surface_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace arm_control_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetSurfaceInfo_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetSurfaceInfo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetSurfaceInfo_Request & msg, bool use_flow_style = false)
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
  const arm_control_interfaces::srv::GetSurfaceInfo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  arm_control_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use arm_control_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const arm_control_interfaces::srv::GetSurfaceInfo_Request & msg)
{
  return arm_control_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<arm_control_interfaces::srv::GetSurfaceInfo_Request>()
{
  return "arm_control_interfaces::srv::GetSurfaceInfo_Request";
}

template<>
inline const char * name<arm_control_interfaces::srv::GetSurfaceInfo_Request>()
{
  return "arm_control_interfaces/srv/GetSurfaceInfo_Request";
}

template<>
struct has_fixed_size<arm_control_interfaces::srv::GetSurfaceInfo_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<arm_control_interfaces::srv::GetSurfaceInfo_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<arm_control_interfaces::srv::GetSurfaceInfo_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'surface_centroid'
// Member 'spill_centroid'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'surface_normal'
// Member 'spill_normal'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"
// Member 'point_cloud'
#include "sensor_msgs/msg/detail/point_cloud2__traits.hpp"

namespace arm_control_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetSurfaceInfo_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: surface_centroid
  {
    out << "surface_centroid: ";
    to_flow_style_yaml(msg.surface_centroid, out);
    out << ", ";
  }

  // member: surface_normal
  {
    out << "surface_normal: ";
    to_flow_style_yaml(msg.surface_normal, out);
    out << ", ";
  }

  // member: spill_centroid
  {
    out << "spill_centroid: ";
    to_flow_style_yaml(msg.spill_centroid, out);
    out << ", ";
  }

  // member: spill_normal
  {
    out << "spill_normal: ";
    to_flow_style_yaml(msg.spill_normal, out);
    out << ", ";
  }

  // member: point_cloud
  {
    out << "point_cloud: ";
    to_flow_style_yaml(msg.point_cloud, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetSurfaceInfo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: surface_centroid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "surface_centroid:\n";
    to_block_style_yaml(msg.surface_centroid, out, indentation + 2);
  }

  // member: surface_normal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "surface_normal:\n";
    to_block_style_yaml(msg.surface_normal, out, indentation + 2);
  }

  // member: spill_centroid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "spill_centroid:\n";
    to_block_style_yaml(msg.spill_centroid, out, indentation + 2);
  }

  // member: spill_normal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "spill_normal:\n";
    to_block_style_yaml(msg.spill_normal, out, indentation + 2);
  }

  // member: point_cloud
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "point_cloud:\n";
    to_block_style_yaml(msg.point_cloud, out, indentation + 2);
  }

  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetSurfaceInfo_Response & msg, bool use_flow_style = false)
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
  const arm_control_interfaces::srv::GetSurfaceInfo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  arm_control_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use arm_control_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const arm_control_interfaces::srv::GetSurfaceInfo_Response & msg)
{
  return arm_control_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<arm_control_interfaces::srv::GetSurfaceInfo_Response>()
{
  return "arm_control_interfaces::srv::GetSurfaceInfo_Response";
}

template<>
inline const char * name<arm_control_interfaces::srv::GetSurfaceInfo_Response>()
{
  return "arm_control_interfaces/srv/GetSurfaceInfo_Response";
}

template<>
struct has_fixed_size<arm_control_interfaces::srv::GetSurfaceInfo_Response>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<geometry_msgs::msg::Vector3>::value && has_fixed_size<sensor_msgs::msg::PointCloud2>::value> {};

template<>
struct has_bounded_size<arm_control_interfaces::srv::GetSurfaceInfo_Response>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<geometry_msgs::msg::Vector3>::value && has_bounded_size<sensor_msgs::msg::PointCloud2>::value> {};

template<>
struct is_message<arm_control_interfaces::srv::GetSurfaceInfo_Response>
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
  const GetSurfaceInfo_Event & msg,
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
  const GetSurfaceInfo_Event & msg,
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

inline std::string to_yaml(const GetSurfaceInfo_Event & msg, bool use_flow_style = false)
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
  const arm_control_interfaces::srv::GetSurfaceInfo_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  arm_control_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use arm_control_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const arm_control_interfaces::srv::GetSurfaceInfo_Event & msg)
{
  return arm_control_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<arm_control_interfaces::srv::GetSurfaceInfo_Event>()
{
  return "arm_control_interfaces::srv::GetSurfaceInfo_Event";
}

template<>
inline const char * name<arm_control_interfaces::srv::GetSurfaceInfo_Event>()
{
  return "arm_control_interfaces/srv/GetSurfaceInfo_Event";
}

template<>
struct has_fixed_size<arm_control_interfaces::srv::GetSurfaceInfo_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<arm_control_interfaces::srv::GetSurfaceInfo_Event>
  : std::integral_constant<bool, has_bounded_size<arm_control_interfaces::srv::GetSurfaceInfo_Request>::value && has_bounded_size<arm_control_interfaces::srv::GetSurfaceInfo_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<arm_control_interfaces::srv::GetSurfaceInfo_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<arm_control_interfaces::srv::GetSurfaceInfo>()
{
  return "arm_control_interfaces::srv::GetSurfaceInfo";
}

template<>
inline const char * name<arm_control_interfaces::srv::GetSurfaceInfo>()
{
  return "arm_control_interfaces/srv/GetSurfaceInfo";
}

template<>
struct has_fixed_size<arm_control_interfaces::srv::GetSurfaceInfo>
  : std::integral_constant<
    bool,
    has_fixed_size<arm_control_interfaces::srv::GetSurfaceInfo_Request>::value &&
    has_fixed_size<arm_control_interfaces::srv::GetSurfaceInfo_Response>::value
  >
{
};

template<>
struct has_bounded_size<arm_control_interfaces::srv::GetSurfaceInfo>
  : std::integral_constant<
    bool,
    has_bounded_size<arm_control_interfaces::srv::GetSurfaceInfo_Request>::value &&
    has_bounded_size<arm_control_interfaces::srv::GetSurfaceInfo_Response>::value
  >
{
};

template<>
struct is_service<arm_control_interfaces::srv::GetSurfaceInfo>
  : std::true_type
{
};

template<>
struct is_service_request<arm_control_interfaces::srv::GetSurfaceInfo_Request>
  : std::true_type
{
};

template<>
struct is_service_response<arm_control_interfaces::srv::GetSurfaceInfo_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_SURFACE_INFO__TRAITS_HPP_
