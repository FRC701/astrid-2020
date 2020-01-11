/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "commands/Launch.h"


RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem)
{

  ConfigureButtonBindings();
  
}

void RobotContainer::ConfigureButtonBindings() {

  frc2::JoystickButton dA {&driver,6};
  frc2::JoystickButton dB {&driver,2};
  frc2::JoystickButton dX {&driver,3};
  frc2::JoystickButton dY {&driver,4};

  dA.WhenPressed(Launch());

}

frc2::Command* RobotContainer::GetAutonomousCommand() {
    return &m_autonomousCommand;
}
