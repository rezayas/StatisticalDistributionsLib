#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/lognormal.hpp>

namespace StatisticalDistributions {
  class Constant : public StatisticalDistribution<long double> {
  public:
    // This is so that e^(x-shift) ~ N(μ,σ).
    Constant(long double constant = 0) {
      init(constant);
    }
    void init(long double = 0);
    virtual long double pdf(long double value) const;
    virtual long double cdf(long double value) const;
    virtual long double Inverse(long double value) const;
    virtual long double operator()(std::mt19937_64 &g) const;

  private:
    long double val;
  };
}
