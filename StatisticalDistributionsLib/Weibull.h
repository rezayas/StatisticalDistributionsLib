#pragma once
#include "StatisticalDistribution.h"

namespace StatisticalDistributions
{
  class Weibull : public StatisticalDistribution<long double> {
  public:
    Weibull(long double a = 1, long double b = 1);
    virtual long double pdf(long double value);
    virtual long double cdf(long double value);
    virtual long double Inverse(long double value);
    virtual long double Sample(RNG &rng);
    virtual long double operator()(std::mt19937_64 &g);
  private:
    const long double a, b;
    std::weibull_distribution<long double> dist;
  };
}
