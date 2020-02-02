/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/RunConveyor.h"

RunConveyor::RunConveyor(Conveyor& conveyor, double speed) 
: mConveyor(conveyor)
, mSpeed(speed)
{
  AddRequirements(&mConveyor);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void RunConveyor::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void RunConveyor::Execute() 
{
  mConveyor.SetConveyor(mSpeed);
}

// Called once the command ends or is interrupted.
void RunConveyor::End(bool interrupted)
{
  mConveyor.SetConveyor(0.0);
}

// Returns true when the command should end.
bool RunConveyor::IsFinished() { return false; }
