#pragma once
#include "Gamma.h"

namespace StatisticalDistributions {
  class ChiSquared : public Gamma {
  public:
    // This needs no explanation, I hope.
    inline ChiSquared(long double dof = 1) {
      init(dof);
    }
    void init(long double = 1); 
  };
}
