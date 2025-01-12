#include "main.h"

void go_forwards() {
  chassis.pid_drive_set(24_in, 110);
  chassis.pid_wait();
}