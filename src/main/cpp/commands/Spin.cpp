/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Spin.h"

Spin::Spin(DooHickey& DooHickey
          ,double speed)
: mDooHickey(DooHickey), mSpeed(speed) 
{
  SetName("Spin");
  AddRequirements(&mDooHickey);
}

// Called just before this Command runs the first time
void Spin::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Spin::Execute() 
{
  mDooHickey.MoveSpinner(mSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool Spin::IsFinished() { return false; }

// Called once after isFinished returns true
void Spin::End(bool interrupted) 
{
  mDooHickey.MoveSpinner(0.0);
}
