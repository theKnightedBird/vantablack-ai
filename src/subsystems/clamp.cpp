#include "main.h"

pros::ADIDigitalOut clamper('A');
bool isClamped = false;

void doClamp() {
  clamper.set_value(!isClamped);
  isClamped = !isClamped;
}

void update_clamp() {
  if (master.get_digital_new_press(DIGITAL_L2)) {
    doClamp();
  }
}