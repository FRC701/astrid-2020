/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Winch.h"

constexpr double kMaxVelocityError{4000-3000};
constexpr double kP{(.05*1023)/kMaxVelocityError};
constexpr double kI{0.0};
constexpr double kD{0.0};
double kF{0.0};

Winch::Winch(const wpi::Twine& name,
            Components& components)
: mComponents{components}
{
    SetName(name);
    SetPID();
}

void Winch::SetPID()
{
    mComponents.left.Config_kP(0, kP, 10);
    mComponents.left.Config_kI(0, kI, 10);
    mComponents.left.Config_kD(0, kD, 10);
    mComponents.left.Config_kF(0, kF, 10);    
    mComponents.right.Config_kP(0, kP, 10);
    mComponents.right.Config_kI(0, kI, 10);
    mComponents.right.Config_kD(0, kD, 10);
    mComponents.right.Config_kF(0, kF, 10);
}

// This method will be called once per scheduler run
void Winch::Periodic() 
{

}

void Winch::WinchHook(double position)
{
    mComponents.left.Set(ControlMode::Position, position);
    mComponents.right.Set(ControlMode::Position, position);
}