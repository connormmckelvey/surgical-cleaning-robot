#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to arm_control_interfaces__srv__GetSurfaceInfo_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetSurfaceInfo_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetSurfaceInfo_Request {
  type RmwMsg = super::srv::rmw::GetSurfaceInfo_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x,
        y: msg.y,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      x: msg.x,
      y: msg.y,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      x: msg.x,
      y: msg.y,
    }
  }
}


// Corresponds to arm_control_interfaces__srv__GetSurfaceInfo_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetSurfaceInfo_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub surface_centroid: geometry_msgs::msg::Point,


    // This member is not documented.
    #[allow(missing_docs)]
    pub surface_normal: geometry_msgs::msg::Vector3,


    // This member is not documented.
    #[allow(missing_docs)]
    pub spill_centroid: geometry_msgs::msg::Point,


    // This member is not documented.
    #[allow(missing_docs)]
    pub spill_normal: geometry_msgs::msg::Vector3,


    // This member is not documented.
    #[allow(missing_docs)]
    pub point_cloud: sensor_msgs::msg::PointCloud2,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for GetSurfaceInfo_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetSurfaceInfo_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetSurfaceInfo_Response {
  type RmwMsg = super::srv::rmw::GetSurfaceInfo_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        surface_centroid: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.surface_centroid)).into_owned(),
        surface_normal: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Owned(msg.surface_normal)).into_owned(),
        spill_centroid: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.spill_centroid)).into_owned(),
        spill_normal: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Owned(msg.spill_normal)).into_owned(),
        point_cloud: sensor_msgs::msg::PointCloud2::into_rmw_message(std::borrow::Cow::Owned(msg.point_cloud)).into_owned(),
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        surface_centroid: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.surface_centroid)).into_owned(),
        surface_normal: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Borrowed(&msg.surface_normal)).into_owned(),
        spill_centroid: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.spill_centroid)).into_owned(),
        spill_normal: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Borrowed(&msg.spill_normal)).into_owned(),
        point_cloud: sensor_msgs::msg::PointCloud2::into_rmw_message(std::borrow::Cow::Borrowed(&msg.point_cloud)).into_owned(),
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      surface_centroid: geometry_msgs::msg::Point::from_rmw_message(msg.surface_centroid),
      surface_normal: geometry_msgs::msg::Vector3::from_rmw_message(msg.surface_normal),
      spill_centroid: geometry_msgs::msg::Point::from_rmw_message(msg.spill_centroid),
      spill_normal: geometry_msgs::msg::Vector3::from_rmw_message(msg.spill_normal),
      point_cloud: sensor_msgs::msg::PointCloud2::from_rmw_message(msg.point_cloud),
      success: msg.success,
    }
  }
}


// Corresponds to arm_control_interfaces__srv__GetPlaneAtPixel_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetPlaneAtPixel_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetPlaneAtPixel_Request {
  type RmwMsg = super::srv::rmw::GetPlaneAtPixel_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x,
        y: msg.y,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      x: msg.x,
      y: msg.y,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      x: msg.x,
      y: msg.y,
    }
  }
}


// Corresponds to arm_control_interfaces__srv__GetPlaneAtPixel_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPlaneAtPixel_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub centroid: geometry_msgs::msg::Point,


    // This member is not documented.
    #[allow(missing_docs)]
    pub normal: geometry_msgs::msg::Vector3,


    // This member is not documented.
    #[allow(missing_docs)]
    pub boundary_points: Vec<geometry_msgs::msg::Point>,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetPlaneAtPixel_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetPlaneAtPixel_Response {
  type RmwMsg = super::srv::rmw::GetPlaneAtPixel_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        centroid: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.centroid)).into_owned(),
        normal: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Owned(msg.normal)).into_owned(),
        boundary_points: msg.boundary_points
          .into_iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        fx: msg.fx,
        fy: msg.fy,
        cx: msg.cx,
        cy: msg.cy,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        centroid: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.centroid)).into_owned(),
        normal: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Borrowed(&msg.normal)).into_owned(),
        boundary_points: msg.boundary_points
          .iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      fx: msg.fx,
      fy: msg.fy,
      cx: msg.cx,
      cy: msg.cy,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      centroid: geometry_msgs::msg::Point::from_rmw_message(msg.centroid),
      normal: geometry_msgs::msg::Vector3::from_rmw_message(msg.normal),
      boundary_points: msg.boundary_points
          .into_iter()
          .map(geometry_msgs::msg::Point::from_rmw_message)
          .collect(),
      fx: msg.fx,
      fy: msg.fy,
      cx: msg.cx,
      cy: msg.cy,
    }
  }
}


// Corresponds to arm_control_interfaces__srv__GetPointCloud_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPointCloud_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetPointCloud_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetPointCloud_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetPointCloud_Request {
  type RmwMsg = super::srv::rmw::GetPointCloud_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


// Corresponds to arm_control_interfaces__srv__GetPointCloud_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPointCloud_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub point_cloud: sensor_msgs::msg::PointCloud2,

}



impl Default for GetPointCloud_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetPointCloud_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetPointCloud_Response {
  type RmwMsg = super::srv::rmw::GetPointCloud_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        point_cloud: sensor_msgs::msg::PointCloud2::into_rmw_message(std::borrow::Cow::Owned(msg.point_cloud)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        point_cloud: sensor_msgs::msg::PointCloud2::into_rmw_message(std::borrow::Cow::Borrowed(&msg.point_cloud)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      point_cloud: sensor_msgs::msg::PointCloud2::from_rmw_message(msg.point_cloud),
    }
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


