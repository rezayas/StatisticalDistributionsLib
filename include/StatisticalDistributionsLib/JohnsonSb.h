#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/normal.hpp>

namespace StatisticalDistributions {
  class JohnsonSb : public StatisticalDistribution<long double> {
  public:
    // So that γ+δ*ln(z/(1-z)) is N(0,1), where x = σz+μ.
    // SciPy (a, b, loc, scale) corresponds to (gamma, delta, mu, sigma)  
    inline JohnsonSb(long double mu, long double sigma,
		     long double gamma, long double delta) {
      init(mu, sigma, gamma, delta);
    }
    void init(long double, long double, long double, long double);
    virtual long double pdf(long double value) const;
    virtual long double cdf(long double value) const;
    virtual long double Inverse(long double value) const;
    virtual long double operator()(std::mt19937_64 &g) const;
    ACCESSOR(cdist, pcdist);
    ACCESSORC(mu, pmu);
    ACCESSORC(sigma, psigma);
    ACCESSORC(gamma, pgamma);
    ACCESSORC(delta, pdelta);
  private:
    long double pmu, psigma, pgamma, pdelta;
    boost::math::normal_distribution<long double> pcdist;
    mutable std::normal_distribution<long double> dist;
  };
}
