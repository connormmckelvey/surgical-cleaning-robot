"""
A Utility File to handle Surface Generation and Spill Detection taking Point Cloud data as input, also provides various helpful functions for working with points
    and point clouds.
    the common parameter "points" and refrences to point clouds are assumed to be a numpy array of dimension 1 with entries of the custom
     numpy datatype with parameters x, y, z, brga, px, py where xyz are 3d cordinates and px,py are the original pixel locations of the point
"""

import math
import numpy as np
import cv2
from collections import deque

point_dtype = np.dtype({
    'names': ['x', 'y', 'z', 'bgra', 'px', 'py'],
    'formats': ['<f4', '<f4', '<f4', '<u4', '<u2', '<u2'],
    'offsets': [0, 4, 8, 12, 16, 18],
    'itemsize': 20
})

def generate_surface(points, seed_cord, distance_threshold, normal_threshold=15.0):
    """
    Grow a connected surface through an organized point cloud using BFS.

    A neighboring point is accepted when:
        1. Its 3D distance from the accepted parent point is within
            distance_threshold.
        2. Its local normal is within normal_threshold degrees of the
            current surface normal.

    The surface normal starts as the seed pixel's local normal and is
    periodically refined using PCA over all accepted surface points.

    Args:
        points: Structured NumPy array with shape (height, width).
        seed_cord: Pixel coordinate tuple formatted as (pixel_x, pixel_y).
        distance_threshold: Maximum allowed 3D distance between neighboring
                            surface points.
        normal_threshold: Maximum allowed angular difference in degrees
                            between a candidate local normal and the current
                            surface normal.

    Returns:
        A one-dimensional structured NumPy array containing accepted points.
    """
    height, width = points.shape
    seed_x, seed_y = seed_cord

    if not in_bounds(seed_x, seed_y, width, height):
        raise ValueError(f'Seed coordinate {seed_cord} is outside point cloud bounds')

    seed_point = points[seed_y, seed_x]

    if not is_valid_point(seed_point):
        return np.empty(0, dtype=points.dtype)

    normal_radius = 2
    normal_update_interval = 25
    normal_cos_threshold = math.cos(math.radians(normal_threshold))

    #added to increase speed by precomputing normals, numpy is way faster and doing an operation once over alot of data than doing it many times over less
    normal_map, normal_valid = precompute_normal_map(points, normal_radius, distance_threshold)

    if not normal_valid[seed_y, seed_x]:
        return np.empty(0, dtype=points.dtype)

    surface_normal = normal_map[seed_y, seed_x].copy()

    queue = deque([(seed_x, seed_y)])
    accepted = np.zeros((height, width), dtype=bool)
    surface_points = []

    accepted[seed_y, seed_x] = True

    neighbor_offsets = [
        (-1, 0),
        (1, 0),
        (0, -1),
        (0, 1)
    ]

    while queue:
        parent_x, parent_y = queue.popleft()
        parent_point = points[parent_y, parent_x]

        surface_points.append(parent_point)

        if (
            len(surface_points) >= normal_update_interval and
            len(surface_points) % normal_update_interval == 0
        ):
            updated_normal = generate_normal_pca(
                np.array(surface_points, dtype=points.dtype)
            )

            if updated_normal is not None:
                surface_normal = updated_normal

        for offset_x, offset_y in neighbor_offsets:
            neighbor_x = parent_x + offset_x
            neighbor_y = parent_y + offset_y

            if not in_bounds(neighbor_x, neighbor_y, width, height):
                continue

            if accepted[neighbor_y, neighbor_x]:
                continue

            neighbor_point = points[neighbor_y, neighbor_x]

            if not is_valid_point(neighbor_point):
                continue

            if distance(parent_point, neighbor_point) > distance_threshold:
                continue

            if not normal_valid[neighbor_y, neighbor_x]:
                continue

            local_normal = normal_map[neighbor_y, neighbor_x]
            normal_similarity = abs(float(np.dot(local_normal, surface_normal)))
            normal_similarity = float(np.clip(normal_similarity, 0.0, 1.0))

            if normal_similarity < normal_cos_threshold:
                continue

            accepted[neighbor_y, neighbor_x] = True
            queue.append((neighbor_x, neighbor_y))

    return np.array(surface_points, dtype=points.dtype)

