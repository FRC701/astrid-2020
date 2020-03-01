#include "commands/AutoReverseFour.h"

namespace 
{
  constexpr int kPointDurationMillis{10};
}

namespace Reverse4Trajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

AutoReverseFour::AutoReverseFour(Chassis& chassis)
: ChassisMotionProfileCommand(
    chassis,
    Reverse4Trajectories::leftTrajectories,
    Reverse4Trajectories::rightTrajectories,
    Reverse4Trajectories::kTrajectoryLength,
    kPointDurationMillis)

{

}
