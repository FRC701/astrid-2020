#ifndef ChassisMotionProfileCommand_H
#define ChassisMotionProfileCommand_H

#include <frc2/command/Command.h>
#include <frc/Notifier.h>
#include "commands/MotionProfile.h"

class ChassisMotionProfileCommand : public frc2::Command {
public:
  typedef robovikes::TrajectoryPoint TrajectoryPoint;

  ChassisMotionProfileCommand(
      const TrajectoryPoint* chassisLeft,
      const TrajectoryPoint* chassisRight,
      unsigned int trajectoryPointCount,
      unsigned int pointDurationMillis,
      bool velocityOnly = true);
  void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();

  class MotionProfileState
  {
  public:
    virtual void run(const ChassisMotionProfileCommand*) = 0;
    virtual bool isFinished() const = 0;
    virtual MotionProfileState* getNextState() = 0;

    virtual ~MotionProfileState() { };
  };

  class MotionProfileLoad : public MotionProfileState
  {
  public:
    void run(const ChassisMotionProfileCommand* motionProfile);
    bool isFinished() const;
    ChassisMotionProfileCommand::MotionProfileState* getNextState();
    virtual ~MotionProfileLoad();
  };

private:
  friend class MotionProfileLoad;

  const TrajectoryPoint* chassisLeft;
  const TrajectoryPoint* chassisRight;
  unsigned int trajectoryPointCount;
  unsigned int pointDurationMillis;
  bool velocityOnly;

  frc::Notifier notifier;
  MotionProfileState* state;

  void PeriodicTask();
};

#endif  // ChassisMotionProfileCommand_H