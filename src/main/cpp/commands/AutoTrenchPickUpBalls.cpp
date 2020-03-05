/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoTrenchPickUpBalls.h"
#include <commands/AutoTrench.h>
#include <commands/EnableIntake.h>


// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
AutoTrenchPickUpBalls::AutoTrenchPickUpBalls(Chassis& chassis, Conveyor& conveyor, Intake& intake) {
  // Add your commands here, e.g.
  AddCommands(AutoTrench(chassis), EnableIntake(intake, conveyor, chassis));
}
