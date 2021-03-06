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
#include "t_sync.h"

//--- other includes --------------------------------------------------------//

//--- project includes ------------------------------------------------------//
#include "shim_dataset.hh"
#include "platform_coords.hh"

using namespace std;
using namespace gm2;

int main(int argc, char **argv)
{
  assert(argc > 1);
  ShimDataset d(argv[1]);
  PlatformCoords p;
  cout.precision(16);

  for (int i = 0; i < d.GetSyncEntries(); ++i) {
    cout << d[i].platform.freq[0] << endl;
  }

  cout << p.coords[1][0] << ", " << p.coords[1][1] << endl;
  return 0;
}
