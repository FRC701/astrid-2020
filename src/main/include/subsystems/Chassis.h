/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

class Chassis : public frc2::SubsystemBase {
 public:
  static std::shared_ptr<Chassis> getInstance();
  Chassis();
  void SetTankDrive(double left);
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
 static const char kSubsystemName[];
  static std::shared_ptr<Chassis> self;
  WPI_TalonFX left1Wheel;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
