/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/IntakeOn.h"

constexpr double driveRatio {8 / 84};
constexpr double driveToIntakeRatio {3};
constexpr double conversionFactor {driveRatio * driveToIntakeRatio};

IntakeOn::IntakeOn(Intake& intake, Chassis& chassis, double speed)
: mSpeed{speed}
, mIntake{intake}
, mChassis{chassis}
{
  AddRequirements(&mIntake);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void IntakeOn::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void IntakeOn::Execute()
{
  double averageDrive = (mChassis.GetLeftVelocity() + mChassis.GetRightVelocity()) / 2;
  double velocity = averageDrive * conversionFactor + mSpeed;
  mIntake.SetIntake(velocity*2);
}

// Called once the command ends or is interrupted.
void IntakeOn::End(bool interrupted)
{
  mIntake.SetIntake(0);
  mIntake.IntakeDisengage();
}

// Returns true when the command should end.
bool IntakeOn::IsFinished() { return false; }
