/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <ctime>
#include <fstream>
#include <sstream>
#include "subsystems/DooHickey.h"
#include <frc/util/color.h>
#include "ctre/Phoenix.h"
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"

#include <frc/smartdashboard/SmartDashboard.h>

DooHickey::DooHickey()
: spinner(0)
,mLogfile("/home/lvuser/test.txt", std::ios_base::out)
{
}

void DooHickey::Init() {
    /* Set relevant frame periods to be at least as fast as periodic rate */
    spinner.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, 10);
    spinner.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, 10);

     /* Set the peak and nominal outputs */
    spinner.ConfigNominalOutputForward(0, 10);
    spinner.ConfigNominalOutputReverse(0, 10);
    spinner.ConfigPeakOutputForward(0.9404, 10);
    spinner.ConfigPeakOutputReverse(-0.9404, 10);

    /* Set Motion Magic gains in slot0 - see documentation */
    spinner.SelectProfileSlot(0, 0);
    spinner.Config_kF(0, 0.3, 10);
    spinner.Config_kP(0, 0.1, 10);
    spinner.Config_kI(0, 0.0, 10);
    spinner.Config_kD(0, 0.0, 10);
    
     /* Set acceleration and vcruise velocity - see documentation */
    spinner.ConfigMotionCruiseVelocity(1024, 10);
    spinner.ConfigMotionAcceleration(1024, 10);

    /* Zero the sensor */
    spinner.SetSelectedSensorPosition(0, 0, 10);

    m_colorMatcher.AddColorMatch(kBlueTarget);
    m_colorMatcher.AddColorMatch(kGreenTarget);
    m_colorMatcher.AddColorMatch(kRedTarget);
    m_colorMatcher.AddColorMatch(kYellowTarget);

    mPreviousTime = std::chrono::system_clock::now();
}
// This method will be called once per scheduler run
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

    /**
     * Run the color match algorithm on our detected color
     */
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
  double DooHickey::MoveSpinner(double speedRPM) {
    double radiusCW = 16; //16in radius 
    double radiusDW = 2;  //change this later 
    double targetPos = (4*(radiusCW/radiusDW)) * 2048;
    double wheelSpeedTP100ms = spinner.GetSelectedSensorVelocity();
    double setSpeedTP100ms = speedRPM * 2048 * 60 * 10;
    spinner.Set(TalonFXControlMode::MotionMagic, targetPos);
    return wheelSpeedTP100ms;
  }
