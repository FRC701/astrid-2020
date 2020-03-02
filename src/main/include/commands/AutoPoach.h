#pragma once

#include "ChassisMotionProfileCommand.h"

class AutoPoach : public frc2::CommandHelper<ChassisMotionProfileCommand, AutoPoach> {
public:
  AutoPoach(Chassis& chassis);
};
