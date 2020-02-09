/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"

namespace{

constexpr double kP{0.0};
constexpr double kI{0.0};
constexpr double kD{0.0};
constexpr double kF{0.0};

constexpr frc::DoubleSolenoid::Value kHoodOutFull {frc::DoubleSolenoid::kReverse};
constexpr frc::DoubleSolenoid::Value kHoodRetract {frc::DoubleSolenoid::kForward};
constexpr frc::DoubleSolenoid::Value kLatchEngage {frc::DoubleSolenoid::kReverse};
constexpr frc::DoubleSolenoid::Value kLatchDisengage {frc::DoubleSolenoid::kForward};

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
  constexpr double TicksPerRotation {2048};
  constexpr double hundredMSPS {10};
  constexpr double secondsPMin {60};
  double SpeedTP100msTop = mshooterleft.GetSelectedSensorVelocity();
  double RPMMotorTop = (SpeedTP100msTop/TicksPerRotation)*hundredMSPS*secondsPMin;
  return RPMMotorTop;
}

double Shooter::MotorBottomRPM()
{
  constexpr double TicksPerRotation {2048};
  constexpr double hundredMSPS {10};
  constexpr double secondsPMin {60};
  double SpeedTP100msTop = mshooterright.GetSelectedSensorVelocity();
  double RPMMotorBottom = (SpeedTP100msTop/TicksPerRotation)*hundredMSPS*secondsPMin;
  return RPMMotorBottom;
}

double Shooter::GetVelocity()
{
  return mshooterleft.GetSelectedSensorVelocity();
}

double Shooter::Shoot(double speed)
{
    mshooterleft.Set(ControlMode::Velocity, speed);
    return speed;
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
}
