/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Chassis.h"

Chassis::Chassis(
    const wpi::Twine& name,
    WPI_TalonFX& left,
    WPI_TalonFX& right)
: mLeft{left}
, mRight{right}
{
    SetName(name);
}

// This method will be called once per scheduler run
void Chassis::Periodic() 
{

}
