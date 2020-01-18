/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Spin.h"

Spin::Spin(DooHickey* dooHickey, double speed) : m_dooHickey(dooHickey), mSpeed(speed) {
  SetName("Spin");
  AddRequirements({m_dooHickey});   // Use addRequirements() here to declare subsystem dependencies.
  std::cout << "Spin::Spin" << std::endl;
}

// Called when the command is initially scheduled.
void Spin::Initialize() {
  std::cout << "Spin::Initialize" << std::endl;
}
// Called repeatedly when this Command is scheduled to run
void Spin::Execute() {
  std::cout << "Spin::Execute" << std::endl;

  m_dooHickey->MoveSpinner(mSpeed);
}

// Called once the command ends or is interrupted.
void Spin::End(bool interrupted) {
  m_dooHickey->MoveSpinner(0.0);
  std::cout << "Spin::End" << std::endl;
}

// Returns true when the command should end.
bool Spin::IsFinished() { return false; }
