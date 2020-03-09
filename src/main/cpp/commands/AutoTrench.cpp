#include "commands/AutoTrench.h"

namespace 
{
  constexpr int kPointDurationMillis{10};
}

namespace TrenchTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

AutoTrench::AutoTrench(Chassis& chassis)
: frc2::CommandHelper<ChassisMotionProfileCommand, AutoTrench>(
    chassis,
    TrenchTrajectories::leftTrajectories,
    TrenchTrajectories::rightTrajectories,
    TrenchTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}
