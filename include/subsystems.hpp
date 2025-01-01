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

ez::tracking_wheel horiz_tracker(horiz_tracking_port, horiz_wheel_diam, horiz_dist_to_cent);
ez::tracking_wheel vert_tracker(vert_tracking_port, vert_wheel_diam, vert_dist_to_cent);
