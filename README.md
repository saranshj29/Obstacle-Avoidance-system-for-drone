# Obstacle-Avoidance-system-for-drone

I built a simple obstacle-avoidance drone based on Arduino. It's a rudimentary performance. But If it has an expensive LiDAR sensor and good obstacle avoidance algorithm is added, it can be applied to other robot fields.i made 2 versions using  HC-SR04 ultra sonic sensor and  VL53L0X  as an obstacle detection sensor

both of them are similar and different from each others is some aspects

The HC-SR04 is a popular ultrasonic sensor used for non-contact distance measurements. This sensor operates by emitting an ultrasonic sound pulse and measuring the time it takes for the echo to return to calculate the distance to an object.

The VL53L0X module works on the principle of Time of Flight (ToF). It sends out a laser pulse and measures the time it takes for the pulse to bounce back.

# Here’s how it works:
The Ultrasonic sensor measures the distance between the sensor itself and the object and transmits it to the Arduino in the form of the analogue signal (value range: 0 to 1023). We should make a setpoint say 35cm from the Ultrasonic sensor so if the setpoint reaches below 35cm the PID algorithm in the Arduino will start its work by sending out the correction value to the stabilization board.


Pulse width modulation (PWM) is a type of modulation where the width of the pulse is varied to encode information. The width of the pulse is proportional to the amplitude of the signal. Pulse width modulation is commonly used in control systems where it is used to control the speed of a motor or the brightness of a light.

# Wiring Diagram – Obstacle Avoidance Drone
![Drone obstacle avoidance](https://github.com/user-attachments/assets/0c2bc23b-8b07-4088-b93f-4630fb17001c)
![sfsdfeasf](https://github.com/user-attachments/assets/b25cafdf-f00a-4e5e-857f-7af97b622c37)

1. Down Sensor
VCC -> VIN
GND -> GND
TRIG & ECHO -> A1
2. Up Sensor
VCC -> VIN
GND -> GND
TRIG & ECHO -> D6
3. Right Sensor
VCC -> VIN
GND -> GND
TRIG & ECHO -> D5
4. Left Sensor
VCC -> VIN
GND -> GND
TRIG & ECHO -> D4
5. Back Sensor
VCC -> VIN
GND -> GND
TRIG & ECHO -> D7
6. Front Sensor
VCC -> VIN
GND -> GND
TRIG & ECHO -> D2
PWM Receiver->Arduino nano
Ch1 -> D8
Ch2 -> D9
Ch3 -> D10
Ch4 ->
Ch5 ->
Ch6 -> A0
Flight Controller->Arduino nano
Ch1 -> D13
Ch2 -> D11
Ch3 -> D12
Ch4 ->
Ch5 ->
Ch6 ->  Not connected
Flight Controller-> PWM Receiver
Ch4 -> Ch4
Ch5 -> Ch5



# USING VL53LOX

In this design, instead of using six ultrasonic sensors to cover the six basic directions (forward, backward, left, right, up, and down), I opted for an alternative approach that deploys eight sensors. These eight sensors are arranged to cover a full 360-degree range, providing more comprehensive obstacle detection in all directions, including diagonal angles. This configuration was chosen to address a specific issue where the drone was facing challenges detecting obstacles located in the corners of the coverage zones of individual sensors, which were outside their detection range.

Ultrasonic sensors tend to have a limited field of view, often leading to blind spots at the edges of their detection zones, especially at the corners between adjacent sensors. By increasing the number of sensors to eight and positioning them strategically, I improved the system’s ability to detect obstacles more accurately and consistently from all angles. This approach enhanced both the precision and reliability of the obstacle detection system, reducing the likelihood of missed detections, especially in corner areas, where objects could previously go undetected.

Ultimately, the eight-sensor configuration provides better coverage, minimizes blind spots, and ensures smoother, safer navigation for the drone in complex environments, especially when it needs to navigate through tight spaces or near obstacles from various angles.
![safAS](https://github.com/user-attachments/assets/2efd0d58-7832-4afa-ab30-f8d3c83170a2)

# Wiring Diagram 
![dafdaf](https://github.com/user-attachments/assets/24533761-e95a-43b5-84f6-ad636080ca9c)


