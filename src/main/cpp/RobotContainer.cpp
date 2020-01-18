/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "commands/Spin.h"
#include "commands/SetHickeyPos.h"
RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  double radiusCW = 16; //16in radius 
  double radiusDW = 2;  //change this later

  frc::SmartDashboard::PutData("Spin 600 RPM", new Spin(&m_dooHickey, 0.1));
  frc::SmartDashboard::PutData("Spin 6000 RPM", new Spin(&m_dooHickey, 0.9404));
  frc::SmartDashboard::PutData("Spin distance", new SetHickeyPos(&mDooHickey, (4*(radiusCW/radiusDW)) * 2048));


  ConfigureButtonBindings();

}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here


}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
