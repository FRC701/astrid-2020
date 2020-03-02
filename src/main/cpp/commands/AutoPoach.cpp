#include "commands/AutoPoach.h"

namespace 
{
  constexpr int kPointDurationMillis{10};
}

namespace PoachTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

namespace Trajectories = PoachTrajectories;

AutoPoach::AutoPoach(Chassis& chassis)
: public frc2::CommandHelper<ChassisMotionProfileCommand, AutoPoach>(
    chassis,
    Trajectories::leftTrajectories,
    Trajectories::rightTrajectories,
    Trajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}
