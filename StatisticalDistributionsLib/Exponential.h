#pragma once
#include "StatisticalDistribution.h"

namespace StatisticalDistributions
{
  class Exponential : public StatisticalDistribution {
  public:
    Exponential(long double rate);
    virtual long double pdf(long double value);
    virtual long double cdf(long double value);
    virtual long double Inverse(long double value);
    virtual long double Sample(RNG &rng);
    virtual long double operator()(std::mt19937_64 &g);
  private:
    const long double rate;
    std::exponential_distribution<long double> dist;
  };
}
