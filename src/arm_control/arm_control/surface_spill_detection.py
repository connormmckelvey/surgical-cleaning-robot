#!/usr/bin/env python3

"""
Surface and Spill Detection for Point Cloud Data 
written by Connor McKelvey, Summer 2026
requires the point_cloud.py utility file
has 3 modes, 'plot_saved', 'plot_live', and 'capture'
NOTE: its slow as heck right now, could be sped up using better numpy vectorization but i dont really understand how to do that yet
plot_saved: "used as a way to test algos and visualize data
    - loads a saved point cloud from a json file
    - displays it as a 2D image
    - allows the user to click on a pixel to select a seed point
    - generates a surface from the seed point and displays it in 3D
    - detects spills on the surface and displays them in 3D
plot_live:
    - when the GetSurfaceInfo service is called, it will generate a surface and detect spills from the current point cloud published from the camera
    - this service takes an xy seed pixel as input and returns a surface and spill normal positioned at the centroid. it also returns a PointCloud2
capture:
    - captures a point cloud from the camera and saves it to a json file
"""

import matplotlib.pyplot as plt
import numpy as np
import json

import rclpy
from rclpy.node import Node
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor

from sensor_msgs.msg import PointCloud2
from visualization_msgs.msg import Marker
from arm_control_interfaces.srv import GetSurfaceInfo, GetPointCloud
from geometry_msgs.msg import Point, Vector3

import arm_control.utilities.point_cloud as pc

class SurfaceSpillDetection(Node):
    def __init__(self):
        super().__init__('surface_spill_detection')

        self.declare_parameter('mode', 'plot_saved')
        self.declare_parameter('distance_threshold', 0.004)  #max distance from parent to canidate when generating surface
        self.declare_parameter('normal_threshold', 15.0) #max angle from parent to canidate when generating surface
        self.declare_parameter('pixel_step', 4) #check every Nth neighboor when generating surfaces
        self.declare_parameter('plot_pixel_step', 16) #plot every 16th pixel
        self.declare_parameter('clean',False) # weather we should clean the spill data (haha) by removing pixels that do not have many neighboors
        self.declare_parameter('min_area', 5) # if clean is True this is the min amount of pixels that need to be next to eachother for it to be considered
        self.declare_parameter('k',8.0) #std away from base color allowed, higher number means stricter spill detection

        self.mode = str(self.get_parameter('mode').value)
        self.distance_threshold = self.get_parameter('distance_threshold').value
        self.normal_threshold = self.get_parameter('normal_threshold').value
        self.pixel_step = self.get_parameter('pixel_step').value
        self.plot_pixel_step = self.get_parameter('plot_pixel_step').value
        self.clean = self.get_parameter('clean').value
        self.min_area = self.get_parameter('min_area').value
        self.k = self.get_parameter('k').value

        self.callback_group = ReentrantCallbackGroup() #stuff needed bc we are calling a service in a service

        self.get_point_cloud_client = self.create_client(
            GetPointCloud,
            '/camera/GetPointCloud',
            callback_group=self.callback_group
        )

        self.get_surface_info_service = self.create_service(
            GetSurfaceInfo,
            '/surface_spill_detection/GetSurfaceInfo',
            self.get_surface_spill_callback,
            callback_group=self.callback_group
        )
 
        self.debug_file = '_point_cloud_data/point_cloud_debug.json'
        self.point_dtype = pc.point_dtype
        self.seed_cord = (0,0)

        self.get_logger().info(f'Surface generator mode: {self.mode}')

        if self.mode == 'capture':
            self.mode_capture()
            return
        if self.mode == 'plot_saved':
            self.mode_plot_saved()
            return
        if self.mode =='plot_live':
            self.mode_live()
            return

