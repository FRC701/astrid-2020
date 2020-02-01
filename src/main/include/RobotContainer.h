/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>
#include <frc2/command/button/JoystickButton.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <frc/XboxController.h>
#include <frc2/command/Command.h>
#include <subsystems/Shooter.h>
#include "subsystems/Chassis.h"
#include <subsystems/Conveyor.h>
#include "subsystems/Intake.h"
#include "subsystems/Telescope.h"
#include "subsystems/Winch.h"
#include "subsystems/DooHickey.h"

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

  // Speed Controller IDs (must be unique)
  static constexpr int kChassisFrontLeft{0};
  static constexpr int kChassisFrontRight{1};
  static constexpr int kChassisRearLeft{2};
  static constexpr int kChassisRearRight{3};
  static constexpr int kTelescope{4};
  static constexpr int kWinchLeft{5};
  static constexpr int kWinchRight{6};
  static constexpr int kConveyor{7};
  static constexpr int kShooterLeft{8};
  static constexpr int kShooterRight{9};
  static constexpr int kIntake{10};
  static constexpr int kDoohickey{11};

  // Solenoid IDs (must be unique)
  static constexpr int kLatchSolenoidFoward{0};
  static constexpr int kLatchSolenoidReverse{7};
  static constexpr int kHoodSolenoidFoward{1};
  static constexpr int kHoodSolenoidReverse{6};
  static constexpr int kDoohickeyPushyThangSolenoidFoward{2};
  static constexpr int kDoohickeyPushyThangSolenoidReverse{5};
  static constexpr int kUnusedSolenoidFoward{3};
  static constexpr int kUnusedSolenoidReverse{4};


  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  frc::XboxController driver{0};
  frc::XboxController codriver{1};

  // Chassis Components
  Chassis::Components mChassisComponents{kChassisFrontLeft, kChassisFrontRight,kChassisRearLeft,kChassisRearRight};  
  Chassis mChassis{"Chassis", mChassisComponents};
  

  // TODO: Aggregate initialization appears to not be supported
  // Sadness. There must be a better way.
  Telescope::Components mTelescopeComponents{kTelescope};
  Telescope mTelescope{"Telescope", mTelescopeComponents};

  Winch::Components mWinchComponents{3,4};
  Winch mWinch{"Winch", mWinchComponents};

  // Conveyor Components
  WPI_TalonFX mConveyorMotor{kConveyor};
  Conveyor mConveyor{"Conveyor", mConveyorMotor};

  //Shooter Components
  WPI_TalonFX mshooterleft{kShooterLeft};
  WPI_TalonFX mshooterright{kShooterRight};

  frc::DoubleSolenoid mhood{kHoodSolenoidFoward, kHoodSolenoidReverse};
  frc::DoubleSolenoid mlatch{kLatchSolenoidFoward, kLatchSolenoidReverse};
  Shooter mShooter{"Shooter", mshooterleft, mshooterright, mhood, mlatch};

  // Intake Components
  WPI_TalonFX mIntakeRoller{kIntake};
  Intake mIntake{"Intake", mIntakeRoller};

  //DooHickey Components
  WPI_TalonFX mDooHickeySpinner{kDoohickey};
  frc::DoubleSolenoid mUpPushyThang{kDoohickeyPushyThangSolenoidFoward, 
                                    kDoohickeyPushyThangSolenoidReverse};
  DooHickey mDooHickey{"DooHickey", mDooHickeySpinner, mUpPushyThang};

  void ConfigureButtonBindings();
};
