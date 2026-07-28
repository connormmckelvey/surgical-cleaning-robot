// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from arm_control_interfaces:msg/GetSurfaceInfo.idl
// generated code does not contain a copyright notice
#include "arm_control_interfaces/msg/detail/get_surface_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `surface_centroid`
// Member `spill_centroid`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `surface_normal`
// Member `spill_normal`
#include "geometry_msgs/msg/detail/vector3__functions.h"
// Member `point_cloud`
#include "sensor_msgs/msg/detail/point_cloud2__functions.h"

bool
arm_control_interfaces__msg__GetSurfaceInfo__init(arm_control_interfaces__msg__GetSurfaceInfo * msg)
{
  if (!msg) {
    return false;
  }
  // surface_centroid
  if (!geometry_msgs__msg__Point__init(&msg->surface_centroid)) {
    arm_control_interfaces__msg__GetSurfaceInfo__fini(msg);
    return false;
  }
  // surface_normal
  if (!geometry_msgs__msg__Vector3__init(&msg->surface_normal)) {
    arm_control_interfaces__msg__GetSurfaceInfo__fini(msg);
    return false;
  }
  // spill_centroid
  if (!geometry_msgs__msg__Point__init(&msg->spill_centroid)) {
    arm_control_interfaces__msg__GetSurfaceInfo__fini(msg);
    return false;
  }
  // spill_normal
  if (!geometry_msgs__msg__Vector3__init(&msg->spill_normal)) {
    arm_control_interfaces__msg__GetSurfaceInfo__fini(msg);
    return false;
  }
  // point_cloud
  if (!sensor_msgs__msg__PointCloud2__init(&msg->point_cloud)) {
    arm_control_interfaces__msg__GetSurfaceInfo__fini(msg);
    return false;
  }
  // success
  return true;
}

void
arm_control_interfaces__msg__GetSurfaceInfo__fini(arm_control_interfaces__msg__GetSurfaceInfo * msg)
{
  if (!msg) {
    return;
  }
  // surface_centroid
  geometry_msgs__msg__Point__fini(&msg->surface_centroid);
  // surface_normal
  geometry_msgs__msg__Vector3__fini(&msg->surface_normal);
  // spill_centroid
  geometry_msgs__msg__Point__fini(&msg->spill_centroid);
  // spill_normal
  geometry_msgs__msg__Vector3__fini(&msg->spill_normal);
  // point_cloud
  sensor_msgs__msg__PointCloud2__fini(&msg->point_cloud);
  // success
}

bool
arm_control_interfaces__msg__GetSurfaceInfo__are_equal(const arm_control_interfaces__msg__GetSurfaceInfo * lhs, const arm_control_interfaces__msg__GetSurfaceInfo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // surface_centroid
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->surface_centroid), &(rhs->surface_centroid)))
  {
    return false;
  }
  // surface_normal
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->surface_normal), &(rhs->surface_normal)))
  {
    return false;
  }
  // spill_centroid
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->spill_centroid), &(rhs->spill_centroid)))
  {
    return false;
  }
  // spill_normal
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->spill_normal), &(rhs->spill_normal)))
  {
    return false;
  }
  // point_cloud
  if (!sensor_msgs__msg__PointCloud2__are_equal(
      &(lhs->point_cloud), &(rhs->point_cloud)))
  {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
arm_control_interfaces__msg__GetSurfaceInfo__copy(
  const arm_control_interfaces__msg__GetSurfaceInfo * input,
  arm_control_interfaces__msg__GetSurfaceInfo * output)
{
  if (!input || !output) {
    return false;
  }
  // surface_centroid
  if (!geometry_msgs__msg__Point__copy(
      &(input->surface_centroid), &(output->surface_centroid)))
  {
    return false;
  }
  // surface_normal
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->surface_normal), &(output->surface_normal)))
  {
    return false;
  }
  // spill_centroid
  if (!geometry_msgs__msg__Point__copy(
      &(input->spill_centroid), &(output->spill_centroid)))
  {
    return false;
  }
  // spill_normal
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->spill_normal), &(output->spill_normal)))
  {
    return false;
  }
  // point_cloud
  if (!sensor_msgs__msg__PointCloud2__copy(
      &(input->point_cloud), &(output->point_cloud)))
  {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

arm_control_interfaces__msg__GetSurfaceInfo *
arm_control_interfaces__msg__GetSurfaceInfo__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arm_control_interfaces__msg__GetSurfaceInfo * msg = (arm_control_interfaces__msg__GetSurfaceInfo *)allocator.allocate(sizeof(arm_control_interfaces__msg__GetSurfaceInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(arm_control_interfaces__msg__GetSurfaceInfo));
  bool success = arm_control_interfaces__msg__GetSurfaceInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
arm_control_interfaces__msg__GetSurfaceInfo__destroy(arm_control_interfaces__msg__GetSurfaceInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    arm_control_interfaces__msg__GetSurfaceInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
arm_control_interfaces__msg__GetSurfaceInfo__Sequence__init(arm_control_interfaces__msg__GetSurfaceInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arm_control_interfaces__msg__GetSurfaceInfo * data = NULL;

  if (size) {
    data = (arm_control_interfaces__msg__GetSurfaceInfo *)allocator.zero_allocate(size, sizeof(arm_control_interfaces__msg__GetSurfaceInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = arm_control_interfaces__msg__GetSurfaceInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        arm_control_interfaces__msg__GetSurfaceInfo__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
arm_control_interfaces__msg__GetSurfaceInfo__Sequence__fini(arm_control_interfaces__msg__GetSurfaceInfo__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      arm_control_interfaces__msg__GetSurfaceInfo__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

arm_control_interfaces__msg__GetSurfaceInfo__Sequence *
arm_control_interfaces__msg__GetSurfaceInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arm_control_interfaces__msg__GetSurfaceInfo__Sequence * array = (arm_control_interfaces__msg__GetSurfaceInfo__Sequence *)allocator.allocate(sizeof(arm_control_interfaces__msg__GetSurfaceInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = arm_control_interfaces__msg__GetSurfaceInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
arm_control_interfaces__msg__GetSurfaceInfo__Sequence__destroy(arm_control_interfaces__msg__GetSurfaceInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    arm_control_interfaces__msg__GetSurfaceInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
arm_control_interfaces__msg__GetSurfaceInfo__Sequence__are_equal(const arm_control_interfaces__msg__GetSurfaceInfo__Sequence * lhs, const arm_control_interfaces__msg__GetSurfaceInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!arm_control_interfaces__msg__GetSurfaceInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
arm_control_interfaces__msg__GetSurfaceInfo__Sequence__copy(
  const arm_control_interfaces__msg__GetSurfaceInfo__Sequence * input,
  arm_control_interfaces__msg__GetSurfaceInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(arm_control_interfaces__msg__GetSurfaceInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    arm_control_interfaces__msg__GetSurfaceInfo * data =
      (arm_control_interfaces__msg__GetSurfaceInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!arm_control_interfaces__msg__GetSurfaceInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          arm_control_interfaces__msg__GetSurfaceInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!arm_control_interfaces__msg__GetSurfaceInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
