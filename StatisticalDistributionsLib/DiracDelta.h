#pragma once
#include "StatisticalDistribution.h"
#include <cmath>
namespace StatisticalDistributions {
  class DiracDelta : public StatisticalDistribution<long double> {
  public:
    inline DiracDelta(long double value) : v(value) {}
    virtual long double pdf(long double value) const {
      return(value == v? INFINITY : 0);
    }
    virtual long double cdf(long double value) const {
      return(value < v? 0 : 1);
    }
    virtual long double Inverse(long double value) const {
      return(v);
    }
    virtual long double operator()(std::mt19937_64 &) const {
      return(v);
    }
    const long double v;
  };
}