def detect_spill(points, k=6.0, clean=True, min_area=50, lab_weighting=np.array([0.0, 1.0, 1.0], dtype=np.float32), red_margin=8.0):
        """Return the subset of `points` belonging to a spill."""
        lab = unpack_lab(points) #get LAB values for every point, done using vectors or something to make it faster

        # gets the majority color of the surface, done using lab values so that it is more robust to lighting changes
        # returns a 1D array of length 3, with the median L, a, and b values of the points INDIVIDUALLY
        majority_color = np.median(lab, axis=0)

        # Distance from background. L is now weighted 0 so brightness is ignored:
        # a grey tray, a white specular reflection, and a shadow all have nearly the same chroma (a,b),
        # so keying on chroma instead of brightness makes glare/shadows collapse onto the background and drop out
        weights_of_lab = lab_weighting # weights L as 0 and the a,b (chroma) channels as 1
        d = np.linalg.norm((lab - majority_color) * weights_of_lab, axis=1) # compares the lab of a pixel to the majority color and then applies the weights,
        #                                                                     then takes the norm of that to get a single value for each pixel
        # gives us an array of distances from the majority color for each pixel, where a higher value means that the pixel is more different from the majority color

        # does some kind of sophisticated outlier detection to find the pixels that are significantly different from the majority color
        # using the median and median absolute deviation (MAD) to find outliers
        # adding the 1e-6 is to avoid division by zero in case the MAD is zero
        # muliplying the MAD by 1.4826 is to make it comparable to the standard deviation for a normal distribution
        med = np.median(d)
        mad = np.median(np.abs(d - med)) * 1.4826 + 1e-6
        mask = d > med + k * mad

        # directional bias: hospital spills are usually reddish, and red lives on the a-channel (a > 128 is the red axis)
        # so we require a pixel's a value to rise above the background's a value by at least red_margin to count as spill
        # this is measured relative to the majority color (not absolute 128) so it still works if the tray has a slight tint
        # this rejects white glare AND any green/blue anomalies; set red_margin=None to fall back to general "any chroma anomaly" detection
        if red_margin is not None:
            mask &= lab[:, 1] > majority_color[1] + red_margin # keep only pixels whose a-channel is sufficiently redder than the background

        if clean:
            mask = spatial_clean(points, mask, min_area)

        #returns points that are in mask
        return points[mask]

def distance(point1, point2) -> float:
    """
    Calculate the Euclidean distance between two 3D points.
    Args:
        point1, point2: Structured NumPy points using point_dtype
    Returns:
        The Euclidean distance between the two points.
    """
    dx = float(point2["x"]) - float(point1["x"])
    dy = float(point2["y"]) - float(point1["y"])
    dz = float(point2["z"]) - float(point1["z"])

    return float(np.sqrt(dx * dx + dy * dy + dz * dz))

def centroid(points):
    """
    Calculate the centroid of a set of 3D points.
    Args:
        points: A 1D structured NumPy array containing the fields
                x, y, z, bgra, px, and py.
    Returns:
        A NumPy array with shape (3,) representing the centroid coordinates.
    """
    xyz = np.column_stack((
        points["x"],
        points["y"],
        points["z"]
    )).astype(np.float32)

    valid_mask = np.all(np.isfinite(xyz), axis=1)
    xyz = xyz[valid_mask]

    if len(xyz) == 0:
        return None

    centroid = np.mean(xyz, axis=0)
    return centroid

def calculate_normal(points):
    """
    Generate a surface normal using the cross product of two vectors.

    Args:
        points: A 1D structured NumPy array containing the fields
                x, y, z, bgra, px, and py.

    Returns:
        A unit-length normal vector with shape (3,).
        Returns None if a normal cannot be calculated.
    """
    if len(points) < 3:
        return None

    p0 = points[0]
    p1 = points[1]
    p2 = points[2]

    v1 = np.array([p1["x"] - p0["x"], p1["y"] - p0["y"], p1["z"] - p0["z"]])
    v2 = np.array([p2["x"] - p0["x"], p2["y"] - p0["y"], p2["z"] - p0["z"]])

    normal = np.cross(v1, v2)
    magnitude = np.linalg.norm(normal)

    if not np.isfinite(magnitude) or magnitude < 1e-8:
        return None

    normal /= magnitude

    # Keep the normal pointing upward in the ZED +Z-up frame.
    if normal[2] < 0:
        normal = -normal

    return normal

