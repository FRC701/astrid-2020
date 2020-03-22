/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"

#include <ctre/phoenix/motorcontrol/ControlMode.h>

std::shared_ptr<NetworkTable> mTable2 = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

namespace{using ControlMode = ctre::phoenix::motorcontrol::ControlMode;



constexpr frc::DoubleSolenoid::Value kHoodOutFull {frc::DoubleSolenoid::kReverse};
constexpr frc::DoubleSolenoid::Value kHoodRetract {frc::DoubleSolenoid::kForward};
constexpr frc::DoubleSolenoid::Value kLatchEngage {frc::DoubleSolenoid::kReverse};
constexpr frc::DoubleSolenoid::Value kLatchDisengage {frc::DoubleSolenoid::kForward};

constexpr double kTicksPerRotation {2048};
constexpr double kHundredMillisPerSecond {10};
constexpr double kSecondsPerMin {60};

constexpr double ticksToRPM(double ticks)
{
  double rpm = (ticks / kTicksPerRotation) * kHundredMillisPerSecond * kSecondsPerMin;
  return rpm;
}

constexpr double RPMToTicks(double rpm)
{
  double ticks = (rpm * kTicksPerRotation) / kHundredMillisPerSecond / kSecondsPerMin;
  return ticks;
}

constexpr double kMaxVelocityError{3540-3000};
constexpr double kP{(.30*1023)/kMaxVelocityError};
constexpr double kI{0.0};
constexpr double kD{10 * kP}; // 30 is too high
constexpr double kF{(1 * 1023)/ RPMToTicks(4000)};

void SetPID(Shooter::Components& components)
{
  components.shooterleft.Config_kP(0, kP, 10);
  components.shooterleft.Config_kI(0, kI, 10);
  components.shooterleft.Config_kD(0, kD, 10);
  components.shooterleft.Config_kF(0, kF, 10);
}

} // namespace

Shooter::Shooter(const wpi::Twine& name, Components* const components)
: mComponents(components)
, mThresholdLoops(0)
{
    SetName(name);
    auto& [shooterLeft, shooterRight, hood, latch] = *mComponents;
    shooterLeft.SetInverted(false);
    shooterRight.SetInverted(true);
    shooterRight.Follow(shooterLeft);
    SetPID(*mComponents);
}

void Shooter::IdleShoot() 
{
  mComponents->shooterleft.Set(ControlMode::PercentOutput, 0.0);
}

double Shooter::MotorTopRPM()
{
  double speedTP100msTop = mComponents->shooterleft.GetSelectedSensorVelocity();
  double RPMMotorTop = ticksToRPM(speedTP100msTop);
  return RPMMotorTop;
}

double Shooter::MotorBottomRPM()
{
  double speedTP100msTop = mComponents->shooterright.GetSelectedSensorVelocity();
  double RPMMotorBottom = ticksToRPM(speedTP100msTop);
  return RPMMotorBottom;
}

double Shooter::GetVelocity()
{
  return mComponents->shooterleft.GetSelectedSensorVelocity();
}

double Shooter::Shoot(double speedRPM)
{
  double speed = RPMToTicks(speedRPM);  
  mComponents->shooterleft.Set(ControlMode::Velocity, speed);
  return speed;
}

void Shooter::ResetRange()
{
  mThresholdLoops = 0;
}

bool Shooter::IsInRange() const
{
  constexpr int kErrorThresholdRPM = 100;
  constexpr int kLoopsToSettle = 30;

  constexpr double kErrorThresholdTicks{RPMToTicks(kErrorThresholdRPM)};
  int loopError = mComponents->shooterleft.GetClosedLoopError();
  if (loopError < kErrorThresholdTicks && loopError > -kErrorThresholdTicks)
  {
    ++mThresholdLoops;
  }
  else
  {
    mThresholdLoops = 0;
  }
  return mThresholdLoops >= kLoopsToSettle;
}

//Start of Pistons
void Shooter::PushHood()
{
  mComponents->hood.Set(kHoodOutFull);
}

void Shooter::RetractHood()
{
  mComponents->hood.Set(kHoodRetract);
}

void Shooter::EngageLatch()
{
  mComponents->latch.Set(kLatchEngage);
}

void Shooter::DisengageLatch()
{
  mComponents->latch.Set(kLatchDisengage);
}

// This method will be called once per scheduler run
void Shooter::Periodic() 
{
  frc::SmartDashboard::PutNumber("Left Motor RPM", MotorBottomRPM());
  frc::SmartDashboard::PutNumber("Right Motor RPM", MotorTopRPM());
}

double Shooter::GetTargetDistance()
{
  /*
  double target1 = mTable2->GetNumber("ta",0.0);
  double target2 = mTable2->GetNumber("ta",0.0);
  double target3 = mTable2->GetNumber("ta",0.0);
  double target4 = mTable2->GetNumber("ta",0.0);
  double target5 = mTable2->GetNumber("ta",0.0);
  double target6 = mTable2->GetNumber("ta",0.0);
  double target7 = mTable2->GetNumber("ta",0.0);
  double target8 = mTable2->GetNumber("ta",0.0);
  double target9 = mTable2->GetNumber("ta",0.0);
  double target10 = mTable2->GetNumber("ta",0.0);
  double target = (target1 + target2  + target3 + target4 + target5 + target6 + target7 + target8 + target9 + target10) / 10;
  */
  double target = mTable2->GetNumber("ta",0.0);
  return target;
}