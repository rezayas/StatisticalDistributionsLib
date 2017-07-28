#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/uniform.hpp>

namespace StatisticalDistributions {
  class Uniform : public StatisticalDistribution<long double> {
  public:
    // Well, this is easy.
    Uniform(long double min = 0, long double max = 1);
    virtual long double pdf(long double value) const;
    virtual long double cdf(long double value) const;
    virtual long double Inverse(long double value) const;
    virtual long double operator()(std::mt19937_64 &g) const;
    const boost::math::uniform_distribution<long double> cdist;
  private:
    mutable std::uniform_real_distribution<long double> dist;
  };
}