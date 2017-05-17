#pragma once
#include "StatisticalDistribution.h"

namespace StatisticalDistributions {
  class Binomial : public StatisticalDistribution<long> {
  public:
    Binomial(long n = 1, long double p = .5);
    virtual long double pdf(long value);
    virtual long double cdf(long value);
    virtual long Inverse(long double value);
    virtual long operator()(std::mt19937_64 &g);
  private:
    const long double p;
    const long n;
    std::binomial_distribution<long> dist;
  };
}
