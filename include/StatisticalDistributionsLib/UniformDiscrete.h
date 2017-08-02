#pragma once
#include "StatisticalDistribution.h"

namespace StatisticalDistributions {
  class UniformDiscrete : public StatisticalDistribution<long> {
  public:
    // Uniform on low <= i < high
    inline UniformDiscrete(long low, long high) {
      init(low, high);
    }
    // Uniform on 0 <= i < n
    inline UniformDiscrete(long n) {
      init(0, n);
    }
    inline void init(long n) {
      init(0, n);
    }
    void init(long, long);
    virtual long double pdf(long value) const;
    virtual long double cdf(long value) const;
    virtual long Inverse(long double value) const;
    virtual long operator()(std::mt19937_64 &g) const;
    ACCESSORC(low, plow);
    ACCESSORC(high, phigh);
  private:
    long plow, phigh;
    mutable std::uniform_int_distribution<long> dist;
  };
}
