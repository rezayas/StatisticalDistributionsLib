#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/normal.hpp>

namespace StatisticalDistributions {
  class JohnsonSb : public StatisticalDistribution<long double> {
  public:
    // So that γ+δ*ln(z/(1-z)) is N(0,1), where x = σz+μ.
    JohnsonSb(long double mu, long double sigma,
	      long double gamma, long double delta);
    virtual long double pdf(long double value) const;
    virtual long double cdf(long double value) const;
    virtual long double Inverse(long double value) const;
    virtual long double operator()(std::mt19937_64 &g) const;
    const long double mu, sigma, gamma, delta;
  private:
    const boost::math::normal_distribution<long double> cdist;
    mutable std::normal_distribution<long double> dist;
  };
}
