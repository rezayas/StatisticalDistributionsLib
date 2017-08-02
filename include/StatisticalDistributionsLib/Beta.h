#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/beta.hpp>

namespace StatisticalDistributions {
  class Beta : public StatisticalDistribution<long double> {
  public:
    // The distribution here is proportional to f(x) = z^(α-1)(1-z)^(β-1).,
    // where z = x * sc + sh.
    inline Beta(long double alpha, long double beta,
		long double scale = 1, long double shift = 0) {
      init(alpha, beta, scale, shift);
    }
    void init(long double, long double, long double = 1, long double = 0);
    static Beta mean_sdev(long double mu, long double sigma);
    inline static Beta minmax(long double alpha, long double beta,
		       long double min = 0, long double max = 1) {
      return(Beta(alpha, beta, max - min, min));
    }
    virtual long double pdf(long double value) const;
    virtual long double cdf(long double value) const;
    virtual long double Inverse(long double value) const;
    virtual long double operator()(std::mt19937_64 &g) const;
    ACCESSORC(scale, pscale);
    ACCESSORC(shift, pshift);
    ACCESSOR(dist, pdist);
  private:
    long double pscale, pshift;
    boost::math::beta_distribution<long double> pdist;
    mutable std::gamma_distribution<long double> gama, gamb;
  };
}
