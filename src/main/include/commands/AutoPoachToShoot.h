#pragma once

#include "ChassisMotionProfileCommand.h"

class AutoPoachToShoot : frc2::CommandHelper<ChassisMotionProfileCommand, AutoPoachToShoot> {
public:
  AutoPoachToShoot(Chassis& chassis);
};
