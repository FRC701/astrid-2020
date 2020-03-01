/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShootShort.h"

ShootShort::ShootShort(Shooter& shooter)
: mShooter(shooter)
{
  AddRequirements(&mShooter);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ShootShort::Initialize()
{
  mShooter.ResetRange();
}


// Called repeatedly when this Command is scheduled to run
void ShootShort::Execute()
{
  mShooter.Shoot(1400);
}

// Called once the command ends or is interrupted.
void ShootShort::End(bool interrupted) {}

// Returns true when the command should end.
bool ShootShort::IsFinished()
{
  return mShooter.IsInRange();
}
