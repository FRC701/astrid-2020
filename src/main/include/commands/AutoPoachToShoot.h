#pragma once

#include "ChassisMotionProfileCommand.h"

class AutoPoachToShoot : public frc2::CommandHelper<ChassisMotionProfileCommand, AutoPoachToShoot> {
public:
  AutoPoachToShoot(Chassis& chassis);
};
