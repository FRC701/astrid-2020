/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>

class Conveyor : public frc2::SubsystemBase {
 public:
  using WPI_TalonFX = ctre::phoenix::motorcontrol::can::WPI_TalonFX;

  Conveyor(const wpi::Twine& name,
        WPI_TalonFX& conveyorMotor);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  bool IsBallComing();
  bool IsBallExiting();
  void BallIntakeIncoming();
  void BallIntakeExiting();
  void SetConveyor(double speed);
  int BallCount();
  bool IsShooting();


 private:
 WPI_TalonFX& mConveyorMotor;
 int mBallCount{0};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
