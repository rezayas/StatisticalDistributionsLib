#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/geometric.hpp>

namespace StatisticalDistributions {
  class Geometric : public StatisticalDistribution<long> {
  public:
    // Proportional to (1-p)^n.
    Geometric(long double p = .5);
    virtual long double pdf(long value) const;
    virtual long double cdf(long value) const;
    virtual long Inverse(long double value) const;
    virtual long operator()(std::mt19937_64 &g) const;
    const boost::math::geometric_distribution<long double, POLROUNDDOWN> cdist;
  private:
    mutable std::geometric_distribution<long> dist;
  };
}
