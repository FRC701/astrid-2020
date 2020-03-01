#include "commands/AutoRookie.h"

namespace 
{
  constexpr int kPointDurationMillis{10};
}

namespace Reverse4Trajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

AutoRookie::AutoRookie(Chassis& chassis)
: ChassisMotionProfileCommand(
    chassis,
    Reverse4Trajectories::leftTrajectories,
    Reverse4Trajectories::rightTrajectories,
    Reverse4Trajectories::kTrajectoryLength,
    kPointDurationMillis)

{

}
