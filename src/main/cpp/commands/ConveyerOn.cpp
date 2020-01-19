/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ConveyerOn.h"

ConveyerOn::ConveyerOn(Conveyer* conveyer) : mConveyer(conveyer) {
  AddRequirements(mConveyer);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ConveyerOn::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ConveyerOn::Execute() {
  mConveyer->SetConveyer();
}

// Called once the command ends or is interrupted.
void ConveyerOn::End(bool interrupted) {
  mConveyer->StopConveyer();
}

// Returns true when the command should end.
bool ConveyerOn::IsFinished() { return false; }
