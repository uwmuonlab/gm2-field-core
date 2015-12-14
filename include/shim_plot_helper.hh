#ifndef GM2_FIELD_CORE_INCLUDE_SHIM_PLOT_HELPER_HH_
#define GM2_FIELD_CORE_INCLUDE_SHIM_PLOT_HELPER_HH_

/*===========================================================================*\

author: Matthias W. Smith
email:  mwsmith2@uw.edu
file:   shim_plot_helper.hh

about:  A class meant to facilitate making plots with the shim data.

\*===========================================================================*/

//--- std includes  ---------------------------------------------------------//

//--- other includes --------------------------------------------------------//
#include "TFile.h"
#include "TTree.h"        

//--- projects includes -----------------------------------------------------//
#include "shim_struct.hh"
#include "shim_datasets.hh"

namespace gm2 {

struct plotlabels_t {
  std::string title;
  std::string xlabel;
  std::string ylabel;
  std::string legend;
};

plot_from_tree(ShimDataset d, 
               std::string branch_vars, 
               std::string figname
               plotlabels_t plabels=NULL);


template T1, T2
plot_as_TGraph(T &a, T &b, plotlabels_t)

} // ::gm2

#endif
