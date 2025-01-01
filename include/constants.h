#include "main.h"
#pragma once

/////
// Constants file, all constants go here
/////

///
// Drive constants
///
const std::vector<int> left_motor_ports = {1, -2, 3};    // TODO: Find
const std::vector<int> right_motors_ports = {4, -5, 6};  // TODO: Find
const int imu_port = 7;                                  // TODO: Find
const double wheel_diam = 4.0;                           // TODO: Find
const double motor_rpm = 343;                            // TODO: Find

const double vert_tracking_port = 8;    // TODO: Find
const double horiz_tracking_port = 9;   // TODO: Find
const double vert_wheel_diam = 2.75;    // TODO: Find
const double horiz_wheel_diam = 2.75;   // TODO: Find
const double vert_dist_to_cent = 0.4;   // TODO: Find
const double horiz_dist_to_cent = 0.4;  // TODO: Find

const double drive_kP = 20.0;        // TODO: Tune
const double drive_kI = 0.0;         // TODO: Tune
const double drive_kD = 100.0;       // TODO: Tune
const double hold_kP = 11.0;         // TODO: Tune
const double hold_kI = 0.0;          // TODO: Tune
const double hold_kD = 20.0;         // TODO: Tune
const double turn_kP = 3.0;          // TODO: Tune
const double turn_kI = 0.05;         // TODO: Tune
const double turn_kD = 20.0;         // TODO: Tune
const double turn_kI_thresh = 15.0;  // TODO: Tune

const okapi::QLength drive_tol_sm = 1_in;      // TODO: Tune
const okapi::QLength drive_tol_lg = 3_in;      // TODO: Tune
const okapi::QAngle turn_tol_sm = 3_deg;       // TODO: Tune
const okapi::QAngle turn_tol_lg = 7_deg;       // TODO: Tune
const okapi::QTime sm_timeout = 90_ms;         // TODO: Tune
const okapi::QTime lg_timeout = 250_ms;        // TODO: Tune
const okapi::QTime zero_vel_timeout = 500_ms;  // TODO: Tune
const okapi::QTime stall_timeout = 500_ms;     // TODO: Tune

const okapi::QLength drive_chain_dist = 3_in;  // TODO: Tune
const okapi::QAngle turn_chain_dist = 3_deg;   // TODO: Tune

const okapi::QAngle slew_turn_windup = 3_deg;   // TODO: Tune
const okapi::QLength slew_drive_windup = 3_in;  // TODO: Tune
const double slew_windup_start = 75;            // TODO: Tune

// Pure pursuit constants
const double turn_bias = 0.9;
const okapi::QLength pp_lookahead = 7_in;
const okapi::QLength pp_target_from_lookahead_max = 16_in;
const double pp_aggresiveness = 0.65;

///
// Vision Constants
///

const int vision_port = 10;
