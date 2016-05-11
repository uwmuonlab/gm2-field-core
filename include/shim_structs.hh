#ifndef GM2_FIELD_CORE_INCLUDE_SHIM_STRUCTS_HH_
#define GM2_FIELD_CORE_INCLUDE_SHIM_STRUCTS_HH_

/*===========================================================================*\

author: Matthias W. Smith
email:  mwsmith2@uw.edu
file:   shim_structs.hh

about:  Contains the data structures for several hardware devices in a single
        location.  The header should be included in any program that aims
        to interface with (read or write) data with this daq.

\*===========================================================================*/

//--- other includes --------------------------------------------------------//
#include "TFile.h"

//--- projects includes -----------------------------------------------------//
#include "shim_constants.hh"

namespace gm2 {

const double laser_phi_offset_p2_to_p1 = 1.971;

// NMR specific stuff
struct platform_t {
  Double_t sys_clock[28];
  Double_t gps_clock[28];
  Double_t dev_clock[28];
  Double_t snr[28];
  Double_t len[28];
  Double_t freq[28];
  Double_t ferr[28];
  Double_t freq_zc[28];
  Double_t ferr_zc[28];
  UShort_t health[28];
  UShort_t method[28];
  UShort_t trace[28][10000];
};

const char * const platform_str = "sys_clock[28]/D:gps_clock[28]/D:"\
"dev_clock[28]/D:snr[28]/D:len[28]/D:freq[28]/D:ferr[28]/D:freq_zc[28]/D:"\
"ferr_zc[28]/D:health[28]/s:method[28]/s:trace[28][10000]/s";

// NMR specific stuff
struct long_platform_t {
  Double_t sys_clock[28];
  Double_t gps_clock[28];
  Double_t dev_clock[28];
  Double_t snr[28];
  Double_t len[28];
  Double_t freq[28];
  Double_t ferr[28];
  Double_t freq_zc[28];
  Double_t ferr_zc[28];
  UShort_t health[28];
  UShort_t method[28];
  UShort_t trace[28][100000];
};

const char * const long_platform_str = "sys_clock[28]/D:gps_clock[28]/D:"\
"dev_clock[28]/D:snr[28]/D:len[28]/D:freq[28]/D:ferr[28]/D:freq_zc[28]/D:"\
"ferr_zc[28]/D:health[28]/s:method[28]/s:trace[28][100000]/s";

// Note that phi_1 & phi_2 will be calculated from eachother, but not r, z.
struct laser_t {
  Int_t midas_time;
  Float_t r_1;
  Float_t z_1;
  Float_t phi_1;
  Float_t r_2;
  Float_t z_2;
  Float_t phi_2;
};

const char *const laser_str = 
"midas_time/I:r_1/F:z_1/F:phi_1/F:r_2/F:z_2/F:phi_2/F";

struct capacitec_t {
  Int_t midas_time;
  Float_t inner_up;
  Float_t inner_lo;
  Float_t outer_up;
  Float_t outer_lo;
};

const char *const capacitec_str = 
"midas_time/I:inner_up/F:inner_lo/F:outer_up/F:outer_lo/F";

struct mscb_cart_t {
  Int_t midas_time;
  Float_t temp[8];
  Float_t ctec[4];
};

const char *const mscb_cart_str = "midas_time/I:temp[8]/F:ctec[4]/F";

struct mscb_ring_t {
  Int_t midas_time;
  Float_t temp[12];
};

const char *const mscb_ring_str = "midas_time/I:temp[12]/F";

struct tilt_sensor_t {
  Int_t midas_time;
  Int_t temp;
  Int_t phi;
  Int_t rad;
};

const char *const tilt_sensor_str = "midas_time/I:temp/I:phi/I:rad/I";

struct hall_probe_t {
  Double_t volt;
  Double_t temp;
  Int_t midas_time;
};

const char *const hall_probe_str = "volt/D:temp/D:midas_time/I";

struct metrolab_t {
  Double_t field;
  Int_t midas_time;
  Int_t state;
  Int_t units;
  Bool_t locked;
  Bool_t is_tesla;
};

const char *const metrolab_str = "field/D:midas_time/I:state/I:units/I:locked/O:"\
"in_tesla/O";

struct data_flags_t {
  Bool_t platform_data;
  Bool_t laser_data;
  Bool_t ctec_data;
  Bool_t mlab_data;
  Bool_t tilt_data;
  Bool_t hall_data;
  Bool_t mscb_cart_data;
  Bool_t mscb_ring_data;
  Bool_t laser_p1;
  Bool_t laser_p2;
  Bool_t laser_swap;
  Bool_t missing_probe19;
};

const char *const data_flags_str = 
"platform_data/O:laser_data/O:ctec_data/O:metro_data/O:tilt_data/O:"
"hall_data/O:mscb_cart_data/O:mscb_ring_data/O:laser_p1/O:laser_p2/O:"\
"laser_swap/O:missing_probe19/O";

// Structs for derived datasets
struct field_t {
  Double_t sys_clock[28];
  Double_t freq[28];
  Double_t snr[28];
  Double_t len[28];
  Double_t multipole[16];
};

const char *const field_str = 
"sys_clock[28]/D:freq[28]/D:snr[28]/D:len[28]/D:multipole[16]/D";

struct ring_t {
  Double_t r;
  Double_t phi;
  Double_t z;
  Double_t gap_inner;
  Double_t gap_outer;
  Double_t gap_mean;
  Double_t gap_diff;
  Int_t pole_id;
  Int_t yoke_id;
};

const char *const ring_str = 
"r/D:phi/D:z/D:gap_inner/D:gap_outer/D:gap_mean/D:/gap_diff/D:"\
"pole_id/I:yoke_id/I";

} // ::gm2

#endif
