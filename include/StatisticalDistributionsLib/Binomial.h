#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/binomial.hpp>

namespace StatisticalDistributions {
  class Binomial : public StatisticalDistribution<long> {
  public:
    // n is number of trials; p is probability of success.
    Binomial(long n = 1, long double p = .5) {
      init(n, p);
    }
    void init(long = 1, long double = .5);
    virtual long double pdf(long value) const;
    virtual long double cdf(long value) const;
    virtual long Inverse(long double value) const;
    virtual long operator()(std::mt19937_64 &g) const;
    ACCESSOR(cdist, pcdist);
  private:
    boost::math::binomial_distribution<long double, POLROUNDDOWN> pcdist;
    mutable std::binomial_distribution<long> dist;
  };
}
