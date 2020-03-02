#include "commands/AutoPoachToShoot.h"

namespace 
{
  constexpr int kPointDurationMillis{10};
}

namespace PoachToShootTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

AutoPoachToShoot::AutoPoachToShoot(Chassis& chassis)
: frc2::CommandHelper<ChassisMotionProfileCommand, AutoPoachToShoot>(
    chassis,
    PoachToShootTrajectories::leftTrajectories,
    PoachToShootTrajectories::rightTrajectories,
    PoachToShootTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}
