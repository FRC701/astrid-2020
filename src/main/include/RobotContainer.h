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
#include "frc/Joystick.h"
#include "frc2/command/button/JoystickButton.h"

#include "subsystems/HoodedFlyWheel.h"

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

 private:

  HoodedFlyWheel m_hoodedFlyWheel;
  
  frc::Joystick driver {1};

  frc2::JoystickButton dA{&driver, 1};
  frc2::JoystickButton dB{&driver, 2};
  frc2::JoystickButton dX{&driver, 3};
  frc2::JoystickButton dY{&driver, 4};  
  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;

  void ConfigureButtonBindings();
};
