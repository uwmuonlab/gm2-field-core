gm2-field-anlysis
===

This is the start of a repository containing code for field anlysis on the g-2 experiment.

Planned Components
---

* fid-analysis
* shim platform specifics
* specific shim data loader

Features
---

Simple loading for shimming root datafiles if you just include the headers.  You can something like:

```
#include "shim_dataset.hh"
#include "platform_coords.hh"

using namespace std;
using namespace gm2;

int main(int argc, char **argv)
{
  ShimDataset d(argv[1]);
  PlatformCoords p;

  for (int i = 0; i < d.GetSyncEntries(); ++i) {
    cout << d[i].platform.freq[0] << endl;
  }

  cout << p.coords[1][0] << ", " << p.coords[1][1] << endl;
  return 0;
}
```

Here, ShimDataset attaches structs to the TTrees and using the index [], does get entry for you.  The regular TTrees can be access with d->t_sync() and d->t_envi().

