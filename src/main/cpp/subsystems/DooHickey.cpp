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
  constexpr double kF{0.0};
  constexpr double kP{0.1};
  constexpr double kI{0.0};
  constexpr double kD{0.0};
  constexpr double kNumberOfRotations{4};
  constexpr double kTicksPerRotation{2048};
  constexpr double kSecondsPerMinute{60};
  constexpr double kSecondsTo100ms{10};
  constexpr double radiusCW{16}; //16" radius of Control panel 
  constexpr double radiusDW{1.5};  //1.5" radius of DooHickey wheel (3" diameter)
  constexpr double TargetPos = (kNumberOfRotations*(radiusCW/radiusDW)) * kTicksPerRotation;
  constexpr frc::DoubleSolenoid::Value kHickeyEngage {frc::DoubleSolenoid::kForward};
  constexpr frc::DoubleSolenoid::Value kHickeyDisengage {frc::DoubleSolenoid::kReverse};
}

DooHickey::DooHickey(const wpi::Twine& name, Components& components)
  : mComponents(components)
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
  double setSpeedTP100ms = speed * kTicksPerRotation / kSecondsPerMinute / kSecondsTo100ms;
  UpdateSpeed(setSpeedTP100ms);
}

void DooHickey::SetHickeyPosition(double position) {
  UpdatePos(TargetPos);
}

void DooHickey::UpdateSpeed(double speed) {
  mComponents.spinner.Set(ControlMode::Velocity, speed);
}

void DooHickey::UpdatePos(double pos) {
  mComponents.spinner.Set(ControlMode::MotionMagic, pos);
}

bool DooHickey::IsInRange() const
{
  constexpr int kErrorThreshold = 10;
  constexpr int kLoopsToSettle = 10;

  if(abs(mComponents.spinner.GetActiveTrajectoryPosition() - TargetPos) < kErrorThreshold)
  {
    mWithinThresholdLoops++;
  }
  else {
    mWithinThresholdLoops = 0;
  }

  return (mWithinThresholdLoops > kLoopsToSettle);
}

void DooHickey::PushThang() {
  mComponents.UpPushyThang.Set(kHickeyEngage);
}

void DooHickey::RetractThang() {
  mComponents.UpPushyThang.Set(kHickeyDisengage);
}

frc::Color DooHickey::MatchedColor()
{
  return mMatchedColor;
}

frc::Color DooHickey::AssignedColor()
{
  return mAssignedColor;
}

DooHickey::stoppingColor DooHickey::StopHereColor()
{
   colorstuff Selector1[] = 
    {
       {kRedTarget, kRedTarget, {-1, kBlueTarget}}
      ,{kRedTarget, kGreenTarget, {-1, kYellowTarget}}
      ,{kRedTarget, kBlueTarget, {0, kRedTarget}}
      ,{kRedTarget, kYellowTarget, {1, kGreenTarget}}

      ,{kGreenTarget, kRedTarget, {1, kBlueTarget}}
      ,{kGreenTarget, kGreenTarget, {-1, kYellowTarget}}
      ,{kGreenTarget, kBlueTarget, {-1, kRedTarget}}
      ,{kGreenTarget, kYellowTarget, {0, kGreenTarget}}

      ,{kBlueTarget, kRedTarget, {0, kBlueTarget}}
      ,{kBlueTarget, kGreenTarget, {1, kYellowTarget}}
      ,{kBlueTarget, kBlueTarget, {-1, kRedTarget}}
      ,{kBlueTarget, kYellowTarget, {-1, kGreenTarget}}

      ,{kYellowTarget, kRedTarget, {-1, kBlueTarget}}
      ,{kYellowTarget, kGreenTarget, {0, kYellowTarget}}
      ,{kYellowTarget, kBlueTarget, {1, kRedTarget}}
      ,{kYellowTarget, kYellowTarget, {-1, kGreenTarget}}
    };
    auto found = std::find_if(std::begin(Selector1), std::end(Selector1),
    [this] (auto& Selector1) -> bool {
      return mMatchedColor == Selector1.viewing && mAssignedColor == Selector1.assigned;
    }); 
    if(found != std::end(Selector1))
    {
      return found -> stopHere;
    } 
    else 
    {
      //How did you get here?
      return Selector1[0].stopHere;
    }
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
    mMatchedColor = m_colorMatcher.MatchClosestColor(detectedColor, confidence);
    //Code for finding out the detected Color 
    if (mMatchedColor == kBlueTarget) {
      colorString = "Blue";
      colorCounter++;
    } else if (mMatchedColor == kRedTarget) {
      colorString = "Red";
    } else if (mMatchedColor == kGreenTarget) {
      colorString = "Green";
    } else if (mMatchedColor == kYellowTarget) {
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
    
    gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
    if(gameData.length() > 0)
    {
    switch (gameData[0])
    {
    case 'B' :
      
      assignedColorString = "Blue";
      mAssignedColor = kBlueTarget;

      break;
    case 'G' :
      
      assignedColorString = "Green";
      mAssignedColor = kGreenTarget;
      
      break;
    case 'R' :
      
      assignedColorString = "Red";
      mAssignedColor = kRedTarget;
     
      break;
    case 'Y' :
      
      assignedColorString = "Yellow";
      mAssignedColor = kYellowTarget;

      
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
    frc::SmartDashboard::PutBoolean("Rotation Control Finished", IsRotationControlFinished);
    frc::SmartDashboard::PutString("Assigned Color", assignedColorString);

  }



