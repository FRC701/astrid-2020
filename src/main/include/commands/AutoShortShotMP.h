#pragma once

#include "ChassisMotionProfileCommand.h"

class AutoShortShotMP : public frc2::CommandHelper<ChassisMotionProfileCommand, AutoShortShotMP> {
public:
  AutoShortShotMP(Chassis& chassis);
};
