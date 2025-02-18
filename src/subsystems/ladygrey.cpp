#include "main.h"

void lady_grey_mech::set_target(lady_grey_state state) {
  this->state = state;
}

void lady_grey_mech::update() {
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