#pragma once
#include "GammaPoisson.h"

namespace StatisticalDistributions {
  class NegBinomial : public GammaPoisson {
  public:
    // n is number of successes; p is probability of success
    NegBinomial(long n, long double p = .5) {
      init(n, p);
    }
    void init(long, long double = .5);
    virtual long operator()(std::mt19937_64 &g) const;
  private:
    mutable std::negative_binomial_distribution<long> dist;
  };
}
