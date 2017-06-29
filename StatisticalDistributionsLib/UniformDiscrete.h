#pragma once
#include "StatisticalDistribution.h"

namespace StatisticalDistributions {
  class UniformDiscrete : public StatisticalDistribution<long> {
  public:
    // Uniform on low <= i < high
    UniformDiscrete(long low, long high);
    // Uniform on 0 <= i < n
    UniformDiscrete(long n);
    virtual long double pdf(long value) const;
    virtual long double cdf(long value) const;
    virtual long Inverse(long double value) const;
    virtual long operator()(std::mt19937_64 &g) const;
  private:
    const long low, high;
    mutable std::uniform_int_distribution<long> dist;
  };
}
