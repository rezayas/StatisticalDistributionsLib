#include "../include/StatisticalDistributionsLib/Poisson.h"

namespace StatisticalDistributions {

  Poisson::Poisson(long double mu) : cdist(mu), dist(mu) {}
  long double Poisson::pdf(long value) const {
    return(boost::math::pdf(cdist, value));
  }
  long double Poisson::cdf(long value) const {
    return(boost::math::cdf(cdist, value));
  }
  long Poisson::Inverse(long double value) const {
    return((long)boost::math::quantile(cdist, value));
  }
  long Poisson::operator()(std::mt19937_64 &g) const {
    return(this->dist(g));
  }
}

