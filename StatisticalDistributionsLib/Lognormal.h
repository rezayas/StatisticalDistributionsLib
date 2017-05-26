#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/lognormal.hpp>

namespace StatisticalDistributions {
  class Lognormal : public StatisticalDistribution<long double> {
  public:
    // This is so that e^(x-shift) ~ N(μ,σ).
    Lognormal(long double mu = 0, long double sigma = 1,
	      long double shift = 0);
    virtual long double pdf(long double value);
    virtual long double cdf(long double value);
    virtual long double Inverse(long double value);
    virtual long double operator()(std::mt19937_64 &g);
    const long double shift;
    std::lognormal_distribution<long double> dist;
  private: 
    const boost::lognormal_distribution<long double> cdist;
  };
}
