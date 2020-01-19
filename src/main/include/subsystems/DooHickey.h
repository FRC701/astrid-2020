/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>
#include <frc2/command/SubsystemBase.h>
#include <chrono>
#include <fstream>
#include <frc2/command/button/JoystickButton.h>
#include <frc/util/color.h>
#include <frc/WPILib.h>
#include "ctre/Phoenix.h"
#include <frc/DoubleSolenoid.h>
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"
#include <frc/smartdashboard/SmartDashboard.h>

class DooHickey : public frc2::SubsystemBase {

 using time_point = std::chrono::time_point<std::chrono::system_clock>;
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
  using WPI_TalonFX = ctre::phoenix::motorcontrol::can::WPI_TalonFX;
  
  DooHickey(const wpi::Twine& name
        ,WPI_TalonFX& spinner
        ,frc::DoubleSolenoid& UpPushyThang);

  void Init();
  void Periodic();
  void SetUpMotionMagic();
  void SetHickeySpeed();
  void SetHickeyPosition(double position);
  void PushThang();
  void RetractThang();
  void UpdateSpeed();
  void UpdatePos();
  void MoveSpinner(double speed);


 private:
 
  WPI_TalonFX& spinner;
  frc::DoubleSolenoid& UpPushyThang;

  std::ofstream mLogfile;
  time_point mPreviousTime;  
};
