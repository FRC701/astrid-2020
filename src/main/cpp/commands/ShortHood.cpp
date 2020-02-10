/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShortHood.h"
#include "commands/LatchDisengage.h"
#include "commands/HoodOutFull.h"
#include <frc2/command/WaitCommand.h>

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
ShortHood::ShortHood(Shooter& shooter) {
  // Add your commands here, e.g.
  constexpr units::second_t kWaitLatch{.10};
  AddCommands(LatchDisengage(shooter), frc2::WaitCommand(kWaitLatch), HoodOutFull(shooter) );
}
