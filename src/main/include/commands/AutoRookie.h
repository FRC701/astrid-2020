#pragma once

#include <frc2/command/CommandHelper.h>
#include "ChassisMotionProfileCommand.h"

class AutoRookie : public frc2::CommandHelper<ChassisMotionProfileCommand, AutoRookie> {
public:
  AutoRookie(Chassis& chassis);
};

