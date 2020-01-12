/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/dualAxleShooter.h"

dualAxleShooter::dualAxleShooter() : 
shooter1(0),
shooter2(1)
{
  std::cout << "Constructing dualAxleShooter" << std::endl;
  shooter2.SetInverted(true);
  shooter1.SetInverted(false);
}

double dualAxleShooter::shoot(double speed){
    shooter1.Set(speed);
    shooter2.Set(speed);
    return speed;
}

double dualAxleShooter::FlyWheelTopRPM(){
  constexpr double TPR {2048};
  constexpr double hundredMSPS {10};
  constexpr double secondsPMin {60};
  constexpr double motorToFlywheel {2.0/3};
  double SpeedTP100ms = shooter1.GetSelectedSensorVelocity();
  double RPMflywheel = SpeedTP100ms/TPR*hundredMSPS*secondsPMin*motorToFlywheel;
  return RPMflywheel;
}
// return no motor:flywheel
double dualAxleShooter::FlyWheelBottomRPM(){
  constexpr double TPR {2048};
  constexpr double hundredMSPS {10};
  constexpr double secondsPMin {60};
  constexpr double motorToFlywheel {2.0/3};
  double SpeedTP100msBottom = shooter2.GetSelectedSensorVelocity(0);
  double RPMflywheelBottom = SpeedTP100msBottom/TPR*hundredMSPS*secondsPMin*motorToFlywheel;
  return RPMflywheelBottom;
}

double dualAxleShooter::MotorTopRPM(){
  constexpr double TPR {2048};
  constexpr double hundredMSPS {10};
  constexpr double secondsPMin {60};
  double SpeedTP100msTop = shooter1.GetSelectedSensorVelocity();
  double RPMMotorTop = SpeedTP100msTop/TPR*hundredMSPS*secondsPMin;
  return RPMMotorTop;
}

double dualAxleShooter::MotorBottomRPM(){
  constexpr double TPR {2048};
  constexpr double hundredMSPS {10};
  constexpr double secondsPMin {60};
  double SpeedTP100msTop = shooter1.GetSelectedSensorVelocity();
  double RPMMotorBottom = SpeedTP100msTop/TPR*hundredMSPS*secondsPMin;
  return RPMMotorBottom;
}

// This method will be called once per scheduler run
void dualAxleShooter::Periodic() {

  frc::SmartDashboard::PutNumber("Bottom Motor RPM", MotorBottomRPM());
  frc::SmartDashboard::PutNumber("Top Motor RPM", MotorTopRPM());
  frc::SmartDashboard::PutNumber("Bottom Flywheel RPM", FlyWheelBottomRPM());
  frc::SmartDashboard::PutNumber("Top Flywheel RPM", FlyWheelTopRPM());

}