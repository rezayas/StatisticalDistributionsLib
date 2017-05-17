#pragma once
#include "StatisticalDistribution.h"

namespace StatisticalDistributions {
  class UniformDiscrete : public StatisticalDistribution<long> {
  public:
    // Uniform on low <= i < high
    UniformDiscrete(long low, long high);
    // Uniform on 0 <= i < n
    UniformDiscrete(long n);
    virtual long double pdf(long value);
    virtual long double cdf(long value);
    virtual long Inverse(long double value);
    virtual long operator()(std::mt19937_64 &g);
  private:
    const long low, high;
    std::uniform_int_distribution<long> dist;
  };
}
