#include "Normal.h"
#include <boost/math/special_functions/erf.hpp>
#define SQUARE(x) ((x)*(x))

namespace StatisticalDistributions {
  using namespace std;
  Normal::Normal(long double mu, long double sigma)
    : dist(mu, sigma), cdist(mu, sigma) {}

  long double Normal::pdf(long double value) const {
    return(boost::math::pdf(cdist, value));
  }
  long double Normal::cdf(long double value) const {
    return(boost::math::cdf(cdist, value));
  }
  long double Normal::Inverse(long double value) const {
    return(boost::math::quantile(cdist, value));
  }
  long double Normal::operator()(std::mt19937_64 &g) const {
    return(this->dist(g));
  }
}
