#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/beta.hpp>

namespace StatisticalDistributions {
  class Beta : public StatisticalDistribution<long double> {
  public:
    // The distribution here is proportional to f(x) = z^(α-1)(1-z)^(β-1).,
    // where z = x * sc + sh.
    Beta(long double alpha, long double beta,
	 long double scale = 1,long double shift = 0);
    static Beta mean_sdev(long double mu, long double sigma);
    virtual long double pdf(long double value);
    virtual long double cdf(long double value);
    virtual long double Inverse(long double value);
    virtual long double operator()(std::mt19937_64 &g);
  private:
    const long double scale, shift;
    std::gamma_distribution<long double> gama, gamb;
    static bool init;
    boost::math::beta_distribution<long double> dist;
  };
}
