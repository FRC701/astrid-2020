/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Shoot.h"

Shoot::Shoot(Shooter& mShooter,  double speed)
: mshooter1(mshooter1)
, mshooter2(mshooter2)
, mShooter(mShooter)
, mSpeed(speed)
{
  AddRequirements(&mShooter);
}

// Called when the command is initially scheduled.
void Shoot::Initialize() 
{

}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() 
{
  mShooter.Shoot(mSpeed);
}

// Called once the command ends or is interrupted.
void Shoot::End(bool interrupted) 
{
  mShooter.Shoot(0.0);
}

// Returns true when the command should end.
bool Shoot::IsFinished() 
{ 
  return false; 
}
