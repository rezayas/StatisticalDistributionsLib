#pragma once
#include "StatisticalDistribution.h"
#include <vector>

namespace StatisticalDistributions {
  class Empirical : public StatisticalDistribution<long> {
  public:
    Empirical(std::vector<long double> weights);
    // Weights need not add to one; they will be normalized.
    virtual long double pdf(long value);
    virtual long double cdf(long value);
    virtual long Inverse(long double value);
    // Currently uses linear search, which is slow.
    virtual long operator()(std::mt19937_64 &g);
  private:
    std::vector<long double> p, q;
    std::discrete_distribution<long> dist;
  };
}
