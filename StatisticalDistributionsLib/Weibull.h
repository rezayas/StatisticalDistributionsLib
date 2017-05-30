#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/weibull.hpp>

namespace StatisticalDistributions {
  class Weibull : public StatisticalDistribution<long double> {
  public:
    // PDF proportional to x^(a-1)e^-((x/b)^a).
    Weibull(long double a = 1, long double b = 1);
    virtual long double pdf(long double value);
    virtual long double cdf(long double value);
    virtual long double Inverse(long double value);
    virtual long double operator()(std::mt19937_64 &g);
    const boost::math::weibull_distribution<long double> cdist;
  private:
    std::weibull_distribution<long double> dist;
  };
}
