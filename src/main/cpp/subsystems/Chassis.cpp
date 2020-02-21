/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Chassis.h"

#include <cmath>
#include <frc/smartdashboard/SmartDashboard.h>

std::shared_ptr<NetworkTable> mTable = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

Chassis::Chassis(const wpi::Twine& name,
    Components& components)

:mComponents(components)
, mDrive{mComponents.frontLeft, mComponents.frontRight}
{
    SetName(name);
    // TODO: SetSensorPhase does not seem to be having an effect
    // The velocity is still going in reverse to the direction of travel.
    mComponents.frontLeft.SetSensorPhase(true);
    mComponents.backLeft.SetSensorPhase(true);
    mComponents.frontLeft.SetInverted(false);
    mComponents.backLeft.SetInverted(false);
    mComponents.frontRight.SetInverted(false);
    mComponents.backRight.SetInverted(false);

     mComponents.backLeft.Follow(mComponents.frontLeft); 
     mComponents.backRight.Follow(mComponents.frontRight); 
}

// This method will be called once per scheduler run
void Chassis::Periodic() 
{
    frc::SmartDashboard::PutNumber("left velocity", GetLeftVelocity());
    frc::SmartDashboard::PutNumber("right velocity", GetRightVelocity());
    frc::SmartDashboard::PutNumber("Target Offset", TargetOffset());
    frc::SmartDashboard::PutNumber("Target Distance", TargetDistance());
}

void Chassis::TankDrive(double left, double right)
{
    mDrive.TankDrive(left, right);
}

double Chassis::GetLeftVelocity()
{
    return mComponents.frontLeft.GetSelectedSensorVelocity();
}

double Chassis::GetRightVelocity()
{
    return mComponents.frontRight.GetSelectedSensorVelocity();
}

void Chassis::ArcadeDrive(double speed, double rotation)
{
    mDrive.ArcadeDrive(speed, rotation);
}

double Chassis::TargetOffset()
{
    return mTable->GetNumber("tx",0.0);
}

double Chassis::TargetDistance() //this doesn't work
{
    double distanceFeet = 14.6 - (11.6 * log(mTable->GetNumber("ta",0.0)));
    return distanceFeet;
}

void Chassis::SetDriverCam()
{
    mTable->PutNumber("camMode", 1);
}

void Chassis::SetVisionCam()
{
    mTable->PutNumber("camMode", 0);
}

void Chassis::limeLightLightsOn()
{
    mTable->PutNumber("ledMode", 0);
}

void Chassis::limeLightLightsOff()
{
    mTable->PutNumber("ledMode", 1);
}