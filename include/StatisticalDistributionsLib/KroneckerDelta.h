#pragma once
#include "StatisticalDistribution.h"
#include <cmath>
namespace StatisticalDistributions {
  class KroneckerDelta : public StatisticalDistribution<long> {
  public:
    inline KroneckerDelta(long value) : pv(value) {}
    inline void init(long value) {
      pv = value;
    }
    virtual long double pdf(long value) const {
      return(value == pv? 1 : 0);
    }
    virtual long double cdf(long value) const {
      return(value < pv? 0 : 1);
    }
    virtual long Inverse(long double value) const {
      return(pv);
    }
    virtual long operator()(std::mt19937_64 &) const {
      return(pv);
    }
    ACCESSORC(v, pv);
  private:    
    long pv;
  };
}
