/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/HoodRetract.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
HoodRetract::HoodRetract() {
  SetName("HoodRetract");
  AddRequirements(mShooter);
  std::cout << "HoodRetract::HoodRetract"  << std::endl;
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void HoodRetract::Initialize() 
{
  mShooter->RetractHood();
}
