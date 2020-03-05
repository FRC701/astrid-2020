/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/util/color.h>
#include <frc/DoubleSolenoid.h>
#include <frc/DriverStation.h>
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "ctre/phoenix/motorcontrol/ControlMode.h"
#include "ctre/phoenix/motorcontrol/StatusFrame.h"


class DooHickey : public frc2::SubsystemBase {

  static constexpr auto i2cPort = frc::I2C::Port::kOnboard;

  rev::ColorSensorV3 m_colorSensor{i2cPort};
  rev::ColorMatch m_colorMatcher;

  double mMotorSpeed;
  double mTargetPos; 

  static constexpr frc::Color kBlueTarget = frc::Color(0.143, 0.427, 0.429);
  static constexpr frc::Color kGreenTarget = frc::Color(0.197, 0.561, 0.240);
  static constexpr frc::Color kRedTarget = frc::Color(0.561, 0.232, 0.114);
  static constexpr frc::Color kYellowTarget = frc::Color(0.361, 0.524, 0.113);
  
public:
  using WPI_TalonSRX = ctre::phoenix::motorcontrol::can::WPI_TalonSRX;
  using ControlMode = ctre::phoenix::motorcontrol::ControlMode;
  using StatusFrameEnhanced = ctre::phoenix::motorcontrol::StatusFrameEnhanced;

  bool IsRotationControlFinished = false;
  
  DooHickey(const wpi::Twine& name
        ,WPI_TalonSRX& spinner
        ,frc::DoubleSolenoid& UpPushyThang);

  void Init();
  void Periodic();
  void SetUpMotionMagic();
  void SetHickeySpeed();
  void SetHickeyPosition(double position);
  void PushThang();
  void RetractThang();
  void UpdateSpeed(double speed);
  void UpdatePos(double pos);
  void MoveSpinner(double speed);


 private:
 
  WPI_TalonSRX& mSpinner;
  frc::DoubleSolenoid& mUpPushyThang;
  
};
