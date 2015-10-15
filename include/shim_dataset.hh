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
  
  // ctors
  ShimDataset(TFile *pf) { 
    pf_ = pf; 
    Load();
  };

  ShimDataset(char *fname) { 
    pf_ = new TFile(fname, "read"); 
    Load();
  };

  ShimDataset(std::string fname) { 
    pf_ = new TFile(fname.c_str(), "read");
    Load();
  };

  ~ShimDataset() {
    pf_->Close();
  }

  platform_t platform;
  hamar_t laser;
  scs2000_t envi;

  // const &ShimDataset operator[] {

  // }

  inline void GetSyncEntry(int idx) {
    pt_sync_->GetEntry(idx);
  };

  inline void GetEnviEntry(int idx) {
    pt_envi_->GetEntry(idx);
  };

  inline void GetEntry(int idx) {
    pt_sync_->GetEntry(idx);
    pt_envi_->GetEntry(idx);
  };

  inline int GetSyncEntries() {
    return pt_sync_->GetEntries();
  };

  inline int GetEnviEntries() {
    return pt_sync_->GetEntries();
  };

 private:
  
  TFile *pf_;
  TTree *pt_sync_;
  TTree *pt_envi_;

  inline void Load() {

    pt_sync_ = (TTree *)pf_->Get("t_sync");
    pt_envi_ = (TTree *)pf_->Get("t_envi");

    pt_sync_->SetBranchAddress("platform", &platform.sys_clock[0]);
    pt_sync_->SetBranchAddress("laser", &laser.midas_time);
    pt_envi_->SetBranchAddress("envi", &envi.midas_time);
  };  

} // ::gm2

#endif
