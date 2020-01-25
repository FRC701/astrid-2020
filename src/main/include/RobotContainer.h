/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <frc/XboxController.h>
#include <frc2/command/Command.h>
#include <subsystems/Shooter.h>
#include "subsystems/Chassis.h"
#include <subsystems/Conveyor.h>
#include "subsystems/Intake.h"
#include "subsystems/Telescope.h"
#include "subsystems/Winch.h"

#include "commands/TelescopeRise.h"
#include "commands/Shoot.h"
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
  using WPI_TalonSRX = ctre::phoenix::motorcontrol::can::WPI_TalonSRX;

  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  frc::XboxController driver{0};

  // The robot's subsystems and commands are defined here...
  // Chassis Components
  WPI_TalonFX mChassisLeft{0};
  WPI_TalonFX mChassisRight{1}; 
  WPI_TalonFX mChassisBackLeft{2};
  WPI_TalonFX mChassisBackRight{3};

  Chassis mChassis{"Chassis", mChassisLeft, mChassisRight, mChassisBackLeft, mChassisBackRight};

  // TODO: Aggregate initialization appears to not be supported
  // Sadness. There must be a better way.
  Telescope::Components mTelescopeComponents{2};
  Telescope mTelescope{"Telescope", mTelescopeComponents};

  Winch::Components mWinchComponents{3,4};  
  Winch mWinch{"Winch", mWinchComponents};

  // Conveyor Components
  WPI_TalonFX mConveyorMotor{5};
  Conveyor mConveyor{"Conveyor", mConveyorMotor};
  // The robot's subsystems and commands are defined here...
  //Shooter Components
  WPI_TalonFX mshooter1{4};
  WPI_TalonFX mshooter2{5};
  Shooter mShooter{"Shooter", mshooter1, mshooter2};

  // Intake Components
  WPI_TalonFX mIntakeRoller{2};
  Intake mIntake{"Intake", mIntakeRoller};

  void ConfigureButtonBindings();
};
