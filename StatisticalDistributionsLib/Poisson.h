#pragma once
#include "StatisticalDistribution.h"

namespace StatisticalDistributions {
  class Poisson : public StatisticalDistribution<long> {
  public:
    // μ is the expected value here.
    Poisson(long double mu = 1);
    virtual long double pdf(long value);
    virtual long double cdf(long value);
    virtual long Inverse(long double value);
    virtual long operator()(std::mt19937_64 &g);
  private:
    const long double mu;
    std::poisson_distribution<long> dist;
  };
}
