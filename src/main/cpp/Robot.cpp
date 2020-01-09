/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */

#include "Robot.h"
#include <frc/TimedRobot.h>
#include <frc/util/color.h>
#include <sstream>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>


Robot::Robot()
: TimedRobot()
{
}

void Robot::RobotInit() {
    _talon = new TalonFX(1);
    _joy = new frc::Joystick(0);

    /* Factory default hardware to prevent unexpected behavior */
    _talon->ConfigFactoryDefault();
    /**
     * Configure Talon SRX Output and Sesnor direction accordingly
     * Invert Motor to have green LEDs when driving Talon Forward / Requesting Postiive Output
     * Phase sensor to have positive increment when driving Talon Forward (Green LED)
     */
    _talon->SetSensorPhase(false);
    _talon->SetInverted(false);

    /* Set relevant frame periods to be at least as fast as periodic rate */
    _talon->SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, 10);
    _talon->SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, 10);

     /* Set the peak and nominal outputs */
    _talon->ConfigNominalOutputForward(0, 10);
    _talon->ConfigNominalOutputReverse(0, 10);
    _talon->ConfigPeakOutputForward(1, 10);
    _talon->ConfigPeakOutputReverse(-1, 10);

     /* Set Motion Magic gains in slot0 - see documentation */
    _talon->SelectProfileSlot(0, 0);
    _talon->Config_kF(0, 0.3, 10);
    _talon->Config_kP(0, 0.1, 10);
    _talon->Config_kI(0, 0.0, 10);
    _talon->Config_kD(0, 0.0, 10);

    /* Set acceleration and vcruise velocity - see documentation */
    _talon->ConfigMotionCruiseVelocity(1500, 10);
    _talon->ConfigMotionAcceleration(1500, 10);


}
void Robot::RobotPeriodic() { 
  
  }

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {
 /* Get gamepad axis - forward stick is positive */
    double leftYstick = -1.0 * _joy->GetY();
    double RightYstick = -1.0 * _joy->GetRawAxis(5);
    if (fabs(leftYstick) < 0.10) { leftYstick = 0;} /* deadband 10% */
    if (fabs(RightYstick) < 0.10) { RightYstick = 0;} /* deadband 10% */

    /* Get current Talon SRX motor output */
    double motorOutput = _talon->GetMotorOutputPercent();
    std::stringstream sb;
    /* Prepare line to print */
    sb << "\tOut%:" << motorOutput;

     /**
     * Peform Motion Magic when Button 1 is held,
     * else run Percent Output, which can be used to confirm hardware setup.
     */
    if (_joy->GetRawButton(1)) {
        /* Motion Magic */ 
        
        /*4096 ticks/rev * 10 Rotations in either direction */
        double targetPos = RightYstick * 4096 * 10.0;
        _talon->Set(ControlMode::MotionMagic, targetPos);

        /* Append more signals to print when in speed mode */
        sb << "\terr:" << _talon->GetClosedLoopError(0);
        sb << "\ttrg:" << targetPos;
    } else {
        /* Percent Output */

        _talon->Set(ControlMode::PercentOutput, leftYstick);
    }

}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}




#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
