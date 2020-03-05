/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AimPID.h"

namespace 
{
  constexpr double kMaxTargetOffset = 25;
  constexpr double kPScale = 1.0/2.0;
  constexpr double kP = (1.0 * kPScale)/kMaxTargetOffset;
  constexpr double kI = 0.0;
  constexpr double kD = 0.0;

  constexpr int kTargetCountMax = 25; // 50 is one second

  using Super = frc2::PIDCommand;
}

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
AimPID::AimPID(Chassis& chassis)
    : CommandHelper(frc2::PIDController(kP, kI, kD),
                    // This should return the measurement
                    [this] { return mChassis.TargetOffset(); },
                    // This should return the setpoint (can also be a constant)
                    [] { return 0; },
                    // This uses the output
                    [this](double rotation) { mChassis.ArcadeDrive(0.0, rotation); })
    , mChassis{chassis}
    , mTargetCount{0}
{
  GetController().SetTolerance(1.0);
}

void AimPID::Initialize() 
{
  mChassis.SetVisionCam();
  mChassis.limeLightLightsOn();
  mTargetCount = 0;

  Super::Initialize();
}

// Returns true when the command should end.
bool AimPID::IsFinished()
{
  if (GetController().AtSetpoint())
  {
    return ++mTargetCount >= kTargetCountMax;
  }
  else
  {
    mTargetCount = 0;
    return false;
  }
}

void AimPID::End(bool interrupted)
{
  Super::End(interrupted); 

  mChassis.limeLightLightsOff();
  mChassis.SetDriverCam();
}
