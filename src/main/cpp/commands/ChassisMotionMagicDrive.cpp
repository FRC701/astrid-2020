/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ChassisMotionMagicDrive.h"

ChassisMotionMagicDrive::ChassisMotionMagicDrive(Chassis& chassis,
                                                  int leftPosition,
                                                  int rightPosition)
: mChassis(chassis)
, mLeftPosition(leftPosition)
, mRightPosition(rightPosition)
, mRangeCount(0)

{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(&mChassis);
}

// Called when the command is initially scheduled.
void ChassisMotionMagicDrive::Initialize() 
{
  mRangeCount = 0;
}

// Called repeatedly when this Command is scheduled to run
void ChassisMotionMagicDrive::Execute() 
{
  mChassis.SetMotionMagic(mLeftPosition, mRightPosition);
}

// Called once the command ends or is interrupted.
void ChassisMotionMagicDrive::End(bool interrupted) 
{
  mChassis.TankDrive(0, 0);
}

// Returns true when the command should end.
bool ChassisMotionMagicDrive::IsFinished() 
{ 
  constexpr int kRangeCountLimit = 10;
  
  if(mChassis.IsInRange())
  {
    mRangeCount++;
  }
  else
  {
    mRangeCount = 0;
  }

  return mRangeCount > kRangeCountLimit;
  
}
