/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include "frc/DoubleSolenoid.h"

class Shooter : public frc2::SubsystemBase {
 public:
  using WPI_TalonFX = ctre::phoenix::motorcontrol::can::WPI_TalonFX;
  using ControlMode = ctre::phoenix::motorcontrol::ControlMode;
  Shooter(
    const wpi::Twine& name,
    WPI_TalonFX& shooterleft,
    WPI_TalonFX& shooterright,
    frc::DoubleSolenoid& hood,
    frc::DoubleSolenoid& latch);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();
  void IdleShoot();
  double MotorTopRPM();
  double MotorBottomRPM();
  double Shoot(double speed);
  void SetPID();
  void PushHood();
  void RetractHood();
  void EngageLatch();
  void DisengageLatch();
  double GetVelocity();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  WPI_TalonFX& mshooterleft;
  WPI_TalonFX& mshooterright;

  frc::DoubleSolenoid& mhood;
  frc::DoubleSolenoid& mlatch;
};
