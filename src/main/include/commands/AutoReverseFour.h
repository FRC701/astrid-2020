#pragma once

#include "ChassisMotionProfileCommand.h"

class AutoReverseFour : public ChassisMotionProfileCommand {
public:
  AutoReverseFour(Chassis& chassis);
};
