#include "main.h"

pros::ADIDigitalOut clamper('A');
bool isClamped = false;

void doClamp() {
  if (master.get_digital_new_press(DIGITAL_L2)) {
    clamper.set_value(!isClamped);
    isClamped = !isClamped;
  }
}