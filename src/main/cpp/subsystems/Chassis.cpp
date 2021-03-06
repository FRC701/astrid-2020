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


namespace{

    constexpr double kTicksPerRotation {2048};
    constexpr double kHundredMillisPerSecond {10};
    constexpr double kSecondsPerMin {60};

    constexpr double RPMToTicks(double rpm)
    {
        double ticks = (rpm * kTicksPerRotation) / kHundredMillisPerSecond / kSecondsPerMin;
        return ticks;
    }

    constexpr double kWheelDiameterInches = 6.0;
    constexpr double kWheelDiameterFeet = kWheelDiameterInches / 12.0;
    constexpr double kFeetPerRotation = M_PI * kWheelDiameterFeet;
    constexpr double kWheelGearTeeth = 84.0;
    constexpr double kEncoderGearTeeth = 8.0;

    double feetToTicks(double feet) 
    {
        return feet * 13000;
    }

    
    constexpr double kMaxVelocityError{3500-3000};
    constexpr double kP{(.10*1023)/kMaxVelocityError};
    constexpr double kI{0.0};
    constexpr double kD{0.0}; // 30 is too high
    constexpr double kF{(.70 * 1023)/ RPMToTicks(3000)};


void SetPID(Chassis::Components& components)
{
  components.frontLeft.Config_kP(0, kP, 10);
  components.frontLeft.Config_kI(0, kI, 10);
  components.frontLeft.Config_kD(0, kD, 10);
  components.frontLeft.Config_kF(0, kF, 10);

  components.frontRight.Config_kP(0, kP, 10);
  components.frontRight.Config_kI(0, kI, 10);
  components.frontRight.Config_kD(0, kD, 10);
  components.frontRight.Config_kF(0, kF, 10);
}


} //namespace

Chassis::Chassis(const wpi::Twine& name,
    Components& components)

:mComponents(components)
, mDrive{mComponents.frontLeft, mComponents.frontRight}
, mNotifier(&Chassis::PeriodicTask, this)
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

    mComponents.frontLeft.ConfigMotionAcceleration(1500, 10);
    mComponents.frontLeft.ConfigMotionCruiseVelocity(1500, 10);
    mComponents.frontRight.ConfigMotionAcceleration(1500, 10);
    mComponents.frontRight.ConfigMotionCruiseVelocity(1500, 10);
    mComponents.backLeft.ConfigMotionAcceleration(1500, 10);
    mComponents.backLeft.ConfigMotionCruiseVelocity(1500, 10);
    mComponents.backRight.ConfigMotionAcceleration(1500, 10);
    mComponents.backRight.ConfigMotionCruiseVelocity(1500, 10);
    
     mComponents.backLeft.Follow(mComponents.frontLeft); 
     mComponents.backRight.Follow(mComponents.frontRight); 
     
     mDrive.SetRightSideInverted(false);

     SetPID(mComponents);
}

void Chassis::StartNotifier()
{
    mNotifier.StartPeriodic(units::millisecond_t(10));
}

void Chassis::StopNotifier()
{
    mNotifier.Stop();
}

void Chassis::PeriodicTask()
{
    ProcessMotionProfileBuffer();
}

// This method will be called once per scheduler run
void Chassis::Periodic() 
{
}

void Chassis::TankDrive(double left, double right)
{
    mDrive.TankDrive(left, right);
}

void Chassis::SlowTankDrive(double left, double right)
{
    mDrive.TankDrive(left * 0.25, right * 0.25);
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

void Chassis::ResetLeftPos()
{
    mComponents.frontLeft.SetSelectedSensorPosition(0);
}

void Chassis::ResetRightPos()
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
    double distanceFeet = mTable->GetNumber("ta",0.0);
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

// Motion Profile Support Interface

void Chassis::SetModePercentOutput()
{
  mComponents.frontLeft.Set(ControlMode::PercentOutput, 0.0);
  mComponents.frontRight.Set(ControlMode::PercentOutput, 0.0);
}

void Chassis::SetModeMotionProfile()
{
  mComponents.frontLeft.Set(ControlMode::MotionProfile, SetValueMotionProfile::Disable);
  mComponents.frontRight.Set(ControlMode::MotionProfile, SetValueMotionProfile::Disable);
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

void Chassis::SetMotionMagic(int leftPosition, int rightPosition)
{
  mComponents.frontLeft.Set(ControlMode::MotionMagic, feetToTicks(leftPosition));
  mComponents.frontRight.Set(ControlMode::MotionMagic, feetToTicks(rightPosition));
}

bool Chassis::IsInRange() const
{
    constexpr int kErrorThreshold = 10;

    return (abs(mComponents.frontLeft.GetClosedLoopError()) < kErrorThreshold && 
            abs(mComponents.frontRight.GetClosedLoopError()) < kErrorThreshold);
}