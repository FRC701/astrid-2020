/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoShortShot.h"
#include "commands/AutoShortShotMP.h"
#include "commands/ChassisMotionMagicDrive.h"
#include "commands/EnableShootShort.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
AutoShortShot::AutoShortShot(Chassis& chassis, Conveyor& conveyor, Shooter& shooter) 
{
  constexpr double kBumperThicknessInches = 0.75 + 2.5;
  constexpr double kRobotLengthFeet = (31.0 + (kBumperThicknessInches * 2.0)) / 12.0;
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(
    //ChassisMotionMagicDrive(chassis, 10.0 - kRobotLengthFeet, 10.0 - kRobotLengthFeet), 
    AutoShortShotMP(chassis),
    EnableShootShort(chassis, conveyor, shooter));
}
