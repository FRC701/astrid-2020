/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/XboxController.h>

class Telescope : public frc2::SubsystemBase {
 public:
 using WPI_TalonSRX = ctre::phoenix::motorcontrol::can::WPI_TalonSRX;

 struct Components
 {
         WPI_TalonSRX telescopeMotor;
         frc::XboxController& coDriver;
 };

  Telescope(const wpi::Twine& name,
          Components& components);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  void TelescopeRise(double percentoutput);
  double GetPosition();
  bool GetRevLimitSwitch();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  Components& mComponents;
};
