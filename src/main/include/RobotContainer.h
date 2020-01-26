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
#include <subsystems/Shooter.h>
#include "subsystems/Chassis.h"
#include <commands/Shoot.h>


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
  Chassis mChassis{"Chassis", mChassisLeft, mChassisRight};



  //Shooter Components
  WPI_TalonFX mshooterleft{4};
  WPI_TalonFX mshooterright{5};

  frc::DoubleSolenoid mhood{2,5};
  frc::DoubleSolenoid mlatch{1,6};
  Shooter mShooter{"Shooter", mshooterleft, mshooterright, mhood, mlatch};

  void ConfigureButtonBindings();
};
