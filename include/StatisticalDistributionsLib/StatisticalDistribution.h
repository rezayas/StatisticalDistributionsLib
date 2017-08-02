#pragma once
#include "RNG.h"
#include <cmath>
#include <random>

#define POLROUNDDOWN boost::math::policies::policy<boost::math::policies::discrete_quantile<boost::math::policies::integer_round_down> >
#define ACCESSOR(x, y) inline const auto &x() const { return(y); }
#define ACCESSORC(x, y) inline auto x() const { return(y); }

namespace StatisticalDistributions {

  template<typename distype> class StatisticalDistribution {
  public:
    StatisticalDistribution() {};
    virtual long double pdf(distype value) const = 0;
    virtual long double cdf(distype value) const = 0;
    virtual distype Inverse(long double value) const = 0;
    long double Sample(RNG &rng) const {
      return(this->operator()(rng.mt_));
    }
    virtual distype operator()(std::mt19937_64 &g) const = 0;
  };
}
