/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Chassis.h"
#include "RobotContainer.h"

Chassis::Chassis(
    const wpi::Twine& name,
    WPI_TalonFX& left,
    WPI_TalonFX& right,
    WPI_TalonFX& left2,
    WPI_TalonFX& right2)
: mLeft{left}
, mRight{right}
, mleft2{left2}
, mright2{right2}
, mDrive{mLeft, mRight}
{
    SetName(name);

    mleft2.Follow(left); 
    mright2.Follow(right); 
}

// This method will be called once per scheduler run
void Chassis::Periodic() 
{

}

void Chassis::TankDrive(double left, double right)
{
    mDrive.TankDrive(left, right);
}
