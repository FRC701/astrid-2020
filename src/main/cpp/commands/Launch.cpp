/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Launch.h"

Launch::Launch() {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void Launch::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Launch::Execute() {
  dualAxleShooter::getInstance()->shoot(1.0);
}

// Called once the command ends or is interrupted.
void Launch::End(bool interrupted) {}

// Returns true when the command should end.
bool Launch::IsFinished() { return false; }
