#include "Poisson.h"

namespace StatisticalDistributions {

  void Poisson::init(long double mu) {
    pcdist = boost::math::poisson_distribution<long double, POLROUNDDOWN>(mu);
    dist = std::poisson_distribution<long>(mu);
  }
  long double Poisson::pdf(long value) const {
    return(boost::math::pdf(pcdist, value));
  }
  long double Poisson::cdf(long value) const {
    return(boost::math::cdf(pcdist, value));
  }
  long Poisson::Inverse(long double value) const {
    return((long)boost::math::quantile(pcdist, value));
  }
  long Poisson::operator()(std::mt19937_64 &g) const {
    return(this->dist(g));
  }
}

