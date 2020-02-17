/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/FullEndIntake.h"
#include "commands/EndIntake.h"
#include "commands/IntakeDisengage.h"
#include "commands/NullCommand.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
FullEndIntake::FullEndIntake(Conveyor& conveyor, Intake& intake)
: mConveyor(conveyor)
, mIntake(intake)
{
  AddCommands(EndIntake(mConveyor), IntakeDisengage(mIntake), NullCommand(mConveyor));
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
}