# callbacks and mode 'main' methods

    def mode_plot_saved(self):
        """
        Display the saved cloud as a 2D image.

        Clicking a valid pixel reports:
            - image pixel coordinate
            - camera-frame XYZ
            - packed RGBA
        Press Enter to generate the surface from the last selected pixel.
        """
        points = self.load_point_cloud()
        image = self.structured_point_cloud_to_image(points)

        height, width = points.shape[:2]

        figure, axes = plt.subplots()
        axes.imshow(image, origin='upper')
        axes.set_title('Click a pixel to select a seed\nPress Enter to generate the surface')
        axes.set_xlabel('Pixel X')
        axes.set_ylabel('Pixel Y')

        marker = axes.scatter(
            [],
            [],
            s=100,
            marker='o',
            facecolors='none',
            edgecolors='red',
            linewidths=2
        )

        def on_click(event):
            if event.inaxes is not axes:
                return

            if event.xdata is None or event.ydata is None:
                return

            pixel_x = int(round(event.xdata))
            pixel_y = int(round(event.ydata))

            if not pc.in_bounds(pixel_x, pixel_y, width, height):
                return

            point = points[pixel_y, pixel_x]

            if not pc.is_valid_point(point):
                self.get_logger().warning(f'Pixel ({pixel_x}, {pixel_y}) has invalid XYZ data')
                return

            self.seed_cord = (pixel_x, pixel_y)
            marker.set_offsets([[pixel_x, pixel_y]])

            axes.set_title(
                f'Pixel ({pixel_x}, {pixel_y})\n'
                f'XYZ ({point["x"]:.3f}, {point["y"]:.3f}, {point["z"]:.3f})\n'
                'Press Enter to generate the surface'
            )
            self.get_logger().info(f'Selected pixel: ({pixel_x}, {pixel_y})')
            figure.canvas.draw_idle()

        def on_key(event):
            if event.key != 'enter':
                return
            surface = pc.generate_surface(points, self.seed_cord, self.distance_threshold, self.normal_threshold)
            generate_normal = pc.generate_normal_pca(surface)
            self.get_logger().info(f'Generated normal vector: {generate_normal}')
            self.get_logger().info(f'Generated {len(surface)} points from {self.seed_cord}')
            self.plot_point_cloud(surface, self.plot_pixel_step)
            self.plot_point_cloud_image(surface)
            spill = pc.detect_spill(surface, k=self.k, clean=self.clean, min_area=self.min_area, lab_weighting=np.array([0, 1.25, 1])) #change default weighting to make colors like blood (redish) more likely to be detected as a spill, and make L less important since lighting can change it a lot
            self.plot_point_cloud(spill)

        figure.canvas.mpl_connect('button_press_event', on_click)
        figure.canvas.mpl_connect('key_press_event', on_key)

        plt.tight_layout()
        plt.show()

    def mode_live(self):
        """
        In live mode, the node waits for a service request to generate a surface and detect spills.
        The service takes a seed pixel coordinate as input and returns the surface and spill information.
        No plotting is done, this node serves solely as a service provider for surface and spill detection in live mode.
        """
        self.get_logger().info('Live mode: waiting for GetSurfaceInfo service requests...')

    def mode_capture(self):
        request = GetPointCloud.Request()
        future = self.get_point_cloud_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)

        response = future.result()

        points = self.pointcloud2_to_numpy(response.point_cloud)
        self.save_point_cloud(points)
        self.get_logger().info(f'Saved point cloud to {self.debug_file}')

    async def get_surface_spill_callback(self, request, response):
        """
        Service callback to generate a surface and detect spills from a given seed pixel.

        Args:
            request: GetSurfaceInfo.Request containing seed pixel coordinates (x, y).
            response: GetSurfaceInfo.Response to be populated with surface and spill information.
        """
        seed_pixel = (request.x,request.y)
        self.get_logger().info(f'Received GetSurfaceInfo request for seed pixel: {seed_pixel}')

        response.surface_centroid = Point()
        response.surface_normal = Vector3()
        response.spill_centroid = Point()
        response.spill_normal = Vector3()
        response.point_cloud = PointCloud2()
        
        response.success = False

        point_cloud_request = GetPointCloud.Request()
        point_cloud_future = self.get_point_cloud_client.call_async(point_cloud_request)
        point_cloud_response = await point_cloud_future

        point_cloud = point_cloud_response.point_cloud
        self.get_logger().info(f'Received point cloud with dimensions: {point_cloud.width}x{point_cloud.height}')

        points = self.pointcloud2_to_numpy(point_cloud)
        self.get_logger().info(f'Converted PointCloud2 to structured NumPy array with shape: {points.shape}')

        seed_point = points[seed_pixel[1], seed_pixel[0]]
        self.get_logger().info(f'Seed pixel coordinates: {seed_pixel}, Seed point XYZ: ({seed_point["x"]}, {seed_point["y"]}, {seed_point["z"]})')

        surface = pc.generate_surface(points,seed_pixel,self.distance_threshold,self.normal_threshold)
        self.get_logger().info(f'Generated surface with {len(surface)} points from seed pixel: {seed_pixel}')
        surface_centroid = pc.centroid(surface)
        surface_normal = pc.calculate_normal(surface)
        self.get_logger().info(f'Surface centroid: {surface_centroid}, Surface normal: {surface_normal}')
        spill = pc.detect_spill(surface, k=self.k, clean=self.clean, min_area=self.min_area, lab_weighting=np.array([0, 1.25, 1]))
        self.get_logger().info(f'Detected spill with {len(spill)} points')

        response.surface_centroid.x = float(surface_centroid[0])
        response.surface_centroid.y = float(surface_centroid[1])
        response.surface_centroid.z = float(surface_centroid[2])

        response.surface_normal.x = float(surface_normal[0])
        response.surface_normal.y = float(surface_normal[1])
        response.surface_normal.z = float(surface_normal[2])

        if spill is not None and len(spill) > 0:
            spill_centroid = pc.centroid(spill)
            spill_normal = pc.calculate_normal(spill)

            response.spill_centroid.x = float(spill_centroid[0])
            response.spill_centroid.y = float(spill_centroid[1])
            response.spill_centroid.z = float(spill_centroid[2])

            response.spill_normal.x = float(spill_normal[0])
            response.spill_normal.y = float(spill_normal[1])
            response.spill_normal.z = float(spill_normal[2])

        response.point_cloud = point_cloud
        response.point_cloud.header.stamp = self.get_clock().now().to_msg()
        response.point_cloud.header.frame_id = 'zed_camera_frame'
        response.success = True

        # self.plot_point_cloud(surface, self.plot_pixel_step)
        # self.plot_point_cloud(spill, self.plot_pixel_step)

        return response    

