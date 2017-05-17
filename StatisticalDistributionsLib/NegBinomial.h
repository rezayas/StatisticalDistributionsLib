#pragma once
#include "GammaPoisson.h"

namespace StatisticalDistributions {
  class NegBinomial : public GammaPoisson {
  public:
    NegBinomial(long n, long double p = .5);
    virtual long operator()(std::mt19937_64 &g);
  private:
    std::negative_binomial_distribution<long> dist;
  };
}
