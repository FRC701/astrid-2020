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
, mCounter(0)
{
  AddRequirements(&mShooter);
}

// Called when the command is initially scheduled.
void Shoot::Initialize() 
{
  mShooter.ResetRange();
  mCounter = 0;
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() 
{
  double target1 = mShooter.GetTargetDistance();
  double target2 = mShooter.GetTargetDistance();
  double target3 = mShooter.GetTargetDistance();
  double target4 = mShooter.GetTargetDistance();
  double target5 = mShooter.GetTargetDistance();
  double target6 = mShooter.GetTargetDistance();
  double target7 = mShooter.GetTargetDistance();
  double target8 = mShooter.GetTargetDistance();
  double target9 = mShooter.GetTargetDistance();
  double target10 = mShooter.GetTargetDistance();
  double target = (target1 + target2 + target3 + target4 + target5 + target6 + target7 + target8 + target9 + target10) / 10;
  //double avgTarget = (target + mShooter.GetTargetDistance()) / 2;
  //mCounter++;
  double motorSpeed = 14080 - (1052 * target) + (30.1 * target * target) - (0.288 * target * target * target);
  mShooter.Shoot(motorSpeed);
  mCounter = 0;
}

// Called once the command ends or is interrupted.
void Shoot::End(bool interrupted)
{}

// Returns true when the command should end.
bool Shoot::IsFinished() 
{
  return mShooter.IsInRange();
}
