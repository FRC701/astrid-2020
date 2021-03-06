#include "Commands/MotionProfile.h"
namespace Reverse4Trajectories
{

extern const unsigned int kTrajectoryLength = 132;

extern const robovikes::TrajectoryPoint leftTrajectories[] = {
  // { position (R), velocity (RPM) },
  { -0.381912, -7.63824 },
  { -1.77147, -13.8956 },
  { -5.20868, -34.3721 },
  { -11.3193, -61.1059 },
  { -20.8671, -95.4780 },
  { -34.6159, -137.488 },
  { -53.3296, -187.137 },
  { -77.7719, -244.424 },
  { -108.707, -309.349 },
  { -146.898, -381.912 },
  { -193.109, -462.113 },
  { -248.105, -549.953 },
  { -312.648, -645.431 },
  { -387.502, -748.547 },
  { -473.433, -859.302 },
  { -571.202, -977.694 },
  { -681.575, -1103.73 },
  { -805.314, -1237.39 },
  { -943.184, -1378.70 },
  { -1095.95, -1527.65 },
  { -1264.37, -1684.23 },
  { -1449.22, -1848.45 },
  { -1651.25, -2020.31 },
  { -1871.23, -2199.81 },
  { -2109.92, -2386.95 },
  { -2368.10, -2581.72 },
  { -2646.13, -2780.32 },
  { -2944.02, -2978.91 },
  { -3261.77, -3177.51 },
  { -3599.38, -3376.10 },
  { -3956.85, -3574.69 },
  { -4334.18, -3773.29 },
  { -4731.37, -3971.88 },
  { -5148.42, -4170.48 },
  { -5585.32, -4369.07 },
  { -6042.09, -4567.67 },
  { -6518.72, -4766.26 },
  { -7015.20, -4964.85 },
  { -7531.55, -5163.45 },
  { -8067.75, -5362.04 },
  { -8623.43, -5556.82 },
  { -9197.83, -5743.95 },
  { -9790.17, -5923.45 },
  { -10399.7, -6095.31 },
  { -11025.7, -6259.53 },
  { -11667.3, -6416.12 },
  { -12323.8, -6565.06 },
  { -12994.4, -6706.37 },
  { -13678.4, -6840.04 },
  { -14375.0, -6966.07 },
  { -15083.5, -7084.46 },
  { -15803.0, -7195.22 },
  { -16532.8, -7298.34 },
  { -17272.2, -7393.81 },
  { -18020.4, -7481.65 },
  { -18776.6, -7561.85 },
  { -19540.0, -7634.42 },
  { -20309.9, -7699.34 },
  { -21085.6, -7756.63 },
  { -21866.2, -7806.28 },
  { -22651.1, -7848.29 },
  { -23439.3, -7882.66 },
  { -24230.3, -7909.39 },
  { -25023.1, -7928.49 },
  { -25817.1, -7939.95 },
  { -26611.3, -7941.71 },
  { -27404.6, -7933.77 },
  { -28196.5, -7918.19 },
  { -28986.0, -7894.98 },
  { -29772.4, -7864.13 },
  { -30554.9, -7825.64 },
  { -31332.9, -7779.51 },
  { -32105.5, -7725.74 },
  { -32871.9, -7664.33 },
  { -33631.4, -7595.29 },
  { -34383.3, -7518.61 },
  { -35126.7, -7434.29 },
  { -35861.0, -7342.33 },
  { -36585.2, -7242.73 },
  { -37298.8, -7135.50 },
  { -38000.8, -7020.63 },
  { -38690.7, -6898.11 },
  { -39367.4, -6767.97 },
  { -40030.5, -6630.18 },
  { -40678.9, -6484.75 },
  { -41312.1, -6331.69 },
  { -41929.2, -6170.98 },
  { -42529.5, -6002.64 },
  { -43112.1, -5826.66 },
  { -43676.4, -5643.05 },
  { -44221.6, -5451.79 },
  { -44747.1, -5254.96 },
  { -45252.8, -5056.36 },
  { -45738.5, -4857.77 },
  { -46204.4, -4659.18 },
  { -46650.5, -4460.58 },
  { -47076.7, -4261.99 },
  { -47483.0, -4063.39 },
  { -47869.5, -3864.80 },
  { -48236.1, -3666.20 },
  { -48582.9, -3467.61 },
  { -48909.8, -3269.02 },
  { -49216.8, -3070.42 },
  { -49504.0, -2871.83 },
  { -49771.4, -2673.23 },
  { -50019.0, -2476.70 },
  { -50247.6, -2286.04 },
  { -50457.9, -2103.02 },
  { -50650.7, -1927.64 },
  { -50826.7, -1759.90 },
  { -50986.7, -1599.80 },
  { -51131.4, -1447.33 },
  { -51261.7, -1302.51 },
  { -51378.2, -1165.32 },
  { -51481.8, -1035.77 },
  { -51573.1, -913.856 },
  { -51653.1, -799.582 },
  { -51722.4, -692.946 },
  { -51781.8, -593.948 },
  { -51832.1, -502.589 },
  { -51873.9, -418.868 },
  { -51908.2, -342.785 },
  { -51935.7, -274.340 },
  { -51957.0, -213.534 },
  { -51973.0, -160.366 },
  { -51984.5, -114.836 },
  { -51992.2, -76.9442 },
  { -51996.9, -46.6907 },
  { -51999.3, -24.0755 },
  { -52000.2, -9.09854 },
  { -52000.4, -1.75981 },
  { -52000.4, -0.00000 }
};
extern const robovikes::TrajectoryPoint rightTrajectories[] = {
  // { position (R), velocity (RPM) },
  { -0.381912, -7.63824 },
  { -1.77147, -13.8956 },
  { -5.20868, -34.3721 },
  { -11.3193, -61.1059 },
  { -20.8671, -95.4780 },
  { -34.6159, -137.488 },
  { -53.3296, -187.137 },
  { -77.7719, -244.424 },
  { -108.707, -309.349 },
  { -146.898, -381.912 },
  { -193.109, -462.113 },
  { -248.105, -549.953 },
  { -312.648, -645.431 },
  { -387.502, -748.547 },
  { -473.433, -859.302 },
  { -571.202, -977.694 },
  { -681.575, -1103.73 },
  { -805.314, -1237.39 },
  { -943.184, -1378.70 },
  { -1095.95, -1527.65 },
  { -1264.37, -1684.23 },
  { -1449.22, -1848.45 },
  { -1651.25, -2020.31 },
  { -1871.23, -2199.81 },
  { -2109.92, -2386.95 },
  { -2368.10, -2581.72 },
  { -2646.13, -2780.32 },
  { -2944.02, -2978.91 },
  { -3261.77, -3177.51 },
  { -3599.38, -3376.10 },
  { -3956.85, -3574.69 },
  { -4334.18, -3773.29 },
  { -4731.37, -3971.88 },
  { -5148.42, -4170.48 },
  { -5585.32, -4369.07 },
  { -6042.09, -4567.67 },
  { -6518.72, -4766.26 },
  { -7015.20, -4964.85 },
  { -7531.55, -5163.45 },
  { -8067.75, -5362.04 },
  { -8623.43, -5556.82 },
  { -9197.83, -5743.95 },
  { -9790.17, -5923.45 },
  { -10399.7, -6095.31 },
  { -11025.7, -6259.53 },
  { -11667.3, -6416.12 },
  { -12323.8, -6565.06 },
  { -12994.4, -6706.37 },
  { -13678.4, -6840.04 },
  { -14375.0, -6966.07 },
  { -15083.5, -7084.46 },
  { -15803.0, -7195.22 },
  { -16532.8, -7298.34 },
  { -17272.2, -7393.81 },
  { -18020.4, -7481.65 },
  { -18776.6, -7561.85 },
  { -19540.0, -7634.42 },
  { -20309.9, -7699.34 },
  { -21085.6, -7756.63 },
  { -21866.2, -7806.28 },
  { -22651.1, -7848.29 },
  { -23439.3, -7882.66 },
  { -24230.3, -7909.39 },
  { -25023.1, -7928.49 },
  { -25817.1, -7939.95 },
  { -26611.3, -7941.71 },
  { -27404.6, -7933.77 },
  { -28196.5, -7918.19 },
  { -28986.0, -7894.98 },
  { -29772.4, -7864.13 },
  { -30554.9, -7825.64 },
  { -31332.9, -7779.51 },
  { -32105.5, -7725.74 },
  { -32871.9, -7664.33 },
  { -33631.4, -7595.29 },
  { -34383.3, -7518.61 },
  { -35126.7, -7434.29 },
  { -35861.0, -7342.33 },
  { -36585.2, -7242.73 },
  { -37298.8, -7135.50 },
  { -38000.8, -7020.63 },
  { -38690.7, -6898.11 },
  { -39367.4, -6767.97 },
  { -40030.5, -6630.18 },
  { -40678.9, -6484.75 },
  { -41312.1, -6331.69 },
  { -41929.2, -6170.98 },
  { -42529.5, -6002.64 },
  { -43112.1, -5826.66 },
  { -43676.4, -5643.05 },
  { -44221.6, -5451.79 },
  { -44747.1, -5254.96 },
  { -45252.8, -5056.36 },
  { -45738.5, -4857.77 },
  { -46204.4, -4659.18 },
  { -46650.5, -4460.58 },
  { -47076.7, -4261.99 },
  { -47483.0, -4063.39 },
  { -47869.5, -3864.80 },
  { -48236.1, -3666.20 },
  { -48582.9, -3467.61 },
  { -48909.8, -3269.02 },
  { -49216.8, -3070.42 },
  { -49504.0, -2871.83 },
  { -49771.4, -2673.23 },
  { -50019.0, -2476.70 },
  { -50247.6, -2286.04 },
  { -50457.9, -2103.02 },
  { -50650.7, -1927.64 },
  { -50826.7, -1759.90 },
  { -50986.7, -1599.80 },
  { -51131.4, -1447.33 },
  { -51261.7, -1302.51 },
  { -51378.2, -1165.32 },
  { -51481.8, -1035.77 },
  { -51573.1, -913.856 },
  { -51653.1, -799.582 },
  { -51722.4, -692.946 },
  { -51781.8, -593.948 },
  { -51832.1, -502.589 },
  { -51873.9, -418.868 },
  { -51908.2, -342.785 },
  { -51935.7, -274.340 },
  { -51957.0, -213.534 },
  { -51973.0, -160.366 },
  { -51984.5, -114.836 },
  { -51992.2, -76.9442 },
  { -51996.9, -46.6907 },
  { -51999.3, -24.0755 },
  { -52000.2, -9.09854 },
  { -52000.4, -1.75981 },
  { -52000.4, -0.00000 }
};

} // namespace Forward4Trajectories
