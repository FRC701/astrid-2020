/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/DoubleSolenoid.h>

class Intake : public frc2::SubsystemBase {
 public:
  Intake();
static std::shared_ptr<Intake> getInstance();
  /** 
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();
  void SetIntake();
  bool GetIntakeLimit();

 private:
  WPI_TalonSRX IntakeMotor;
  frc::DoubleSolenoid IntakeGo;
  static const char kSubsystemName[];
  static std::shared_ptr<Intake> self;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
