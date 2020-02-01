/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/WinchHook.h"


WinchHook::WinchHook(Winch& winch, double percentoutput)
: mWinch(winch), mWinchMotor(percentoutput)
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(&mWinch);
}

// Called when the command is initially scheduled.
void WinchHook::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void WinchHook::Execute() 
{
  mWinch.WinchHook->Set();
}

// Called once the command ends or is interrupted.
void WinchHook::End(bool interrupted) {}

// Returns true when the command should end.
bool WinchHook::IsFinished() { return false; }
