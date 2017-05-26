#include "GammaPoisson.h"

namespace StatisticalDistributions {

  GammaPoisson::GammaPoisson(long double alpha, long double beta)
    : cdist(alpha, beta/(beta + 1)), dist(alpha, beta) {}
  long double GammaPoisson::pdf(long value) {
    return(boost::math::pdf(cdist, value));
  }
  long double GammaPoisson::cdf(long value) {
    return(boost::math::cdf(cdist, value));
  }
  long GammaPoisson::Inverse(long double value) {
    return((long)boost::math::quantile(cdist, value));
  }
  long GammaPoisson::operator()(std::mt19937_64 &g) {
    std::poisson_distribution<long> x(dist(g)); //UGLY.
    return(x(g));
  }
}

