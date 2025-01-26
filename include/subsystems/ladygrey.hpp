#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

enum lady_grey_state {
  IDLE,
  GRABBING,
  SCORING
};

class lady_grey_mech {
 public:
  lady_grey_mech();
  void update();
  void set_target(lady_grey_state state);
};