/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/HickeyPosControl.h"

HickeyPosControl::HickeyPosControl(DooHickey& DooHickey
  ,DooHickey::stoppingColor stopHere
  ,double speed)
: mDooHickey(DooHickey), mStopHere(stopHere), mSpeed(speed) 
{
  SetName("HickeyPosControl");
  AddRequirements(&mDooHickey);
}

// Called when the command is initially scheduled.
void HickeyPosControl::Initialize() {
  mStopHere = mDooHickey.StopHereColor();
}

// Called repeatedly when this Command is scheduled to run
void HickeyPosControl::Execute() {
  mDooHickey.MoveSpinner(mSpeed * mStopHere.direction);
}

// Called once the command ends or is interrupted.
void HickeyPosControl::End(bool interrupted) {
  mDooHickey.MoveSpinner(0.0);
}

// Returns true when the command should end.
bool HickeyPosControl::IsFinished() {
 return mDooHickey.MatchedColor() == mStopHere.Color;
}
