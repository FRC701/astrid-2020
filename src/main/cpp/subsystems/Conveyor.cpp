/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Conveyor.h"
#include <frc/smartdashboard/SmartDashboard.h>

Conveyor::Conveyor(const wpi::Twine& name, WPI_TalonFX* const conveyorMotor) 
: mConveyorMotor{conveyorMotor}
{
    SetName(name);

    mConveyorMotor->SetInverted(true);
    mConveyorMotor->OverrideLimitSwitchesEnable(false);
}

// This method will be called once per scheduler run
void Conveyor::Periodic()
{
    frc::SmartDashboard::PutBoolean("Conveyor Enter Limit Switch", IsBallComing());
    frc::SmartDashboard::PutBoolean("Conveyor Exit Limit Switch", IsBallExiting());
}

bool Conveyor::IsBallComing()
{
    return mConveyorMotor->IsFwdLimitSwitchClosed();
}

bool Conveyor::IsBallExiting()
{
    return mConveyorMotor->IsRevLimitSwitchClosed();
}

void Conveyor::BallIntakeIncoming()
{
    if(BallCount() < 5)
    {
        ++mBallCount;
    }
}
void Conveyor::BallIntakeExiting()
{
    if(BallCount() > 0)
    {
        --mBallCount;
    }
}
void Conveyor::SetConveyor(double speed)
{
    mConveyorMotor->Set(speed);
}

int Conveyor::BallCount()
{
    return mBallCount;
}

bool Conveyor::IsShooting()
{
    return false; // TODO: Make this real later
}

double Conveyor::GetVelocity()
{
    return mConveyorMotor->GetSelectedSensorVelocity();
}

void Conveyor::ResetBalls()
{
    mBallCount = 0;
}
