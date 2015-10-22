#ifndef GM2_FIELD_CORE_INCLUDE_PLATFORM_COORDS_HH_
#define GM2_FIELD_CORE_INCLUDE_PLATFORM_COORDS_HH_

/*===========================================================================*\

author: Matthias W. Smith
email:  mwsmith2@uw.edu
file:   shim_platform.hh

about:  A class that holds specific attributes of the shimming platform, like
        probe coordinates.

\*===========================================================================*/

#define NMR_FID_LN 100000
#define SHORT_FID_LN 10000
#define SHIM_PLATFORM_CH 28
#define SHIM_FIXED_CH 4

//--- std includes  ---------------------------------------------------------//

namespace gm2 {

// Constants
constexpr double storage_rad = 7112.0;

constexpr int platform_nprobes = 25;
constexpr double platform_rad = 4.5;

constexpr double platform_cart[25][2] = {
  { 0.0000000000,-0.0000000000},
  { 0.0000000000,-2.2500000000},
  { 1.5909902577,-1.5909902577},
  { 2.2500000000, 0.0000000000},
  { 1.5909902577, 1.5909902577},
  { 0.0000000000, 2.2500000000},
  {-1.5909902577, 1.5909902577},
  {-2.2500000000, 0.0000000000},
  {-1.5909902577,-1.5909902577},
  { 0.0000000000, 0.0000000000},
  { 1.7220754456,-4.1574578963},
  { 3.1819805153,-3.1819805153},
  { 4.1574578963,-1.7220754456},
  { 4.5000000000, 0.0000000000},
  { 4.1574578963, 1.7220754456},
  { 3.1819805153, 3.1819805153},
  { 1.7220754456, 4.1574578963},
  { 0.0000000000, 4.5000000000},
  {-1.7220754456, 4.1574578963},
  {-3.1819805153, 3.1819805153},
  {-4.1574578963, 1.7220754456},
  {-4.5000000000, 0.0000000000},
  {-4.1574578963,-1.7220754456},
  {-3.1819805153,-3.1819805153},
  {-1.7220754456,-4.1574578963}
};

constexpr double platform_polar[25][2] = {
  { 0.0000000000,-1.5707963268},
  { 2.2500000000,-1.5707963268},
  { 2.2500000000,-0.7853981634},
  { 2.2500000000, 0.0000000000},
  { 2.2500000000, 0.7853981634},
  { 2.2500000000, 1.5707963268},
  { 2.2500000000, 2.3561944902},
  { 2.2500000000, 3.1415926536},
  { 2.2500000000, 3.9269908170},
  { 0.0000000000, 0.0000000000},
  { 4.5000000000,-1.1780972451},
  { 4.5000000000,-0.7853981634},
  { 4.5000000000,-0.3926990817},
  { 4.5000000000, 0.0000000000},
  { 4.5000000000, 0.3926990817},
  { 4.5000000000, 0.7853981634},
  { 4.5000000000, 1.1780972451},
  { 4.5000000000, 1.5707963268},
  { 4.5000000000, 1.9634954085},
  { 4.5000000000, 2.3561944902},
  { 4.5000000000, 2.7488935719},
  { 4.5000000000, 3.1415926536},
  { 4.5000000000, 3.5342917353},
  { 4.5000000000, 3.9269908170},
  { 4.5000000000, 4.3196898987}
};

constexpr std::map<std::string, double> offset_map = {
  {"laser_p2_to_p1", 1.971},
  {"laser_p1_to_p2",-1.971}
};

constexpr laser_p2_to_p1(double x) {
  x += offset_map["laser_p2_to_p1"];
  if (x >= 360.0) {
    x -= 360.0;
  } else if (x <= 0.0) {
    x += 360.0;
  }
}

constexpr laser_p1_to_p2(double x) {
  x += offset_map["laser_p1_to_p2"];
  if (x >= 360.0) {
    x -= 360.0;
  } else if (x <= 0.0) {
    x += 360.0;
  }
}

} // ::gm2

#endif
