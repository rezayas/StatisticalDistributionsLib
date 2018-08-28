#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/weibull.hpp>

namespace StatisticalDistributions {
  class Weibull : public StatisticalDistribution<long double> {
  public:
    // PDF proportional to x^(a-1)e^-((x/b)^a).
    // SciPy parameters (k, lambda) correspond to (a, b)
    inline Weibull(long double a = 1, long double b = 1) : pcdist(a, b) {
      init(a, b);
    }
    void init(long double = 1, long double = 1);
    virtual long double pdf(long double value) const;
    virtual long double cdf(long double value) const;
    virtual long double Inverse(long double value) const;
    virtual long double operator()(std::mt19937_64 &g) const;
    ACCESSOR(cdist, pcdist);
  private:
    boost::math::weibull_distribution<long double> pcdist;
    mutable std::weibull_distribution<long double> dist;
  };
}
