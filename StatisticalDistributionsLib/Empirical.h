#pragma once
#include "StatisticalDistribution.h"
#include <vector>

namespace StatisticalDistributions {
  class Empirical : public StatisticalDistribution<long> {
  public:
    Empirical(std::vector<long double> weights);
    virtual long double pdf(long value);
    virtual long double cdf(long value);
    virtual long Inverse(long double value);
    virtual long operator()(std::mt19937_64 &g);
  private:
    std::vector<long double> p, q;
    std::discrete_distribution<long> dist;
  };
}
