#pragma once

#include "ChassisMotionProfileCommand.h"

class AutoReverseFour :  public frc2::CommandHelper<ChassisMotionProfileCommand, AutoReverseFour> {
public:
  AutoReverseFour(Chassis& chassis);
};
