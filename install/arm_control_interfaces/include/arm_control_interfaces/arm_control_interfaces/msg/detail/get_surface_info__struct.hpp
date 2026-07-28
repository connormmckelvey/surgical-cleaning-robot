// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from arm_control_interfaces:msg/GetSurfaceInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "arm_control_interfaces/msg/get_surface_info.hpp"


#ifndef ARM_CONTROL_INTERFACES__MSG__DETAIL__GET_SURFACE_INFO__STRUCT_HPP_
#define ARM_CONTROL_INTERFACES__MSG__DETAIL__GET_SURFACE_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'surface_centroid'
// Member 'spill_centroid'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'surface_normal'
// Member 'spill_normal'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"
// Member 'point_cloud'
#include "sensor_msgs/msg/detail/point_cloud2__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__arm_control_interfaces__msg__GetSurfaceInfo __attribute__((deprecated))
#else
# define DEPRECATED__arm_control_interfaces__msg__GetSurfaceInfo __declspec(deprecated)
#endif

namespace arm_control_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GetSurfaceInfo_
{
  using Type = GetSurfaceInfo_<ContainerAllocator>;

  explicit GetSurfaceInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : surface_centroid(_init),
    surface_normal(_init),
    spill_centroid(_init),
    spill_normal(_init),
    point_cloud(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit GetSurfaceInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : surface_centroid(_alloc, _init),
    surface_normal(_alloc, _init),
    spill_centroid(_alloc, _init),
    spill_normal(_alloc, _init),
    point_cloud(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _surface_centroid_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _surface_centroid_type surface_centroid;
  using _surface_normal_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _surface_normal_type surface_normal;
  using _spill_centroid_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _spill_centroid_type spill_centroid;
  using _spill_normal_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _spill_normal_type spill_normal;
  using _point_cloud_type =
    sensor_msgs::msg::PointCloud2_<ContainerAllocator>;
  _point_cloud_type point_cloud;
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__surface_centroid(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->surface_centroid = _arg;
    return *this;
  }
  Type & set__surface_normal(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->surface_normal = _arg;
    return *this;
  }
  Type & set__spill_centroid(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->spill_centroid = _arg;
    return *this;
  }
  Type & set__spill_normal(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->spill_normal = _arg;
    return *this;
  }
  Type & set__point_cloud(
    const sensor_msgs::msg::PointCloud2_<ContainerAllocator> & _arg)
  {
    this->point_cloud = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    arm_control_interfaces::msg::GetSurfaceInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const arm_control_interfaces::msg::GetSurfaceInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<arm_control_interfaces::msg::GetSurfaceInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<arm_control_interfaces::msg::GetSurfaceInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      arm_control_interfaces::msg::GetSurfaceInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<arm_control_interfaces::msg::GetSurfaceInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      arm_control_interfaces::msg::GetSurfaceInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<arm_control_interfaces::msg::GetSurfaceInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<arm_control_interfaces::msg::GetSurfaceInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<arm_control_interfaces::msg::GetSurfaceInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__arm_control_interfaces__msg__GetSurfaceInfo
    std::shared_ptr<arm_control_interfaces::msg::GetSurfaceInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__arm_control_interfaces__msg__GetSurfaceInfo
    std::shared_ptr<arm_control_interfaces::msg::GetSurfaceInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetSurfaceInfo_ & other) const
  {
    if (this->surface_centroid != other.surface_centroid) {
      return false;
    }
    if (this->surface_normal != other.surface_normal) {
      return false;
    }
    if (this->spill_centroid != other.spill_centroid) {
      return false;
    }
    if (this->spill_normal != other.spill_normal) {
      return false;
    }
    if (this->point_cloud != other.point_cloud) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetSurfaceInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetSurfaceInfo_

// alias to use template instance with default allocator
using GetSurfaceInfo =
  arm_control_interfaces::msg::GetSurfaceInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace arm_control_interfaces

#endif  // ARM_CONTROL_INTERFACES__MSG__DETAIL__GET_SURFACE_INFO__STRUCT_HPP_
