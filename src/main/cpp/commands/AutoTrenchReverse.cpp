#include "commands/AutoTrenchReverse.h"

namespace 
{
  constexpr int kPointDurationMillis{10};
}

namespace TrenchReverseTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

AutoTrenchReverse::AutoTrenchReverse(Chassis& chassis)
: frc2::CommandHelper<ChassisMotionProfileCommand, AutoTrenchReverse>(
    chassis,
    TrenchReverseTrajectories::leftTrajectories,
    TrenchReverseTrajectories::rightTrajectories,
    TrenchReverseTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}
