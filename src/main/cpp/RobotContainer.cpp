/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "commands/Shoot.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem),
driver(0),
dA(0,1),
dB(0,2),
dX(0,3),
dY(0,4)
 {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  dA.WhenPressed(new Shoot());
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}

double RobotContainer::getDriverLeftYAxis() {
  return driver.GetRawAxis(0);
}
