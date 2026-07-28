#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "arm_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__arm_control_interfaces__srv__GetSurfaceInfo_Request() -> *const std::ffi::c_void;
}

#[link(name = "arm_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn arm_control_interfaces__srv__GetSurfaceInfo_Request__init(msg: *mut GetSurfaceInfo_Request) -> bool;
    fn arm_control_interfaces__srv__GetSurfaceInfo_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetSurfaceInfo_Request>, size: usize) -> bool;
    fn arm_control_interfaces__srv__GetSurfaceInfo_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetSurfaceInfo_Request>);
    fn arm_control_interfaces__srv__GetSurfaceInfo_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetSurfaceInfo_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetSurfaceInfo_Request>) -> bool;
}

// Corresponds to arm_control_interfaces__srv__GetSurfaceInfo_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetSurfaceInfo_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub x: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: i32,

}



impl Default for GetSurfaceInfo_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !arm_control_interfaces__srv__GetSurfaceInfo_Request__init(&mut msg as *mut _) {
        panic!("Call to arm_control_interfaces__srv__GetSurfaceInfo_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetSurfaceInfo_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__srv__GetSurfaceInfo_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__srv__GetSurfaceInfo_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__srv__GetSurfaceInfo_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetSurfaceInfo_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetSurfaceInfo_Request where Self: Sized {
  const TYPE_NAME: &'static str = "arm_control_interfaces/srv/GetSurfaceInfo_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__arm_control_interfaces__srv__GetSurfaceInfo_Request() }
  }
}


#[link(name = "arm_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__arm_control_interfaces__srv__GetSurfaceInfo_Response() -> *const std::ffi::c_void;
}

#[link(name = "arm_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn arm_control_interfaces__srv__GetSurfaceInfo_Response__init(msg: *mut GetSurfaceInfo_Response) -> bool;
    fn arm_control_interfaces__srv__GetSurfaceInfo_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetSurfaceInfo_Response>, size: usize) -> bool;
    fn arm_control_interfaces__srv__GetSurfaceInfo_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetSurfaceInfo_Response>);
    fn arm_control_interfaces__srv__GetSurfaceInfo_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetSurfaceInfo_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetSurfaceInfo_Response>) -> bool;
}

// Corresponds to arm_control_interfaces__srv__GetSurfaceInfo_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetSurfaceInfo_Response {

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



impl Default for GetSurfaceInfo_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !arm_control_interfaces__srv__GetSurfaceInfo_Response__init(&mut msg as *mut _) {
        panic!("Call to arm_control_interfaces__srv__GetSurfaceInfo_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetSurfaceInfo_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__srv__GetSurfaceInfo_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__srv__GetSurfaceInfo_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__srv__GetSurfaceInfo_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetSurfaceInfo_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetSurfaceInfo_Response where Self: Sized {
  const TYPE_NAME: &'static str = "arm_control_interfaces/srv/GetSurfaceInfo_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__arm_control_interfaces__srv__GetSurfaceInfo_Response() }
  }
}


#[link(name = "arm_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__arm_control_interfaces__srv__GetPlaneAtPixel_Request() -> *const std::ffi::c_void;
}

#[link(name = "arm_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn arm_control_interfaces__srv__GetPlaneAtPixel_Request__init(msg: *mut GetPlaneAtPixel_Request) -> bool;
    fn arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetPlaneAtPixel_Request>, size: usize) -> bool;
    fn arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetPlaneAtPixel_Request>);
    fn arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetPlaneAtPixel_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetPlaneAtPixel_Request>) -> bool;
}

// Corresponds to arm_control_interfaces__srv__GetPlaneAtPixel_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPlaneAtPixel_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub x: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: i32,

}



impl Default for GetPlaneAtPixel_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !arm_control_interfaces__srv__GetPlaneAtPixel_Request__init(&mut msg as *mut _) {
        panic!("Call to arm_control_interfaces__srv__GetPlaneAtPixel_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetPlaneAtPixel_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetPlaneAtPixel_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetPlaneAtPixel_Request where Self: Sized {
  const TYPE_NAME: &'static str = "arm_control_interfaces/srv/GetPlaneAtPixel_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__arm_control_interfaces__srv__GetPlaneAtPixel_Request() }
  }
}


#[link(name = "arm_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__arm_control_interfaces__srv__GetPlaneAtPixel_Response() -> *const std::ffi::c_void;
}

#[link(name = "arm_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn arm_control_interfaces__srv__GetPlaneAtPixel_Response__init(msg: *mut GetPlaneAtPixel_Response) -> bool;
    fn arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetPlaneAtPixel_Response>, size: usize) -> bool;
    fn arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetPlaneAtPixel_Response>);
    fn arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetPlaneAtPixel_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetPlaneAtPixel_Response>) -> bool;
}

// Corresponds to arm_control_interfaces__srv__GetPlaneAtPixel_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPlaneAtPixel_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub centroid: geometry_msgs::msg::rmw::Point,


    // This member is not documented.
    #[allow(missing_docs)]
    pub normal: geometry_msgs::msg::rmw::Vector3,


    // This member is not documented.
    #[allow(missing_docs)]
    pub boundary_points: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub fx: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub fy: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cx: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cy: f64,

}



