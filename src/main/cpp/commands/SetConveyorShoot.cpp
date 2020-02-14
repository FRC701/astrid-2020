/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetConveyorShoot.h"

SetConveyorShoot::SetConveyorShoot(Conveyor& conveyor, double speed)
: mConveyor{conveyor}
, mSpeed(speed)
, mTimer()
{
  AddRequirements(&mConveyor);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void SetConveyorShoot::Initialize() 
{
  mTimer.Start();
  mTimer.Reset();
}

// Called repeatedly when this Command is scheduled to run
void SetConveyorShoot::Execute()
{
  mConveyor.SetConveyor(mSpeed);
}

// Called once the command ends or is interrupted.
void SetConveyorShoot::End(bool interrupted)
{
  mConveyor.SetConveyor(0.0);
  mTimer.Stop();
}

// Returns true when the command should end.
bool SetConveyorShoot::IsFinished()
{
  if(!mConveyor.IsBallExiting())
  {
    mTimer.Reset();
  }
  return (mTimer.Get() >= 3);
}
