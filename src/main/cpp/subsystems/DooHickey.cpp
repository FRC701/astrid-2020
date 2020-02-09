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
  constexpr frc::DoubleSolenoid::Value kHickeyEngage {frc::DoubleSolenoid::kReverse};
  constexpr frc::DoubleSolenoid::Value kHickeyDisengage {frc::DoubleSolenoid::kForward};
}

DooHickey::DooHickey(const wpi::Twine& name, Components& components)
: mComponents(components)
  ,mMotorSpeed{0}
  ,mTargetPos{0}
{
  SetName(name);
  SetUpMotionMagic();
}

void DooHickey::SetUpMotionMagic() {

    /* Set relevant frame periods to be at least as fast as periodic rate */
    mComponents.spinner.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, 10);
    mComponents.spinner.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, 10);

     /* Set the peak and nominal outputs */
    mComponents.spinner.ConfigNominalOutputForward(0, 10);
    mComponents.spinner.ConfigNominalOutputReverse(0, 10);
    mComponents.spinner.ConfigPeakOutputForward(1.0, 10);
    mComponents.spinner.ConfigPeakOutputReverse(-1.0, 10);

    /* Set Motion Magic gains in slot0 - see documentation */
    mComponents.spinner.SelectProfileSlot(0, 0);
    mComponents.spinner.Config_kF(0, kF, 10);
    mComponents.spinner.Config_kP(0, kP, 10);
    mComponents.spinner.Config_kI(0, kI, 10);
    mComponents.spinner.Config_kD(0, kD, 10);
    
     /* Set acceleration and vcruise velocity - see documentation */
    mComponents.spinner.ConfigMotionCruiseVelocity(1024, 10);
    mComponents.spinner.ConfigMotionAcceleration(1024, 10);

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
  mComponents.spinner.Set(ControlMode::Velocity, mMotorSpeed);
}

void DooHickey::UpdatePos() {
  mComponents.spinner.Set(ControlMode::MotionMagic, mTargetPos);
}

void DooHickey::PushThang() {
  mComponents.UpPushyThang.Set(kHickeyEngage);
}

void DooHickey::RetractThang() {
  mComponents.UpPushyThang.Set(kHickeyDisengage);
}

void DooHickey::Periodic() {

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
    frc::Color assignedColor;

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

    struct colorstuff 
    {
      frc::Color viewing;
      frc::Color assigned;
    };
    struct direction
    {
      int direction;
    };
    struct stoppingColor
    {
      frc::Color stopHere;
    };
    colorstuff Selector1[] = 
    {
       {kRedTarget, kRedTarget}
      ,{kRedTarget, kGreenTarget}
      ,{kRedTarget, kBlueTarget}
      ,{kRedTarget, kYellowTarget}

      ,{kGreenTarget, kRedTarget}
      ,{kGreenTarget, kGreenTarget}
      ,{kGreenTarget, kBlueTarget}
      ,{kGreenTarget, kYellowTarget}

      ,{kBlueTarget, kRedTarget}
      ,{kBlueTarget, kGreenTarget}
      ,{kBlueTarget, kBlueTarget}
      ,{kBlueTarget, kYellowTarget}

      ,{kYellowTarget, kRedTarget}
      ,{kYellowTarget, kGreenTarget}
      ,{kYellowTarget, kBlueTarget}
      ,{kYellowTarget, kYellowTarget}
    };
    direction Selector2[] =
    {
       {-1}
      ,{-1}
      ,{ 0}
      ,{ 1}

      ,{ 1}
      ,{-1}
      ,{-1}
      ,{ 0}

      ,{ 0}
      ,{ 1}
      ,{-1}
      ,{-1}

      ,{-1}
      ,{ 0}
      ,{ 1}
      ,{-1}
    };
    stoppingColor Selector3[] = 
    {
       {kBlueTarget}
      ,{kYellowTarget}
      ,{kRedTarget}
      ,{kGreenTarget}
      
      ,{kBlueTarget}
      ,{kYellowTarget}
      ,{kRedTarget}
      ,{kGreenTarget}

      ,{kBlueTarget}
      ,{kYellowTarget}
      ,{kRedTarget}
      ,{kGreenTarget}

      ,{kBlueTarget}
      ,{kYellowTarget}
      ,{kRedTarget}
      ,{kGreenTarget}
    };
/*
    for(int i = 0; i < sizeof(Selector1); i++) 
    {
      if(matchedColor == Selector1[i].viewing && assignedColor == Selector1[i].assigned)
      {
        while(matchedColor != Selector3[i].stopHere)
        {
          MoveSpinner(Selector2[i].direction * 18730);
        }
      }
    }
*/

    //Code for stopping the motor after Rotation Control is finished AND the specified Color is reached.
    gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
    if(gameData.length() > 0)
    {
    switch (gameData[0])
    {
    case 'B' :
      
      assignedColorString = "Blue";
      assignedColor = kBlueTarget;

      break;
    case 'G' :
      
      assignedColorString = "Green";
      assignedColor = kGreenTarget;
      
      break;
    case 'R' :
      
      assignedColorString = "Red";
      assignedColor = kRedTarget;
     
      break;
    case 'Y' :
      
      assignedColorString = "Yellow";
      assignedColor = kYellowTarget;

      
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



