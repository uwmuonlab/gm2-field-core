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
#include "shim_analyzer.hh"

using namespace std;
using namespace gm2;

int main(int argc, char **argv)
{
  assert(argc > 1);
  ShimDataset d(argv[1]);
  cout.precision(6);

  cout << "phi ";
  for (int i = 0; i < platform_nprobes; ++i) {
    cout << "mm_" << i << " ";
  }
  cout << endl;

  for (int idx = 0; idx < 2; ++idx) {
//  for (int idx = 0; idx < d.GetSyncEntries(); ++idx) {

    auto multipoles = fit_multipoles(d[idx].platform);

    // cout << d.laser.phi_1 << " ";
    // for (int i = 0; i < platform_nprobes; ++i) {
    //   cout << d.platform.freq[i] << " ";
    // }
    // cout << endl;

    for (auto &v : multipoles) {
      cout << v / 61790.0 * 1.0e6 << " ";
    }

    cout << endl;
  }

  return 0;
}
