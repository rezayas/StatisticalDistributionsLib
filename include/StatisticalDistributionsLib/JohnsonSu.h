#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/normal.hpp>

namespace StatisticalDistributions {
  class JohnsonSu : public StatisticalDistribution<long double> {
  public:
    // So that γ+δ*asinh((x-μ)/σ) ~ N(0,1).
    // SciPy fit (a, b, loc, scale) corresponds to (gamma, delta, mu, sigma) 
    inline JohnsonSu(long double mu, long double sigma,
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
    ACCESSORC(sigma, psigma);
    ACCESSORC(delta, pdelta);
  private:
    long double pgamma, pmu, psigma, pdelta;
    boost::math::normal_distribution<long double> pcdist;
    mutable std::normal_distribution<long double> dist;
  };
}
