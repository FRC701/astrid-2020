/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/NullCommand.h"

NullCommand::NullCommand(Conveyor& conveyor)
: mConveyor(conveyor)
{
  AddRequirements(&mConveyor);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void NullCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void NullCommand::Execute() {}

// Called once the command ends or is interrupted.
void NullCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool NullCommand::IsFinished() { return false; }
