#include "Exponential.h"

namespace StatisticalDistributions {
  Exponential::Exponential(long double rate, long double shift)
    : dist(rate), cdist(rate), shift(shift) {}

  long double Exponential::pdf(long double value) const {
    return(boost::math::pdf(cdist, value - shift));
  }
  long double Exponential::cdf(long double value) const {
    return(boost::math::cdf(cdist, value - shift));
  }
  long double Exponential::Inverse(long double value) const {
    return(boost::math::quantile(cdist, value) + shift);
  }
  long double Exponential::operator()(std::mt19937_64 &g) const {
    return(this->dist(g));
  }
}
