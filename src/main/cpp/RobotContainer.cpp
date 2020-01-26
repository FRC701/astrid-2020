/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "commands/TankDrive.h"
#include <commands/HoodRetract.h>
#include <commands/HoodOutFull.h>
#include <commands/LatchDisengage.h>
#include <commands/LatchEngage.h>

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

  frc::SmartDashboard::PutData("Telescope Rise", new TelescopeRise(mTelescope, 0.1));

  frc::SmartDashboard::PutData(&mShooter);
  frc::SmartDashboard::PutData("Shoot 100%", new Shoot(mShooter, 1.0));
  frc::SmartDashboard::PutData("Shoot 75%", new Shoot(mShooter, .75));
  frc::SmartDashboard::PutData("Shoot 50%", new Shoot(mShooter, .50));
  frc::SmartDashboard::PutData("Shoot 25%", new Shoot(mShooter, .25));
  frc::SmartDashboard::PutData("Shoot 10%", new Shoot(mShooter, .10));

  frc::SmartDashboard::PutData("Open Hatch Fully", new HoodOutFull());
  frc::SmartDashboard::PutData("Close Hatch", new HoodRetract());
  frc::SmartDashboard::PutData("Engage Latch", new LatchEngage());
  frc::SmartDashboard::PutData("Disengage Latch", new LatchDisengage());

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return nullptr;
}
