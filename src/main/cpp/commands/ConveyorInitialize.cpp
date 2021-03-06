/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ConveyorInitialize.h"
#include "commands/EndIntake.h"

ConveyorInitialize::ConveyorInitialize(Conveyor& conveyor)
: mConveyor{conveyor}
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(&mConveyor);
}

// Called when the command is initially scheduled.
void ConveyorInitialize::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ConveyorInitialize::Execute() 
{
    mConveyor.SetConveyor(0.0);
}

// Called once the command ends or is interrupted.
void ConveyorInitialize::End(bool interrupted)
{
}

// Returns true when the command should end.
bool ConveyorInitialize::IsFinished()
{
    return mConveyor.IsBallComing();
}