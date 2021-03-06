/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Intake.h"
#include <frc/smartdashboard/SmartDashboard.h>

namespace{
    constexpr frc::DoubleSolenoid::Value kIntakeEngage {frc::DoubleSolenoid::kForward};
    constexpr frc::DoubleSolenoid::Value kIntakeDisengage {frc::DoubleSolenoid::kReverse};
}

Intake::Intake(
    const wpi::Twine& name,
    WPI_TalonFX& roller
   ,frc::DoubleSolenoid& IntakePiston)
: mRoller{roller}
, mIntakePiston{IntakePiston}
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

double Intake::GetVelocity()
{
    return mRoller.GetSelectedSensorVelocity();
}

void Intake::IntakeEngage()
{
    mIntakePiston.Set(kIntakeEngage);
}

void Intake::IntakeDisengage()
{
    mIntakePiston.Set(kIntakeDisengage);
}