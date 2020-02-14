/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/EnableIntake.h"
#include "commands/IntakeEngage.h"
#include "commands/IntakeCommand.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
EnableIntake::EnableIntake(Intake& intake, Conveyor& conveyor, Chassis& chassis)
: mIntake(intake), mConveyor(conveyor), mChassis(chassis)
{
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(IntakeEngage(mIntake), IntakeCommand(mIntake, mConveyor, mChassis));
}
