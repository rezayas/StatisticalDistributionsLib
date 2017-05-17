#pragma once
#include "Gamma.h"

namespace StatisticalDistributions {
  class ChiSquared : public Gamma {
  public:
    // This needs no explanation, I hope.
    ChiSquared(long double dof = 1);
  };
}
