/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Aim.h"

Aim::Aim(Chassis& chassis)
: mChassis(chassis)
, mCounter(0)
{
  AddRequirements(&mChassis);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void Aim::Initialize() 
{
  mChassis.SetVisionCam();
  mChassis.limeLightLightsOn();
  mCounter = 0;
}

// Called repeatedly when this Command is scheduled to run
void Aim::Execute() 
{
  double targetOffset = mChassis.TargetOffset();
  if(targetOffset > -10.0 && targetOffset < 10.0)
  {
    if(targetOffset < 2.0)
    {
      mChassis.ArcadeDrive(0.0, -0.36); //.36
    }
    if(targetOffset > 0.0)
    {
      mChassis.ArcadeDrive(0.0, 0.36);
    }
  }
  else
  {
    double pCoefficient {25.0};
    double rotation = (mChassis.TargetOffset()) / pCoefficient;
    mChassis.ArcadeDrive(0.0, rotation);
  }  
}

// Called once the command ends or is interrupted.
void Aim::End(bool interrupted) {}

// Returns true when the command should end.
bool Aim::IsFinished()
{
  double targetOffset = mChassis.TargetOffset();
  if(mCounter <= 30)
  {
    if(targetOffset < 2.0 && targetOffset > 0.0)
    {
      mCounter++;
    }
  }
  else if(mCounter > 30)
  {
    return targetOffset < 2.0 && targetOffset > 0.0;
  }
  else
  {
    return false;
  }
  
}
