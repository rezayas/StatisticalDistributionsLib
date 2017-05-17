#pragma once
#include "StatisticalDistribution.h"

namespace StatisticalDistributions {
  class Bernoulli : public StatisticalDistribution<bool> {
  public:
    Bernoulli(long double p = .5);
    // p is the probability of success.
    virtual long double pdf(bool value);
    virtual long double cdf(bool value);
    virtual bool Inverse(long double value);
    virtual bool operator()(std::mt19937_64 &g);
  private:
    const long double p;
    std::bernoulli_distribution dist;
  };
}
