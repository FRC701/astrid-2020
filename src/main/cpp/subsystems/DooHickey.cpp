/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DooHickey.h"
#include <ctime>
#include <fstream>
#include <sstream>

constexpr frc::DoubleSolenoid::Value kHickeyEngage {frc::DoubleSolenoid::kForward};
constexpr frc::DoubleSolenoid::Value kHickeyDisengage {frc::DoubleSolenoid::kReverse};

DooHickey::DooHickey(
    const wpi::Twine& name,
    WPI_TalonFX& spinner,
    frc::DoubleSolenoid& UpPushyThang)
  : mSpinner(spinner)
  ,mUpPushyThang(UpPushyThang)
  ,mLogfile("/home/lvuser/test.txt", std::ios_base::out)   
  ,mMotorSpeed{0}
  ,mTargetPos{0}
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
    mSpinner.Config_kF(0, 0.3, 10);
    mSpinner.Config_kP(0, 0.1, 10);
    mSpinner.Config_kI(0, 0.0, 10);
    mSpinner.Config_kD(0, 0.0, 10);
    
     /* Set acceleration and vcruise velocity - see documentation */
    mSpinner.ConfigMotionCruiseVelocity(1024, 10);
    mSpinner.ConfigMotionAcceleration(1024, 10);

}

void DooHickey::Init() {
    
    m_colorMatcher.AddColorMatch(kBlueTarget);
    m_colorMatcher.AddColorMatch(kGreenTarget);
    m_colorMatcher.AddColorMatch(kRedTarget);
    m_colorMatcher.AddColorMatch(kYellowTarget);

    mPreviousTime = std::chrono::system_clock::now();
}
void DooHickey::MoveSpinner(double speed) {
  mMotorSpeed = speed;
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
    mPreviousTime = std::chrono::system_clock::now();
    frc::Color detectedColor = m_colorSensor.GetColor();
    
    std::string colorString;
    double confidence = 0.0;
    frc::Color matchedColor = m_colorMatcher.MatchClosestColor(detectedColor, confidence);

    if (matchedColor == kBlueTarget) {
      colorString = "Blue";
    } else if (matchedColor == kRedTarget) {
      colorString = "Red";
    } else if (matchedColor == kGreenTarget) {
      colorString = "Green";
    } else if (matchedColor == kYellowTarget) {
      colorString = "Yellow";
    } else {
      colorString = "Unknown";
    } 

    time_point now = std::chrono::system_clock::now();

    /**
     * Open Smart Dashboard or Shuffleboard to see the color detected by the 
     * sensor.
     */
    frc::SmartDashboard::PutNumber("Red", detectedColor.red);
    frc::SmartDashboard::PutNumber("Green", detectedColor.green);
    frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
    frc::SmartDashboard::PutNumber("Confidence", confidence);
    frc::SmartDashboard::PutString("Detected Color", colorString);

    std::chrono::duration<double> elapsed = now - mPreviousTime;
    std::time_t end_time = std::chrono::system_clock::to_time_t(now);

    mLogfile << std::ctime(&end_time) << "," 
            << elapsed.count() << "," 
            << detectedColor.red << "," 
            << detectedColor.green << ","
            << detectedColor.blue << std::endl;
  
    mPreviousTime = now;
  }



