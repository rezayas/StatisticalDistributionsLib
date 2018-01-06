#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/triangular.hpp>

namespace StatisticalDistributions {
  class Triangular : public StatisticalDistribution<long double> {
  public:
    // Should be fairly obvious.
    // Fails unless min <= mode <= max.
    inline Triangular(long double min, long double max, long double mode) {
      init(min, max, mode);
    }
    void init(long double, long double, long double);
    virtual long double pdf(long double value) const;
    virtual long double cdf(long double value) const;
    virtual long double Inverse(long double value) const;
    virtual long double operator()(std::mt19937_64 &g) const;
    ACCESSOR(cdist, pcdist);
  private:
    boost::math::triangular_distribution<long double> pcdist;
    mutable std::piecewise_linear_distribution<long double> dist;
  };
  
}
