/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/StopShooting.h"

StopShooting::StopShooting(Shooter& mShooter)
: mShooter(mShooter)
{
  AddRequirements(&mShooter);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void StopShooting::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void StopShooting::Execute() 
{
  mShooter.IdleShoot();
}

// Called once the command ends or is interrupted.
void StopShooting::End(bool interrupted) {}

// Returns true when the command should end.
bool StopShooting::IsFinished() { return true; }
