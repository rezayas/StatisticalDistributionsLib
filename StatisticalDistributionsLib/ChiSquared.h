#pragma once
#include "Gamma.h"

namespace StatisticalDistributions {
  class ChiSquared : public Gamma {
  public:
    ChiSquared(long double dof = 1);
  };
}
