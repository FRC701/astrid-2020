/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"

Shooter::Shooter(    
    const wpi::Twine& name,
    WPI_TalonFX& shooter1,
    WPI_TalonFX& shooter2)
: mshooter1{shooter1}
, mshooter2{shooter2}
{
    SetName(name);
}


double Shooter::MotorTopRPM()
{
  constexpr double TPR {2048};
  constexpr double hundredMSPS {10};
  constexpr double secondsPMin {60};
  double SpeedTP100msTop = mshooter1.GetSelectedSensorVelocity();
  double RPMMotorTop = (SpeedTP100msTop/TPR)*hundredMSPS*secondsPMin;
  return RPMMotorTop;
}

double Shooter::MotorBottomRPM()
{
  constexpr double TPR {2048};
  constexpr double hundredMSPS {10};
  constexpr double secondsPMin {60};
  double SpeedTP100msTop = mshooter2.GetSelectedSensorVelocity();
  double RPMMotorBottom = (SpeedTP100msTop/TPR)*hundredMSPS*secondsPMin;
  return RPMMotorBottom;
}

double Shooter::Shoot(double speed)
{
    mshooter2.Set(speed);
    mshooter1.Set(speed);
    return speed;
}


// This method will be called once per scheduler run
void Shooter::Periodic() 
{
  frc::SmartDashboard::PutNumber("Left Motor RPM", MotorBottomRPM());
  frc::SmartDashboard::PutNumber("Right Motor RPM", MotorTopRPM());
}
