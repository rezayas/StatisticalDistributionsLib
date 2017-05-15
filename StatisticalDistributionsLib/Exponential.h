#pragma once
#include "StatisticalDistribution.h"

namespace StatisticalDistributions
{
  class Exponential : public StatisticalDistribution {
  public:
    Exponential(double rate);
    virtual double pdf(double value);
    virtual double cdf(double value);
    virtual double Inverse(double value);
    virtual double Sample(RNG &rng);
    virtual double operator()(std::mt19937 &g);
  private:
    const double rate;
    std::exponential_distribution<double> dist;
  };
}
