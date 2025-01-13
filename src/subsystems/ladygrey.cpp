#include "main.h"

pros::Motor ladyGrey(11);

void moveArm() {
  if (master.get_digital(DIGITAL_LEFT)) {
    ladyGrey.move(110);
  } else if (master.get_digital(DIGITAL_RIGHT)) {
    ladyGrey.move(-110);
  } else {
    ladyGrey.brake();
  }
}