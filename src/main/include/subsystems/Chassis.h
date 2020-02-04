/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>



class Chassis : public frc2::SubsystemBase {
 public:
  using WPI_TalonFX = ctre::phoenix::motorcontrol::can::WPI_TalonFX;

  struct Components 
  {
      WPI_TalonFX frontLeft;
      WPI_TalonFX frontRight;
      WPI_TalonFX backLeft;
      WPI_TalonFX backRight;
  };
  Chassis(const wpi::Twine& name,
        Components& components);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  void TankDrive(double left, double right);
  void ArcadeDrive(double speed, double rotation);

  double GetLeftVelocity();
  double GetRightVelocity();

  double TargetOffset();
  double TargetDistance();

  void SetDriverCam();
  void SetVisionCam();
  void limeLightLightsOn();
  void limeLightLightsOff();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  Components& mComponents;

  frc::DifferentialDrive mDrive;
  
};
