# Obstacle-Avoidance-system-for-drone

I built a simple obstacle-avoidance drone based on Arduino. It's a rudimentary performance. But If it has an expensive LiDAR sensor and good obstacle avoidance algorithm is added, it can be applied to other robot fields.i made 2 versions using  HC-SR04 ultra sonic sensor and  VL53L0X  as an obstacle detection sensor

both of them are similar and different from each others is some aspects

The HC-SR04 is a popular ultrasonic sensor used for non-contact distance measurements. This sensor operates by emitting an ultrasonic sound pulse and measuring the time it takes for the echo to return to calculate the distance to an object.

The VL53L0X module works on the principle of Time of Flight (ToF). It sends out a laser pulse and measures the time it takes for the pulse to bounce back.

# Here’s how it works:
The Ultrasonic sensor measures the distance between the sensor itself and the object and transmits it to the Arduino in the form of the analogue signal (value range: 0 to 1023). We should make a setpoint say 35cm from the Ultrasonic sensor so if the setpoint reaches below 35cm the PID algorithm in the Arduino will start its work by sending out the correction value to the stabilization board.


Pulse width modulation (PWM) is a type of modulation where the width of the pulse is varied to encode information. The width of the pulse is proportional to the amplitude of the signal. Pulse width modulation is commonly used in control systems where it is used to control the speed of a motor or the brightness of a light.
