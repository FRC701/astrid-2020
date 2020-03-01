#include "Commands/MotionProfile.h"
namespace ShortAdjustTrajectories
{

extern const unsigned int kTrajectoryLength = 98;

extern const robovikes::TrajectoryPoint leftTrajectories[] = {
  // { position (R), velocity (RPM) },
  { -0.371690, -7.43379 },
  { -1.85845, -14.8676 },
  { -5.20365, -33.4521 },
  { -11.1507, -59.4703 },
  { -20.4429, -92.9224 },
  { -33.8238, -133.808 },
  { -52.0365, -182.128 },
  { -75.8247, -237.881 },
  { -105.932, -301.069 },
  { -142.729, -367.973 },
  { -186.217, -434.877 },
  { -236.395, -501.781 },
  { -293.263, -568.685 },
  { -356.822, -635.589 },
  { -427.071, -702.493 },
  { -504.011, -769.398 },
  { -587.641, -836.302 },
  { -677.962, -903.206 },
  { -774.973, -970.110 },
  { -878.674, -1037.01 },
  { -989.066, -1103.92 },
  { -1106.15, -1170.82 },
  { -1229.92, -1237.73 },
  { -1360.38, -1304.63 },
  { -1497.54, -1371.53 },
  { -1641.38, -1438.44 },
  { -1791.92, -1505.34 },
  { -1949.14, -1572.25 },
  { -2113.06, -1639.15 },
  { -2283.66, -1706.06 },
  { -2460.96, -1772.96 },
  { -2644.94, -1839.86 },
  { -2835.62, -1906.77 },
  { -3032.99, -1973.67 },
  { -3237.05, -2040.58 },
  { -3447.79, -2107.48 },
  { -3665.23, -2174.38 },
  { -3889.36, -2241.29 },
  { -4120.18, -2308.19 },
  { -4357.69, -2375.10 },
  { -4601.52, -2438.28 },
  { -4850.92, -2494.04 },
  { -5105.16, -2542.36 },
  { -5363.48, -2583.24 },
  { -5625.15, -2616.70 },
  { -5889.42, -2642.71 },
  { -6155.55, -2661.30 },
  { -6422.80, -2672.45 },
  { -6690.26, -2674.59 },
  { -6957.03, -2667.74 },
  { -7222.37, -2653.45 },
  { -7485.55, -2631.72 },
  { -7745.80, -2602.56 },
  { -8002.40, -2565.97 },
  { -8254.59, -2521.94 },
  { -8501.64, -2470.48 },
  { -8742.80, -2411.58 },
  { -8977.48, -2346.83 },
  { -9205.47, -2279.92 },
  { -9426.78, -2213.02 },
  { -9641.39, -2146.11 },
  { -9849.31, -2079.21 },
  { -10050.5, -2012.31 },
  { -10245.1, -1945.40 },
  { -10432.9, -1878.50 },
  { -10614.1, -1811.59 },
  { -10788.6, -1744.69 },
  { -10956.3, -1677.79 },
  { -11117.4, -1610.88 },
  { -11271.8, -1543.98 },
  { -11419.5, -1477.07 },
  { -11560.5, -1410.17 },
  { -11694.9, -1343.26 },
  { -11822.5, -1276.36 },
  { -11943.5, -1209.46 },
  { -12057.7, -1142.55 },
  { -12165.3, -1075.65 },
  { -12266.1, -1008.74 },
  { -12360.3, -941.840 },
  { -12447.8, -874.936 },
  { -12528.6, -808.032 },
  { -12602.7, -741.127 },
  { -12670.2, -674.223 },
  { -12730.9, -607.319 },
  { -12784.9, -540.415 },
  { -12832.3, -473.511 },
  { -12872.9, -406.607 },
  { -12906.9, -339.703 },
  { -12934.4, -274.369 },
  { -12955.8, -214.323 },
  { -12972.0, -161.711 },
  { -12983.6, -116.532 },
  { -12991.5, -78.7873 },
  { -12996.3, -48.4764 },
  { -12998.9, -25.5993 },
  { -12999.9, -10.1559 },
  { -13000.1, -2.14633 },
  { -13000.1, -0.00000 }
};
extern const robovikes::TrajectoryPoint rightTrajectories[] = {
  // { position (R), velocity (RPM) },
  { -0.371690, -7.43379 },
  { -1.85845, -14.8676 },
  { -5.20365, -33.4521 },
  { -11.1507, -59.4703 },
  { -20.4429, -92.9224 },
  { -33.8238, -133.808 },
  { -52.0365, -182.128 },
  { -75.8247, -237.881 },
  { -105.932, -301.069 },
  { -142.729, -367.973 },
  { -186.217, -434.877 },
  { -236.395, -501.781 },
  { -293.263, -568.685 },
  { -356.822, -635.589 },
  { -427.071, -702.493 },
  { -504.011, -769.398 },
  { -587.641, -836.302 },
  { -677.962, -903.206 },
  { -774.973, -970.110 },
  { -878.674, -1037.01 },
  { -989.066, -1103.92 },
  { -1106.15, -1170.82 },
  { -1229.92, -1237.73 },
  { -1360.38, -1304.63 },
  { -1497.54, -1371.53 },
  { -1641.38, -1438.44 },
  { -1791.92, -1505.34 },
  { -1949.14, -1572.25 },
  { -2113.06, -1639.15 },
  { -2283.66, -1706.06 },
  { -2460.96, -1772.96 },
  { -2644.94, -1839.86 },
  { -2835.62, -1906.77 },
  { -3032.99, -1973.67 },
  { -3237.05, -2040.58 },
  { -3447.79, -2107.48 },
  { -3665.23, -2174.38 },
  { -3889.36, -2241.29 },
  { -4120.18, -2308.19 },
  { -4357.69, -2375.10 },
  { -4601.52, -2438.28 },
  { -4850.92, -2494.04 },
  { -5105.16, -2542.36 },
  { -5363.48, -2583.24 },
  { -5625.15, -2616.70 },
  { -5889.42, -2642.71 },
  { -6155.55, -2661.30 },
  { -6422.80, -2672.45 },
  { -6690.26, -2674.59 },
  { -6957.03, -2667.74 },
  { -7222.37, -2653.45 },
  { -7485.55, -2631.72 },
  { -7745.80, -2602.56 },
  { -8002.40, -2565.97 },
  { -8254.59, -2521.94 },
  { -8501.64, -2470.48 },
  { -8742.80, -2411.58 },
  { -8977.48, -2346.83 },
  { -9205.47, -2279.92 },
  { -9426.78, -2213.02 },
  { -9641.39, -2146.11 },
  { -9849.31, -2079.21 },
  { -10050.5, -2012.31 },
  { -10245.1, -1945.40 },
  { -10432.9, -1878.50 },
  { -10614.1, -1811.59 },
  { -10788.6, -1744.69 },
  { -10956.3, -1677.79 },
  { -11117.4, -1610.88 },
  { -11271.8, -1543.98 },
  { -11419.5, -1477.07 },
  { -11560.5, -1410.17 },
  { -11694.9, -1343.26 },
  { -11822.5, -1276.36 },
  { -11943.5, -1209.46 },
  { -12057.7, -1142.55 },
  { -12165.3, -1075.65 },
  { -12266.1, -1008.74 },
  { -12360.3, -941.840 },
  { -12447.8, -874.936 },
  { -12528.6, -808.032 },
  { -12602.7, -741.127 },
  { -12670.2, -674.223 },
  { -12730.9, -607.319 },
  { -12784.9, -540.415 },
  { -12832.3, -473.511 },
  { -12872.9, -406.607 },
  { -12906.9, -339.703 },
  { -12934.4, -274.369 },
  { -12955.8, -214.323 },
  { -12972.0, -161.711 },
  { -12983.6, -116.532 },
  { -12991.5, -78.7873 },
  { -12996.3, -48.4764 },
  { -12998.9, -25.5993 },
  { -12999.9, -10.1559 },
  { -13000.1, -2.14633 },
  { -13000.1, -0.00000 }
};

} // namespace RookieTrajectories
