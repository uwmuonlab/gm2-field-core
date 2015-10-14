#ifndef GM2_FIELD_CORE_INCLUDE_SHIM_DATASET_HH_
#define GM2_FIELD_CORE_INCLUDE_SHIM_DATASET_HH_

/*===========================================================================*\

author: Matthias W. Smith
email:  mwsmith2@uw.edu
file:   shim_dataset.hh

about:  A class meant to handle shimming data in a nice way, load all the
        structs and attach them to branches.  That kind of thing.

\*===========================================================================*/

//--- std includes  ---------------------------------------------------------//

//--- other includes --------------------------------------------------------//
#include "TFile.h"
#include "TTree.h"        

//--- projects includes -----------------------------------------------------//
#include "types/nmr_structs.hh"

namespace gm2 {


class ShimDataset {

 public:
  
  // ctor
  ShimDataset(TFile *pf);
  ShimDataset(std::string rootfile);
  ShimDataset(char *rootfile);

  ~ShimDataset() {
    pf_->Close();
  }

  platform_t platform;
  hamar_t laser;
  scs2000_t envi;

  // const &ShimDataset operator[] {

  // }

  void GetSyncEntry(int idx) {
    pt_sync_->GetEntry(idx);
  };

  void GetEnviEntry(int idx) {
    pt_envi_->GetEntry(idx);
  };

  void GetEntry(int idx) {
    pt_sync_->GetEntry(idx);
    pt_envi_->GetEntry(idx);
  };

  int GetSyncEntries() {
    return pt_sync_->GetEntries();
  };

  int GetEnviEntries() {
    return pt_sync_->GetEntries();
  };


 private:
  
  TFile *pf_;
  TTree *pt_sync_;
  TTree *pt_envi_;

  void Load();
};

} // ::gm2

#endif
