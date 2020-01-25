/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "commands/TankDrive.h"
#include "commands/IntakeOn.h"

RobotContainer::RobotContainer()
{
  using JoystickHand = frc::GenericHID::JoystickHand;

  // Initialize all of your commands and subsystems here
  mChassis.SetDefaultCommand
  (
    TankDrive
    (
      mChassis,
      [this] { return driver.GetY(JoystickHand::kLeftHand); },
      [this] { return driver.GetY(JoystickHand::kRightHand); }
    )
  );

  frc::SmartDashboard::PutData("Intake 10 percent", new IntakeOn(0.1, mIntake));
  frc::SmartDashboard::PutData("Intake 20 percent", new IntakeOn(0.2, mIntake));
  frc::SmartDashboard::PutData("Intake 30 percent", new IntakeOn(0.3, mIntake));
  frc::SmartDashboard::PutData("Intake 40 percent", new IntakeOn(0.4, mIntake));
  frc::SmartDashboard::PutData("Intake 50 percent", new IntakeOn(0.5, mIntake));
  frc::SmartDashboard::PutData("Intake 60 percent", new IntakeOn(0.6, mIntake));
  frc::SmartDashboard::PutData("Intake 70 percent", new IntakeOn(0.7, mIntake));
  frc::SmartDashboard::PutData("Intake 80 percent", new IntakeOn(0.8, mIntake));
  frc::SmartDashboard::PutData("Intake 90 percent", new IntakeOn(0.9, mIntake));
  frc::SmartDashboard::PutData("Intake 100 percent", new IntakeOn(1.0, mIntake));

  // Configure the button bindings
  frc::SmartDashboard::PutData("Telescope Rise", new TelescopeRise(mTelescope, 0.1));

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return nullptr;
}
