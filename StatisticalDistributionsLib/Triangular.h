#pragma once
#include "StatisticalDistribution.h"

namespace StatisticalDistributions {
  class Triangular : public StatisticalDistribution<long double> {
  public:
    Triangular(long double min, long double max, long double mode);
    virtual long double pdf(long double value);
    virtual long double cdf(long double value);
    virtual long double Inverse(long double value);
    virtual long double operator()(std::mt19937_64 &g);
  private:
    const long double min, max, mode;
    std::piecewise_linear_distribution<long double> dist;
  };
}
