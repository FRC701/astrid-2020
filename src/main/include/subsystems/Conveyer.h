/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

class Conveyer : public frc2::SubsystemBase {
 public:
  Conveyer();
  static std::shared_ptr<Conveyer> getInstance();
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();
  void SetConveyer();
  void StopConveyer();
  bool GetConveyerBanner();
  bool GetIntakeBanner(); 
  int BallPlus();
  int BallMinus();
 private:
 WPI_TalonFX IntakeRoller;
 int balls;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