#conversion methods

    def pointcloud2_to_numpy(self, msg):
        """
        Decode the ZED PointCloud2 message into the member point dtype.

        The ROS message stores only x, y, z, bgra, px, and py. This method adds px and
        py while copying the raw message into the enriched point array used by
        the rest of the node.

        Output:
            points[py, px] with fields x, y, z, bgra, px, and py.

        Camera coordinate frame:
            +X = forward
            +Y = left
            +Z = up
        """
        raw_point_dtype = np.dtype({
            'names': ['x', 'y', 'z', 'bgra'],
            'formats': ['<f4', '<f4', '<f4', '<u4'],
            'offsets': [0, 4, 8, 12],
            'itemsize': msg.point_step
        })

        if msg.row_step == msg.width * msg.point_step:
            raw_points = np.frombuffer(
                msg.data,
                dtype=raw_point_dtype,
                count=msg.height * msg.width
            ).reshape(msg.height, msg.width)
        else:
            raw_points = np.ndarray(
                shape=(msg.height, msg.width),
                dtype=raw_point_dtype,
                buffer=msg.data,
                strides=(msg.row_step, msg.point_step)
            )

        points = np.empty((msg.height, msg.width), dtype=pc.point_dtype)
        points['x'] = raw_points['x']
        points['y'] = raw_points['y']
        points['z'] = raw_points['z']
        points['bgra'] = raw_points['bgra']

        pixel_y, pixel_x = np.indices((msg.height, msg.width), dtype=np.uint16)
        points['px'] = pixel_x
        points['py'] = pixel_y

        return points

    def save_point_cloud(self, points_nparray):
        """Save an organized structured point cloud to JSON."""
        height, width = points_nparray.shape
        saved_data = {"height": height, "width": width, "points": []}

        for pixel_y in range(height):
            for pixel_x in range(width):
                point = points_nparray[pixel_y, pixel_x]

                point_dict = {
                    "pixel_x": int(point["px"]),
                    "pixel_y": int(point["py"]),
                    "x": float(point["x"]),
                    "y": float(point["y"]),
                    "z": float(point["z"]),
                    "rgba": int(point["bgra"])
                }

                saved_data["points"].append(point_dict)

        with open(self.debug_file, "w") as file:
            json.dump(saved_data, file)

    def load_point_cloud(self):
        """Load an organized structured point cloud from JSON."""
        with open(self.debug_file, "r") as file:
            saved_data = json.load(file)

        height = saved_data["height"]
        width = saved_data["width"]

        points_nparray = np.zeros((height, width), dtype=pc.point_dtype)

        for point in saved_data["points"]:
            pixel_x = point["pixel_x"]
            pixel_y = point["pixel_y"]

            points_nparray[pixel_y, pixel_x] = (
                point["x"],
                point["y"],
                point["z"],
                point["rgba"],
                pixel_x,
                pixel_y
            )
        return points_nparray

    def structured_point_cloud_to_image(self, points):
        """
        Convert an organized structured point cloud numpy array to a 2D image.
        The image is in RGBA format, with invalid points set to bright green.
        """
        height, width = points.shape[0], points.shape[1]
        image = np.zeros((height, width, 4), dtype=np.uint8)

        for pixel_y in range(height):
            for pixel_x in range(width):
                point = points[pixel_y, pixel_x]

                if pc.is_valid_point(point):
                    bgra = point["bgra"]
                    blue = (bgra >> 16) & 0xFF
                    green = (bgra >> 8) & 0xFF
                    red = bgra & 0xFF
                    alpha = (bgra >> 24) & 0xFF

                    if alpha == 0:
                        alpha = 255

                    image[pixel_y, pixel_x] = [red, green, blue, alpha]
                else:
                    # Invalid points are set to bright green
                    image[pixel_y, pixel_x] = [0, 255, 0, 255]

        return image

