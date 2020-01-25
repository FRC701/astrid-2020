/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TelescopeRise.h"

TelescopeRise::TelescopeRise(double speed,
                              Telescope& telescope)
: mSpeed(speed), mTelescope(telescope) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(&mTelescope);
}

// Called when the command is initially scheduled.
void TelescopeRise::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TelescopeRise::Execute() 
{
  mTelescope.TelescopeRise(mSpeed);
}

// Called once the command ends or is interrupted.
void TelescopeRise::End(bool interrupted) {}

// Returns true when the command should end.
bool TelescopeRise::IsFinished() { return false; }
