/*===========================================================================*\

author: Matthias W. Smith
email:  mwsmith2@uw.edu
date:   2015/09/04

about: The program runs on a shim data in a specific format

usage:

./make_stability_plots <input-file> [output-dir]

\*===========================================================================*/

//--- std includes ----------------------------------------------------------//
#include <cassert>
#include <iostream>

//--- other includes --------------------------------------------------------//

//--- project includes ------------------------------------------------------//
#include "shim_dataset.hh"

using namespace std;
using namespace gm2;

int main(int argc, char **argv)
{
  assert(argc > 1);
  ExtractedDataset d(argv[1]);
  cout.precision(8);

  cout << "field.freq[0] = " << d[0].field.freq[0] << endl;
  cout << "field.mp[0] = " << d[0].field.multipole[0] << endl;  
  cout << "tilt.phi = " << d[0].tilt.phi << endl;
  cout << "ctec.inner_up = " << d[0].ctec.inner_up << endl;
  cout << "platform_coords[1] = " << platform_cart[1][0];
  cout  << ", " << platform_cart[1][1] << endl;

  return 0;
}
