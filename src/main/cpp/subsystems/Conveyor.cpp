/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Conveyor.h"
#include <frc/smartdashboard/SmartDashboard.h>

Conveyor::Conveyor(const wpi::Twine& name, WPI_TalonFX& conveyorMotor) 
: mConveyorMotor{conveyorMotor}
{
    SetName(name);
}

// This method will be called once per scheduler run
void Conveyor::Periodic()
{
    frc::SmartDashboard::PutNumber("conveyor velocity", GetVelocity());
    frc::SmartDashboard::PutNumber("Balls:", BallCount());
}

bool Conveyor::IsBallComing()
{
    return mConveyorMotor.IsFwdLimitSwitchClosed();
}

bool Conveyor::IsBallExiting()
{
    return mConveyorMotor.IsRevLimitSwitchClosed();
}

void Conveyor::BallIntakeIncoming()
{
    ++mBallCount;
}
void Conveyor::BallIntakeExiting()
{
    --mBallCount;
}
void Conveyor::SetConveyor(double speed)
{
    mConveyorMotor.Set(speed);
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
    return mConveyorMotor.GetSelectedSensorVelocity();
}

void Conveyor::ResetBalls()
{
    mBallCount = 0;
}