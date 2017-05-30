#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/normal.hpp>

namespace StatisticalDistributions {
  class JohnsonSl : public StatisticalDistribution<long double> {
  public:
    // So that γ+δ*ln((x-μ)/σ) is N(0,1).
    JohnsonSl(long double mu, long double sigma,
	      long double gamma, long double delta);
    virtual long double pdf(long double value);
    virtual long double cdf(long double value);
    virtual long double Inverse(long double value);
    virtual long double operator()(std::mt19937_64 &g);
    const long double gamma, mu, delta, sigma;
  private:
    const boost::math::normal_distribution<long double> cdist;
    std::normal_distribution<long double> dist;
  };
}
