/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/HickeyOn.h"

HickeyOn::HickeyOn(DooHickey& dooHickey)
: mDooHickey{dooHickey}
{
  AddRequirements(&mDooHickey);
}


// Called when the command is initially scheduled.
void HickeyOn::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void HickeyOn::Execute() 
{
  mDooHickey.RetractThang();
}

// Called once the command ends or is interrupted.
void HickeyOn::End(bool interrupted) 
{
  mDooHickey.PushThang();
}

// Returns true when the command should end.
bool HickeyOn::IsFinished() { return false; }
