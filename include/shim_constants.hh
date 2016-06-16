#ifndef GM2_FIELD_CORE_INCLUDE_SHIM_CONSTANTS_HH_
#define GM2_FIELD_CORE_INCLUDE_SHIM_CONSTANTS_HH_

/*===========================================================================*\

author: Matthias W. Smith
email:  mwsmith2@uw.edu
file:   shim_constants.hh

about:  A header file for shimming constants.

\*===========================================================================*/

//--- std includes  ---------------------------------------------------------//

namespace gm2 {

// General constants
constexpr double storage_rad = 7112.0;
constexpr double field_khz_to_ppm = 61790.0 * 1.0e-6;

// NMR constants
constexpr double nmr_sample_period = 0.0001;

// Multipole constants
constexpr int num_multipoles = 16;

// Platform constants
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
  { 0.0000000000,-4.5000000000},
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
  { 4.5000000000,-1.5707963268},
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

constexpr double pole_start_angle(int pole_id) {
  return pole_id * 10.0 - 15;
}

constexpr double pole_stop_angle(int pole_id) {
  return pole_id * 10.0 - 5.0;
}

// Laser constants
constexpr double laser_phi_offset =  1.971;

} // ::gm2

#endif
