/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ConveyorInWait.h"

ConveyorInWait::ConveyorInWait(Conveyor& conveyor, double speed)
: mConveyor(conveyor),
  mSpeed(speed)
{
  AddRequirements(&mConveyor);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ConveyorInWait::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ConveyorInWait::Execute() {
  if (mConveyor.IsBallComing())
  {
    mConveyor.SetConveyor(mSpeed);
  }
  else
  {
    mConveyor.SetConveyor(0);
  }
  
}

// Called once the command ends or is interrupted.
void ConveyorInWait::End(bool interrupted) {
}

// Returns true when the command should end.
bool ConveyorInWait::IsFinished() { 
  return false;
}
