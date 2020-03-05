/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TimedDrive.h"

TimedDrive::TimedDrive(Chassis& chassis, double percent, int counts)
: mChassis(chassis)
, mPercent(percent)
, mCount(counts)
, mTime(counts)
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(&mChassis);
}

// Called when the command is initially scheduled.
void TimedDrive::Initialize() 
{
  mCount = mTime;
}

// Called repeatedly when this Command is scheduled to run
void TimedDrive::Execute() {
  mChassis.TankDrive(mPercent, mPercent);
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
