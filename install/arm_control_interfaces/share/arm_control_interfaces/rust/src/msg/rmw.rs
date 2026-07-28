#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "arm_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__arm_control_interfaces__msg__GetSurfaceInfo() -> *const std::ffi::c_void;
}

#[link(name = "arm_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn arm_control_interfaces__msg__GetSurfaceInfo__init(msg: *mut GetSurfaceInfo) -> bool;
    fn arm_control_interfaces__msg__GetSurfaceInfo__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetSurfaceInfo>, size: usize) -> bool;
    fn arm_control_interfaces__msg__GetSurfaceInfo__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetSurfaceInfo>);
    fn arm_control_interfaces__msg__GetSurfaceInfo__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetSurfaceInfo>, out_seq: *mut rosidl_runtime_rs::Sequence<GetSurfaceInfo>) -> bool;
}

// Corresponds to arm_control_interfaces__msg__GetSurfaceInfo
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// msg/GetSurfaceInfo.msg

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetSurfaceInfo {

    // This member is not documented.
    #[allow(missing_docs)]
    pub surface_centroid: geometry_msgs::msg::rmw::Point,


    // This member is not documented.
    #[allow(missing_docs)]
    pub surface_normal: geometry_msgs::msg::rmw::Vector3,


    // This member is not documented.
    #[allow(missing_docs)]
    pub spill_centroid: geometry_msgs::msg::rmw::Point,


    // This member is not documented.
    #[allow(missing_docs)]
    pub spill_normal: geometry_msgs::msg::rmw::Vector3,


    // This member is not documented.
    #[allow(missing_docs)]
    pub point_cloud: sensor_msgs::msg::rmw::PointCloud2,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for GetSurfaceInfo {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !arm_control_interfaces__msg__GetSurfaceInfo__init(&mut msg as *mut _) {
        panic!("Call to arm_control_interfaces__msg__GetSurfaceInfo__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetSurfaceInfo {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__msg__GetSurfaceInfo__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__msg__GetSurfaceInfo__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__msg__GetSurfaceInfo__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetSurfaceInfo {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetSurfaceInfo where Self: Sized {
  const TYPE_NAME: &'static str = "arm_control_interfaces/msg/GetSurfaceInfo";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__arm_control_interfaces__msg__GetSurfaceInfo() }
  }
}


