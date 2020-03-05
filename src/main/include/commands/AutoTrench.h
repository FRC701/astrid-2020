#pragma once

#include "ChassisMotionProfileCommand.h"

class AutoTrench : public frc2::CommandHelper<ChassisMotionProfileCommand, AutoTrench> {
public:
  AutoTrench(Chassis& chassis);
};
