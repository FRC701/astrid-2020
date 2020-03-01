/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "subsystems/Conveyor.h"
#include "subsystems/Intake.h"

class FullEndIntake
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 FullEndIntake> {
 public:
  FullEndIntake(Conveyor& conveyor, Intake& intake);
 private:
  Conveyor& mConveyor;
 private:
  Intake& mIntake;
};
