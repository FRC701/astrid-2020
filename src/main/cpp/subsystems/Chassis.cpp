/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Chassis.h"

#include <cmath>
#include <frc/smartdashboard/SmartDashboard.h>

using ControlMode = ctre::phoenix::motorcontrol::ControlMode;

std::shared_ptr<NetworkTable> mTable = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

Chassis::Chassis(const wpi::Twine& name,
    Components& components)

:mComponents(components)
, mDrive{mComponents.frontLeft, mComponents.frontRight}
{
    SetName(name);
    // TODO: SetSensorPhase does not seem to be having an effect
    // The velocity is still going in reverse to the direction of travel.
    mComponents.frontLeft.SetSensorPhase(false);
    mComponents.backLeft.SetSensorPhase(true);
    mComponents.frontLeft.SetInverted(true);
    mComponents.backLeft.SetInverted(true);
    mComponents.frontRight.SetInverted(false);
    mComponents.backRight.SetInverted(false);

     mComponents.backLeft.Follow(mComponents.frontLeft); 
     mComponents.backRight.Follow(mComponents.frontRight); 
     
     mDrive.SetRightSideInverted(false);
}

// This method will be called once per scheduler run
void Chassis::Periodic() 
{
    frc::SmartDashboard::PutNumber("left chassis velocity", GetLeftVelocity());
    frc::SmartDashboard::PutNumber("right chassis velocity", GetRightVelocity());
    frc::SmartDashboard::PutNumber("Target Offset", TargetOffset());
    frc::SmartDashboard::PutNumber("Target Distance", TargetDistance());
    frc::SmartDashboard::PutNumber("Right Chassis Pos", GetRightPos());
    frc::SmartDashboard::PutNumber("Left Chassis Pos", GetLeftPos());
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

double Chassis::GetRightPos()
{
    return mComponents.frontRight.GetSelectedSensorPosition();
}

double Chassis::GetLeftPos()
{
    return mComponents.frontLeft.GetSelectedSensorPosition();
}

double Chassis::ResetLeftPos()
{
    mComponents.frontLeft.SetSelectedSensorPosition(0);
}

double Chassis::ResetRightPos()
{
    mComponents.frontRight.SetSelectedSensorPosition(0);
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
    constexpr double TargetHeightInch {84};
    constexpr double CameraHeightInch {18};
    constexpr double CameraAngleOffGroundDegrees {15};
    double distanceInch = (TargetHeightInch - CameraHeightInch) / tan(CameraAngleOffGroundDegrees + TargetOffset());
    return distanceInch;
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

// Motion Profile Support Interface

void Chassis::SetModePercentOutput()
{
  mComponents.frontLeft.Set(ControlMode::PercentOutput, 0.0);
  mComponents.frontRight.Set(ControlMode::PercentOutput, 0.0);
}

void Chassis::SetModeMotionProfile()
{
  mComponents.frontLeft.Set(ControlMode::MotionProfile, 0.0);
  mComponents.frontRight.Set(ControlMode::MotionProfile, 0.0);
}

void Chassis::ClearMotionProfileTrajectories()
{
  mComponents.frontLeft.ClearMotionProfileTrajectories();
  mComponents.frontRight.ClearMotionProfileTrajectories();
}

void Chassis::ConfigMotionProfileTrajectoryPeriod(int trajectoryDurationMillis) {
}

void Chassis::SetMotionProfileSetValue(SetValueMotionProfile setValue)
{
  mComponents.frontLeft.Set(ControlMode::MotionProfile, setValue);
  mComponents.frontRight.Set(ControlMode::MotionProfile, setValue);
}

void Chassis::PushMotionProfileTrajectory(const TrajectoryPoint& leftTrajectoryPoint,
                                          const TrajectoryPoint& rightTrajectoryPoint)
{
  mComponents.frontLeft.PushMotionProfileTrajectory(leftTrajectoryPoint);
  mComponents.frontRight.PushMotionProfileTrajectory(rightTrajectoryPoint);
}

void Chassis::ProcessMotionProfileBuffer()
{
  mComponents.frontLeft.ProcessMotionProfileBuffer();
  mComponents.frontRight.ProcessMotionProfileBuffer();
}

void Chassis::GetMotionProfileStatus(MotionProfileStatus* leftStatus,
                                     MotionProfileStatus* rightStatus)
{
  mComponents.frontLeft.GetMotionProfileStatus(*leftStatus);
  mComponents.frontRight.GetMotionProfileStatus(*rightStatus);
}

void Chassis::SetMotionMagic(int position)
{
  mComponents.frontLeft.Set(ControlMode::MotionMagic, position);
  mComponents.frontRight.Set(ControlMode::MotionMagic, position);
}

