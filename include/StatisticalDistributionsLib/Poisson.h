#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/poisson.hpp>

namespace StatisticalDistributions {
  class Poisson : public StatisticalDistribution<long> {
  public:
    // μ is the expected value here.
    void Poisson(long double mu = 1) {
      init(mu);
    }
    void init(long double = 1);
    virtual long double pdf(long value) const;
    virtual long double cdf(long value) const;
    virtual long Inverse(long double value) const;
    virtual long operator()(std::mt19937_64 &g) const;
    ACCESSOR(cdist, pcdist);
  private:
    boost::math::poisson_distribution<long double, POLROUNDDOWN> pcdist;
    mutable std::poisson_distribution<long> dist;
  };
}
