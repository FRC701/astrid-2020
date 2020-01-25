/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Conveyor.h"

Conveyor::Conveyor(const wpi::Twine& name, WPI_TalonFX& conveyorMotor) 
: mConveyorMotor{conveyorMotor}
{
    SetName(name);
}

// This method will be called once per scheduler run
void Conveyor::Periodic()
{

}

bool Conveyor::IsBallComing()
{
    return mConveyorMotor.IsFwdLimitSwitchClosed();
}

bool Conveyor::IsBallExiting()
{
    return !mConveyorMotor.IsRevLimitSwitchClosed();
}

void Conveyor::BallIntakeIncoming()
{
    ++mBallCount;
}
void Conveyor::BallIntakeExiting()
{
    --mBallCount;
}
void Conveyor::SetConveyor()
{
    if(CurrentBallCount() == 0 && !IsBallComing() && IsBallExiting())
    {
        mConveyorMotor.Set(0);
    }
    else if(CurrentBallCount() != 0 && !IsBallExiting() && !IsBallComing())
    {
        mConveyorMotor.Set(0);
    }
    else
    {
        mConveyorMotor.Set(0.3);
    }
    
}

int Conveyor::CurrentBallCount()
{
    return mBallCount;
}