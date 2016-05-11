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
#include "shim_structs.hh"

namespace gm2 {

class ShimDataset {

 public:
  
  // Variables
  platform_t platform;
  laser_t laser;
  capacitec_t ctec;
  metrolab_t mlab;
  data_flags_t flags;
  mscb_cart_t cart;
  mscb_ring_t ring;
  tilt_sensor_t tilt;
  hall_probe_t hall;

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

  // Copy constructor
  ShimDataset(const ShimDataset &sd) {
    pf_ = new TFile(sd.pf_->GetName());
    Load();
  }

  ~ShimDataset() {
    pf_->Close();
  }

  inline const ShimDataset &operator[] (int idx) {
    GetEntry(idx);
    return *this;
  };

  // }

  inline void GetSyncEntry(int idx) {
    pt_sync_->GetEntry(idx);
  };

  inline void GetCartEntry(int idx) {
    pt_cart_->GetEntry(idx);
  };

  inline void GetRingEntry(int idx) {
    pt_ring_->GetEntry(idx);
  };

  inline void GetTiltEntry(int idx) {
    pt_tilt_->GetEntry(idx);
  };  

  inline void GetMlabEntry(int idx) {
    pt_mlab_->GetEntry(idx);
  };  

  inline void GetEntry(int idx) {
    pt_sync_->GetEntry(idx);
    pt_cart_->GetEntry(idx);
    pt_ring_->GetEntry(idx);
    pt_tilt_->GetEntry(idx);
    pt_hall_->GetEntry(idx);
    pt_mlab_->GetEntry(idx);
  };

  inline int GetSyncEntries() {
    return pt_sync_->GetEntries();
  };

  inline int GetRingEntries() {
    return pt_ring_->GetEntries();
  };

  inline int GetCartEntries() {
    return pt_cart_->GetEntries();
  };

  inline int GetTiltEntries() {
    return pt_tilt_->GetEntries();
  };

  inline int GetHallEntries() {
    return pt_hall_->GetEntries();
  };

  inline int GetMlabEntries() {
    return pt_mlab_->GetEntries();
  };

  inline TTree *pt_sync() { return pt_sync_; };
  inline TTree *pt_cart() { return pt_cart_; };
  inline TTree *pt_ring() { return pt_ring_; };
  inline TTree *pt_tilt() { return pt_tilt_; };
  inline TTree *pt_hall() { return pt_hall_; };
  inline TTree *pt_mlab() { return pt_mlab_; };

 private:
  
  TFile *pf_;
  TTree *pt_sync_;
  TTree *pt_cart_;
  TTree *pt_ring_;
  TTree *pt_tilt_; 
  TTree *pt_hall_; 
  TTree *pt_mlab_;

  inline void Load() {

    pt_sync_ = (TTree *)pf_->Get("t_sync");
    pt_cart_ = (TTree *)pf_->Get("t_cart");
    pt_ring_ = (TTree *)pf_->Get("t_ring");
    pt_tilt_ = (TTree *)pf_->Get("t_tilt");
    pt_hall_ = (TTree *)pf_->Get("t_hall");
    pt_mlab_ = (TTree *)pf_->Get("t_mlab");

    pt_sync_->SetBranchAddress("platform", &platform.sys_clock[0]);
    pt_sync_->SetBranchAddress("laser", &laser.midas_time);
    pt_sync_->SetBranchAddress("ctec", &ctec.midas_time);
    pt_sync_->SetBranchAddress("flags", &flags.platform_data);
    pt_cart_->SetBranchAddress("cart", &cart.midas_time);
    pt_ring_->SetBranchAddress("ring", &ring.midas_time);
    pt_tilt_->SetBranchAddress("tilt", &tilt.midas_time);
    pt_hall_->SetBranchAddress("hall", &hall.volt);
    pt_mlab_->SetBranchAddress("mlab", &mlab.field);
  };  

};


class ExtractedDataset {

 public:
  
  // Variables
  field_t field;
  hamar_t laser;
  capacitec_t ctec;
  metrolab_t mlab;
  sync_flags_t flags;
  scs2000_t envi;
  tilt_sensor_t tilt;
  hall_platform_t hall;

  // ctors
  ExtractedDataset(TFile *pf) { 
    pf_ = pf; 
    Load();
  };

  ExtractedDataset(char *fname) { 
    pf_ = new TFile(fname, "read"); 
    Load();
  };

  ExtractedDataset(std::string fname) { 
    pf_ = new TFile(fname.c_str(), "read");
    Load();
  };

  // Copy constructor
  ExtractedDataset(const ExtractedDataset &sd) {
    pf_ = new TFile(sd.pf_->GetName());
    Load();
  }

  ~ExtractedDataset() {
    pf_->Close();
  }

  inline const ExtractedDataset &operator[] (int idx) {
    pt_->GetEntry(idx);    
    return *this;
  };

  inline int GetEntries() {
    return pt_->GetEntries();
  };

  inline TTree *pt() { return pt_; };

 private:
  
  TFile *pf_;
  TTree *pt_;

  inline void Load() {

    pt_ = (TTree *)pf_->Get("t");

    pt_->SetBranchAddress("field", &field.sys_clock[0]);
    pt_->SetBranchAddress("laser", &laser.midas_time);
    pt_->SetBranchAddress("ctec", &ctec.midas_time);
    pt_->SetBranchAddress("flags", &flags.platform_data);
    pt_->SetBranchAddress("envi", &envi.midas_time);
    pt_->SetBranchAddress("tilt", &tilt.midas_time);
    pt_->SetBranchAddress("hall", &hall.volt);
    pt_->SetBranchAddress("mlab", &mlab.field);
  };  

};

} // ::gm2

#endif
