#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

enum ladyGreyState {
  IDLE,
  GRABBING,
  SCORING
};

class ladyGreyMech {
 public:
  ladyGreyMech();
  void update();
  void set_target();

 private:
  pros::Motor motor;
  ez::PID controller;
  ladyGreyState state;
};