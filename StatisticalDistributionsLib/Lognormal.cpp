#include "Lognormal.h"
#include <boost/math/special_functions/erf.hpp>
#define SQUARE(x) ((x)*(x))

namespace StatisticalDistributions {
  using namespace std;
  Lognormal::Lognormal(long double mu, long double sigma, long double shift)
    : dist(mu, sigma), cdist(mu, sigma), shift(shift) {}

  long double Lognormal::pdf(long double value) const {
    return(boost::math::pdf(cdist, value - shift));
  }
  long double Lognormal::cdf(long double value) const {
    return(boost::math::cdf(cdist, value - shift));
  }
  long double Lognormal::Inverse(long double value) const {
    return(boost::math::quantile(cdist, value) + shift);
  }
  long double Lognormal::operator()(std::mt19937_64 &g) const {
    return(this->dist(g) + shift);
  }
}
