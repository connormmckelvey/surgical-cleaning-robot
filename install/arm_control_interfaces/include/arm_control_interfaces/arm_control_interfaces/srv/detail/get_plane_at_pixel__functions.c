// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from arm_control_interfaces:srv/GetPlaneAtPixel.idl
// generated code does not contain a copyright notice
#include "arm_control_interfaces/srv/detail/get_plane_at_pixel__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
arm_control_interfaces__srv__GetPlaneAtPixel_Request__init(arm_control_interfaces__srv__GetPlaneAtPixel_Request * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  return true;
}

void
arm_control_interfaces__srv__GetPlaneAtPixel_Request__fini(arm_control_interfaces__srv__GetPlaneAtPixel_Request * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
}

bool
arm_control_interfaces__srv__GetPlaneAtPixel_Request__are_equal(const arm_control_interfaces__srv__GetPlaneAtPixel_Request * lhs, const arm_control_interfaces__srv__GetPlaneAtPixel_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  return true;
}

bool
arm_control_interfaces__srv__GetPlaneAtPixel_Request__copy(
  const arm_control_interfaces__srv__GetPlaneAtPixel_Request * input,
  arm_control_interfaces__srv__GetPlaneAtPixel_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  return true;
}

arm_control_interfaces__srv__GetPlaneAtPixel_Request *
arm_control_interfaces__srv__GetPlaneAtPixel_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arm_control_interfaces__srv__GetPlaneAtPixel_Request * msg = (arm_control_interfaces__srv__GetPlaneAtPixel_Request *)allocator.allocate(sizeof(arm_control_interfaces__srv__GetPlaneAtPixel_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(arm_control_interfaces__srv__GetPlaneAtPixel_Request));
  bool success = arm_control_interfaces__srv__GetPlaneAtPixel_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
arm_control_interfaces__srv__GetPlaneAtPixel_Request__destroy(arm_control_interfaces__srv__GetPlaneAtPixel_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    arm_control_interfaces__srv__GetPlaneAtPixel_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence__init(arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arm_control_interfaces__srv__GetPlaneAtPixel_Request * data = NULL;

  if (size) {
    data = (arm_control_interfaces__srv__GetPlaneAtPixel_Request *)allocator.zero_allocate(size, sizeof(arm_control_interfaces__srv__GetPlaneAtPixel_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = arm_control_interfaces__srv__GetPlaneAtPixel_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        arm_control_interfaces__srv__GetPlaneAtPixel_Request__fini(&data[i - 1]);
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
arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence__fini(arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence * array)
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
      arm_control_interfaces__srv__GetPlaneAtPixel_Request__fini(&array->data[i]);
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

arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence *
arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence * array = (arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence *)allocator.allocate(sizeof(arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence__destroy(arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence__are_equal(const arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence * lhs, const arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!arm_control_interfaces__srv__GetPlaneAtPixel_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence__copy(
  const arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence * input,
  arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(arm_control_interfaces__srv__GetPlaneAtPixel_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    arm_control_interfaces__srv__GetPlaneAtPixel_Request * data =
      (arm_control_interfaces__srv__GetPlaneAtPixel_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!arm_control_interfaces__srv__GetPlaneAtPixel_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          arm_control_interfaces__srv__GetPlaneAtPixel_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!arm_control_interfaces__srv__GetPlaneAtPixel_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `centroid`
// Member `boundary_points`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `normal`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
arm_control_interfaces__srv__GetPlaneAtPixel_Response__init(arm_control_interfaces__srv__GetPlaneAtPixel_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // centroid
  if (!geometry_msgs__msg__Point__init(&msg->centroid)) {
    arm_control_interfaces__srv__GetPlaneAtPixel_Response__fini(msg);
    return false;
  }
  // normal
  if (!geometry_msgs__msg__Vector3__init(&msg->normal)) {
    arm_control_interfaces__srv__GetPlaneAtPixel_Response__fini(msg);
    return false;
  }
  // boundary_points
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->boundary_points, 0)) {
    arm_control_interfaces__srv__GetPlaneAtPixel_Response__fini(msg);
    return false;
  }
  // fx
  // fy
  // cx
  // cy
  return true;
}

void
arm_control_interfaces__srv__GetPlaneAtPixel_Response__fini(arm_control_interfaces__srv__GetPlaneAtPixel_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // centroid
  geometry_msgs__msg__Point__fini(&msg->centroid);
  // normal
  geometry_msgs__msg__Vector3__fini(&msg->normal);
  // boundary_points
  geometry_msgs__msg__Point__Sequence__fini(&msg->boundary_points);
  // fx
  // fy
  // cx
  // cy
}

bool
arm_control_interfaces__srv__GetPlaneAtPixel_Response__are_equal(const arm_control_interfaces__srv__GetPlaneAtPixel_Response * lhs, const arm_control_interfaces__srv__GetPlaneAtPixel_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // centroid
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->centroid), &(rhs->centroid)))
  {
    return false;
  }
  // normal
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->normal), &(rhs->normal)))
  {
    return false;
  }
  // boundary_points
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->boundary_points), &(rhs->boundary_points)))
  {
    return false;
  }
  // fx
  if (lhs->fx != rhs->fx) {
    return false;
  }
  // fy
  if (lhs->fy != rhs->fy) {
    return false;
  }
  // cx
  if (lhs->cx != rhs->cx) {
    return false;
  }
  // cy
  if (lhs->cy != rhs->cy) {
    return false;
  }
  return true;
}

bool
arm_control_interfaces__srv__GetPlaneAtPixel_Response__copy(
  const arm_control_interfaces__srv__GetPlaneAtPixel_Response * input,
  arm_control_interfaces__srv__GetPlaneAtPixel_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // centroid
  if (!geometry_msgs__msg__Point__copy(
      &(input->centroid), &(output->centroid)))
  {
    return false;
  }
  // normal
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->normal), &(output->normal)))
  {
    return false;
  }
  // boundary_points
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->boundary_points), &(output->boundary_points)))
  {
    return false;
  }
  // fx
  output->fx = input->fx;
  // fy
  output->fy = input->fy;
  // cx
  output->cx = input->cx;
  // cy
  output->cy = input->cy;
  return true;
}

