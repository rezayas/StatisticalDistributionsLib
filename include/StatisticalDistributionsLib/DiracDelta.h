#pragma once
#include "StatisticalDistribution.h"
#include <cmath>
namespace StatisticalDistributions {
  class DiracDelta : public StatisticalDistribution<long double> {
  public:
    inline DiracDelta(long double value) : pv(value) {}
    inline void init(long double value) {
      pv = value;
    }
    virtual long double pdf(long double value) const {
      return(value == pv? INFINITY : 0);
    }
    virtual long double cdf(long double value) const {
      return(value < pv? 0 : 1);
    }
    virtual long double Inverse(long double value) const {
      return(pv);
    }
    virtual long double operator()(std::mt19937_64 &) const {
      return(pv);
    }
    ACCESSORC(v, pv);
  private:
    long double pv;
  };
}
