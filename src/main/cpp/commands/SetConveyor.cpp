/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetConveyor.h"
#include "commands/EndIntake.h"

SetConveyor::SetConveyor(Conveyor& conveyor, double speed)
: mConveyor{conveyor}
, mSpeed(speed)
, mTimer()
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(&mConveyor);
}

// Called when the command is initially scheduled.
void SetConveyor::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SetConveyor::Execute() 
{
    if(mConveyor.IsBallComing() && mConveyor.IsBallExiting())
    {
        while(mConveyor.IsBallComing())
        {
            mConveyor.SetConveyor(mSpeed);
        }
        while(!mConveyor.IsBallComing())
        {
            mConveyor.SetConveyor(-0.4);
        }
        while(mConveyor.IsBallComing())
        {
            mConveyor.SetConveyor(0.1);
        }
    }
    else
    {
        mConveyor.SetConveyor(0.0);
    }
}

// Called once the command ends or is interrupted.
void SetConveyor::End(bool interrupted)
{
    mTimer.Start();
    mTimer.Reset();
    while((!mConveyor.IsBallComing() || !mConveyor.IsBallExiting()) && mTimer.Get() <= 2)
    {
        mConveyor.SetConveyor(-0.25);
    }
    mTimer.Stop();
    mConveyor.SetConveyor(0.0);
}

// Returns true when the command should end.
bool SetConveyor::IsFinished()
{
    return false;
}