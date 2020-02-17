/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetConveyor.h"
#include "commands/ConveyorInitialize.h"
#include "commands/ConveyorIn.h"
#include "commands/ConveyorSettle.h"
#include "commands/ConveyorSet.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
SetConveyor::SetConveyor(Conveyor& conveyor, double speed)
: mConveyor(conveyor)
, mSpeed(speed)
{
  AddCommands(
    ConveyorInitialize(mConveyor),
    ConveyorIn(mConveyor, mSpeed),
    ConveyorSettle(mConveyor, mSpeed),
    ConveyorSet(mConveyor, mSpeed)
  );
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
}
