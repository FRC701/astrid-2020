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
  frc::SmartDashboard::PutData(&mDualAxleShooter);
  frc::SmartDashboard::PutData("Launch 10%", new Launch(&mDualAxleShooter, 0.1));
  frc::SmartDashboard::PutData("Launch 20%", new Launch(&mDualAxleShooter, 0.2));
  frc::SmartDashboard::PutData("Launch 30%", new Launch(&mDualAxleShooter, 0.3));
  frc::SmartDashboard::PutData("Launch 40%", new Launch(&mDualAxleShooter, 0.4));
  frc::SmartDashboard::PutData("Launch 45%", new Launch(&mDualAxleShooter, 0.45));
  frc::SmartDashboard::PutData("Launch 50%", new Launch(&mDualAxleShooter, 0.5));
  frc::SmartDashboard::PutData("Launch 60%", new Launch(&mDualAxleShooter, 0.6));
  frc::SmartDashboard::PutData("Launch 70%", new Launch(&mDualAxleShooter, 0.7));
  frc::SmartDashboard::PutData("Launch 75%", new Launch(&mDualAxleShooter, 0.75));
  frc::SmartDashboard::PutData("Launch 80%", new Launch(&mDualAxleShooter, 0.8));
  frc::SmartDashboard::PutData("Launch 90%", new Launch(&mDualAxleShooter, 0.9));
  frc::SmartDashboard::PutData("Launch 100%", new Launch(&mDualAxleShooter, 1.0));
  frc::SmartDashboard::PutData("Launch 5%", new Launch(&mDualAxleShooter, .05));

  frc::SmartDashboard::PutData("Launch rpm", new Launch(&mDualAxleShooter, 4900));//6826 10240 20480 




//  frc::SmartDashboard::PutData("Shooter 10%", new shoot(0.1));

  ConfigureButtonBindings();
  
}

void RobotContainer::ConfigureButtonBindings() {

}

frc2::Command* RobotContainer::GetAutonomousCommand() {
    return &m_autonomousCommand;
}