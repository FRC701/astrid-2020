/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShooterCloseShot.h"

ShooterCloseShot::ShooterCloseShot(Shooter& shooter)
: mShooter{shooter}
{
  SetName("ShooterCloseShot");
  AddRequirements(&mShooter);
  std::cout << "ShooterCloseShot::ShooterCloseShot" << std::endl; 
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ShooterCloseShot::Initialize() 
{
  mShooter.EngageLatch();
  mShooter.PushHood();
  mShooter.Shoot(.20);
}

// Called repeatedly when this Command is scheduled to run
void ShooterCloseShot::Execute() {}

// Called once the command ends or is interrupted.
void ShooterCloseShot::End(bool interrupted) {}

// Returns true when the command should end.
bool ShooterCloseShot::IsFinished() { return false; }
