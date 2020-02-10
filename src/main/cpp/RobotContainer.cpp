/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "commands/IntakeOn.h"
#include "commands/SetConveyor.h"
#include "commands/TankDrive.h"
#include "commands/Aim.h"
#include "commands/HoodOutFull.h"
#include "commands/HoodRetract.h"
#include "commands/LatchDisengage.h"
#include "commands/LatchEngage.h"
#include "commands/LimeLightsOff.h"
#include "commands/LimeLightsOn.h"
#include "commands/Spin.h"
#include "commands/SetHickeyPos.h"
#include "commands/HickeyDisengage.h"
#include "commands/HickeyEngage.h"
#include "commands/RunConveyor.h"
#include "commands/ResetBallConveyor.h"
#include <commands/IntakeEngage.h>
#include <commands/IntakeDisengage.h>
#include "commands/EnableIntake.h"


RobotContainer::RobotContainer()
{
  using JoystickHand = frc::GenericHID::JoystickHand;

  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  mChassis.SetDefaultCommand
  (
    TankDrive
    (
      mChassis,
      [this] { return driver.GetY(JoystickHand::kLeftHand); },
      [this] { return driver.GetY(JoystickHand::kRightHand); }
    )
  );
  constexpr double radiusCW = 16; //16" radius of Control panel 
  constexpr double radiusDW = 1.5;  //1.5" radius of DooHickey wheel (3" diameter)
  constexpr double TargetPos = (4*(radiusCW/radiusDW)) * 2048; 

  frc::SmartDashboard::PutData("Intake 10 percent", new IntakeOn(mIntake, 0.1));
  frc::SmartDashboard::PutData("Intake 20 percent", new IntakeOn(mIntake, 0.2));
  frc::SmartDashboard::PutData("Intake 30 percent", new IntakeOn(mIntake, 0.3));
  frc::SmartDashboard::PutData("Intake 40 percent", new IntakeOn(mIntake, 0.4));
  frc::SmartDashboard::PutData("Intake 50 percent", new IntakeOn(mIntake, 0.5));
  frc::SmartDashboard::PutData("Intake 60 percent", new IntakeOn(mIntake, 0.6));
  frc::SmartDashboard::PutData("Intake 70 percent", new IntakeOn(mIntake, 0.7));
  frc::SmartDashboard::PutData("Intake 80 percent", new IntakeOn(mIntake, 0.8));
  frc::SmartDashboard::PutData("Intake 90 percent", new IntakeOn(mIntake, 0.9));
  frc::SmartDashboard::PutData("Intake 100 percent", new IntakeOn(mIntake, 1.0));
  frc::SmartDashboard::PutData("Intake Engage", new IntakeEngage(mIntake));
  frc::SmartDashboard::PutData("Intake Disengage", new IntakeDisengage(mIntake));
  frc::SmartDashboard::PutData("Enable Intake", new EnableIntake(mIntake, mConveyor));


  //mConveyor.SetDefaultCommand(SetConveyor(mConveyor, 0.2));

  frc::SmartDashboard::PutData("Telescope Rise", new TelescopeRise(mTelescope, 0.1));
  
  frc::SmartDashboard::PutData("VisionMode", new Aim(mChassis));
  frc::SmartDashboard::PutData("Lime Lights On", new LimeLightsOn(mChassis));
  frc::SmartDashboard::PutData("Lime Lights Off", new LimeLightsOff(mChassis));
  
  frc::SmartDashboard::PutData("Spin 600 RPM", new Spin(mDooHickey, 0.1));
  frc::SmartDashboard::PutData("Spin 6000 RPM", new Spin(mDooHickey, 0.9404));
  frc::SmartDashboard::PutData("Spin distance", new SetHickeyPos(mDooHickey, TargetPos));
  frc::SmartDashboard::PutData("Engage da Hickey", new HickeyEngage(mDooHickey));
  frc::SmartDashboard::PutData("Disengage da Hickey", new HickeyDisengage(mDooHickey));

  frc::SmartDashboard::PutData(&mShooter);
  frc::SmartDashboard::PutData("Shoot 3000", new Shoot(mShooter, 3000.));
  frc::SmartDashboard::PutData("Shoot 4000", new Shoot(mShooter, 4000.));
  frc::SmartDashboard::PutData("Shoot 2000", new Shoot(mShooter, 2000.));
  frc::SmartDashboard::PutData("Shoot 1000", new Shoot(mShooter, 1000.));
  frc::SmartDashboard::PutData("Shoot 4500", new Shoot(mShooter, 4500.));

  frc::SmartDashboard::PutData("Open Hatch Fully", new HoodOutFull(mShooter));
  frc::SmartDashboard::PutData("Close Hatch", new HoodRetract(mShooter));
  frc::SmartDashboard::PutData("Engage Latch", new LatchEngage(mShooter));
  frc::SmartDashboard::PutData("Disengage Latch", new LatchDisengage(mShooter));

  frc::SmartDashboard::PutData("run conveyor 100", new RunConveyor(mConveyor, 1.0));
  frc::SmartDashboard::PutData("run conveyor 80", new RunConveyor(mConveyor, 0.8));
  frc::SmartDashboard::PutData("run conveyor 60", new RunConveyor(mConveyor, 0.6));
  frc::SmartDashboard::PutData("run conveyor 50", new RunConveyor(mConveyor, 0.5));
  frc::SmartDashboard::PutData("run conveyor 40", new RunConveyor(mConveyor, 0.4));
  frc::SmartDashboard::PutData("run conveyor 30", new RunConveyor(mConveyor, 0.3));
  frc::SmartDashboard::PutData("run conveyor 20", new RunConveyor(mConveyor, 0.2));

  frc::SmartDashboard::PutData("reset balls in conveyor", new ResetBallConveyor(mConveyor));

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  frc2::Trigger( [this] { return mConveyor.IsBallComing(); }).WhenActive( [this]{ mConveyor.BallIntakeIncoming(); });
  frc2::Trigger( [this] { return mConveyor.IsBallExiting(); }).WhenInactive( [this] { if(mConveyor.IsBallExiting()) { mConveyor.BallIntakeExiting(); }});
  frc2::Button coA {[this]{return coDriver.GetRawButton(1);}};

  coA.ToggleWhenPressed(EnableIntake(mIntake, mConveyor));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return nullptr;
}
