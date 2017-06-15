#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/bernoulli.hpp>

namespace StatisticalDistributions {
  class Bernoulli : public StatisticalDistribution<long> {
  public:
    Bernoulli(long double p = .5);
    // p is the probability of success.
    virtual long double pdf(long value) const;
    virtual long double cdf(long value) const;
    virtual long Inverse(long double value) const;
    virtual long operator()(std::mt19937_64 &g) const ;
    const boost::math::bernoulli_distribution<long double, POLROUNDDOWN> cdist;
  private:
    mutable std::bernoulli_distribution dist;
  };
}
