// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from arm_control_interfaces:srv/GetSurfaceInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "arm_control_interfaces/srv/get_surface_info.hpp"


#ifndef ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_SURFACE_INFO__STRUCT_HPP_
#define ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_SURFACE_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__arm_control_interfaces__srv__GetSurfaceInfo_Request __attribute__((deprecated))
#else
# define DEPRECATED__arm_control_interfaces__srv__GetSurfaceInfo_Request __declspec(deprecated)
#endif

namespace arm_control_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetSurfaceInfo_Request_
{
  using Type = GetSurfaceInfo_Request_<ContainerAllocator>;

  explicit GetSurfaceInfo_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0l;
      this->y = 0l;
    }
  }

  explicit GetSurfaceInfo_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0l;
      this->y = 0l;
    }
  }

  // field types and members
  using _x_type =
    int32_t;
  _x_type x;
  using _y_type =
    int32_t;
  _y_type y;

  // setters for named parameter idiom
  Type & set__x(
    const int32_t & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const int32_t & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    arm_control_interfaces::srv::GetSurfaceInfo_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const arm_control_interfaces::srv::GetSurfaceInfo_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      arm_control_interfaces::srv::GetSurfaceInfo_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      arm_control_interfaces::srv::GetSurfaceInfo_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__arm_control_interfaces__srv__GetSurfaceInfo_Request
    std::shared_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__arm_control_interfaces__srv__GetSurfaceInfo_Request
    std::shared_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetSurfaceInfo_Request_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetSurfaceInfo_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetSurfaceInfo_Request_

// alias to use template instance with default allocator
using GetSurfaceInfo_Request =
  arm_control_interfaces::srv::GetSurfaceInfo_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace arm_control_interfaces


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
# define DEPRECATED__arm_control_interfaces__srv__GetSurfaceInfo_Response __attribute__((deprecated))
#else
# define DEPRECATED__arm_control_interfaces__srv__GetSurfaceInfo_Response __declspec(deprecated)
#endif

namespace arm_control_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetSurfaceInfo_Response_
{
  using Type = GetSurfaceInfo_Response_<ContainerAllocator>;

  explicit GetSurfaceInfo_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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

  explicit GetSurfaceInfo_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    arm_control_interfaces::srv::GetSurfaceInfo_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const arm_control_interfaces::srv::GetSurfaceInfo_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      arm_control_interfaces::srv::GetSurfaceInfo_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      arm_control_interfaces::srv::GetSurfaceInfo_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__arm_control_interfaces__srv__GetSurfaceInfo_Response
    std::shared_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__arm_control_interfaces__srv__GetSurfaceInfo_Response
    std::shared_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetSurfaceInfo_Response_ & other) const
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
  bool operator!=(const GetSurfaceInfo_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetSurfaceInfo_Response_

// alias to use template instance with default allocator
using GetSurfaceInfo_Response =
  arm_control_interfaces::srv::GetSurfaceInfo_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace arm_control_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__arm_control_interfaces__srv__GetSurfaceInfo_Event __attribute__((deprecated))
#else
# define DEPRECATED__arm_control_interfaces__srv__GetSurfaceInfo_Event __declspec(deprecated)
#endif

namespace arm_control_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetSurfaceInfo_Event_
{
  using Type = GetSurfaceInfo_Event_<ContainerAllocator>;

  explicit GetSurfaceInfo_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit GetSurfaceInfo_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<arm_control_interfaces::srv::GetSurfaceInfo_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<arm_control_interfaces::srv::GetSurfaceInfo_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<arm_control_interfaces::srv::GetSurfaceInfo_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<arm_control_interfaces::srv::GetSurfaceInfo_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<arm_control_interfaces::srv::GetSurfaceInfo_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<arm_control_interfaces::srv::GetSurfaceInfo_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<arm_control_interfaces::srv::GetSurfaceInfo_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<arm_control_interfaces::srv::GetSurfaceInfo_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    arm_control_interfaces::srv::GetSurfaceInfo_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const arm_control_interfaces::srv::GetSurfaceInfo_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      arm_control_interfaces::srv::GetSurfaceInfo_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      arm_control_interfaces::srv::GetSurfaceInfo_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__arm_control_interfaces__srv__GetSurfaceInfo_Event
    std::shared_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__arm_control_interfaces__srv__GetSurfaceInfo_Event
    std::shared_ptr<arm_control_interfaces::srv::GetSurfaceInfo_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetSurfaceInfo_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetSurfaceInfo_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetSurfaceInfo_Event_

// alias to use template instance with default allocator
using GetSurfaceInfo_Event =
  arm_control_interfaces::srv::GetSurfaceInfo_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace arm_control_interfaces

namespace arm_control_interfaces
{

namespace srv
{

struct GetSurfaceInfo
{
  using Request = arm_control_interfaces::srv::GetSurfaceInfo_Request;
  using Response = arm_control_interfaces::srv::GetSurfaceInfo_Response;
  using Event = arm_control_interfaces::srv::GetSurfaceInfo_Event;
};

}  // namespace srv

}  // namespace arm_control_interfaces

#endif  // ARM_CONTROL_INTERFACES__SRV__DETAIL__GET_SURFACE_INFO__STRUCT_HPP_
