#include "Commands/MotionProfile.h"
namespace RookieTrajectories
{

extern const unsigned int kTrajectoryLength = 132;

extern const robovikes::TrajectoryPoint leftTrajectories[] = {
  // { position (R), velocity (RPM) },
  { 0.402179, 8.04358 },
  { 1.86548, 14.6330 },
  { 5.48509, 36.1961 },
  { 11.9199, 64.3486 },
  { 21.9744, 100.545 },
  { 36.4529, 144.784 },
  { 56.1596, 197.068 },
  { 81.8991, 257.394 },
  { 114.476, 325.765 },
  { 154.693, 402.179 },
  { 203.357, 486.636 },
  { 261.271, 579.137 },
  { 329.239, 679.682 },
  { 408.066, 788.270 },
  { 498.556, 904.902 },
  { 601.514, 1029.58 },
  { 717.744, 1162.30 },
  { 848.050, 1303.06 },
  { 993.236, 1451.87 },
  { 1154.11, 1608.72 },
  { 1331.47, 1773.61 },
  { 1526.12, 1946.55 },
  { 1738.88, 2127.53 },
  { 1970.53, 2316.55 },
  { 2221.89, 2513.62 },
  { 2493.77, 2718.73 },
  { 2786.55, 2927.86 },
  { 3100.25, 3136.99 },
  { 3434.86, 3346.13 },
  { 3790.39, 3555.26 },
  { 4166.83, 3764.39 },
  { 4564.18, 3973.53 },
  { 4982.45, 4182.66 },
  { 5421.63, 4391.79 },
  { 5881.72, 4600.93 },
  { 6362.72, 4810.06 },
  { 6864.64, 5019.19 },
  { 7387.48, 5228.32 },
  { 7931.22, 5437.46 },
  { 8495.88, 5646.59 },
  { 9081.05, 5851.70 },
  { 9685.93, 6048.77 },
  { 10309.7, 6237.79 },
  { 10951.6, 6418.77 },
  { 11610.8, 6591.71 },
  { 12286.4, 6756.60 },
  { 12977.8, 6913.45 },
  { 13684.0, 7062.26 },
  { 14404.3, 7203.02 },
  { 15137.9, 7335.74 },
  { 15883.9, 7460.42 },
  { 16641.6, 7577.05 },
  { 17410.2, 7685.64 },
  { 18188.8, 7786.18 },
  { 18976.7, 7878.68 },
  { 19773.0, 7963.14 },
  { 20576.9, 8039.55 },
  { 21387.7, 8107.92 },
  { 22204.5, 8168.25 },
  { 23026.6, 8220.53 },
  { 23853.1, 8264.77 },
  { 24683.2, 8300.97 },
  { 25516.1, 8329.12 },
  { 26351.0, 8349.23 },
  { 27187.1, 8361.30 },
  { 28023.5, 8363.15 },
  { 28858.9, 8354.79 },
  { 29692.8, 8338.39 },
  { 30524.2, 8313.94 },
  { 31352.3, 8281.45 },
  { 32176.4, 8240.92 },
  { 32995.6, 8192.34 },
  { 33809.2, 8135.72 },
  { 34616.3, 8071.06 },
  { 35416.2, 7998.35 },
  { 36207.9, 7917.60 },
  { 36990.8, 7828.80 },
  { 37764.0, 7731.97 },
  { 38526.7, 7627.08 },
  { 39278.1, 7514.16 },
  { 40017.4, 7393.19 },
  { 40743.8, 7264.18 },
  { 41456.6, 7127.12 },
  { 42154.8, 6982.02 },
  { 42837.7, 6828.88 },
  { 43504.4, 6667.69 },
  { 44154.3, 6498.46 },
  { 44786.4, 6321.19 },
  { 45400.0, 6135.87 },
  { 45994.2, 5942.51 },
  { 46568.3, 5741.10 },
  { 47121.7, 5533.82 },
  { 47654.2, 5324.69 },
  { 48165.7, 5115.56 },
  { 48656.4, 4906.42 },
  { 49126.1, 4697.29 },
  { 49574.9, 4488.16 },
  { 50002.8, 4279.03 },
  { 50409.8, 4069.89 },
  { 50795.9, 3860.76 },
  { 51161.1, 3651.63 },
  { 51505.3, 3442.49 },
  { 51828.6, 3233.36 },
  { 52131.1, 3024.23 },
  { 52412.6, 2815.09 },
  { 52673.4, 2608.13 },
  { 52914.1, 2407.36 },
  { 53135.6, 2214.63 },
  { 53338.6, 2029.94 },
  { 53523.9, 1853.30 },
  { 53692.4, 1684.70 },
  { 53844.8, 1524.14 },
  { 53982.0, 1371.63 },
  { 54104.7, 1227.16 },
  { 54213.7, 1090.73 },
  { 54310.0, 962.351 },
  { 54394.2, 842.013 },
  { 54467.2, 729.718 },
  { 54529.7, 625.467 },
  { 54582.6, 529.260 },
  { 54626.7, 441.096 },
  { 54662.8, 360.976 },
  { 54691.7, 288.899 },
  { 54714.2, 224.866 },
  { 54731.1, 168.876 },
  { 54743.2, 120.930 },
  { 54751.3, 81.0274 },
  { 54756.2, 49.1685 },
  { 54758.7, 25.3531 },
  { 54759.7, 9.58137 },
  { 54759.9, 1.85320 },
  { 54759.9, 0.00000 }
};
extern const robovikes::TrajectoryPoint rightTrajectories[] = {
  // { position (R), velocity (RPM) },
  { 0.402179, 8.04358 },
  { 1.86548, 14.6330 },
  { 5.48509, 36.1961 },
  { 11.9199, 64.3486 },
  { 21.9744, 100.545 },
  { 36.4529, 144.784 },
  { 56.1596, 197.068 },
  { 81.8991, 257.394 },
  { 114.476, 325.765 },
  { 154.693, 402.179 },
  { 203.357, 486.636 },
  { 261.271, 579.137 },
  { 329.239, 679.682 },
  { 408.066, 788.270 },
  { 498.556, 904.902 },
  { 601.514, 1029.58 },
  { 717.744, 1162.30 },
  { 848.050, 1303.06 },
  { 993.236, 1451.87 },
  { 1154.11, 1608.72 },
  { 1331.47, 1773.61 },
  { 1526.12, 1946.55 },
  { 1738.88, 2127.53 },
  { 1970.53, 2316.55 },
  { 2221.89, 2513.62 },
  { 2493.77, 2718.73 },
  { 2786.55, 2927.86 },
  { 3100.25, 3136.99 },
  { 3434.86, 3346.13 },
  { 3790.39, 3555.26 },
  { 4166.83, 3764.39 },
  { 4564.18, 3973.53 },
  { 4982.45, 4182.66 },
  { 5421.63, 4391.79 },
  { 5881.72, 4600.93 },
  { 6362.72, 4810.06 },
  { 6864.64, 5019.19 },
  { 7387.48, 5228.32 },
  { 7931.22, 5437.46 },
  { 8495.88, 5646.59 },
  { 9081.05, 5851.70 },
  { 9685.93, 6048.77 },
  { 10309.7, 6237.79 },
  { 10951.6, 6418.77 },
  { 11610.8, 6591.71 },
  { 12286.4, 6756.60 },
  { 12977.8, 6913.45 },
  { 13684.0, 7062.26 },
  { 14404.3, 7203.02 },
  { 15137.9, 7335.74 },
  { 15883.9, 7460.42 },
  { 16641.6, 7577.05 },
  { 17410.2, 7685.64 },
  { 18188.8, 7786.18 },
  { 18976.7, 7878.68 },
  { 19773.0, 7963.14 },
  { 20576.9, 8039.55 },
  { 21387.7, 8107.92 },
  { 22204.5, 8168.25 },
  { 23026.6, 8220.53 },
  { 23853.1, 8264.77 },
  { 24683.2, 8300.97 },
  { 25516.1, 8329.12 },
  { 26351.0, 8349.23 },
  { 27187.1, 8361.30 },
  { 28023.5, 8363.15 },
  { 28858.9, 8354.79 },
  { 29692.8, 8338.39 },
  { 30524.2, 8313.94 },
  { 31352.3, 8281.45 },
  { 32176.4, 8240.92 },
  { 32995.6, 8192.34 },
  { 33809.2, 8135.72 },
  { 34616.3, 8071.06 },
  { 35416.2, 7998.35 },
  { 36207.9, 7917.60 },
  { 36990.8, 7828.80 },
  { 37764.0, 7731.97 },
  { 38526.7, 7627.08 },
  { 39278.1, 7514.16 },
  { 40017.4, 7393.19 },
  { 40743.8, 7264.18 },
  { 41456.6, 7127.12 },
  { 42154.8, 6982.02 },
  { 42837.7, 6828.88 },
  { 43504.4, 6667.69 },
  { 44154.3, 6498.46 },
  { 44786.4, 6321.19 },
  { 45400.0, 6135.87 },
  { 45994.2, 5942.51 },
  { 46568.3, 5741.10 },
  { 47121.7, 5533.82 },
  { 47654.2, 5324.69 },
  { 48165.7, 5115.56 },
  { 48656.4, 4906.42 },
  { 49126.1, 4697.29 },
  { 49574.9, 4488.16 },
  { 50002.8, 4279.03 },
  { 50409.8, 4069.89 },
  { 50795.9, 3860.76 },
  { 51161.1, 3651.63 },
  { 51505.3, 3442.49 },
  { 51828.6, 3233.36 },
  { 52131.1, 3024.23 },
  { 52412.6, 2815.09 },
  { 52673.4, 2608.13 },
  { 52914.1, 2407.36 },
  { 53135.6, 2214.63 },
  { 53338.6, 2029.94 },
  { 53523.9, 1853.30 },
  { 53692.4, 1684.70 },
  { 53844.8, 1524.14 },
  { 53982.0, 1371.63 },
  { 54104.7, 1227.16 },
  { 54213.7, 1090.73 },
  { 54310.0, 962.351 },
  { 54394.2, 842.013 },
  { 54467.2, 729.718 },
  { 54529.7, 625.467 },
  { 54582.6, 529.260 },
  { 54626.7, 441.096 },
  { 54662.8, 360.976 },
  { 54691.7, 288.899 },
  { 54714.2, 224.866 },
  { 54731.1, 168.876 },
  { 54743.2, 120.930 },
  { 54751.3, 81.0274 },
  { 54756.2, 49.1685 },
  { 54758.7, 25.3531 },
  { 54759.7, 9.58137 },
  { 54759.9, 1.85320 },
  { 54759.9, 0.00000 }
};

} // namespace RookieTrajectories