#pragma once
#include "StatisticalDistribution.h"

namespace StatisticalDistributions {
  class UniformDiscrete : public StatisticalDistribution<bool> {
  public:
    UniformDiscrete(long low, long high);
    UniformDiscrete(long n)
    virtual long double pdf(long value);
    virtual long double cdf(long value);
    virtual long Inverse(long double value);
    virtual long operator()(std::mt19937_64 &g);
  private:
    const long low, high;
    std::uniform_int_distribution<long> dist;
  };
}
