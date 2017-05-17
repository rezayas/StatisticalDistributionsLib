#pragma once
#include "StatisticalDistribution.h"

namespace StatisticalDistributions {
  class Exponential : public StatisticalDistribution<long double> {
  public:
    // Proportional to e^-(rate * x), but 0 if x < shift.
    Exponential(long double rate, long double shift = 0);
    virtual long double pdf(long double value);
    virtual long double cdf(long double value);
    virtual long double Inverse(long double value);
    virtual long double operator()(std::mt19937_64 &g);
  private:
    const long double rate, shift;
    std::exponential_distribution<long double> dist;
  };
}