def generate_normal_pca(points):
    """
    Generate a surface normal using PCA.

    Args:
        points: A 1D structured NumPy array containing the fields
                x, y, z, bgra, px, and py.

    Returns:
        A unit-length normal vector with shape (3,).
        Returns None if a normal cannot be calculated.
    """
    xyz = np.column_stack((
        points["x"],
        points["y"],
        points["z"]
    )).astype(np.float32)

    valid_mask = np.all(np.isfinite(xyz), axis=1)
    xyz = xyz[valid_mask]

    center = np.mean(xyz, axis=0)
    centered_points = xyz - center
    covariance = centered_points.T @ centered_points
    eigenvalues, eigenvectors = np.linalg.eigh(covariance)
    normal = eigenvectors[:, np.argmin(eigenvalues)]
    magnitude = np.linalg.norm(normal)
    if not np.isfinite(magnitude) or magnitude < 1e-8:
        return None

    normal /= magnitude

    # Keep the normal pointing upward in the ZED +Z-up frame.
    if normal[2] < 0:
        normal = -normal

    return normal

def precompute_normal_map(points, radius=2, distance_threshold=None):
    """Precompute one normal per organized point-cloud pixel.

    Normals are estimated from horizontal and vertical tangent vectors using
    points on opposite sides of each pixel. The full normal map is generated
    with NumPy array operations instead of calculating a PCA normal inside the
    surface-growth loop.
    Args:
        points: Structured NumPy array with shape (height, width).
        radius: Pixel offset used for the tangent vectors.
        distance_threshold: Optional maximum allowed 3D distance from the
                            center point to each tangent endpoint. When None,
                            only finite-point validation is used.
    Returns:
        normal_map: Float32 array with shape (height, width, 3).
        normal_valid: Boolean array identifying pixels with usable normals.
    """
    if points.ndim != 2:
        raise ValueError('precompute_normal_map expects an organized 2D point cloud')

    if radius < 1:
        raise ValueError('radius must be at least 1')

    height, width = points.shape
    normal_map = np.zeros((height, width, 3), dtype=np.float32)
    normal_valid = np.zeros((height, width), dtype=bool)

    if height <= radius * 2 or width <= radius * 2:
        return normal_map, normal_valid

    xyz = np.empty((height, width, 3), dtype=np.float32)
    xyz[..., 0] = points['x']
    xyz[..., 1] = points['y']
    xyz[..., 2] = points['z']

    center = xyz[radius:-radius, radius:-radius]
    left = xyz[radius:-radius, :-2 * radius]
    right = xyz[radius:-radius, 2 * radius:]
    up = xyz[:-2 * radius, radius:-radius]
    down = xyz[2 * radius:, radius:-radius]

    horizontal = right - left
    vertical = down - up
    normals = np.cross(horizontal, vertical)

    valid = (
        np.all(np.isfinite(center), axis=2) &
        np.all(np.isfinite(left), axis=2) &
        np.all(np.isfinite(right), axis=2) &
        np.all(np.isfinite(up), axis=2) &
        np.all(np.isfinite(down), axis=2)
    )

    if distance_threshold is not None:
        max_endpoint_distance = distance_threshold * max(2, radius)
        max_endpoint_distance_squared = max_endpoint_distance * max_endpoint_distance

        left_distance_squared = np.sum((left - center) ** 2, axis=2)
        right_distance_squared = np.sum((right - center) ** 2, axis=2)
        up_distance_squared = np.sum((up - center) ** 2, axis=2)
        down_distance_squared = np.sum((down - center) ** 2, axis=2)

        valid &= (
            (left_distance_squared <= max_endpoint_distance_squared) &
            (right_distance_squared <= max_endpoint_distance_squared) &
            (up_distance_squared <= max_endpoint_distance_squared) &
            (down_distance_squared <= max_endpoint_distance_squared)
        )

    magnitudes = np.linalg.norm(normals, axis=2)
    valid &= np.isfinite(magnitudes) & (magnitudes > 1e-8)

    normalized = np.zeros_like(normals, dtype=np.float32)
    normalized[valid] = normals[valid] / magnitudes[valid, None]

    flip_mask = valid & (normalized[..., 2] < 0)
    normalized[flip_mask] *= -1.0

    normal_map[radius:-radius, radius:-radius] = normalized
    normal_valid[radius:-radius, radius:-radius] = valid

    return normal_map, normal_valid

