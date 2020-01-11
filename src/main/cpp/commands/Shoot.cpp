/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Shoot.h"

Shoot::Shoot(HoodedFlyWheel* hoodedFlyWheel) : m_hoodedFlyWheel(hoodedFlyWheel) {
  SetName("Shoot");// Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_hoodedFlyWheel});
  std::cout << "Shoot::Shoot" << std::endl;
}

Shoot::~Shoot() {
  std::cout << "die die die::Shoot" << std::endl;
}

// Called when the command is initially scheduled.
void Shoot::Initialize() {
  std::cout << "Shoot::Initialize" << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
  std::cout << "Shoot::Execute" << std::endl;

  m_hoodedFlyWheel->BangBangMode(0.8);
}

// Called once the command ends or is interrupted.
void Shoot::End(bool interrupted) {
  std::cout << "Shoot::End" << std::endl;
}

// Returns true when the command should end.
bool Shoot::IsFinished() {
  std::cout << "Shoot::IsFinished" << std::endl;
  return false; 
}
