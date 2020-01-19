/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>

class Chassis : public frc2::SubsystemBase {
 public:
  using WPI_TalonFX = ctre::phoenix::motorcontrol::can::WPI_TalonFX;

  Chassis(const wpi::Twine& name,
        WPI_TalonFX& left,
        WPI_TalonFX& right);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  WPI_TalonFX& mLeft;
  WPI_TalonFX& mRight;
};
