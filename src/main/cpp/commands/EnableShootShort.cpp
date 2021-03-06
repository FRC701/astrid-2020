/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/EnableShootShort.h"
#include "commands/ChassisShortAdjust.h"
#include "commands/ShortHood.h"
#include "commands/SetConveyor.h"
#include "commands/Shoot.h"
#include "commands/ShootBallsShort.h"
#include "commands/HoodRetract.h"
#include "commands/TankDrive.h"
#include "commands/TimedDrive.h"


// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
EnableShootShort::EnableShootShort(Chassis& chassis, Conveyor& conveyor, Shooter& shooter)
: mChassis(chassis), mConveyor(conveyor), mShooter(shooter)
{
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  //
  // What is this magic number? What is the calculation?
  AddCommands(
    ShortHood(shooter), 
    ChassisShortAdjust(chassis),
    ShootBallsShort(shooter, conveyor, 1350), // 2000RPM for testing
    HoodRetract(shooter));
}