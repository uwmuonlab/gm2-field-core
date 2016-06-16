#ifndef GM2_FIELD_CORE_INCLUDE_SHIM_TRANSFORMS_HH_
#define GM2_FIELD_CORE_INCLUDE_SHIM_TRANSFORMS_HH_

/*===========================================================================*\

author: Matthias W. Smith
email:  mwsmith2@uw.edu
file:   shim_transforms.hh

about:  Contains coordinate transformation functions that will be useful
        for shimming analysis.

\*===========================================================================*/

//--- other includes --------------------------------------------------------//
#include "TFile.h"

//--- projects includes -----------------------------------------------------//
#include "shim_constants.hh"

namespace gm2 {

double laser_phi_p2_to_p1(double x) {
  x -= laser_phi_offset;

  if (x >= 360.0) {
    x -= 360.0;
  } else if (x <= 0.0) {
    x += 360.0;
  }

  return x;
};

double laser_phi_p1_to_p2(double x) {
  x += laser_phi_offset;

  if (x >= 360.0) {
    x -= 360.0;
  } else if (x <= 0.0) {
    x += 360.0;
  }

  return x;
};

// Copy one channel b in pb to a in pa
void platform_copy_channel(platform_t& pa, int a, platform_t& pb, int b)
{
  pa.sys_clock[a] = pb.sys_clock[b];
  pa.gps_clock[a] = pb.gps_clock[b];
  pa.dev_clock[a] = pb.dev_clock[b];
  pa.snr[a] = pb.snr[b];
  pa.len[a] = pb.len[b];
  pa.freq[a] = pb.freq[b];
  pa.ferr[a] = pb.ferr[b];
  pa.freq_zc[a] = pb.freq_zc[b];
  pa.ferr_zc[a] = pb.ferr_zc[b];
  pa.health[a] = pb.health[b];
  pa.method[a] = pb.method[b];
  std::copy(&pb.trace[b][0], &pb.trace[b][SAVE_FID_LN], &pa.trace[a][0]);
}

} // ::gm2

#endif
