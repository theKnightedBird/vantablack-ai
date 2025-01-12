#include "main.h"

///
// Constants
///
void configure_drive() {
  // P, I, D, and Start I
  chassis.pid_drive_constants_set(drive_kP, drive_kI, drive_kD);              // Fwd/rev constants, used for odom and non odom motions
  chassis.pid_heading_constants_set(hold_kP, hold_kI, hold_kD);               // Holds the robot straight while going forward without odom
  chassis.pid_turn_constants_set(turn_kP, turn_kI, turn_kD, turn_kI_thresh);  // Turn in place constants
  chassis.pid_swing_constants_set(turn_kP, turn_kI, turn_kD);                 // Swing constants
  chassis.pid_odom_angular_constants_set(turn_kP, turn_kI, turn_kD);          // Angular control for odom motions
  chassis.pid_odom_boomerang_constants_set(turn_kD, turn_kD, turn_kD);        // Angular control for boomerang motions

  // Exit conditions
  chassis.pid_turn_exit_condition_set(sm_timeout, turn_tol_sm, lg_timeout, turn_tol_lg, zero_vel_timeout, stall_timeout);
  chassis.pid_swing_exit_condition_set(sm_timeout, turn_tol_sm, lg_timeout, turn_tol_lg, zero_vel_timeout, stall_timeout);
  chassis.pid_drive_exit_condition_set(sm_timeout, drive_tol_sm, lg_timeout, drive_tol_lg, zero_vel_timeout, stall_timeout);
  chassis.pid_odom_turn_exit_condition_set(sm_timeout, turn_tol_sm, lg_timeout, turn_tol_lg, zero_vel_timeout, stall_timeout);
  chassis.pid_odom_drive_exit_condition_set(sm_timeout, drive_tol_sm, lg_timeout, drive_tol_lg, zero_vel_timeout, stall_timeout);
  chassis.pid_turn_chain_constant_set(turn_chain_dist);
  chassis.pid_swing_chain_constant_set(turn_chain_dist);
  chassis.pid_drive_chain_constant_set(drive_chain_dist);

  // Slew constants
  chassis.slew_drive_set(true);
  chassis.slew_turn_constants_set(slew_turn_windup, slew_windup_start);
  chassis.slew_drive_constants_set(slew_drive_windup, slew_windup_start);
  chassis.slew_swing_constants_set(slew_turn_windup, slew_windup_start);

  // The amount that turns are prioritized over driving in odom motions
  // - if you have tracking wheels, you can run this higher.  1.0 is the max
  chassis.odom_turn_bias_set(turn_bias);

  chassis.odom_look_ahead_set(pp_lookahead);                          // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(pp_target_from_lookahead_max);  // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(pp_aggresiveness);                 // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest);  // Changes the default behavior for turning, this defaults it to the shortest path there
}

void measure_offsets() {
  // Number of times to test
  int iterations = 10;

  // Our final offsets
  double l_offset = 0.0, r_offset = 0.0, b_offset = 0.0, f_offset = 0.0;

  // Reset all trackers if they exist
  if (chassis.odom_tracker_left != nullptr) chassis.odom_tracker_left->reset();
  if (chassis.odom_tracker_right != nullptr) chassis.odom_tracker_right->reset();
  if (chassis.odom_tracker_back != nullptr) chassis.odom_tracker_back->reset();
  if (chassis.odom_tracker_front != nullptr) chassis.odom_tracker_front->reset();

  for (int i = 0; i < iterations; i++) {
    // Reset pid targets and get ready for running an auton
    chassis.pid_targets_reset();
    chassis.drive_imu_reset();
    chassis.drive_sensor_reset();
    chassis.drive_brake_set(MOTOR_BRAKE_HOLD);
    chassis.odom_xyt_set(0_in, 0_in, 0_deg);
    double imu_start = chassis.odom_theta_get();
    double target = i % 2 == 0 ? 90 : 270;  // Switch the turn target every run from 270 to 90

    // Turn to target at half power
    chassis.pid_turn_set(target, 63, ez::raw);
    chassis.pid_wait();
    pros::delay(250);

    // Calculate delta in angle
    double t_delta = util::to_rad(fabs(util::wrap_angle(chassis.odom_theta_get() - imu_start)));

    // Calculate delta in sensor values that exist
    double l_delta = chassis.odom_tracker_left != nullptr ? chassis.odom_tracker_left->get() : 0.0;
    double r_delta = chassis.odom_tracker_right != nullptr ? chassis.odom_tracker_right->get() : 0.0;
    double b_delta = chassis.odom_tracker_back != nullptr ? chassis.odom_tracker_back->get() : 0.0;
    double f_delta = chassis.odom_tracker_front != nullptr ? chassis.odom_tracker_front->get() : 0.0;

    // Calculate the radius that the robot traveled
    l_offset += l_delta / t_delta;
    r_offset += r_delta / t_delta;
    b_offset += b_delta / t_delta;
    f_offset += f_delta / t_delta;
  }

  // Average all offsets
  l_offset /= iterations;
  r_offset /= iterations;
  b_offset /= iterations;
  f_offset /= iterations;

  // Set new offsets to trackers that exist
  if (chassis.odom_tracker_left != nullptr) chassis.odom_tracker_left->distance_to_center_set(l_offset);
  if (chassis.odom_tracker_right != nullptr) chassis.odom_tracker_right->distance_to_center_set(r_offset);
  if (chassis.odom_tracker_back != nullptr) chassis.odom_tracker_back->distance_to_center_set(b_offset);
  if (chassis.odom_tracker_front != nullptr) chassis.odom_tracker_front->distance_to_center_set(f_offset);
}
