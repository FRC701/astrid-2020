/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Shoot.h"
#include "subsystems/HoodedFlyWheel.h"

Shoot::Shoot() {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(HoodedFlyWheel::getInstance().get());
}

// Called when the command is initially scheduled.
void Shoot::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
  HoodedFlyWheel::getInstance()->BangBangMode(0.8);
}

// Called once the command ends or is interrupted.
void Shoot::End(bool interrupted) {}

// Returns true when the command should end.
bool Shoot::IsFinished() { return false; }
