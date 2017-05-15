#pragma once
#include "StatisticalDistribution.h"

namespace StatisticalDistributions {
  class Uniform : public StatisticalDistribution {
  public:
    Uniform(double min, double max);
    virtual double pdf(double value);
    virtual double cdf(double value);
    virtual double Sample(RNG &rng);
    virtual double Inverse(double value);
    virtual double operator()(std::mt19937 &g);
  private:
    const double min, max;
    std::uniform_real_distribution<double> dist;
  };
}
