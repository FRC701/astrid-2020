#include "commands/AutoReverseFour.h"

namespace 
{
  constexpr int kPointDurationMillis{10};
}

namespace RookieTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

AutoReverseFour::AutoReverseFour(Chassis& chassis)
: ChassisMotionProfileCommand(
    chassis,
    RookieTrajectories::leftTrajectories,
    RookieTrajectories::rightTrajectories,
    RookieTrajectories::kTrajectoryLength,
    kPointDurationMillis)

{

}
