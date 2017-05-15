#pragma once
#include "StatisticalDistribution.h"

namespace StatisticalDistributions {
  class Uniform : public StatisticalDistribution {
  public:
    Uniform(long double min, long double max);
    virtual long double pdf(long double value);
    virtual long double cdf(long double value);
    virtual long double Sample(RNG &rng);
    virtual long double Inverse(long double value);
    virtual long double operator()(std::mt19937_64 &g);
  private:
    const long double min, max;
    std::uniform_real_distribution<long double> dist;
  };
}
