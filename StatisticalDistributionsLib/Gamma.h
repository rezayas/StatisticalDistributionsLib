#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/gamma.hpp>

namespace StatisticalDistributions {
  class Gamma : public StatisticalDistribution<long double> {
  public:
    // Proportional to x^(α-1)e^-(x/β).
    Gamma(long double alpha = 1, long double beta = 1, long double shift = 0);
    static Gamma mean_sdev(long double mu = 1, long double sigma = 1);
    virtual long double pdf(long double value) const;
    virtual long double cdf(long double value) const;
    virtual long double Inverse(long double value) const;
    virtual long double operator()(std::mt19937_64 &g) const;
    const long double shift;
    const boost::math::gamma_distribution<long double> cdist;
  private:
    mutable std::gamma_distribution<long double> dist;
  };
}
