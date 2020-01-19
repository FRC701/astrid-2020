/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Intake.h"
#include "frc/smartdashboard/SmartDashboard.h"

namespace 
{

constexpr frc::DoubleSolenoid::Value kMotorEngage = frc::DoubleSolenoid::kForward;
constexpr frc::DoubleSolenoid::Value kMotorDisengage = frc::DoubleSolenoid::kReverse;

constexpr double kIntakePercentSpeed = 0.5;

constexpr int kForwardChannel = 0;
constexpr int kReverseChannel = 7;
}

Intake::Intake() :
IntakeMotor(1), IntakeGo(kForwardChannel, kReverseChannel)
{}
// This method will be called once per scheduler run
void Intake::Periodic() {
}

void Intake::SetIntake() {
    IntakeMotor.Set(kIntakePercentSpeed);
    
}

void Intake::StopIntake() {
  IntakeMotor.Set(0);
}