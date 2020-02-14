/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/EndIntake.h"

EndIntake::EndIntake(Conveyor& conveyor)
: mConveyor(conveyor)
, mTimer()
{
  AddRequirements(&mConveyor);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void EndIntake::Initialize()
{
  mTimer.Start();
  mTimer.Reset();
}

// Called repeatedly when this Command is scheduled to run
void EndIntake::Execute()
{
  mConveyor.SetConveyor(-0.4);
}

// Called once the command ends or is interrupted.
void EndIntake::End(bool interrupted)
{
  mTimer.Stop();
  mConveyor.SetConveyor(0.0);
}

// Returns true when the command should end.
bool EndIntake::IsFinished()
{
  return (!mConveyor.IsBallComing() || !mConveyor.IsBallExiting()) && mTimer.Get() <= 2;
}