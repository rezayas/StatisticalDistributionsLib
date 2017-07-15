#include "../include/StatisticalDistributionsLib/GammaPoisson.h"

namespace StatisticalDistributions {

  GammaPoisson::GammaPoisson(long double alpha, long double beta)
    : cdist(alpha, beta/(beta + 1)), dist(alpha, beta) {}
  long double GammaPoisson::pdf(long value) const {
    return(boost::math::pdf(cdist, value));
  }
  long double GammaPoisson::cdf(long value) const {
    return(boost::math::cdf(cdist, value));
  }
  long GammaPoisson::Inverse(long double value) const {
    return((long)boost::math::quantile(cdist, value));
  }
  long GammaPoisson::operator()(std::mt19937_64 &g) const {
    std::poisson_distribution<long> x(dist(g)); //UGLY.
    return(x(g));
  }
}

