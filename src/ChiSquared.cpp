#include "ChiSquared.h"

namespace StatisticalDistributions {
  void ChiSquared::init(long double dof) {
    Gamma::init(dof/2, 2);
  }
}

