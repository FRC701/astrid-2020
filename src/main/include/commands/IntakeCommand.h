/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelRaceGroup.h>
#include "subsystems/Conveyor.h"
#include "subsystems/Intake.h"
#include "subsystems/Chassis.h"

class IntakeCommand
    : public frc2::CommandHelper<frc2::ParallelRaceGroup,
                                 IntakeCommand> {
 public:
  IntakeCommand(Intake& intake, Conveyor& conveyor, Chassis& chassis);
 private:
  Intake& mIntake;
  Conveyor& mConveyor;
  Chassis& mChassis;
};
