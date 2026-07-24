"""
Training controller for the Surgical Arm ROS 2 project.
written by Connor McKelvey, 2026
This node controls the training data collection process. it opens a window showing the zed camera window and the user selects the
cleaning surface then presses enter. On enter the node will call the GetSurfaceInfo service (this can be very slow for large surfaces)
and then begin the rosbag recording of topics (if the rosbag doesnt start with a msg to the terminal, the service took too long and you will have to try again).
when 'q' is pressed the rosbag recording will stop
TODO:
    - reimplement normalizing the tag pose to the surface centroid and normal and publishing/recording that aswell
    - speed up or change surface/spill detection workflow (could go back to simply using the zed camera service to get the plane at a point and use that)
"""

import time

import cv2 as cv
import numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image

from arm_control_interfaces.msg import GetSurfaceInfo as GetSurfaceInfoMsg
from arm_control_interfaces.srv import GetSurfaceInfo as GetSurfaceInfoSrv
import arm_control.utilities.rosbag_capture as rb


class TrainingControllerNode(Node):
    def __init__(self):
        super().__init__('training_controller')

        # ROS parameters
        self.declare_parameter('rosbag_enabled', True)
        self.declare_parameter('rosbag_folder', '_training_bags')
        
        self.rosbag_enabled = self.get_parameter('rosbag_enabled').value
        self.rosbag_folder = self.get_parameter('rosbag_folder').value

        self.topics_to_record = [
            'camera/tag_pose',
            'force_sensor/data',
            'training/surface_spill_info',
        ]

        self.surface_result_pub = self.create_publisher(
            GetSurfaceInfoMsg,
            'training/surface_spill_info',
            10,
        )

        self.image_sub = self.create_subscription(
            Image,
            'camera/image_raw',
            self.image_callback,
            10,
        )

        self.surface_client = self.create_client(
            GetSurfaceInfoSrv,
            'surface_spill_detection/GetSurfaceInfo',
        )

        # Recording/service state
        self.bag_process = None
        self.selected_pixel = None
        self.request_in_progress = False

        # Last returned result, used only for GUI status.
        self.last_result_success = None

        self.window_name = 'ZED 2i Training Capture'
        cv.namedWindow(self.window_name)
        cv.setMouseCallback(self.window_name, self.mouse_callback)

        self.get_logger().info('Left-click a seed pixel, press Enter to record and call the service, and press Q to stop/reset.')

    def mouse_callback(self, event, x, y, flags, param):
        if event != cv.EVENT_LBUTTONDOWN or self.request_in_progress or self.bag_process is not None:
            return
        self.selected_pixel = (int(x), int(y))
        self.last_result_success = None
        self.get_logger().info(f'Selected seed pixel: {self.selected_pixel}')

    def image_callback(self, msg):
        frame = self.image_message_to_bgr(msg)
        if frame is None:
            return

        self.draw_status(frame)
        cv.imshow(self.window_name, frame)

        key = cv.waitKey(1)

        if key in (10, 13):  # Linux Enter or carriage return
            self.begin_capture()
        elif key == ord('q'):
            self.reset_capture()
        elif key == 27:  # Escape
            rclpy.shutdown()

#rosbag capture methods

    def begin_capture(self):
        request = GetSurfaceInfoSrv.Request()
        request.x = self.selected_pixel[0]
        request.y = self.selected_pixel[1]
        
        self.future = self.surface_client.call_async(request)
        self.future.add_done_callback(self.surface_response_callback)
        self.request_in_progress = True

    def surface_response_callback(self, future):
        self.request_in_progress = False
        prev_sub_count = self.surface_result_pub.get_subscription_count()

        self.bag_process = rb.start_rosbag_recording(self.topics_to_record, self.rosbag_folder)
        self.get_logger().info(f'Started rosbag recording to {self.rosbag_folder}... waiting for subscribers to surface_spill_info topic.')

        while self.surface_result_pub.get_subscription_count() <= prev_sub_count:
            time.sleep(0.1)

        response = future.result()
        
        result_msg = GetSurfaceInfoMsg()
        result_msg.surface_centroid = response.surface_centroid
        result_msg.surface_normal = response.surface_normal
        result_msg.spill_centroid = response.spill_centroid
        result_msg.spill_normal = response.spill_normal
        result_msg.point_cloud = response.point_cloud
        result_msg.success = response.success

        self.surface_result_pub.publish(result_msg)

    def reset_capture(self):
        if self.bag_process is None:
            return

        self.get_logger().info('Stopping rosbag recording...')
        rb.stop_rosbag_recording(self.bag_process)
        self.bag_process = None
        self.recording_started_at = None

#helper methods
    def image_message_to_bgr(self, msg):
        if msg.encoding != 'bgr8':
            return None
        frame = np.frombuffer(msg.data, dtype=np.uint8)
        return frame.reshape((msg.height, msg.width, 3)).copy()

    def draw_status(self, frame):
        if self.selected_pixel is not None:
            cv.drawMarker(
                frame,
                self.selected_pixel,
                (0, 255, 255),
                markerType=cv.MARKER_CROSS,
                markerSize=24,
                thickness=2,
            )
            cv.putText(
                frame,
                f'Seed: {self.selected_pixel}',
                (15, 30),
                cv.FONT_HERSHEY_SIMPLEX,
                0.7,
                (0, 255, 255),
                2,
            )
        else:
            cv.putText(
                frame,
                'Left-click to select a seed pixel',
                (15, 30),
                cv.FONT_HERSHEY_SIMPLEX,
                0.7,
                (255, 255, 255),
                2,
            )

        status = 'Press Enter to start capture'
        status_color = (255, 255, 255)

        cv.putText(
            frame,
            status,
            (15, 60),
            cv.FONT_HERSHEY_SIMPLEX,
            0.7,
            status_color,
            2,
        )

        if self.last_result_success is not None:
            result_text = 'Service result: SUCCESS' if self.last_result_success else 'Service result: FAILED'
            result_color = (0, 255, 0) if self.last_result_success else (0, 0, 255)
            cv.putText(
                frame,
                result_text,
                (15, 90),
                cv.FONT_HERSHEY_SIMPLEX,
                0.7,
                result_color,
                2,
            )

    def cleanup(self):
        self.reset_capture()
        cv.destroyAllWindows()


def main(args=None):
    rclpy.init(args=args)
    node = TrainingControllerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.cleanup()
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()