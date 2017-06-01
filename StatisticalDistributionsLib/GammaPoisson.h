#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/negative_binomial.hpp>

namespace StatisticalDistributions {
  class GammaPoisson : public StatisticalDistribution<long> {
  public:
    // This picks μ from Γ(α,β) (see Gamma.h),
    // then grabs from Pois(μ).
    GammaPoisson(long double alpha = 1, long double beta = 1);
    virtual long double pdf(long value) const;
    virtual long double cdf(long value) const;
    virtual long Inverse(long double value) const;
    virtual long operator()(std::mt19937_64 &g) const;
    const boost::math::negative_binomial_distribution<long double,
      POLROUNDDOWN> cdist;
  private:
    mutable std::gamma_distribution<long double> dist;
  };
}
