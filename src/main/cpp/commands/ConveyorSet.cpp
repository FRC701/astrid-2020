/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ConveyorSet.h"

ConveyorSet::ConveyorSet(Conveyor& conveyor, double speed)
: mConveyor(conveyor)
, mSpeed(speed)
, mSetConveyor(mConveyor, mSpeed)
{
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ConveyorSet::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ConveyorSet::Execute()
{
  mConveyor.SetConveyor(0.1);
}

// Called once the command ends or is interrupted.
void ConveyorSet::End(bool interrupted)
{
  mSetConveyor.Schedule();
}

// Returns true when the command should end.
bool ConveyorSet::IsFinished()
{
  return !mConveyor.IsBallComing();
}
