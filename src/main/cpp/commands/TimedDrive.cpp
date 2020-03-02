/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TimedDrive.h"

TimedDrive::TimedDrive(Chassis& chassis, int counts)
: mChassis(chassis)
, mCount(counts)
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(&mChassis);
}

// Called when the command is initially scheduled.
void TimedDrive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TimedDrive::Execute() {
  mChassis.TankDrive(0.5, 0.5);
}

// Called once the command ends or is interrupted.
void TimedDrive::End(bool interrupted) {
  mChassis.TankDrive(0.0, 0.0);  
}

// Returns true when the command should end.
bool TimedDrive::IsFinished() {
  mCount--;
  return mCount <= 0;
}
