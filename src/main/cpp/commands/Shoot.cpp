/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Shoot.h"

Shoot::Shoot(Shooter& mShooter,  double speed)
: mShooter(mShooter)
, mSpeed(speed)
{
  AddRequirements(&mShooter);
}

// Called when the command is initially scheduled.
void Shoot::Initialize() 
{
  mShooter.ResetRange();
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() 
{
  //double distanceConstant;
  //double motorSpeed = mShooter.GetTargetDistance() * distanceConstant;
  mShooter.Shoot(mSpeed);
}

// Called once the command ends or is interrupted.
void Shoot::End(bool interrupted) 
{}

// Returns true when the command should end.
bool Shoot::IsFinished() 
{
  return mShooter.IsInRange();
}
