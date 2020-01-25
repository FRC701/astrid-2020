/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <frc2/command/button/Trigger.h>
#include "RobotContainer.h"
#include "commands/TankDrive.h"
#include "commands/SetConveyor.h"

RobotContainer::RobotContainer()
{
  using JoystickHand = frc::GenericHID::JoystickHand;

  // Initialize all of your commands and subsystems here
  mChassis.SetDefaultCommand(
    TankDrive(
      [this] { return driver.GetY(JoystickHand::kLeftHand); },
      [this] { return driver.GetY(JoystickHand::kRightHand); },
      mChassis
    )
  );

  mConveyor.SetDefaultCommand(SetConveyor(mConveyor));

  // Configure the button bindings
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
