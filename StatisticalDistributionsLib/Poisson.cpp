#include "Poisson.h"
#include <boost/math/special_functions/gamma.hpp>

namespace StatisticalDistributions {
  using namespace boost::math;

  Poisson::Poisson(long double mu) : mu(mu), dist(mu) {}
  long double Poisson::pdf(long value) {
    return(std::pow(mu, value) * std::exp(-mu) / tgamma(value + 1));
  }
  long double Poisson::cdf(long value) {
    if(value < 0)
      return(0);
    return(gamma_q(value + 1, mu));
  }
  long Poisson::Inverse(long double value) {
    return((long)gamma_q_inv(mu, value));
  }
  long Poisson::operator()(std::mt19937_64 &g) {
    return(this->dist(g));
  }
}

