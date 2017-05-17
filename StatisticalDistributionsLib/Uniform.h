#pragma once
#include "StatisticalDistribution.h"

namespace StatisticalDistributions {
  class Uniform : public StatisticalDistribution<long double> {
  public:
    // Well, this is easy.
    Uniform(long double min = 0, long double max = 1);
    virtual long double pdf(long double value);
    virtual long double cdf(long double value);
    virtual long double Inverse(long double value);
    virtual long double operator()(std::mt19937_64 &g);
  private:
    const long double min, max;
    std::uniform_real_distribution<long double> dist;
  };
}
