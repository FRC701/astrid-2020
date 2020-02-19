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
  if(mChassis.TargetOffset() > -10.0 && mChassis.TargetOffset() < 10.0)
  {
    if(mChassis.TargetOffset() < -1.0)
    {
      mChassis.ArcadeDrive(0, 0.348);
    }
    if(mChassis.TargetOffset() > 1.0)
    {
      mChassis.ArcadeDrive(0, -0.348);
    }
  }
  else
  {
    double pCoefficient {-25};
    double rotation = mChassis.TargetOffset() / pCoefficient;
    mChassis.ArcadeDrive(0, rotation);
  }  
}

// Called once the command ends or is interrupted.
void Aim::End(bool interrupted) {}

// Returns true when the command should end.
bool Aim::IsFinished()
{
  if(mCounter <= 30)
  {
    if(mChassis.TargetOffset() < 1 && mChassis.TargetOffset() > -1)
    {
      mCounter++;
    }
  }
  if(mCounter > 30)
  {
    return mChassis.TargetOffset() < 1 && mChassis.TargetOffset() > -1;
  }
  else
  {
    return false;
  }
  
}
