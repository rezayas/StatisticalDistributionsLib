#include "JohnsonSu.h"
#define SQUARE(x) ((x)*(x))

namespace StatisticalDistributions {
  JohnsonSu::JohnsonSu(long double mu, long double sigma, long double gamma, long double delta)
    : dist(-gamma / delta, 1 / delta), gamma(gamma), mu(mu), delta(delta),
      sigma(sigma), cdist(-gamma / delta, 1 / delta) {}

  long double JohnsonSu::pdf(long double value) {
    long double y = (value - mu) / sigma;
    return(delta / sigma * std::sqrt(1 + y * y) *
	   boost::math::pdf(cdist, std::asinh(y)));
  }
  long double JohnsonSu::cdf(long double value) {
    return(boost::math::cdf(cdist, std::asinh((value - mu)/sigma)));
  }
  long double JohnsonSu::Inverse(long double value) {
    return(std::sinh(boost::math::quantile(cdist, value)) * sigma + mu);
  }
  long double JohnsonSu::operator()(std::mt19937_64 &g) {
    return(sinh(this->dist(g)) * sigma + mu);
  }
}
