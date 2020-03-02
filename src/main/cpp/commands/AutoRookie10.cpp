#include "commands/AutoRookie10.h"

namespace 
{
  constexpr int kPointDurationMillis{10};
}

namespace Rookie10Trajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

AutoRookie10::AutoRookie10(Chassis& chassis)
: frc2::CommandHelper<ChassisMotionProfileCommand, AutoRookie10>(
    chassis,
    Rookie10Trajectories::leftTrajectories,
    Rookie10Trajectories::rightTrajectories,
    Rookie10Trajectories::kTrajectoryLength,
    kPointDurationMillis)

{

}
