#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"
#include "subsystems/ladygrey.hpp"

// Your motors, sensors, etc. should go here.  Below are examples
extern ez::Drive chassis;
extern ez::tracking_wheel horiz_tracker;
extern ez::tracking_wheel vert_tracker;

extern pros::MotorGroup hookintake;
void intake();

extern pros::ADIDigitalOut clamper;
void doClamp();
void update_clamp();

extern lady_grey_mech ladygrey;
void moveArm();