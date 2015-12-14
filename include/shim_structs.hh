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
// A macro to define nmr structs since they are very similar.
#define MAKE_NMR_STRUCT(name, num_ch, len_tr)\
struct name {\
  Double_t sys_clock[num_ch];\
  Double_t gps_clock[num_ch];\
  Double_t dev_clock[num_ch];\
  Double_t snr[num_ch];\
  Double_t len[num_ch];\
  Double_t freq[num_ch];\
  Double_t ferr[num_ch];\
  Double_t freq_zc[num_ch];\
  Double_t ferr_zc[num_ch];\
  UShort_t health[num_ch];\
  UShort_t method[num_ch];\
  UShort_t trace[num_ch][len_tr];\
};

// Might as well define a root branch string for the struct.
#define NMR_HELPER(name, num_ch, len_tr) \
const char * const name = "sys_clock["#num_ch"]/D:gps_clock["#num_ch"]/D:"\
"dev_clock["#num_ch"]/D:snr["#num_ch"]/D:len["#num_ch"]/D:freq["#num_ch"]/D:"\
"ferr["#num_ch"]/D:freq_zc["#num_ch"]/D:ferr_zc["#num_ch"]/D:"\
"health["#num_ch"]/s:method["#num_ch"]/s:trace["#num_ch"]["#len_tr"]/s"

#define MAKE_NMR_STRING(name, num_ch, len_tr) NMR_HELPER(name, num_ch, len_tr)

MAKE_NMR_STRUCT(platform_t, SHIM_PLATFORM_CH, SHORT_FID_LN);
MAKE_NMR_STRING(platform_str, SHIM_PLATFORM_CH, SHORT_FID_LN);

struct field_t {
  Double_t sys_clock[28];
  Double_t freq[28];
  Double_t snr[28];
  Double_t len[28];
  Double_t multipole[16];
};

const char *const field_str = 
"sys_clock[28]/D:freq[28]/D:snr[28]/D:len[28]/D:multipole[16]/D";

// Note that phi_1 & phi_2 will be calculated from eachother, but not r, z.
struct hamar_t {
  Int_t midas_time;
  Float_t r_1;
  Float_t z_1;
  Float_t phi_1;
  Float_t r_2;
  Float_t z_2;
  Float_t phi_2;
};

const char *const hamar_str = 
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

struct scs2000_t {
  Int_t midas_time;
  Float_t temp[8];
  Float_t ctec[4];
};

const char *const scs2000_str = "midas_time/I:temp[8]/F:ctec[4]/F";

struct tilt_sensor_t {
  Int_t midas_time;
  Int_t temp;
  Int_t phi;
  Int_t rad;
};

const char *const tilt_sensor_str = "midas_time/I:temp/I:phi/I:rad/I";

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

struct sync_flags_t {
  Bool_t platform_data;
  Bool_t laser_data;
  Bool_t ctec_data;
  Bool_t mlab_data;
  Bool_t envi_data;
  Bool_t tilt_data;
  Bool_t laser_p1;
  Bool_t laser_p2;
  Bool_t laser_swap;
  Bool_t missing_probe19;
};

const char *const sync_flags_str = 
"platform_data/O:laser_data/O:ctec_data/O:metro_data/O:envi_data/O:"\
"tilt_data/O:laser_p1/O:laser_p2/O:laser_swap/O:missing_probe19/O";

} // ::gm2

#endif
