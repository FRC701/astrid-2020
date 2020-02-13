/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetConveyorIntake.h"
#include "commands/SetConveyor.h"
#include "commands/EndIntake.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
SetConveyorIntake::SetConveyorIntake(Conveyor& conveyor, double speed) 
: mConveyor(conveyor)
, mSpeed(speed)
{
  AddCommands(SetConveyor(mConveyor, mSpeed), EndIntake(mConveyor));
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
}
