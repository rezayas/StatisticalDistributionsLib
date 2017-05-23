#include "Normal.h"
#include <boost/math/special_functions/erf.hpp>
#define SQUARE(x) ((x)*(x))

namespace StatisticalDistributions {
  static const long double sqrt2 = sqrt(2);
  using namespace std;
  Normal::Normal(long double mu, long double sigma)
    : dist(mu, sigma), mu(mu), sigma(sigma) {}

  long double Normal::pdf(long double value) {
    static const long double irt2pi = 1 / sqrt(8 * atan(1.0L));
    return(irt2pi * exp(- SQUARE((value - mu) / (2 * sigma))) / sigma);
  }
  long double Normal::cdf(long double value) {
    return((erf((value - mu) / (sigma * sqrt2)) + 1) / 2);
  }
  long double Normal::Inverse(long double value) {
    return(mu + sigma * sqrt2 * boost::math::erf_inv(2 * value - 1));
  }
  long double Normal::operator()(std::mt19937_64 &g) {
    return(this->dist(g));
  }
}
