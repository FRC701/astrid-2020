/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShootBalls.h"
#include "commands/Shoot.h"
#include "commands/SetConveyorShoot.h"
#include "commands/StowHood.h"
#include "commands/StopShooting.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
ShootBalls::ShootBalls(Shooter& shooter, Conveyor& conveyor, double shooterRPM) {
  // Add your commands here, e.g.
  AddCommands(Shoot(shooter, shooterRPM), SetConveyorShoot(conveyor, .65), StowHood(shooter), StopShooting(shooter));
}
