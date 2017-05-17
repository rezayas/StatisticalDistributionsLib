#pragma once
#include "Beta.h"

namespace StatisticalDistributions {
  class BetaBinomial : public StatisticalDistribution<long> {
  public:
    // See the beta distribution for the distribution of p.
    // Then take binomial(n, p).
    BetaBinomial(long n, long double alpha = 1, long double beta = 1);
    virtual long double pdf(long value);
    virtual long double cdf(long value);
    virtual long Inverse(long double value);
    virtual long operator()(std::mt19937_64 &g);
  private:
    const long double alpha, beta, n;
    Beta dist;
  };
}
