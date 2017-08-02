#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/normal.hpp>

namespace StatisticalDistributions {
  class JohnsonSl : public StatisticalDistribution<long double> {
  public:
    // So that γ+δ*ln((x-μ)/σ) is N(0,1).
    inline JohnsonSl(long double mu, long double sigma,
	      long double gamma, long double delta) {
      init(mu, sigma, gamma, delta);
    }
    void init(long double, long double, long double, long double);
    virtual long double pdf(long double value) const;
    virtual long double cdf(long double value) const;
    virtual long double Inverse(long double value) const;
    virtual long double operator()(std::mt19937_64 &g) const;
    ACCESSOR(cdist, pcdist);
    ACCESSORC(gamma, pgamma);
    ACCESSORC(mu, pmu);
    ACCESSORC(delta, pdelta);
    ACCESSORC(sigma, psigma);
  private:
    long double pgamma, pmu, pdelta, psigma;
    boost::math::normal_distribution<long double> pcdist;
    mutable std::normal_distribution<long double> dist;
  };
}
