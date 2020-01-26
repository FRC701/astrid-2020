/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"

constexpr frc::DoubleSolenoid::Value kHoodOutFull {frc::DoubleSolenoid::kForward};
constexpr frc::DoubleSolenoid::Value kHoodRetract {frc::DoubleSolenoid::kReverse};


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
}


double Shooter::MotorTopRPM()
{
  constexpr double TPR {2048};
  constexpr double hundredMSPS {10};
  constexpr double secondsPMin {60};
  double SpeedTP100msTop = mshooterleft.GetSelectedSensorVelocity();
  double RPMMotorTop = (SpeedTP100msTop/TPR)*hundredMSPS*secondsPMin;
  return RPMMotorTop;
}

double Shooter::MotorBottomRPM()
{
  constexpr double TPR {2048};
  constexpr double hundredMSPS {10};
  constexpr double secondsPMin {60};
  double SpeedTP100msTop = mshooterright.GetSelectedSensorVelocity();
  double RPMMotorBottom = (SpeedTP100msTop/TPR)*hundredMSPS*secondsPMin;
  return RPMMotorBottom;
}

double Shooter::Shoot(double speed)
{
    mshooterright.Set(speed);
    mshooterleft.Set(speed);
    return speed;
}


void Shooter::PushHood()
{
  mhood.Set(kHoodOutFull);
}

void Shooter::RetractHood()
{
  mhood.Set(kHoodRetract);
}



// This method will be called once per scheduler run
void Shooter::Periodic() 
{
  frc::SmartDashboard::PutNumber("Left Motor RPM", MotorBottomRPM());
  frc::SmartDashboard::PutNumber("Right Motor RPM", MotorTopRPM());
}
