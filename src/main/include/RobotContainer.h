/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>
#include <frc/XboxController.h>
#include <frc2/command/Command.h>

#include "subsystems/Chassis.h"
#include "subsystems/Telescope.h"
#include "subsystems/Winch.h"

#include "commands/TelescopeRise.h"
#include "commands/WinchHook.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  using WPI_TalonFX = ctre::phoenix::motorcontrol::can::WPI_TalonFX;

  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  frc::XboxController driver{0};

  // The robot's subsystems and commands are defined here...
  // Chassis Components
  WPI_TalonFX mChassisLeft{0};
  WPI_TalonFX mChassisRight{1};  
  WPI_TalonFX mTelescopeMotor{2};
  WPI_TalonFX mWinchMotor{3};
  Chassis mChassis{"Chassis", mChassisLeft, mChassisRight};
  Telescope mTelescope{"Telescope", mTelescopeMotor};
  Winch mWinch{"Winch", mWinchMotor};

  // The robot's subsystems and commands are defined here...

  void ConfigureButtonBindings();
};
