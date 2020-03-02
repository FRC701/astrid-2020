#pragma once

#include "ChassisMotionProfileCommand.h"

class AutoRookie10 : public frc2::CommandHelper<ChassisMotionProfileCommand, AutoRookie10> {
public:
  AutoRookie10(Chassis& chassis);
};
