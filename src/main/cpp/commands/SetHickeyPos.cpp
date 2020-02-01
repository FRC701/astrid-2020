/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetHickeyPos.h"

SetHickeyPos::SetHickeyPos(DooHickey& dooHickey, double position) : mDooHickey(dooHickey), mPosition(position) {
  SetName("SetHickeyPos");
  AddRequirements(&mDooHickey);
  std::cout << "Spin::Spin" << std::endl;

}

// Called when the command is initially scheduled.
void SetHickeyPos::Initialize() {
    mDooHickey.SetHickeyPosition(mPosition);

}