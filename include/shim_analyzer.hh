#ifndef GM2_FIELD_CORE_INCLUDE_SHIM_ANALYZER_HH_
#define GM2_FIELD_CORE_INCLUDE_SHIM_ANALYZER_HH_

/*===========================================================================*\

author: Matthias W. Smith
email:  mwsmith2@uw.edu
file:   shim_analyzer.hh

about:  A class meant to handle the initial analysis of shim datasets.

\*===========================================================================*/

//--- std includes  ---------------------------------------------------------//

//--- other includes --------------------------------------------------------//
#include "TFile.h"
#include "TTree.h"        
#include "Math/SMatrix.h"
#include "Math/SVector.h"

//--- projects includes -----------------------------------------------------//
#include "shim_structs.hh"
#include "shim_dataset.hh"

namespace gm2 {

std::vector<double> fit_multipoles(platform_t platform);

std::vector<double> fit_weighted_multipoles(platform_t platform);

// class ShimAnalyzer {

//  public:

//   ShimAnalyzer(std::string rootfile) {
//     data_ = ShimDataset(rootfile);
//   };

//   ShimAnalyzer(const ShimDatset &data) {
//     data_ = data;
//   }
  
//  private:

//   ShimDataset data_;
//   PlatformCoords platform_coords_;

//   void FitMultipoles();
// };

} // ::gm2

#endif
