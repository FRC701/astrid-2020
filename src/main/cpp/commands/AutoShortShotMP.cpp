#include "commands/AutoShortShotMP.h"

namespace 
{
  constexpr int kPointDurationMillis{10};
}

namespace ShortShotTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

AutoShortShotMP::AutoShortShotMP(Chassis& chassis)
: frc2::CommandHelper<ChassisMotionProfileCommand, AutoShortShotMP>(
    chassis,
    ShortShotTrajectories::leftTrajectories,
    ShortShotTrajectories::rightTrajectories,
    ShortShotTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}
