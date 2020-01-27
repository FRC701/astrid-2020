/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "commands/TankDrive.h"
#include "commands/Spin.h"
#include "commands/SetHickeyPos.h"
#include "commands/HickeyDisengage.h"
#include "commands/HickeyEngage.h"

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
  constexpr double radiusCW = 16; //16" radius of Control panel 
  constexpr double radiusDW = 1.5;  //1.5" radius of DooHickey wheel (3" diameter)
  constexpr double TargetPos = (4*(radiusCW/radiusDW)) * 2048; 

  frc::SmartDashboard::PutData("Telescope Rise", new TelescopeRise(mTelescope, 0.1));
  frc::SmartDashboard::PutData("Spin 600 RPM", new Spin(mDooHickey, 0.1));
  frc::SmartDashboard::PutData("Spin 6000 RPM", new Spin(mDooHickey, 0.9404));
  frc::SmartDashboard::PutData("Spin distance", new SetHickeyPos(mDooHickey, TargetPos));
  frc::SmartDashboard::PutData("Engage da Hickey", new HickeyEngage(mDooHickey));
  frc::SmartDashboard::PutData("Disengage da Hickey", new HickeyDisengage(mDooHickey));

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
