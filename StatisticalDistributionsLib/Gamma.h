#pragma once
#include "StatisticalDistribution.h"

namespace StatisticalDistributions
{
  class Gamma : public StatisticalDistribution<long double> {
  public:
    Gamma(long double alpha = 1, long double beta = 1, long double shift = 0);
    static Gamma mean_sdev(long double mu = 1, long double sigma = 1);
    virtual long double pdf(long double value);
    virtual long double cdf(long double value);
    virtual long double Inverse(long double value);
    virtual long double Sample(RNG &rng);
    virtual long double operator()(std::mt19937_64 &g);
  private:
    const long double alpha, beta, shift;
    long double pdfc;
    std::gamma_distribution<long double> dist;
  };
}
