#pragma once
#include "Beta.h"

namespace StatisticalDistributions {
  class BetaBinomial : public StatisticalDistribution<long> {
  public:
    // See the beta distribution for the distribution of p.
    // Then take binomial(n, p).
    inline BetaBinomial(long n, long double alpha = 1, long double beta = 1) {
      init(n, alpha, beta);
    }
    void init(long, long double = 1, long double = 1);
    virtual long double pdf(long value) const;
    virtual long double cdf(long value) const;
    virtual long Inverse(long double value) const;
    virtual long operator()(std::mt19937_64 &g) const;
    ACCESSORC(alpha, palpha);
    ACCESSORC(beta, pbeta);
    ACCESSORC(n, pn);
  private:
    long double palpha, pbeta;
    long pn;
    Beta pdist;
  };
}
