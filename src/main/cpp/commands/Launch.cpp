/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Launch.h"

Launch::Launch(dualAxleShooter* DualAxleShooter, double speed) : mDualAxleShooter(DualAxleShooter), mSpeed(speed) {


  SetName("Launch");
  AddRequirements({mDualAxleShooter});
  std::cout << "Launch::Launch" << std::endl;
}

// Called when the command is initially scheduled.
void Launch::Initialize() {
    std::cout << "Launch::Initialize" << std::endl;

}

// Called repeatedly when this Command is scheduled to run
void Launch::Execute() {

  std::cout << "Launch::Execute" << std::endl;

  mDualAxleShooter->shoot(mSpeed);
}

// Called once the command ends or is interrupted.
void Launch::End(bool interrupted) {
  mDualAxleShooter->IdleShoot();
  std::cout << "Launch::End" << std::endl;

}

// Returns true when the command should end.
bool Launch::IsFinished() {
  
  std::cout << "Launch::IsFinished" << std::endl;
  return false; 
  }
