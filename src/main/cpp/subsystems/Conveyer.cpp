/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Conveyer.h"

namespace
{
    constexpr double kConveyerPercentSpeed = 0.5;

constexpr int kForwardChannel = 1;
constexpr int kReverseChannel = 7;
}
Conveyer::Conveyer() :
IntakeRoller(2),
balls(0)
{}

// This method will be called once per scheduler run
void Conveyer::Periodic() {}

void Conveyer::SetConveyer() {
    IntakeRoller.Set(kConveyerPercentSpeed);
}
void Conveyer::StopConveyer(){
    IntakeRoller.Set(0);
}
bool Conveyer::GetConveyerBanner() {
  return IntakeRoller.GetSensorCollection().IsRevLimitSwitchClosed();

}
  bool Conveyer::GetIntakeBanner() {
  return IntakeRoller.GetSensorCollection().IsFwdLimitSwitchClosed();
}

int Conveyer::BallPlus() {
    return balls++;
}

int Conveyer::BallMinus() {
    return balls--;
}
