#ifndef GM2_FIELD_CORE_INCLUDE_PLATFORM_COORDS_HH_
#define GM2_FIELD_CORE_INCLUDE_PLATFORM_COORDS_HH_

/*===========================================================================*\

author: Matthias W. Smith
email:  mwsmith2@uw.edu
file:   shim_platform.hh

about:  A class that holds specific attributes of the shimming platform, like
        probe coordinates.

\*===========================================================================*/

//--- std includes  ---------------------------------------------------------//

//--- other includes --------------------------------------------------------//

//--- projects includes -----------------------------------------------------//

namespace gm2 {

class PlatformCoords
{
 public:
  
  const int nprobes = 25;
  const double radius = 4.5;
  const double coords[25][2] = {
    { 0.000, 0.000},
    { 2.250, 0.000},
    { 1.591, 1.591},
    { 0.000, 2.250},
    {-1.591, 1.591},
    {-2.250, 0.000},
    {-1.591,-1.591},
    { 0.000,-2.250},
    { 1.591,-1.591},
    { 4.500, 0.000},
    { 4.157, 1.722},
    { 3.182, 3.182},
    { 1.722, 4.157},
    { 0.000, 4.500},
    {-1.722, 4.157},
    {-3.182, 3.182},
    {-4.157, 1.722},
    {-4.500, 0.000},
    {-4.157,-1.722},
    {-3.182,-3.182},
    {-1.722,-4.157},
    {-0.000,-4.500},
    { 1.722,-4.157},
    { 3.182,-3.182},
    { 4.157,-1.722}
  };

  const std::map<std::string, double> laser_offset = {
    {"P1", 1.5},
    {"P2", 1.5},
  };

  PlatformCoords() {};

};

} // ::gm2

#endif
