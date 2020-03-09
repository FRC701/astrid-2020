#pragma once

#include "ChassisMotionProfileCommand.h"

class AutoTrenchReverse : public frc2::CommandHelper<ChassisMotionProfileCommand, AutoTrenchReverse> {
public:
  AutoTrenchReverse(Chassis& chassis);
};
