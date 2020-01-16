/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/FlyWheelPID.h"

FlyWheelPID::FlyWheelPID()
    : PIDSubsystem(
          // The PIDController used by the subsystem
          frc2::PIDController(0, 0, 0)),
          leftShooter(0),
          rightShooter(1) {
            leftShooter.SetInverted(false);
            rightShooter.SetInverted(true);
            rightShooter.Follow(leftShooter);
          }

void FlyWheelPID::UseOutput(double output, double setpoint) {
  leftShooter.Set(output);
  // Use the output here
}

double FlyWheelPID::GetMeasurement() {
  // Return the process variable measurement here
  return 0;
}
