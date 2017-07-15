#include "../include/StatisticalDistributionsLib/JohnsonSb.h"
#include <boost/math/special_functions/erf.hpp>
#define SQUARE(x) ((x)*(x))

namespace StatisticalDistributions {
  JohnsonSb::JohnsonSb(long double mu, long double sigma, long double gamma, long double delta)
    : dist(-gamma / std::abs(delta), 1 / std::abs(delta)), gamma(gamma),
      mu(mu), delta(std::abs(delta)), sigma(std::abs(sigma)),
      cdist(-gamma / std::abs(delta), 1 / std::abs(delta)) {}

  long double JohnsonSb::pdf(long double value) const {
    long double z = (value - mu) / sigma;
    if(z < 0 || z > 1)
      return(0);
    return(boost::math::pdf(cdist, std::log(z / (1 - z)))
	   * delta / sigma / z / (1 - z));
  }
  long double JohnsonSb::cdf(long double value) const {
    long double z = (value - mu) / sigma;
    if(z < 0)
      return(0);
    if(z > 1)
      return(1);
    return(boost::math::cdf(cdist, std::log(z / (1 - z))));
  }
  long double JohnsonSb::Inverse(long double value) const {
    return(sigma / (1 + std::exp(- boost::math::quantile(cdist, value))) + mu);
  }
  long double JohnsonSb::operator()(std::mt19937_64 &g) const {
    return(sigma / (1 + std::exp(dist(g))) + mu);
  }
}
