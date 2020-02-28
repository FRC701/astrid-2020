/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Winch.h"

namespace {

//change the number for velocity error; shouldn't be as large
constexpr double kP{(.05*1023)};
constexpr double kI{0.0};
constexpr double kD{0.0};
constexpr double kF{0.0};

constexpr double kTicksPerRotation {2048};
constexpr double kHundredMillisPerSecond {10};
constexpr double kSecondsPerMin {60};

constexpr double ticksToRPM(double ticks)
{
  double rpm = (ticks / kTicksPerRotation) * kHundredMillisPerSecond * kSecondsPerMin;
  return rpm;
}

double inchesToRotations(double inches)
{
  return inches * 70 / (2 * M_PI) / 12;
}

double inchesToTicks(double inches)
{
  return inchesToRotations(inches) * kTicksPerRotation;
}

double ticksToInches(double ticks)
{
    return 1.0 / inchesToTicks(ticks);
}

void SetPID(Winch::Components& components)
{
    components.left.Config_kP(0, kP, 10);
    components.left.Config_kI(0, kI, 10);
    components.left.Config_kD(0, kD, 10);
    components.left.Config_kF(0, kF, 10);    
    components.right.Config_kP(0, kP, 10);
    components.right.Config_kI(0, kI, 10);
    components.right.Config_kD(0, kD, 10);
    components.right.Config_kF(0, kF, 10);
}

}

Winch::Winch(const wpi::Twine& name,
            Components& components)
: mComponents{components}
, mMotors{components.left, components.right}
{
    SetName(name);
    SetPID(mComponents);
}
void Winch::ResetWinchPosition()
{
    mComponents.left.SetSelectedSensorPosition(0);
    mComponents.right.SetSelectedSensorPosition(0);
}

double Winch::WinchHookLeftRPM()
{
    double WinchHookSpeed = mComponents.left.GetSelectedSensorVelocity();
    double RPMMotorLeft = ticksToRPM(WinchHookSpeed);
    return RPMMotorLeft;
}

double Winch::WinchHookRightRPM()
{
    double WinchHookSpeed = mComponents.right.GetSelectedSensorVelocity();
    double RPMMotorRight = ticksToRPM(WinchHookSpeed);
    return RPMMotorRight;
}

double Winch::WinchHookLeftPosition()
{
    double winchHookPosition = mComponents.left.GetSelectedSensorPosition();
    double inches = ticksToInches(winchHookPosition);
    return winchHookPosition;
}

double Winch::WinchHookRightPosition()
{
    double winchHookPosition = mComponents.right.GetSelectedSensorPosition();
    double inches = ticksToInches(winchHookPosition);
    return winchHookPosition;
}

double Winch::LeftVoltage()
{
    return mComponents.left.GetMotorOutputVoltage();
}

double Winch::RightVoltage()
{
    return mComponents.right.GetMotorOutputVoltage();
}

// This method will be called once per scheduler run
void Winch::Periodic() 
{
    frc::SmartDashboard::PutNumber("Winch Hook Left Motor RPM", WinchHookLeftRPM());
    frc::SmartDashboard::PutNumber("Winch Hook Right Motor RPM", WinchHookRightRPM());
    frc::SmartDashboard::PutNumber("Winch Hook Left Motor Position", WinchHookLeftPosition());
    frc::SmartDashboard::PutNumber("Winch Hook Right Motor Position", WinchHookRightPosition());
    frc::SmartDashboard::PutNumber("Winch Hook Left Motor Voltage", LeftVoltage());
    frc::SmartDashboard::PutNumber("Winch Hook Right Motor Voltage", RightVoltage());
}

void Winch::WinchHook(double position)
{
    using ControlMode = ctre::phoenix::motorcontrol::ControlMode;
    mComponents.left.Set(ControlMode::Position, position);
    mComponents.right.Set(ControlMode::Position, position);
}

void Winch::WinchHookPercent(double percentOutput)
{
    mMotors.Set(percentOutput);
}

void Winch::WinchHookPercentDual(double leftPercentOutput, double rightPercentOutput)
{
    mComponents.left.Set(leftPercentOutput);
    mComponents.right.Set(rightPercentOutput);
}

