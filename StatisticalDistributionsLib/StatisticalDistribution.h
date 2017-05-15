#pragma once
#include "RNG.h"
#include <math.h>
#include <random>

namespace StatisticalDistributions {
  class StatisticalDistribution {
  public:
    StatisticalDistribution() {};
    virtual double pdf(double value) = 0;
    virtual double cdf(double value) = 0;
    virtual double Inverse(double value) = 0;
    virtual double Sample(RNG &rng) = 0;
    virtual double operator()(std::mt19937 &g) = 0;
  };
}