arm_control_interfaces__srv__GetPlaneAtPixel_Response *
arm_control_interfaces__srv__GetPlaneAtPixel_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arm_control_interfaces__srv__GetPlaneAtPixel_Response * msg = (arm_control_interfaces__srv__GetPlaneAtPixel_Response *)allocator.allocate(sizeof(arm_control_interfaces__srv__GetPlaneAtPixel_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(arm_control_interfaces__srv__GetPlaneAtPixel_Response));
  bool success = arm_control_interfaces__srv__GetPlaneAtPixel_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
arm_control_interfaces__srv__GetPlaneAtPixel_Response__destroy(arm_control_interfaces__srv__GetPlaneAtPixel_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    arm_control_interfaces__srv__GetPlaneAtPixel_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence__init(arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arm_control_interfaces__srv__GetPlaneAtPixel_Response * data = NULL;

  if (size) {
    data = (arm_control_interfaces__srv__GetPlaneAtPixel_Response *)allocator.zero_allocate(size, sizeof(arm_control_interfaces__srv__GetPlaneAtPixel_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = arm_control_interfaces__srv__GetPlaneAtPixel_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        arm_control_interfaces__srv__GetPlaneAtPixel_Response__fini(&data[i - 1]);
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
arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence__fini(arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence * array)
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
      arm_control_interfaces__srv__GetPlaneAtPixel_Response__fini(&array->data[i]);
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

arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence *
arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence * array = (arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence *)allocator.allocate(sizeof(arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence__destroy(arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence__are_equal(const arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence * lhs, const arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!arm_control_interfaces__srv__GetPlaneAtPixel_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence__copy(
  const arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence * input,
  arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(arm_control_interfaces__srv__GetPlaneAtPixel_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    arm_control_interfaces__srv__GetPlaneAtPixel_Response * data =
      (arm_control_interfaces__srv__GetPlaneAtPixel_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!arm_control_interfaces__srv__GetPlaneAtPixel_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          arm_control_interfaces__srv__GetPlaneAtPixel_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!arm_control_interfaces__srv__GetPlaneAtPixel_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "arm_control_interfaces/srv/detail/get_plane_at_pixel__functions.h"

bool
arm_control_interfaces__srv__GetPlaneAtPixel_Event__init(arm_control_interfaces__srv__GetPlaneAtPixel_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    arm_control_interfaces__srv__GetPlaneAtPixel_Event__fini(msg);
    return false;
  }
  // request
  if (!arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence__init(&msg->request, 0)) {
    arm_control_interfaces__srv__GetPlaneAtPixel_Event__fini(msg);
    return false;
  }
  // response
  if (!arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence__init(&msg->response, 0)) {
    arm_control_interfaces__srv__GetPlaneAtPixel_Event__fini(msg);
    return false;
  }
  return true;
}

void
arm_control_interfaces__srv__GetPlaneAtPixel_Event__fini(arm_control_interfaces__srv__GetPlaneAtPixel_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence__fini(&msg->request);
  // response
  arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence__fini(&msg->response);
}

bool
arm_control_interfaces__srv__GetPlaneAtPixel_Event__are_equal(const arm_control_interfaces__srv__GetPlaneAtPixel_Event * lhs, const arm_control_interfaces__srv__GetPlaneAtPixel_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
arm_control_interfaces__srv__GetPlaneAtPixel_Event__copy(
  const arm_control_interfaces__srv__GetPlaneAtPixel_Event * input,
  arm_control_interfaces__srv__GetPlaneAtPixel_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!arm_control_interfaces__srv__GetPlaneAtPixel_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!arm_control_interfaces__srv__GetPlaneAtPixel_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

arm_control_interfaces__srv__GetPlaneAtPixel_Event *
arm_control_interfaces__srv__GetPlaneAtPixel_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arm_control_interfaces__srv__GetPlaneAtPixel_Event * msg = (arm_control_interfaces__srv__GetPlaneAtPixel_Event *)allocator.allocate(sizeof(arm_control_interfaces__srv__GetPlaneAtPixel_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(arm_control_interfaces__srv__GetPlaneAtPixel_Event));
  bool success = arm_control_interfaces__srv__GetPlaneAtPixel_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
arm_control_interfaces__srv__GetPlaneAtPixel_Event__destroy(arm_control_interfaces__srv__GetPlaneAtPixel_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    arm_control_interfaces__srv__GetPlaneAtPixel_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence__init(arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arm_control_interfaces__srv__GetPlaneAtPixel_Event * data = NULL;

  if (size) {
    data = (arm_control_interfaces__srv__GetPlaneAtPixel_Event *)allocator.zero_allocate(size, sizeof(arm_control_interfaces__srv__GetPlaneAtPixel_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = arm_control_interfaces__srv__GetPlaneAtPixel_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        arm_control_interfaces__srv__GetPlaneAtPixel_Event__fini(&data[i - 1]);
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
arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence__fini(arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence * array)
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
      arm_control_interfaces__srv__GetPlaneAtPixel_Event__fini(&array->data[i]);
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

arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence *
arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence * array = (arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence *)allocator.allocate(sizeof(arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence__destroy(arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence__are_equal(const arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence * lhs, const arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!arm_control_interfaces__srv__GetPlaneAtPixel_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence__copy(
  const arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence * input,
  arm_control_interfaces__srv__GetPlaneAtPixel_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(arm_control_interfaces__srv__GetPlaneAtPixel_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    arm_control_interfaces__srv__GetPlaneAtPixel_Event * data =
      (arm_control_interfaces__srv__GetPlaneAtPixel_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!arm_control_interfaces__srv__GetPlaneAtPixel_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          arm_control_interfaces__srv__GetPlaneAtPixel_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!arm_control_interfaces__srv__GetPlaneAtPixel_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
