/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include "frc/WPILib.h"
#include <frc/DriverStation.h>
#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>
#include "subsystems/DooHickey.h"
#include "RobotContainer.h"
#include <frc2/command/CommandScheduler.h>
#include "frc/smartdashboard/SendableChooser.inc"

#include "subsystems/Chassis.h"

class Robot : public frc::TimedRobot {
 public:

 Robot::Robot();
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  /*void AutoRookie(Chassis& chassis);
  void AutoRookie10(Chassis& chassis);
  void AutoPoach(Chassis& chassis);
  void AutoPoachToShoot(Chassis& chassis); */

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  frc2::Command* m_autonomousCommand = nullptr;
  frc::SendableChooser<frc2::Command*>* chooser;
  RobotContainer m_container;

  Chassis& mChassis;
};
