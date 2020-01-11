/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Climber.h"
#include "frc/DoubleSolenoid.h"

constexpr frc::DoubleSolenoid::Value kClimberEngage {frc::DoubleSolenoid::kForward};
constexpr frc::DoubleSolenoid::Value kClimberDisengage {frc::DoubleSolenoid::kReverse};

Climber::Climber() :
ClimberMotor(0),
climberSolenoid(0, 7)
{}

// This method will be called once per scheduler run
void Climber::Periodic() {}

void Climber::Engage() {
  climberSolenoid.Set(kClimberEngage);
}

void Climber::Disengage() {
  climberSolenoid.Set(kClimberDisengage);
}
