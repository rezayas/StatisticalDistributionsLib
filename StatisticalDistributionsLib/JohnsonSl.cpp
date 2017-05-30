#include "JohnsonSl.h"
#include <boost/math/special_functions/erf.hpp>
#define SQUARE(x) ((x)*(x))

namespace StatisticalDistributions {
  JohnsonSl::JohnsonSl(long double mu, long double sigma, long double gamma, long double delta)
    : dist(-gamma / delta, 1 / delta), gamma(gamma), mu(mu), delta(delta),
      sigma(sigma), cdist(-gamma / delta, 1/delta) {}

  long double JohnsonSl::pdf(long double value) {
    long double y = (value - mu) / gamma;
    return(delta / y * boost::math::pdf(cdist, std::log(y)));
  }
  long double JohnsonSl::cdf(long double value) {
    long double r = boost::math::cdf(cdist, std::log((value - mu) / sigma));
    return(sigma < 0? 1 - r : r);
  }
  long double JohnsonSl::Inverse(long double value) {
    if(sigma < 0)
      value = 1 - value;
    return(std::exp(boost::math::quantile(cdist, value)) * sigma + mu);
  }
  long double JohnsonSl::operator()(std::mt19937_64 &g) {
    return(std::exp(dist(g)) * sigma + mu);
  }
}
