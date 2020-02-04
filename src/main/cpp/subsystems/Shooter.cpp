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

constexpr frc::DoubleSolenoid::Value kHoodOutFull {frc::DoubleSolenoid::kForward};
constexpr frc::DoubleSolenoid::Value kHoodRetract {frc::DoubleSolenoid::kReverse};
constexpr frc::DoubleSolenoid::Value kLatchEngage {frc::DoubleSolenoid::kForward};
constexpr frc::DoubleSolenoid::Value kLatchDisengage {frc::DoubleSolenoid::kReverse};

}

Shooter::Shooter(const wpi::Twine& name, Components& components)
: mComponents(components)
{
    SetName(name);
    mComponents.shooterleft.SetInverted(false);
    mComponents.shooterright.SetInverted(false);
    mComponents.shooterright.Follow(mComponents.shooterleft);
    SetPID();
}

void Shooter::SetPID()
{
  mComponents.shooterleft.Config_kP(0, kP, 10);
  mComponents.shooterleft.Config_kI(0, kI, 10);
  mComponents.shooterleft.Config_kD(0, kD, 10);
  mComponents.shooterleft.Config_kF(0, kF, 10);
}

void Shooter::IdleShoot() 
{
  mComponents.shooterleft.Set(ControlMode::PercentOutput, 0.0);
}

double Shooter::MotorTopRPM()
{
  constexpr double TicksPerRotation {2048};
  constexpr double hundredMSPS {10};
  constexpr double secondsPMin {60};
  double SpeedTP100msTop = mComponents.shooterleft.GetSelectedSensorVelocity();
  double RPMMotorTop = (SpeedTP100msTop/TicksPerRotation)*hundredMSPS*secondsPMin;
  return RPMMotorTop;
}

double Shooter::MotorBottomRPM()
{
  constexpr double TicksPerRotation {2048};
  constexpr double hundredMSPS {10};
  constexpr double secondsPMin {60};
  double SpeedTP100msTop = mComponents.shooterright.GetSelectedSensorVelocity();
  double RPMMotorBottom = (SpeedTP100msTop/TicksPerRotation)*hundredMSPS*secondsPMin;
  return RPMMotorBottom;
}

double Shooter::Shoot(double speed)
{
    mComponents.shooterright.Set(speed);
    mComponents.shooterleft.Set(speed);
    return speed;
}

//Start of Pistons
void Shooter::PushHood()
{
  mComponents.hood.Set(kHoodOutFull);
}

void Shooter::RetractHood()
{
  mComponents.hood.Set(kHoodRetract);
}

void Shooter::EngageLatch()
{
  mComponents.latch.Set(kLatchEngage);
}

void Shooter::DisengageLatch()
{
  mComponents.latch.Set(kLatchDisengage);
}


// This method will be called once per scheduler run
void Shooter::Periodic() 
{
  frc::SmartDashboard::PutNumber("Left Motor RPM", MotorBottomRPM());
  frc::SmartDashboard::PutNumber("Right Motor RPM", MotorTopRPM());
}
