/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetConveyor.h"
#include <frc/Timer.h>

SetConveyor::SetConveyor(Conveyor& conveyor, double speed, bool isIntake)
: mConveyor{conveyor}
, mSpeed(speed)
, mIsIntake(isIntake)
, mTimer()
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(&mConveyor);
}

// Called when the command is initially scheduled.
void SetConveyor::Initialize()
{
    mTimer.Start();
    mTimer.Reset();
}

// Called repeatedly when this Command is scheduled to run
void SetConveyor::Execute() 
{
    if(mConveyor.IsBallComing() && mConveyor.IsBallExiting() && mIsIntake)
    {
        while(mConveyor.IsBallComing())
        {
            mConveyor.SetConveyor(mSpeed);
        }
        while(!mConveyor.IsBallComing())
        {
            mConveyor.SetConveyor(-0.3);
        }
        while(mConveyor.IsBallComing())
        {
            mConveyor.SetConveyor(0.1);
        }
    }
    else if(!mIsIntake)
    {
        mConveyor.SetConveyor(mSpeed);
    }
    else
    {
        mConveyor.SetConveyor(0.0);
    }
}

// Called once the command ends or is interrupted.
void SetConveyor::End(bool interrupted)
{
    mTimer.Reset();
    if(mIsIntake)
    {
        while(!mConveyor.IsBallExiting())
        {
            mConveyor.SetConveyor(-0.2);
            mTimer.Reset();
        }
        while(mConveyor.IsBallExiting() || mTimer.Get() >= 2)
        {
            mConveyor.SetConveyor(0.2);
        }
        mConveyor.SetConveyor(0.0);
    }
    else
    {
        mConveyor.SetConveyor(0.0);
    }
    mTimer.Reset();
    mTimer.Stop();
    
}

// Returns true when the command should end.
bool SetConveyor::IsFinished()
{
    if(mIsIntake)
    {
        return !mConveyor.IsBallExiting();
    }
    else
    {
        if(!mConveyor.IsBallExiting())
        {
            mTimer.Reset();
        }
        return (mTimer.Get() >= 2);
    }  
}