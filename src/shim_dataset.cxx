#include "shim_dataset.hh"

namespace gm2 {

ShimDataset::ShimDataset(TFile *pf) {

  pf_ = pf;
}

ShimDataset::ShimDataset(std::string rootfile) {

  pf_ = new TFile(rootfile.c_str(), "read");
}

ShimDataset::ShimDataset(char *rootfile) {

  pf_ = new TFile(rootfile, "read");
}

void ShimDataset::Load() {

  pt_sync_ = (TTree *)pf_->Get("t_sync");
  pt_envi_ = (TTree *)pf_->Get("t_envi");

  pt_sync_->SetBranchAddress("platform", &platform.sys_clock[0]);
  pt_sync_->SetBranchAddress("laser", &laser.midas_time);
  pt_envi_->SetBranchAddress("envi", &envi.midas_time);
}

} // ::gm2