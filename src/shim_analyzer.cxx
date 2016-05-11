#include "shim_analyzer.hh"

namespace gm2 {

std::vector<double> fit_multipoles(platform_t platform)
{
  using namespace ROOT::Math;
  // Solve a linear multipole fit of form y = Mx + eps.
  // The minimizing solution is x - (M^T * M)-1*M^T = 0.

  // Initialization.
  const int nprobes = platform_nprobes;
  static bool initialized = false;

  static SMatrix<double, nprobes, num_multipoles> M;
  static SMatrix<double, num_multipoles, nprobes> S;
  static SVector<double, nprobes> y;
  static SVector<double, num_multipoles> x;
  static std::vector<double> x_ret(num_multipoles, 0.0);

  if (!initialized) {

    int n;
    bool skew;
    double rho, phi, val;

    for (int i = 0; i < nprobes; ++i) {

      for (int j = 0; j < num_multipoles; ++j) {

        n = (j + 1) / 2;
        skew = ((j % 2) == 0);

        rho = platform_polar[i][0] / platform_rad;
        phi = platform_polar[i][1];

        if (j == 0) {
          skew = false;
        }

        if (skew) {

          val = sin(n * phi);

          if (std::abs(val) < 1.0e-20) {
            val = 0.0;
          }          

        } else {

          val = cos(n * phi);

          if (std::abs(val) < 1.0e-20) {
            val = 0.0;
          }
        }

        val *= pow(rho, n);
        M(i, j) = val;
      }
    }

    int rc;
    double det;

    SMatrix<double, num_multipoles, nprobes> M_t;
    SMatrix<double, num_multipoles, num_multipoles> I;    
    M_t = Transpose(M);
    I = M_t * M;

    I.Det2(det);
    S = I.Inverse(rc) * M_t;

    initialized = true;
  }

  for (int i = 0; i < nprobes; ++i) {
    y[i] = platform.freq[i];
  }

  x = S * y;

  for (int i = 0; i < num_multipoles; ++i) {
    int n = (i + 1) / 2;
    x_ret[i] = x[i];
    // std::cout << i << ": ";
    // for (int j = 0; j < nprobes; ++j) {
    //   printf("% 1.1e,", M(j, i));
    // }
    // std::cout << std::endl;
  }

//  S.Print(std::cout);
//  M.Print(std::cout);
//  std::cout << M * x << std::endl;

  return x_ret;
}

std::vector<double> fit_weighted_multipoles(platform_t platform)
{
  using namespace ROOT::Math;
  // Solve a linear multipole fit of form Wy = MWM^Tx + eps.
  // The minimizing solution is x - (M^T * W * M)^(-1) * W * M^T = 0.

  // Initialization.
  const int nprobes = platform_nprobes;
  static bool initialized = false;

  static SMatrix<double, nprobes, nprobes> W;
  static SMatrix<double, nprobes, num_multipoles> M;
  static SMatrix<double, num_multipoles, nprobes> S;
  static SVector<double, nprobes> y;
  static SVector<double, num_multipoles> x;
  static std::vector<double> x_ret(num_multipoles, 0.0);

  if (!initialized) {

    int n;
    bool skew;
    double rho, phi, val;

    for (int i = 0; i < nprobes; ++i) {

      for (int j = 0; j < num_multipoles; ++j) {

        n = (j + 1) / 2;
        skew = ((j % 2) == 0);

        rho = platform_polar[i][0] / platform_rad;
        phi = platform_polar[i][1];

        if (j == 0) {
          skew = false;
        }

        if (skew) {

          val = sin(n * phi);

          if (std::abs(val) < 1.0e-20) {
            val = 0.0;
          }          

        } else {

          val = cos(n * phi);

          if (std::abs(val) < 1.0e-20) {
            val = 0.0;
          }
        }

        val *= pow(rho, n);
        M(i, j) = val;
      }
    }

    initialized = true;
  }

  for (int i = 0; i < nprobes; ++i) {
    y[i] = platform.freq[i];
    W(i, i) = pow(10.0, 0.1 * platform.health[i]  - 9.0) / 10.0;
  }

  int rc;
  double det;

  SMatrix<double, num_multipoles, nprobes> M_t;
  SMatrix<double, num_multipoles, num_multipoles> I;    

  M_t = Transpose(M);
  I = M_t * W * M;

  I.Det2(det);
  S = I.Inverse(rc) * M_t * W;

  x = S * y;

  for (int i = 0; i < num_multipoles; ++i) {
    int n = (i + 1) / 2;
    x_ret[i] = x[i];
    // std::cout << i << ": ";
    // for (int j = 0; j < nprobes; ++j) {
    //   printf("% 1.1e,", M(j, i));
    // }
    // std::cout << std::endl;
  }

//  S.Print(std::cout);
//  M.Print(std::cout);
//  std::cout << M * x << std::endl;

  return x_ret;
}

} // ::gm2