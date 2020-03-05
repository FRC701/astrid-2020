/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoTrenchRun.h"
#include <commands/AutoTrenchReverse.h>
#include <commands/EnableShoot.h>
#include <commands/AutoTrenchPickUpBalls.h>

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
AutoTrenchRun::AutoTrenchRun(Chassis& chassis, Conveyor& conveyor, Intake& intake, Shooter& shooter) {
  // Add your commands here, e.g.
  AddCommands(EnableShoot(chassis, conveyor, shooter), AutoTrenchPickUpBalls(chassis, conveyor, intake),
              AutoTrenchReverse(chassis), EnableShoot(chassis, conveyor, shooter));
}
