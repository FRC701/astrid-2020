/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Telescope.h"
#include <frc/smartdashboard/SmartDashboard.h>

Telescope::Telescope(
    const wpi::Twine& name,
    Components& components)
: mComponents{components}
{
    SetName(name);
    mComponents.telescopeMotor.ConfigForwardSoftLimitEnable(false);
    mComponents.telescopeMotor.ConfigReverseSoftLimitEnable(true);
    mComponents.telescopeMotor.ConfigForwardSoftLimitThreshold(1300);
    mComponents.telescopeMotor.ConfigReverseSoftLimitThreshold(0);
}

// This method will be called once per scheduler run
void Telescope::Periodic() 
{
    frc::SmartDashboard::PutNumber("Telescope Encoder", GetPosition());
}

void Telescope::TelescopeRise(double percentoutput) 
{
    mComponents.telescopeMotor.Set(percentoutput);
}

double Telescope::GetPosition()
{
    return mComponents.telescopeMotor.GetSelectedSensorPosition();

}