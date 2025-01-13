#include "main.h"

pros::MotorGroup hookintake({-19, -21});

void intake() {
  if (master.get_digital(DIGITAL_L1)) {
    hookintake.move(127);
  } else if (master.get_digital(DIGITAL_R1)) {
    hookintake.move(-127);
  } else {
    hookintake.brake();
  }
}
