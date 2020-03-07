/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Outtake.h"
#include "commands/IntakeEngage.h"
#include "commands/IntakeGuard.h"
#include "commands/ConveyorRun.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
Outtake::Outtake(Intake& intake, Conveyor& conveyor) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(IntakeEngage(intake), IntakeGuard(intake, -0.8), ConveyorRun(conveyor, -0.8));
}
