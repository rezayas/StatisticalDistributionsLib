#include "Lognormal.h"
#include <boost/math/special_functions/erf.hpp>
#define SQUARE(x) ((x)*(x))

namespace StatisticalDistributions
{
  static const long double sqrt2 = sqrt(2);
  using namespace std;
  Lognormal::Lognormal(long double mu, long double sigma, long double shift)
    : dist(mu, sigma), mu(mu), sigma(sigma), shift(shift) {}

  long double Lognormal::pdf(long double value) {
    static const long double irt2pi = 1 / sqrt(8 * atan(1.0L));
    return(irt2pi * exp(- SQUARE((log(value - shift) - mu)
				 / (2 * sigma))) / (sigma * value));
  }
  long double Lognormal::cdf(long double value) {
    return((erf((log(value - shift) - mu) / (sigma * sqrt2)) + 1) / 2);
  }
  long double Lognormal::Inverse(long double value) {
    return(exp(mu + sigma * sqrt2 * boost::math::erf_inv(value)) + shift);
  }
  long double Lognormal::operator()(std::mt19937_64 &g) {
    return(this->dist(g) + shift);
  }
}
