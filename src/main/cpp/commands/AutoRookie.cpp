#include "commands/AutoRookie.h"

namespace 
{
  constexpr int kPointDurationMillis{10};
}

namespace RookieTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

AutoRookie::AutoRookie(Chassis& chassis)
: ChassisMotionProfileCommand(
    chassis,
    RookieTrajectories::leftTrajectories,
    RookieTrajectories::rightTrajectories,
    RookieTrajectories::kTrajectoryLength,
    kPointDurationMillis)

{

}
