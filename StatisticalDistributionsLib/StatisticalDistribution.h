#pragma once
#include "RNG.h"
#include <math.h>
#include <random>

namespace StatisticalDistributions {
  class StatisticalDistribution {
  public:
    StatisticalDistribution() {};
    virtual long double pdf(long double value) = 0;
    virtual long double cdf(long double value) = 0;
    virtual long double Inverse(long double value) = 0;
    virtual long double Sample(RNG &rng) = 0;
    virtual long double operator()(std::mt19937_64 &g) = 0;
  };
}
