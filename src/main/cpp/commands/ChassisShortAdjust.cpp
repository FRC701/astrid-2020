#include "commands/ChassisShortAdjust.h"

namespace 
{
  constexpr int kPointDurationMillis{10};
}

namespace ShortAdjustTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

ChassisShortAdjust::ChassisShortAdjust(Chassis& chassis)
: ChassisMotionProfileCommand(
    chassis,
    ShortAdjustTrajectories::leftTrajectories,
    ShortAdjustTrajectories::rightTrajectories,
    ShortAdjustTrajectories::kTrajectoryLength,
    kPointDurationMillis)

{

}
