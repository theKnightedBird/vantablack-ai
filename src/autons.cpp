#include "main.h"

void go_forwards() {
  chassis.pid_drive_set(24_in, 110);
  chassis.pid_wait();
}

void score_four() {
  chassis.pid_turn_set(180_deg, 110);
  chassis.pid_wait();
  chassis.pid_drive_set(-34.64_in, 110);
  chassis.pid_wait();
  doClamp();
  chassis.pid_turn_set(45_deg, 110);
  chassis.pid_wait();
  hookintake.move(127);
  chassis.pid_drive_set(32.62_in, 110);
  chassis.pid_wait();
}