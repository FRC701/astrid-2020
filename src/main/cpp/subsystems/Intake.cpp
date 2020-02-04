/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Intake.h"

Intake::Intake(
    const wpi::Twine& name,
    WPI_TalonFX& roller,
    frc::DoubleSolenoid intakeEngagement)
: mRoller{roller},
, mIntakeEngagement(intakeEngagement)
{
    SetName(name);
}

// This method will be called once per scheduler run
void Intake::Periodic()
{
    
}

void Intake::SetIntake(double speed)
{
    mRoller.Set(speed);
}
void Intake::Engage()
{
    mIntakeEngagement.Set(frc::DoubleSolenoid::kForward);
}

void Intake::Disengage()
{
    mIntakeEngagement.Set(frc::DoubleSolenoid::kReverse);
}