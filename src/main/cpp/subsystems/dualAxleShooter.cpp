/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/dualAxleShooter.h"


std::shared_ptr<dualAxleShooter> dualAxleShooter::self;

std::shared_ptr<dualAxleShooter> dualAxleShooter::getInstance() {
  if (! self) {
    self = std::shared_ptr<dualAxleShooter>(new dualAxleShooter);
  }
  return self;
}

dualAxleShooter::dualAxleShooter() :
shooter1(0),
shooter2(1)
{}

double dualAxleShooter::shoot(double speed){
    shooter1.Set(1.0);
    shooter2.Set(1.0);
    return speed;
}

// This method will be called once per scheduler run
void dualAxleShooter::Periodic() {}
