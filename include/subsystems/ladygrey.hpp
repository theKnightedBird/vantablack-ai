#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

enum lady_grey_state {
  IDLE,
  GRABBING,
  SCORING
};

class lady_grey_mech {
  pros::Motor motor;
  ez::PID controller;
  lady_grey_state state;

 public:
  lady_grey_mech() : motor(11), controller(10) {
    state = IDLE;
    motor.set_brake_mode(MOTOR_BRAKE_HOLD);
  }
  void update();
  void set_target(lady_grey_state);
};