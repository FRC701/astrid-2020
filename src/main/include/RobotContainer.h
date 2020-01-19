/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>

#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"
#include "frc2/command/button/JoystickButton.h"
#include "subsystems/Conveyer.h"
#include "subsystems/Intake.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

  static std::shared_ptr<RobotContainer> getInstance();

  double getDriverLeftYAxis();
  double getDriverRightYAxis();

 private:
  frc::Joystick driver;
  frc2::JoystickButton dA;
  frc2::JoystickButton dB;
  frc2::JoystickButton dX;
  frc2::JoystickButton dY;
  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;
  Conveyer mConveyor;
  Intake mIntake;

  void ConfigureButtonBindings();

  static std::shared_ptr<RobotContainer> self;

};
