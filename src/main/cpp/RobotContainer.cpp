/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "commands/TankDrive.h"
#include "commands/ConveyerOn.h"
#include "commands/IntakeOn.h"

std::shared_ptr<RobotContainer> RobotContainer::self;

std::shared_ptr<RobotContainer> RobotContainer::getInstance() {
  if (! self) {
    self = std::make_shared<RobotContainer>();
  }
  return self;
}

RobotContainer::RobotContainer() : 
driver(0),
dA(0,1),
dB(0,2),
dX(0,3),
dY(0,4),
m_autonomousCommand(&m_subsystem),
mConveyor(),
mIntake()
{
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  dA.WhenPressed(new TankDrive());
  // Configure your button bindings here

  frc::SmartDashboard::PutData("Conveyor On", new ConveyerOn(&mConveyor));
  frc::SmartDashboard::PutData("Intake On", new IntakeOn(&mIntake));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}

double RobotContainer::getDriverLeftYAxis() {
  return driver.GetRawAxis(0);
}