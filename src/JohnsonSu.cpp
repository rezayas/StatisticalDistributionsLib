#include "../include/StatisticalDistributionsLib/JohnsonSu.h"
#define SQUARE(x) ((x)*(x))

namespace StatisticalDistributions {
  JohnsonSu::JohnsonSu(long double mu, long double sigma, long double gamma, long double delta)
    : dist(-gamma / std::abs(delta), 1 / std::abs(delta)), gamma(gamma),
      mu(mu), delta(std::abs(delta)), sigma(std::abs(sigma)),
      cdist(-gamma / std::abs(delta), 1 / std::abs(delta)) {}

  long double JohnsonSu::pdf(long double value) const {
    long double y = (value - mu) / sigma;
    return(delta / sigma * std::sqrt(1 + y * y) *
	   boost::math::pdf(cdist, std::asinh(y)));
  }
  long double JohnsonSu::cdf(long double value) const {
    return(boost::math::cdf(cdist, std::asinh((value - mu)/sigma)));
  }
  long double JohnsonSu::Inverse(long double value) const {
    return(std::sinh(boost::math::quantile(cdist, value)) * sigma + mu);
  }
  long double JohnsonSu::operator()(std::mt19937_64 &g) const {
    return(sinh(this->dist(g)) * sigma + mu);
  }
}
