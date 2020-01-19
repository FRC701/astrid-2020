/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/WPILib.h>


class dualAxleShooter : public frc2::SubsystemBase {
 public:
  dualAxleShooter();
  static std::shared_ptr<dualAxleShooter> getInstance();


  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  double shoot(double speed);
  void IdleShoot();
  void SetPID();
  double FlyWheelTopRPM();
  double FlyWheelBottomRPM();
  double MotorTopRPM();
  double MotorBottomRPM();

 private:
  WPI_TalonFX shooter1;
  WPI_TalonFX shooter2;
  double p, i, d, f;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
