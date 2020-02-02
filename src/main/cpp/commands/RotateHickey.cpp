/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/RotateHickey.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
RotateHickey::RotateHickey(DooHickey& dooHickey)
: mDooHickey(dooHickey) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  //TODO: Look at the sensors to know if the UpPushyThang is Engaged or Disengaged instead of wait.

  constexpr double radiusCW = 16; //16" radius of Control panel 
  constexpr double radiusDW = 1.5;  //1.5" radius of DooHickey wheel (3" diameter)
  constexpr double TargetPos = (4*(radiusCW/radiusDW)) * 2048; 
  constexpr units::second_t duration {3};

  AddCommands(HickeyEngage(mDooHickey)
              ,frc2::WaitCommand(duration)
              ,SetHickeyPos(mDooHickey, TargetPos)
              ,HickeyDisengage(mDooHickey)
              );
  
}
