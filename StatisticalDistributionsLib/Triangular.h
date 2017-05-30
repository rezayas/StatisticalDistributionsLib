#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/triangular.hpp>

namespace StatisticalDistributions {
  class Triangular : public StatisticalDistribution<long double> {
  public:
    // Should be fairly obvious.
    // Fails unless min <= mode <= max.
    Triangular(long double min, long double max, long double mode);
    virtual long double pdf(long double value);
    virtual long double cdf(long double value);
    virtual long double Inverse(long double value);
    virtual long double operator()(std::mt19937_64 &g);
    const boost::math::triangular_distribution<long double> cdist;
  private:
    std::piecewise_linear_distribution<long double> dist;
  };
}
