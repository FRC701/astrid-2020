/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "commands/TankDrive.h"

namespace {
  constexpr double kWinchPercentOutput = 0.2;
}

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

  mTelescope.SetDefaultCommand
  (
    TelescopeRise
    (
      mTelescope,
      [this] { return codriver.GetY(JoystickHand::kLeftHand); }
    )
  );

  frc::SmartDashboard::PutData("Telescope Rise", new TelescopeRise(mTelescope, [this] {return 0.1;}));
  frc::SmartDashboard::PutData("Telescope Fall", new TelescopeRise(mTelescope, [this] {return -0.1;}));


  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  frc2::Button dA {[this]{return codriver.GetRawButton(1);}};
  
  dA.WhenPressed(new WinchHook(mWinch, kWinchPercentOutput));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return nullptr;
}
