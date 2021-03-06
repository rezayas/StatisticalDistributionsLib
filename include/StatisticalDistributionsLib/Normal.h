#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/normal.hpp>

namespace StatisticalDistributions {
  class Normal : public StatisticalDistribution<long double> {
  public:
    // I should hope you don't need an explanation.
    inline Normal(long double mu = 0, long double sigma = 1) {
      init(mu, sigma);
    }
    void init(long double = 0, long double = 1);
    virtual long double pdf(long double value) const;
    virtual long double cdf(long double value) const;
    virtual long double Inverse(long double value) const;
    virtual long double operator()(std::mt19937_64 &g) const;
    ACCESSOR(cdist, pcdist);
  private:
    boost::math::normal_distribution<long double> pcdist;
    mutable std::normal_distribution<long double> dist;
  };
}
