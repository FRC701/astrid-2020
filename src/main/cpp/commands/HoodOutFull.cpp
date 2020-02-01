/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/HoodOutFull.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
HoodOutFull::HoodOutFull(Shooter& shooter)
: mShooter(shooter)
 {
  SetName("HoodOutFull");
  AddRequirements(&mShooter);
  std::cout << "HoodOutFull::HoodOutFull" << std::endl;
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void HoodOutFull::Initialize() 
{
  mShooter.PushHood();
}

