#pragma once
#include "RNG.h"
#include <cmath>
#include <random>

#define POLROUNDDOWN boost::math::policies::policy<boost::math::policies::discrete_quantile<boost::math::policies::integer_round_down> >

namespace StatisticalDistributions {

  template<typename distype> class StatisticalDistribution {
  public:
    StatisticalDistribution() {};
    virtual long double pdf(distype value) = 0;
    virtual long double cdf(distype value) = 0;
    virtual distype Inverse(long double value) = 0;
    long double Sample(RNG &rng) {
      return(this->operator()(rng.mt_));
    }
    virtual distype operator()(std::mt19937_64 &g) = 0;
  };
}
