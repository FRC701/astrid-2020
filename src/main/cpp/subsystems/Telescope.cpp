/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Telescope.h"

Telescope::Telescope(
    const wpi::Twine& name,
    WPI_TalonFX& telescopemotor)
: mTelescopeMotor{telescopemotor}
{
    SetName(name);
}

// This method will be called once per scheduler run
void Telescope::Periodic() 
{

}

void Telescope::SetTelescope(double percentoutput) 
{
    mTelescopeMotor.Set(ControlMode::PercentOutput, percentoutput);
}
