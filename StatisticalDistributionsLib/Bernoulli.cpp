#include "Bernoulli.h"

namespace StatisticalDistributions {

  Bernoulli::Bernoulli(long double p)
    : dist(p), cdist(p) {}
  long double Bernoulli::pdf(bool value) {
    return(boost::math::pdf(cdist, value));
  }
  long double Bernoulli::cdf(bool value) {
    return(boost::math::cdf(cdist, value));
  }
  bool Bernoulli::Inverse(long double value) {
    return((bool)boost::math::quantile(cdist, value));
  }
  bool Bernoulli::operator()(std::mt19937_64 &g) {
    return(this->dist(g));
  }
}

