#include "main.h"

class lady_grey_mech {
  pros::Motor motor;
  ez::PID controller;
  lady_grey_state state;

 public:
  lady_grey_mech() : motor(11), controller(10) {
    state = IDLE;
    motor.set_brake_mode(MOTOR_BRAKE_HOLD);
  }
  void update() {
    switch (state) {
      case IDLE:
        motor.move_absolute(50, 127);
        break;
      case GRABBING:
        motor.move_absolute(100, 127);
        break;
      case SCORING:
        motor.move_absolute(120, 127);
        break;
      default:
        break;
    }
  }
  void set_target(lady_grey_state state) {
    this->state = state;
  }
};