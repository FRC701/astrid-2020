/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "commands/Shoot.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem)
 {
   frc::SmartDashboard::PutData(&m_hoodedFlyWheel);
   frc::SmartDashboard::PutData("Shoot", new Shoot(&m_hoodedFlyWheel));
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {

  dA.WhenPressed(Shoot(&m_hoodedFlyWheel));
  dB.WhenPressed(Shoot(&m_hoodedFlyWheel));
  dX.WhenPressed(Shoot(&m_hoodedFlyWheel));
  dY.WhenPressed(Shoot(&m_hoodedFlyWheel));

  
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}