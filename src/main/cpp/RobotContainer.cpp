/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "commands/IntakeOn.h"
#include "commands/SetConveyor.h"
#include "commands/TankDrive.h"
#include "commands/Aim.h"
#include "commands/LimeLightsOn.h"
#include "commands/LimeLightsOff.h"
#include "frc/smartdashboard/SmartDashboard.h"

RobotContainer::RobotContainer()
{
  using JoystickHand = frc::GenericHID::JoystickHand;

  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  mChassis.SetDefaultCommand
  (
    TankDrive
    (
      mChassis,
      [this] { return driver.GetY(JoystickHand::kLeftHand); },
      [this] { return driver.GetY(JoystickHand::kRightHand); }
    )
  );

  frc::SmartDashboard::PutData("Intake 10 percent", new IntakeOn(mIntake, 0.1));
  frc::SmartDashboard::PutData("Intake 20 percent", new IntakeOn(mIntake, 0.2));
  frc::SmartDashboard::PutData("Intake 30 percent", new IntakeOn(mIntake, 0.3));
  frc::SmartDashboard::PutData("Intake 40 percent", new IntakeOn(mIntake, 0.4));
  frc::SmartDashboard::PutData("Intake 50 percent", new IntakeOn(mIntake, 0.5));
  frc::SmartDashboard::PutData("Intake 60 percent", new IntakeOn(mIntake, 0.6));
  frc::SmartDashboard::PutData("Intake 70 percent", new IntakeOn(mIntake, 0.7));
  frc::SmartDashboard::PutData("Intake 80 percent", new IntakeOn(mIntake, 0.8));
  frc::SmartDashboard::PutData("Intake 90 percent", new IntakeOn(mIntake, 0.9));
  frc::SmartDashboard::PutData("Intake 100 percent", new IntakeOn(mIntake, 1.0));

  mConveyor.SetDefaultCommand(SetConveyor(mConveyor, 0.2));

  frc::SmartDashboard::PutData("Telescope Rise", new TelescopeRise(mTelescope, 0.1));
  frc::SmartDashboard::PutData("VisionMode", new Aim(mChassis));
  frc::SmartDashboard::PutData("Lime Lights On", new LimeLightsOn(mChassis));
  frc::SmartDashboard::PutData("Lime Lights Off", new LimeLightsOff(mChassis));
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  frc2::Trigger( [this] { return mConveyor.IsBallComing(); }).WhenActive( [this]{ mConveyor.BallIntakeIncoming(); });
  frc2::Trigger( [this] { return mConveyor.IsBallExiting(); }).WhenInactive( [this] { mConveyor.BallIntakeExiting(); });
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return nullptr;
}
