"""
Force Sensor Node for ROS 2, made for the OR Cleaning Robot Project in the HERO Lab
Written by Connor McKelvey, 2026
This node interfaces with the HX711-based force sensor via Haplink serial protocol.
It reads raw ADC values, applies tare and calibration, and publishes force data in Newtons.
This was designed to prevent the need for reflashing the arduino firmware when taring/calibration
The node also provides ROS 2 services for taring and calibrating the sensor, the calibration assumes a known weight of 200g is placed on the sensor for calibration.
Inputs: Raw ADC values from the force sensor via Haplink
Outputs: Force in Newtons, Raw ADC values, Tared ADC values, Active Offset
Services: Tare, Calibrate

to call the services use the following commands:
ros2 service call /force_sensor_driver/tare std_srvs/srv/Trigger
ros2 service call /force_sensor_driver/calibrate std_srvs/srv/Trigger

"""

import rclpy
from rclpy.node import Node
from rcl_interfaces.msg import SetParametersResult
from diagnostic_msgs.msg import DiagnosticStatus, KeyValue
from std_srvs.srv import Trigger
from haplink import Haplink, DataType

class ForceSensorDriverNode(Node):
    def __init__(self):
        super().__init__('force_sensor_driver')
        
        # --- Parameters ---
        self.declare_parameter('debug', True)
        self.declare_parameter('scale', 8528.3965)  # Initial scale, will be updated when you Calibrate
        self.declare_parameter('offset', -692)  # Initial offset, will be updated when you Tare

        self.debug = self.get_parameter('debug').value
        self.scale = self.get_parameter('scale').value #77500.0  # Initial scale, will be updated when you Calibrate
        self.offset = self.get_parameter('offset').value #13997.0  # Initial offset, will be updated when you Tare

        self.port = '/dev/ttyUSB0'
        self.baud = 115200 
        self.g = 9.80665  # m/s^2, standard gravity
        self.frequency = 100.0  # Hz, for the serial read loop

        self.tare_requested = False
        self.calibration_requested = False

        self.haplink = Haplink(self.port, baudrate=self.baud, timeout=0.001)

        # initalize the connection to the Haplink device
        self.get_logger().info(f"Connecting to hardware via Haplink on {self.port}...")
        try:
            if not self.haplink.connect():
                self.get_logger().error("Haplink connection timed out.")
                raise RuntimeError("Haplink connection failed.")            
            # Register Telemetry IDs matching the Arduino firmware
            self.haplink.register_telemetry(0, 'raw_adc', DataType.INT32)
            self.haplink.register_telemetry(1, 'arduino_time', DataType.INT32)
        except Exception as e:
            self.get_logger().error(f"Haplink failed to initialize: {str(e)}")
            raise RuntimeError("Haplink connection failed.")
        self.get_logger().info("Haplink connection established successfully.")

        # --- ROS 2 Publishers & Services ---
        self.telemetry_pub = self.create_publisher(DiagnosticStatus, 'force_sensor/data', 10)
        
        # Universal Tare Service
        self.tare_srv = self.create_service(Trigger, 'force_sensor_driver/tare', self.handle_tare_service)

        # calibrate service assuming the use of a 200g weight for calibration
        self.calibrate_srv = self.create_service(Trigger, 'force_sensor_driver/calibrate', self.handle_calibrate_service)

        # Parameter update callback for "ros2 param set" commands
        self.add_on_set_parameters_callback(self.handle_parameter_updates)

        # --- High Speed Serial Execution loop (100Hz) ---
        self.create_timer(1/self.frequency, self.read_serial_loop)

    def read_serial_loop(self):
        self.haplink.update()
        
        raw_adc_val = self.haplink.get_telemetry('raw_adc')
        arduino_time_val = self.haplink.get_telemetry('arduino_time')
        
        if raw_adc_val is not None and arduino_time_val is not None:
            raw_adc = float(raw_adc_val)
            arduino_time = float(arduino_time_val)
            
            # --- Check if user triggered a Tare Event ---
            if self.tare_requested:
                self.offset = raw_adc
                self.tare_requested = False
                self.get_logger().info(f"Tare complete! New zero offset calculated: {self.offset}")
            
            if self.calibration_requested:
                known_mass_kg = 0.2
                known_force_newtons = known_mass_kg * self.g
                self.scale = (raw_adc - self.offset) / known_force_newtons
                self.calibration_requested = False
                self.get_logger().info(f"Calibration complete! New scale factor: {self.scale} ADC counts/N")

            # --- Execute The Calibration Math Pipeline ---
            tared_adc = raw_adc - self.offset
            calculated_mass = tared_adc / self.scale
            force_newtons = calculated_mass * self.g /10
            
            # Live Diagnostic Terminal Feedback
            if self.debug:
                print(f"Raw: {raw_adc:.0f} | Tared: {tared_adc:.0f} | Newtons: {force_newtons:.4f} N | Time: {arduino_time:.0f}ms")
            
            # --- Construct and Publish Dictionary Packet ---
            msg = DiagnosticStatus()
            msg.name = "Force Sensor Data"
            msg.hardware_id = "hx711_pc_calibrated"
            msg.level = DiagnosticStatus.OK
            msg.message = "Streaming data from force sensor."

            msg.values = [
                KeyValue(key="newtons", value=f"{force_newtons:.4f}"),
                KeyValue(key="raw_adc", value=f"{raw_adc:.1f}"),
                KeyValue(key="tared_adc", value=f"{tared_adc:.1f}"),
                KeyValue(key="active_offset", value=f"{self.offset:.1f}"),
                KeyValue(key="active_scale", value=f"{self.scale:.4f}"),
                KeyValue(key="arduino_millis", value=f"{arduino_time:.1f}")
            ]
            self.telemetry_pub.publish(msg)
            

    def handle_parameter_updates(self, params):
        result = SetParametersResult(successful=True)
        for param in params:
            if param.name == 'scale':
                self.scale = float(param.value)
                self.get_logger().info(f"Scale factor changed to: {self.scale}")
            elif param.name == 'offset':
                self.offset = float(param.value)
                self.get_logger().info(f"Offset changed to: {self.offset}")
        return result

    def handle_tare_service(self, request, response):
        self.get_logger().info("cmd received")
        self.tare_requested = True
        response.success = True
        response.message = "tare command received."
        return response
    
    def handle_calibrate_service(self, request, response):
        self.get_logger().info("Calibration command received place 200g")
        self.calibration_requested = True
        response.success = True
        response.message = "Calibration command acknowledged"
        return response

    def destroy_node(self):
        if self.haplink.is_connected():
            self.haplink.disconnect()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    try:
        node = ForceSensorDriverNode()
        rclpy.spin(node)
    except Exception as e:
        print(f"Node execution interrupted: {e}")
    finally:
        if 'node' in locals():
            node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()