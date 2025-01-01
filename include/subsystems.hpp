#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

// Your motors, sensors, etc. should go here.  Below are examples
ez::Drive chassis(
    left_motor_ports,
    right_motors_ports,
    imu_port,
    wheel_diam,
    motor_rpm);

ez::tracking_wheel horiz_tracker(8, 2.75, 4.0);
ez::tracking_wheel vert_tracker(9, 2.75, 4.0);
