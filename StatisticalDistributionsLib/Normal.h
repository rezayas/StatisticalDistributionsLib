#pragma once
#include "StatisticalDistribution.h"

namespace StatisticalDistributions
{
  class Normal : public StatisticalDistribution<long double> {
  public:
    Normal(long double mu = 0, long double sigma = 1);
    virtual long double pdf(long double value);
    virtual long double cdf(long double value);
    virtual long double Inverse(long double value);
    virtual long double Sample(RNG &rng);
    virtual long double operator()(std::mt19937_64 &g);
  private:
    const long double mu, sigma;
    std::normal_distribution<long double> dist;
  };
}
