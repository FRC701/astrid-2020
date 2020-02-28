/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/WinchHook.h"

namespace {

double inchesToRotations(double inches)
{
  return inches * 70 / (2 * M_PI) / 12;
}

double inchesToTicks(double inches)
{
  return inchesToRotations(inches) * 2048;
}

}

WinchHook::WinchHook(Winch& winch, double positionInches)
: mWinch(winch), mWinchMotor(inchesToTicks(positionInches))
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(&mWinch);
}

// Called when the command is initially scheduled.
void WinchHook::Initialize() {
  mWinch.ResetWinchPosition();
}

// Called repeatedly when this Command is scheduled to run
void WinchHook::Execute() 
{
  mWinch.WinchHookPercentDual(
      (mWinch.WinchHookLeftPosition() > mWinchMotor ? 0.0 : 0.80),
      (mWinch.WinchHookRightPosition() > mWinchMotor ? 0.0 : 0.80));
}

// Called once the command ends or is interrupted.
void WinchHook::End(bool interrupted) 
{
    mWinch.WinchHookPercent(0);
}

// Returns true when the command should end.
bool WinchHook::IsFinished()
{
  return (mWinch.WinchHookLeftPosition() > mWinchMotor 
       && mWinch.WinchHookRightPosition() > mWinchMotor);
}
