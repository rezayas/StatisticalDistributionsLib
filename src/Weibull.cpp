#include "../include/StatisticalDistributionsLib/Weibull.h"

namespace StatisticalDistributions {
  Weibull::Weibull(long double a, long double b) : dist(a, b), cdist(a, b) {}

  long double Weibull::pdf(long double value) const {
    return(boost::math::pdf(cdist, value));
  }
  long double Weibull::cdf(long double value) const {
    return(boost::math::cdf(cdist, value));
  }
  long double Weibull::Inverse(long double value) const {
    return(boost::math::quantile(cdist, value));
  }
  long double Weibull::operator()(std::mt19937_64 &g) const {
    return(this->dist(g));
  }
}