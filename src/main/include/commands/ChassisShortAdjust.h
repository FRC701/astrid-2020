#pragma once

#include "ChassisMotionProfileCommand.h"

class ChassisShortAdjust : public frc2::CommandHelper<ChassisMotionProfileCommand, ChassisShortAdjust> {
public:
  ChassisShortAdjust(Chassis& chassis);
};
