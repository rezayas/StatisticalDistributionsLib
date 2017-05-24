#include "GammaPoisson.h"
#include <boost/math/special_functions/beta.hpp>

namespace StatisticalDistributions {

  GammaPoisson::GammaPoisson(long double alpha, long double beta)
    : alpha(alpha), beta(beta), p(1/(1/beta + 1)), dist(alpha, beta) {}
  long double GammaPoisson::pdf(long value) {
    return(std::pow(p, alpha) * std::pow(1-p, value) * value
	   / boost::math::beta(value, alpha));
  }
  long double GammaPoisson::cdf(long value) {
    return(boost::math::ibetac(value + 1, alpha, p));
  }
  long GammaPoisson::Inverse(long double value) {
    return((long)alpha * beta); // The mean.
  }
  long GammaPoisson::operator()(std::mt19937_64 &g) {
    std::poisson_distribution<long> x(dist(g)); //UGLY.
    return(x(g));
  }
}

