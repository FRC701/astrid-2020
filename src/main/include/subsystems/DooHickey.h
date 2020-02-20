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
#include <cmath>


class DooHickey : public frc2::SubsystemBase {
  
public:
  using WPI_TalonSRX = ctre::phoenix::motorcontrol::can::WPI_TalonSRX;
  using ControlMode = ctre::phoenix::motorcontrol::ControlMode;
  using StatusFrameEnhanced = ctre::phoenix::motorcontrol::StatusFrameEnhanced;

  static constexpr auto i2cPort = frc::I2C::Port::kOnboard;

  rev::ColorSensorV3 m_colorSensor{i2cPort};
  rev::ColorMatch m_colorMatcher;

  std::string gameData;
  std::string colorString;
  std::string assignedColorString;
  
  double confidence = 0.0;
  int colorCounter = 0;

  static constexpr frc::Color kBlueTarget = frc::Color(0.143, 0.427, 0.429);
  static constexpr frc::Color kGreenTarget = frc::Color(0.197, 0.561, 0.240);
  static constexpr frc::Color kRedTarget = frc::Color(0.561, 0.232, 0.114);
  static constexpr frc::Color kYellowTarget = frc::Color(0.361, 0.524, 0.113);

  bool IsRotationControlFinished = false;
  struct Components
    {
      WPI_TalonSRX spinner;
      frc::DoubleSolenoid UpPushyThang;
    }; 
    
  struct stoppingColor  
    {
      int direction;
      frc::Color Color;
    };
    
  struct colorstuff 
    {
      frc::Color viewing;
      frc::Color assigned;
      stoppingColor stopHere;
    };
  
  DooHickey(const wpi::Twine& name, Components& components);

  void Init();
  void Periodic();
  void SetUpMotionMagic();
  void SetHickeySpeed();
  void SetHickeyPosition(double position);
  void PushThang();
  void RetractThang();
  void UpdateSpeed(double pos);
  void UpdatePos(double speed);
  void MoveSpinner(double speed);
  bool IsInRange() const;
  frc::Color MatchedColor();
  frc::Color AssignedColor();
  stoppingColor StopHereColor();

 private:
   int mutable mWithinThresholdLoops = {0};
   Components& mComponents; 

  frc::Color mMatchedColor = kGreenTarget;
  frc::Color mAssignedColor = kGreenTarget;
};