#plotting methods

    def plot_point_cloud(self, points, step=1, show_centroid=True, show_normal=True):
        """
        Plot either an organized point cloud or a one-dimensional surface array.

        Args:
            points: Structured NumPy array containing x, y, z, bgra, px, and py fields.
                    May have shape (height, width) or (number_of_points).
            step: Plot every nth point.
            show_centroid: Whether to plot the centroid.
            show_normal: Whether to plot the normal.
        """

        # Convert both organized clouds and surface arrays into one flat array.
        flat_points = points.reshape(-1)

        sampled_points = flat_points[::step]

        valid_mask = (
            np.isfinite(sampled_points["x"]) &
            np.isfinite(sampled_points["y"]) &
            np.isfinite(sampled_points["z"])
        )

        sampled_points = sampled_points[valid_mask]

        x = sampled_points["x"]
        y = sampled_points["y"]
        z = sampled_points["z"]
        bgra = sampled_points["bgra"].astype(np.uint32, copy=False)

        blue = ((bgra >> 16) & 0xFF).astype(np.float32) / 255.0
        green = ((bgra >> 8) & 0xFF).astype(np.float32) / 255.0
        red = (bgra & 0xFF).astype(np.float32) / 255.0
        alpha = ((bgra >> 24) & 0xFF).astype(np.float32) / 255.0

        alpha[alpha == 0] = 1.0

        colors = np.column_stack((red, green, blue, alpha))

        figure = plt.figure()
        axis = figure.add_subplot(111, projection="3d")

        plot_y = y

        axis.scatter(
            x,
            plot_y,
            z,
            c=colors,
            s=100,
            marker="."
        )
        
        if show_centroid:
            centroid = pc.centroid(sampled_points)
            if centroid is not None:
                axis.scatter(
                    centroid[0],
                    centroid[1],
                    centroid[2],
                    c='yellow',
                    s=200,
                    marker='o',
                    edgecolors='black',
                    linewidths=2,
                    label='Centroid'
                )
                axis.legend()

        if show_normal: #show a normal vector positioned at the centroid of the surface, with a length of 0.05 meters
            normal = pc.calculate_normal(sampled_points)
            if normal is not None:
                centroid = pc.centroid(sampled_points)
                if centroid is not None:
                    axis.quiver(
                        centroid[0],
                        centroid[1],
                        centroid[2],
                        normal[0],
                        normal[1],
                        normal[2],
                        length=0.05,
                        color='cyan',
                        linewidth=2,
                        label='Normal'
                    )
                    axis.legend()

        axis.set_xlabel("X - Forward")
        axis.set_ylabel("-Y - Right")
        axis.set_zlabel("Z - Up")
        axis.set_title(
            f"Point Cloud - {sampled_points.size} Points"
        )

        x_range = np.ptp(x)
        y_range = np.ptp(plot_y)
        z_range = np.ptp(z)

        largest_range = max(x_range, y_range, z_range)

        if largest_range > 0:
            x_center = (np.max(x) + np.min(x)) / 2
            y_center = (np.max(plot_y) + np.min(plot_y)) / 2
            z_center = (np.max(z) + np.min(z)) / 2

            half_range = largest_range / 2

            axis.set_xlim(
                x_center - half_range,
                x_center + half_range
            )
            axis.set_ylim(
                y_center - half_range,
                y_center + half_range
            )
            axis.set_zlim(
                z_center - half_range,
                z_center + half_range
            )

        plt.show()

    def plot_point_cloud_image(self, points):
        """
        Render a flat point-cloud array as a 2D image using each point's px and py.

        Args:
            points: One-dimensional structured NumPy array containing:
                    x, y, z, bgra, px, and py.

        Returns:
            None
        """
        width = int(np.max(points['px'])) + 1
        height = int(np.max(points['py'])) + 1

        image = np.zeros((height, width, 3), dtype=np.uint8)

        packed_bgra = points['bgra'].astype(np.uint32)

        # Common little-endian PointCloud2 packed RGBA layout:
        # byte 0 = B
        # byte 1 = G
        # byte 2 = R
        blue = ((packed_bgra >> 16) & 0xFF).astype(np.uint8)
        green = ((packed_bgra >> 8) & 0xFF).astype(np.uint8)
        red = (packed_bgra & 0xFF).astype(np.uint8)

        pixel_x = points['px'].astype(np.int32)
        pixel_y = points['py'].astype(np.int32)

        image[pixel_y, pixel_x, 0] = red
        image[pixel_y, pixel_x, 1] = green
        image[pixel_y, pixel_x, 2] = blue

        figure, axes = plt.subplots()

        axes.imshow(image, origin='upper')
        axes.set_title('Point Cloud Image')
        axes.set_xlabel('Pixel X')
        axes.set_ylabel('Pixel Y')

        plt.tight_layout()
        plt.show()

def main(args=None):
    rclpy.init(args=args)
    node = SurfaceSpillDetection()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    try:
        executor.spin()
    except KeyboardInterrupt:
        executor.shutdown()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()