/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/DooHickey.h"

class SetHickeyPos
    : public frc2::CommandHelper<frc2::CommandBase, SetHickeyPos> {
 public:
 
  SetHickeyPos(DooHickey& dooHickey, double position);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;
  void Interrupted();

 private:
  DooHickey& mDooHickey;
   double mPosition;
};
