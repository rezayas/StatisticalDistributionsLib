#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/lognormal.hpp>

namespace StatisticalDistributions {
  class Lognormal : public StatisticalDistribution<long double> {
  public:
    // This is so that e^(x-shift) ~ N(μ,σ).
    Lognormal(long double mu = 0, long double sigma = 1,
	      long double shift = 0) {
      init(mu, sigma, shift);
    }
    void init(long double = 0, long double = 1, long double = 0);
    virtual long double pdf(long double value) const;
    virtual long double cdf(long double value) const;
    virtual long double Inverse(long double value) const;
    virtual long double operator()(std::mt19937_64 &g) const;
    ACCESSORC(shift, pshift);
    ACCESSOR(cdist, pcdist);
  private:
    long double pshift;
    boost::math::lognormal_distribution<long double> pcdist;
    mutable std::lognormal_distribution<long double> dist;
  };
}
