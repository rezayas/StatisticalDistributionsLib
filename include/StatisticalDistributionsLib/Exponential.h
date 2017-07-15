#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/exponential.hpp>

namespace StatisticalDistributions {
  class Exponential : public StatisticalDistribution<long double> {
  public:
    // Proportional to e^-(rate * x), but 0 if x < shift.
    Exponential(long double rate, long double shift = 0);
    virtual long double pdf(long double value) const;
    virtual long double cdf(long double value) const;
    virtual long double Inverse(long double value) const;
    virtual long double operator()(std::mt19937_64 &g) const;
    const boost::math::exponential_distribution<long double> cdist;
    const long double shift;
  private:
    mutable std::exponential_distribution<long double> dist;
  };
}
