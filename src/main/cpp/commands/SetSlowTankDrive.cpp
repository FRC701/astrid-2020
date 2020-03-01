/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetSlowTankDrive.h"

SetSlowTankDrive::SetSlowTankDrive(Chassis& chassis,
                                  std::function<double()> left,
                                  std::function<double()> right)
: mChassis(chassis), mLeft(left), mRight(right)
{
  AddRequirements(&mChassis);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void SetSlowTankDrive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SetSlowTankDrive::Execute() 
{
  mChassis.SlowTankDrive(mLeft(), mRight());
}

// Called once the command ends or is interrupted.
void SetSlowTankDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool SetSlowTankDrive::IsFinished() { return false; }
