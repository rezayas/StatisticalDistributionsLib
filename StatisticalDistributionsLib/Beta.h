#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/beta.hpp>

namespace StatisticalDistributions {
  class Beta : public StatisticalDistribution<long double> {
  public:
    // The distribution here is proportional to f(x) = x^(α-1)(1-x)^(β-1).
    Beta(long double alpha, long double beta);
    static Beta mean_sdev(long double mu, long double sigma);
    virtual long double pdf(long double value);
    virtual long double cdf(long double value);
    virtual long double Inverse(long double value);
    virtual long double operator()(std::mt19937_64 &g);
  private:
    const long double alpha, beta;
    static std::uniform_real_distribution<long double> uni;
    const boost::math::beta_distribution<long double> dist;
  };
}
