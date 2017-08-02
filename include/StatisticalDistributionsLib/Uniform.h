#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/uniform.hpp>

namespace StatisticalDistributions {
  class Uniform : public StatisticalDistribution<long double> {
  public:
    // Well, this is easy.
    inline Uniform(long double min = 0, long double max = 1) {
      init(min, max);
    }
    void init(long double = 0, long double = 1);
    virtual long double pdf(long double value) const;
    virtual long double cdf(long double value) const;
    virtual long double Inverse(long double value) const;
    virtual long double operator()(std::mt19937_64 &g) const;
    ACCESSOR(cdist, pcdist);
  private:
    boost::math::uniform_distribution<long double> pcdist;
    mutable std::uniform_real_distribution<long double> dist;
  };
}
