#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

// Your motors, sensors, etc. should go here.  Below are examples
extern ez::Drive chassis;
extern ez::tracking_wheel horiz_tracker;
extern ez::tracking_wheel vert_tracker;

extern pros::MotorGroup hookintake;
void intake();

extern pros::ADIDigitalOut clamper;
void doClamp();

extern pros::Motor ladyGrey;
void moveArm();