/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <commands/ShooterFarShot.h>

ShooterFarShot::ShooterFarShot(Shooter& shooter)
: mShooter{shooter} 
{
  SetName("ShooterFarShot");
  AddRequirements(&mShooter);
  std::cout << "ShooterFarShot::ShooterFarShot" << std::endl; 
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ShooterFarShot::Initialize() 
{

}

// Called repeatedly when this Command is scheduled to run
void ShooterFarShot::Execute() 
{
  mShooter.DisengageLatch();
  mShooter.PushHood();
  mShooter.Shoot(1.0);
}

// Called once the command ends or is interrupted.
void ShooterFarShot::End(bool interrupted) 
{
  mShooter.Shoot(0.0);
}

// Returns true when the command should end.
bool ShooterFarShot::IsFinished() { return false; }
