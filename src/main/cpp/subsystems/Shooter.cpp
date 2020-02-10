/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"

namespace{

constexpr frc::DoubleSolenoid::Value kHoodOutFull {frc::DoubleSolenoid::kReverse};
constexpr frc::DoubleSolenoid::Value kHoodRetract {frc::DoubleSolenoid::kForward};
constexpr frc::DoubleSolenoid::Value kLatchEngage {frc::DoubleSolenoid::kReverse};
constexpr frc::DoubleSolenoid::Value kLatchDisengage {frc::DoubleSolenoid::kForward};

constexpr double kTicksPerRotation {2048};
constexpr double kHundredMillisPerSecond {10};
constexpr double kSecondsPerMin {60};

double ticksToRPM(double ticks)
{
  double rpm = (ticks / kTicksPerRotation) * kHundredMillisPerSecond * kSecondsPerMin;
  return rpm;
}

double RPMToTicks(double rpm)
{
  double ticks = (rpm * kTicksPerRotation) / kHundredMillisPerSecond / kSecondsPerMin;
  return ticks;
}
constexpr double kMaxVelocityError{4000-3000};
constexpr double kP{(.05*1023)/kMaxVelocityError};
constexpr double kI{0.0};
constexpr double kD{0.0};
double kF{(.95 * 1023)/ RPMToTicks(4000)};

}


Shooter::Shooter(    
    const wpi::Twine& name,
    WPI_TalonFX& shooterleft,
    WPI_TalonFX& shooterright,
    frc::DoubleSolenoid& hood,
    frc::DoubleSolenoid& latch)
: mshooterleft{shooterleft}
, mshooterright{shooterright}
, mhood{hood}
, mlatch{latch}
{
    SetName(name);
    shooterleft.SetInverted(false);
    shooterright.SetInverted(true);
    shooterright.Follow(shooterleft);
    SetPID();
}

void Shooter::SetPID()
{
  mshooterleft.Config_kP(0, kP, 10);
  mshooterleft.Config_kI(0, kI, 10);
  mshooterleft.Config_kD(0, kD, 10);
  mshooterleft.Config_kF(0, kF, 10);
}

void Shooter::IdleShoot() 
{
  mshooterleft.Set(ControlMode::PercentOutput, 0.0);
}

double Shooter::MotorTopRPM()
{
  double SpeedTP100msTop = mshooterleft.GetSelectedSensorVelocity();
  return ticksToRPM(SpeedTP100msTop);
}

double Shooter::MotorBottomRPM()
{
  double SpeedTP100msTop = mshooterright.GetSelectedSensorVelocity();
  return ticksToRPM(SpeedTP100msTop);
}

double Shooter::GetVelocity()
{
  return mshooterleft.GetSelectedSensorVelocity();
}

double Shooter::Shoot(double speedRPM)
{
  double speed = RPMToTicks(speedRPM);  
  mshooterleft.Set(ControlMode::Velocity, speed);
  return speed;
}

bool Shooter::IsInRange() const
{
  constexpr int kErrorThreshold = 10;
  constexpr int kLoopsToSettle = 10;

  int loopError = mshooterleft.GetClosedLoopError();
  if (loopError < kErrorThreshold && loopError > -kErrorThreshold)
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
  mhood.Set(kHoodOutFull);
}

void Shooter::RetractHood()
{
  mhood.Set(kHoodRetract);
}

void Shooter::EngageLatch()
{
  mlatch.Set(kLatchEngage);
}

void Shooter::DisengageLatch()
{
  mlatch.Set(kLatchDisengage);
}

// This method will be called once per scheduler run
void Shooter::Periodic() 
{
  frc::SmartDashboard::PutNumber("Left Motor RPM", MotorBottomRPM());
  frc::SmartDashboard::PutNumber("Right Motor RPM", MotorTopRPM());
  frc::SmartDashboard::PutBoolean("Shooter is in range", IsInRange());
}
