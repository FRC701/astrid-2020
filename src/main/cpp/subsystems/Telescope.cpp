/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Telescope.h"
#include <frc/smartdashboard/SmartDashboard.h>

using ControlMode = ctre::phoenix::motorcontrol::ControlMode;

Telescope::Telescope(
    const wpi::Twine& name,
    Components& components)
: mComponents{components}
{
    SetName(name);
    mComponents.telescopeMotor.SetInverted(true);
    mComponents.telescopeMotor.OverrideLimitSwitchesEnable(true);
    mComponents.telescopeMotor.ConfigForwardSoftLimitEnable(false);
    mComponents.telescopeMotor.ConfigReverseSoftLimitEnable(false);
    mComponents.telescopeMotor.ConfigForwardSoftLimitThreshold(1300);
    mComponents.telescopeMotor.ConfigReverseSoftLimitThreshold(0);
    mComponents.telescopeMotor.SetNeutralMode(ctre::phoenix::motorcontrol::Brake);
}

// This method will be called once per scheduler run
void Telescope::Periodic() 
{
    frc::SmartDashboard::PutBoolean("telescope limit", GetLimitSwitch());
    frc::SmartDashboard::PutNumber("Telescope Encoder", GetPosition());
    frc::SmartDashboard::PutBoolean("Telescope limit switch", GetRevLimitSwitch());
}

void Telescope::TelescopeRise(double percentoutput) 
{
    mComponents.telescopeMotor.Set(ControlMode::PercentOutput, percentoutput);
}

double Telescope::GetPosition()
{
    return mComponents.telescopeMotor.GetSelectedSensorPosition();

}

bool Telescope::GetRevLimitSwitch()
{
    return mComponents.telescopeMotor.IsRevLimitSwitchClosed();
}