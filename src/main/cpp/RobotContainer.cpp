/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/button/JoystickButton.h>

#include "RobotContainer.h"
#include "commands/ClimberEngage.h"
#include "subsystems/Climber.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here
  frc::SmartDashboard::PutData(&m_climber);

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
    frc2::JoystickButton m_bUp{&m_joy, 0};
    frc2::JoystickButton m_bDown{&m_joy, 0};

    m_bUp.WhenPressed(ClimberEngage(0.2, &m_climber));
    m_bDown.WhenPressed(ClimberEngage(-0.2, &m_climber));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
  return &m_climberEngage;
}
