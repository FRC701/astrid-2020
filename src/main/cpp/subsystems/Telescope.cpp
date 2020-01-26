/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Telescope.h"

Telescope::Telescope(
    const wpi::Twine& name,
    Components& components)
: mComponents{components}
{
    SetName(name);
}

// This method will be called once per scheduler run
void Telescope::Periodic() 
{

}

void Telescope::TelescopeRise(double percentoutput) 
{
    mComponents.telescopeMotor.Set(percentoutput);
}
