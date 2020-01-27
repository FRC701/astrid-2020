/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Winch.h"

Winch::Winch(const wpi::Twine& name,
            Components& components)
: mComponents{components}
, mMotors{components.left, components.right}
{
    SetName(name);
}

// This method will be called once per scheduler run
void Winch::Periodic() 
{

}

void Winch::WinchHook(double percentoutput)
{
    mMotors.Set(percentoutput);
}