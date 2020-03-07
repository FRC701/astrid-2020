/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ConveyorRun.h"

ConveyorRun::ConveyorRun(Conveyor& conveyor, double percentVBus)
: mConveyor(conveyor) 
, mPercentVBus(percentVBus)
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(&mConveyor);
}

// Called when the command is initially scheduled.
void ConveyorRun::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ConveyorRun::Execute() 
{
  mConveyor.SetConveyor(mPercentVBus);
}

// Called once the command ends or is interrupted.
void ConveyorRun::End(bool interrupted) 
{
  mConveyor.SetConveyor(0.0);
}

// Returns true when the command should end.
bool ConveyorRun::IsFinished()
{ 
  return false; 
}