def calculate_local_normal(points, pixel_x, pixel_y, radius, distance_threshold):
    """Estimate a pixel's local surface normal using PCA on nearby points."""
    height, width = points.shape
    center_point = points[pixel_y, pixel_x]

    if not is_valid_point(center_point):
        return None

    x_min = max(0, pixel_x - radius)
    x_max = min(width, pixel_x + radius + 1)
    y_min = max(0, pixel_y - radius)
    y_max = min(height, pixel_y + radius + 1)

    local_points = []
    max_local_distance = distance_threshold * max(2, radius)

    for neighbor_y in range(y_min, y_max):
        for neighbor_x in range(x_min, x_max):
            point = points[neighbor_y, neighbor_x]

            if not is_valid_point(point):
                continue

            if distance(center_point, point) > max_local_distance:
                continue

            local_points.append(point)

    if len(local_points) < 3:
        return None

    return generate_normal_pca(np.array(local_points, dtype=points.dtype))

def in_bounds(x, y, width, height):
    return 0 <= x < width and 0 <= y < height

def is_valid_point(point):
    """returns true if X,Y,Z of a point is finite, expects a structured point with x, y, z, bgra, px, and py fields"""
    return np.isfinite(point['x']) and np.isfinite(point['y']) and np.isfinite(point['z'])

def bgra_to_lab(bgra):
    """Convert a packed BGRA integer to a Lab color tuple."""
    blue = (bgra >> 16) & 0xFF
    green = (bgra >> 8) & 0xFF
    red = bgra & 0xFF

    bgr_color = np.array([[[blue, green, red]]], dtype=np.uint8)
    lab_color = cv2.cvtColor(bgr_color, cv2.COLOR_BGR2LAB)

    return tuple(lab_color[0, 0])

def unpack_lab(points):
    """Vectorized BGRA -> Lab for a structured point array, lab values are returned in the order L, a, b as a 2D array of shape (num_points, 3)"""
    bgra = points['bgra']
    blue  = (bgra >> 16) & 0xFF
    green = (bgra >> 8)  & 0xFF
    red   =  bgra        & 0xFF
    bgr = np.stack([blue, green, red], axis=-1).astype(np.uint8).reshape(-1, 1, 3)
    lab = cv2.cvtColor(bgr, cv2.COLOR_BGR2LAB).reshape(-1, 3).astype(np.float32)
    return lab

def spatial_clean(points, mask, min_area):
    """Drop speckle by rasterizing into image space (px, py) and keeping big blobs."""
    px = points['px'].astype(np.int32)
    py = points['py'].astype(np.int32) #convert to int32 from uint16
    W, H = int(px.max()) + 1, int(py.max()) + 1 #width and height of the image

    img = np.zeros((H, W), np.uint8)
    img[py, px] = mask.astype(np.uint8) * 255

    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (5, 5))
    img = cv2.morphologyEx(img, cv2.MORPH_OPEN,  kernel)   # remove noise
    img = cv2.morphologyEx(img, cv2.MORPH_CLOSE, kernel)   # fill holes

    n, labels, stats, _ = cv2.connectedComponentsWithStats(img, 8)
    keep = np.zeros(n, dtype=bool)
    for i in range(1, n):  # skip background label 0
        if stats[i, cv2.CC_STAT_AREA] >= min_area:
            keep[i] = True

    return keep[labels][py, px]