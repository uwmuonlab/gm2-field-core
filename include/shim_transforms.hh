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

} // ::nmr

#endif
