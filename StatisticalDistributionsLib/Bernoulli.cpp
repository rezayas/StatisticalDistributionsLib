#include "Bernoulli.h"

namespace StatisticalDistributions {

  Bernoulli::Bernoulli(long double p)
    : dist(p), cdist(p) {}
  long double Bernoulli::pdf(long value) const {
    return(boost::math::pdf(cdist, value));
  }
  long double Bernoulli::cdf(long value) const {
    return(boost::math::cdf(cdist, value));
  }
  long Bernoulli::Inverse(long double value) const {
    return((bool)boost::math::quantile(cdist, value));
  }
  long Bernoulli::operator()(std::mt19937_64 &g) const {
    return(this->dist(g));
  }
}

