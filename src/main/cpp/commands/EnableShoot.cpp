/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/EnableShoot.h"
#include "commands/Aim.h"
#include "commands/SetConveyor.h"
#include "commands/Shoot.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
EnableShoot::EnableShoot(Chassis& chassis, Conveyor& conveyor, Shooter& shooter)
: mChassis(chassis), mConveyor(conveyor), mShooter(shooter)
{
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(Aim(mChassis),  Shoot(mShooter, 13653), SetConveyor(mConveyor, 0.3));
}
