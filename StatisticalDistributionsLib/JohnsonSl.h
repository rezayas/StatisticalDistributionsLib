#pragma once
#include "StatisticalDistribution.h"

namespace StatisticalDistributions
{
  class JohnsonSb : public StatisticalDistribution<long double> {
  public:
    JohnsonSb(long double gamma, long double xi,
	      long double delta, long double lambda);
    virtual long double pdf(long double value);
    virtual long double cdf(long double value);
    virtual long double Inverse(long double value);
    virtual long double operator()(std::mt19937_64 &g);
  private:
    const long double gamma, xi, delta, lambda;
    std::normal_distribution<long double> dist;
  };
}