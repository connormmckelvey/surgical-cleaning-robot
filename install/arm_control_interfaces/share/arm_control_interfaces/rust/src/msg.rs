#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to arm_control_interfaces__msg__GetSurfaceInfo
/// msg/GetSurfaceInfo.msg

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetSurfaceInfo {

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



impl Default for GetSurfaceInfo {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GetSurfaceInfo::default())
  }
}

impl rosidl_runtime_rs::Message for GetSurfaceInfo {
  type RmwMsg = super::msg::rmw::GetSurfaceInfo;

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


