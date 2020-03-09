/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/IntakeGuard.h"

IntakeGuard::IntakeGuard(Intake& intake, double speed)
: mIntake{intake}
, mSpeed(speed)
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(&mIntake);
}



// Called when the command is initially scheduled.
void IntakeGuard::Initialize() 
{
  mIntake.IntakeEngage();
}

// Called repeatedly when this Command is scheduled to run
void IntakeGuard::Execute() 
{
  mIntake.SetIntake(mSpeed);
}

// Called once the command ends or is interrupted.
void IntakeGuard::End(bool interrupted) 
{
  mIntake.SetIntake(0.0);
  mIntake.IntakeDisengage();
}

// Returns true when the command should end.
bool IntakeGuard::IsFinished() { return false; }
