/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DooHickey.h"
#include <sstream>

namespace
{
  constexpr double kF{0.3};
  constexpr double kP{0.1};
  constexpr double kI{0.0};
  constexpr double kD{0.0};
  constexpr frc::DoubleSolenoid::Value kHickeyEngage {frc::DoubleSolenoid::kForward};
  constexpr frc::DoubleSolenoid::Value kHickeyDisengage {frc::DoubleSolenoid::kReverse};
}

DooHickey::DooHickey(
    const wpi::Twine& name,
    WPI_TalonFX& spinner,
    frc::DoubleSolenoid& UpPushyThang)
  :mMotorSpeed{0}
  ,mTargetPos{0}
  ,mSpinner(spinner)
  ,mUpPushyThang(UpPushyThang)
{
  SetName(name);
  SetUpMotionMagic();
}

void DooHickey::SetUpMotionMagic() {

    /* Set relevant frame periods to be at least as fast as periodic rate */
    mSpinner.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, 10);
    mSpinner.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, 10);

     /* Set the peak and nominal outputs */
    mSpinner.ConfigNominalOutputForward(0, 10);
    mSpinner.ConfigNominalOutputReverse(0, 10);
    mSpinner.ConfigPeakOutputForward(1.0, 10);
    mSpinner.ConfigPeakOutputReverse(-1.0, 10);

    /* Set Motion Magic gains in slot0 - see documentation */
    mSpinner.SelectProfileSlot(0, 0);
    mSpinner.Config_kF(0, kF, 10);
    mSpinner.Config_kP(0, kP, 10);
    mSpinner.Config_kI(0, kI, 10);
    mSpinner.Config_kD(0, kD, 10);
    
     /* Set acceleration and vcruise velocity - see documentation */
    mSpinner.ConfigMotionCruiseVelocity(1024, 10);
    mSpinner.ConfigMotionAcceleration(1024, 10);

}

void DooHickey::Init() {
    
    m_colorMatcher.AddColorMatch(kBlueTarget);
    m_colorMatcher.AddColorMatch(kGreenTarget);
    m_colorMatcher.AddColorMatch(kRedTarget);
    m_colorMatcher.AddColorMatch(kYellowTarget);

}
void DooHickey::MoveSpinner(double speed) {
  double setSpeedTP100ms = speed * 2048 * 60 * 10;
  mMotorSpeed = setSpeedTP100ms;
  UpdateSpeed();
}

void DooHickey::SetHickeyPosition(double position){
  mTargetPos = position;
  UpdatePos();
}

void DooHickey::UpdateSpeed() {
  mSpinner.Set(ControlMode::Velocity, mMotorSpeed);
}

void DooHickey::UpdatePos() {
  mSpinner.Set(ControlMode::MotionMagic, mTargetPos);
}

void DooHickey::PushThang() {
  mUpPushyThang.Set(kHickeyEngage);
}

void DooHickey::RetractThang() {
  mUpPushyThang.Set(kHickeyDisengage);
}

void DooHickey::Periodic() {
   

     frc2::CommandScheduler::GetInstance().Run(); 
    /**
     * The method GetColor() returns a normalized color value from the sensor and can be
     * useful if outputting the color to an RGB LED or similar. To
     * read the raw color, use GetRawColor().
     * 
     * The color sensor works best when within a few inches from an object in
     * well lit conditions (the built in LED is a big help here!). The farther
     * an object is the more light from the surroundings will bleed into the 
     * measurements and make it difficult to accurately determine its color.
     */
    frc::Color detectedColor = m_colorSensor.GetColor();
    
    int colorCounter = 0;
    std::string gameData;
    std::string colorString;
    std::string assignedColorString;
    double confidence = 0.0;
    frc::Color matchedColor = m_colorMatcher.MatchClosestColor(detectedColor, confidence);

    //Code for finding out the detected Color 
    if (matchedColor == kBlueTarget) {
      colorString = "Blue";
      colorCounter++;
    } else if (matchedColor == kRedTarget) {
      colorString = "Red";
    } else if (matchedColor == kGreenTarget) {
      colorString = "Green";
    } else if (matchedColor == kYellowTarget) {
      colorString = "Yellow";
    } else {
      colorString = "Unknown";
    } 

    /*Tracks the number of times a specific color is detected (in this case blue), so that we can 
    * know when rotation control is over. We should see each color 2 times a rotation and the goal is 3
    * rotations.
    */ 
    if (colorCounter >= 6) {
      IsRotationControlFinished = true;
    }

    //Code for stopping the motor after Rotation Control is finished AND the specified Color is reached.
    gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
    if(gameData.length() > 0)
    {
    switch (gameData[0])
    {
    case 'B' :
      /*If the matched color is blue when the assigned color is blue and rotation control is finished
      *then stop the motor
      */
      assignedColorString = "Blue";
      if(matchedColor == kBlueTarget && IsRotationControlFinished == true) 
      {
        mMotorSpeed = 0;
      }
      break;
    case 'G' :
      /*If the matched color is green when the assigned color is green and rotation control is finished
      *then stop the motor
      */
      assignedColorString = "Green";
      if(matchedColor == kGreenTarget && IsRotationControlFinished == true) 
      {
        mMotorSpeed = 0;
      }
      break;
    case 'R' :
      /*If the matched color is red when the assigned color is red and rotation control is finished
      *then stop the motor
      */
      assignedColorString = "Red";
      if(matchedColor == kRedTarget && IsRotationControlFinished == true) 
      {
        mMotorSpeed = 0;
      }
      break;
    case 'Y' :
      /*If the matched color is yellow when the assigned color is yellow and rotation control is finished
      *then stop the motor
      */
      assignedColorString = "Yellow";
      if(matchedColor == kYellowTarget && IsRotationControlFinished == true) 
      {
        mMotorSpeed = 0;
      }
      break;
    default :
      //This is corrupt data
      break;
    }
    } else {
      //Code for no data received yet
    }

    /**
     * Open Smart Dashboard or Shuffleboard to see the color detected by the 
     * sensor.
     */
    frc::SmartDashboard::PutNumber("Red", detectedColor.red);
    frc::SmartDashboard::PutNumber("Green", detectedColor.green);
    frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
    frc::SmartDashboard::PutNumber("Confidence", confidence);
    frc::SmartDashboard::PutString("Detected Color", colorString);
    frc::SmartDashboard::PutNumber("Rotation Control Finished", IsRotationControlFinished);
    frc::SmartDashboard::PutString("Assigned Color", assignedColorString);

  }