impl Default for GetPlaneAtPixel_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !arm_control_interfaces__srv__GetPlaneAtPixel_Response__init(&mut msg as *mut _) {
        panic!("Call to arm_control_interfaces__srv__GetPlaneAtPixel_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetPlaneAtPixel_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetPlaneAtPixel_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetPlaneAtPixel_Response where Self: Sized {
  const TYPE_NAME: &'static str = "arm_control_interfaces/srv/GetPlaneAtPixel_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__arm_control_interfaces__srv__GetPlaneAtPixel_Response() }
  }
}


#[link(name = "arm_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__arm_control_interfaces__srv__GetPointCloud_Request() -> *const std::ffi::c_void;
}

#[link(name = "arm_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn arm_control_interfaces__srv__GetPointCloud_Request__init(msg: *mut GetPointCloud_Request) -> bool;
    fn arm_control_interfaces__srv__GetPointCloud_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetPointCloud_Request>, size: usize) -> bool;
    fn arm_control_interfaces__srv__GetPointCloud_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetPointCloud_Request>);
    fn arm_control_interfaces__srv__GetPointCloud_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetPointCloud_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetPointCloud_Request>) -> bool;
}

// Corresponds to arm_control_interfaces__srv__GetPointCloud_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPointCloud_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetPointCloud_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !arm_control_interfaces__srv__GetPointCloud_Request__init(&mut msg as *mut _) {
        panic!("Call to arm_control_interfaces__srv__GetPointCloud_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetPointCloud_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__srv__GetPointCloud_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__srv__GetPointCloud_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__srv__GetPointCloud_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetPointCloud_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetPointCloud_Request where Self: Sized {
  const TYPE_NAME: &'static str = "arm_control_interfaces/srv/GetPointCloud_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__arm_control_interfaces__srv__GetPointCloud_Request() }
  }
}


#[link(name = "arm_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__arm_control_interfaces__srv__GetPointCloud_Response() -> *const std::ffi::c_void;
}

#[link(name = "arm_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn arm_control_interfaces__srv__GetPointCloud_Response__init(msg: *mut GetPointCloud_Response) -> bool;
    fn arm_control_interfaces__srv__GetPointCloud_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetPointCloud_Response>, size: usize) -> bool;
    fn arm_control_interfaces__srv__GetPointCloud_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetPointCloud_Response>);
    fn arm_control_interfaces__srv__GetPointCloud_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetPointCloud_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetPointCloud_Response>) -> bool;
}

// Corresponds to arm_control_interfaces__srv__GetPointCloud_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPointCloud_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub point_cloud: sensor_msgs::msg::rmw::PointCloud2,

}



impl Default for GetPointCloud_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !arm_control_interfaces__srv__GetPointCloud_Response__init(&mut msg as *mut _) {
        panic!("Call to arm_control_interfaces__srv__GetPointCloud_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetPointCloud_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__srv__GetPointCloud_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__srv__GetPointCloud_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { arm_control_interfaces__srv__GetPointCloud_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetPointCloud_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetPointCloud_Response where Self: Sized {
  const TYPE_NAME: &'static str = "arm_control_interfaces/srv/GetPointCloud_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__arm_control_interfaces__srv__GetPointCloud_Response() }
  }
}






#[link(name = "arm_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__arm_control_interfaces__srv__GetSurfaceInfo() -> *const std::ffi::c_void;
}

// Corresponds to arm_control_interfaces__srv__GetSurfaceInfo
#[allow(missing_docs, non_camel_case_types)]
pub struct GetSurfaceInfo;

impl rosidl_runtime_rs::Service for GetSurfaceInfo {
    type Request = GetSurfaceInfo_Request;
    type Response = GetSurfaceInfo_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__arm_control_interfaces__srv__GetSurfaceInfo() }
    }
}




#[link(name = "arm_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__arm_control_interfaces__srv__GetPlaneAtPixel() -> *const std::ffi::c_void;
}

// Corresponds to arm_control_interfaces__srv__GetPlaneAtPixel
#[allow(missing_docs, non_camel_case_types)]
pub struct GetPlaneAtPixel;

impl rosidl_runtime_rs::Service for GetPlaneAtPixel {
    type Request = GetPlaneAtPixel_Request;
    type Response = GetPlaneAtPixel_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__arm_control_interfaces__srv__GetPlaneAtPixel() }
    }
}




#[link(name = "arm_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__arm_control_interfaces__srv__GetPointCloud() -> *const std::ffi::c_void;
}

// Corresponds to arm_control_interfaces__srv__GetPointCloud
#[allow(missing_docs, non_camel_case_types)]
pub struct GetPointCloud;

impl rosidl_runtime_rs::Service for GetPointCloud {
    type Request = GetPointCloud_Request;
    type Response = GetPointCloud_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__arm_control_interfaces__srv__GetPointCloud() }
    }
}


