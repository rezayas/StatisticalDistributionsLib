#pragma once
#include "StatisticalDistribution.h"
#include <cmath>
namespace StatisticalDistributions {
  class KroneckerDelta : public StatisticalDistribution<long> {
  public:
    inline KroneckerDelta(long value) : v(value) {}
    virtual long double pdf(long value) const {
      return(value == v? 1 : 0);
    }
    virtual long double cdf(long value) const {
      return(value < v? 0 : 1);
    }
    virtual long Inverse(long double value) const {
      return(v);
    }
    virtual long operator()(std::mt19937_64 &) const {
      return(v);
    }
    const long v;
  };
}
