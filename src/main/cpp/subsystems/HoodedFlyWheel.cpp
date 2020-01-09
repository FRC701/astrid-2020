/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/HoodedFlyWheel.h"

const char HoodedFlyWheel::kSubsystemName[] = "HoodedFlyWheel";

std::shared_ptr<HoodedFlyWheel> HoodedFlyWheel::self;

std::shared_ptr<HoodedFlyWheel> HoodedFlyWheel::getInstance() {
  if (! self) {
     self = std::shared_ptr<HoodedFlyWheel>(new HoodedFlyWheel);
  }
  return self;
}

HoodedFlyWheel::HoodedFlyWheel()
: flyWheel(0)
{}

// This method will be called once per scheduler run
void HoodedFlyWheel::Periodic() {}

double HoodedFlyWheel::BangBangMode(double speedRPM) {
    double wheelSpeedTP100ms = flyWheel.GetSelectedSensorVelocity();
    double setSpeedTP100ms = speedRPM * 2048 * 60 * 10;
    double bangState = wheelSpeedTP100ms < setSpeedTP100ms ? 1.0 : 0.0;
    flyWheel.Set(bangState);
    return wheelSpeedTP100ms;
}
