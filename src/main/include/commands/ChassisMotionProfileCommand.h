#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/Notifier.h>
#include "commands/MotionProfile.h"
#include "subsystems/Chassis.h"

class ChassisMotionProfileCommand : public frc2::CommandHelper<frc2::CommandBase, ChassisMotionProfileCommand> 
{
public:
  using TrajectoryPoint = robovikes::TrajectoryPoint;

  ChassisMotionProfileCommand(
      Chassis& chassis,
      const TrajectoryPoint* chassisLeft,
      const TrajectoryPoint* chassisRight,
      unsigned int trajectoryPointCount,
      unsigned int pointDurationMillis,
      bool velocityOnly = true);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;

  ChassisMotionProfileCommand(ChassisMotionProfileCommand&& other) = default;
  ChassisMotionProfileCommand(const ChassisMotionProfileCommand& other) = default;
  ChassisMotionProfileCommand() = default;

  class MotionProfileState
  {
  public:
    virtual void run(const ChassisMotionProfileCommand*) = 0;
    virtual bool isFinished() const = 0;
    virtual ChassisMotionProfileCommand::MotionProfileState* getNextState(const ChassisMotionProfileCommand*) = 0;

    virtual ~MotionProfileState() { };
  };

  class MotionProfileLoad : public MotionProfileState
  {
  public:
    using MotionProfileState = ChassisMotionProfileCommand::MotionProfileState;
    void run(const ChassisMotionProfileCommand* motionProfile);
    bool isFinished() const;
    MotionProfileState* getNextState(const ChassisMotionProfileCommand*);
    virtual ~MotionProfileLoad();
  };

  Chassis& mChassis;

private:
  friend class MotionProfileLoad;
  friend class MotionProfileStart;
  friend class MotionProfileLoadTalon;
  friend class MotionProfileRun;
  friend class MotionProfileFinished;

  const TrajectoryPoint* chassisLeft;
  const TrajectoryPoint* chassisRight;
  unsigned int trajectoryPointCount;
  unsigned int pointDurationMillis;
  bool velocityOnly;

  frc::Notifier notifier;
  MotionProfileState* state;

  void PeriodicTask();
};

