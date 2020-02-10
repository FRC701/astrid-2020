/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include "commands/RotateHickey.h"
#include "commands/HickeyEngage.h"
#include "commands/HickeyDisengage.h"
#include "commands/SetHickeyPos.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
RotateHickey::RotateHickey(DooHickey& DooHickey)
:mDooHickey(DooHickey)
 {
  constexpr double kNumberOfRotations{4};
  constexpr double kTicksPerRotation{2048};
  constexpr double radiusCW{16}; //16" radius of Control panel 
  constexpr double radiusDW{1.5};  //1.5" radius of DooHickey wheel (3" diameter)
  constexpr double TargetPos = (kNumberOfRotations*(radiusCW/radiusDW)) * kTicksPerRotation; 
  units::second_t duration{3};

  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(HickeyEngage(mDooHickey), frc2::WaitCommand(duration), SetHickeyPos(mDooHickey, TargetPos), HickeyDisengage(mDooHickey));


}
