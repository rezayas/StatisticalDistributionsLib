#pragma once
#include "StatisticalDistribution.h"
#include <vector>

namespace StatisticalDistributions {
  class Empirical : public StatisticalDistribution<long> {
  public:
    Empirical(std::vector<long double> weights);
    // Weights need not add to one; they will be normalized.
    virtual long double pdf(long value) const;
    virtual long double cdf(long value) const;
    virtual long Inverse(long double value) const;
    // Currently uses linear search, which is slow.
    virtual long operator()(std::mt19937_64 &g) const;
  private:
    std::vector<long double> p, q;
    mutable std::discrete_distribution<long> dist;
  };
}
