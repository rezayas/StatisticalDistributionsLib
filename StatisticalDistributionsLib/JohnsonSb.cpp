#include "JohnsonSb.h"
#include <boost/math/special_functions/erf.hpp>
#define SQUARE(x) ((x)*(x))

namespace StatisticalDistributions
{
  static const long double sqrt2 = sqrt(2);
  using namespace std;
  JohnsonSb::JohnsonSb(long double gamma, long double xi, long double delta, long double lambda)
    : dist(-gamma / delta, delta), gamma(gamma), xi(xi), delta(delta),
      lambda(lambda) {}

  long double JohnsonSb::pdf(long double value) {
    static const long double irt2pi = 1 / sqrt(8 * atan(1.0L));
    return(delta * irt2pi / lambda / sqrt(1 + SQUARE((value - xi)/lambda))
	   * exp(-SQUARE(gamma + delta * asinh((value - xi) / lambda))/2));
  }
  long double JohnsonSb::cdf(long double value) {
    return((erf((gamma + delta * asinh((value - xi)/lambda))/sqrt(2))
	    + 1) / 2);
  }
  long double JohnsonSb::Inverse(long double value) {
    return(sinh((boost::math::erf_inv(2 * value - 1)*sqrt(2) - gamma)/delta)
	   * lambda + xi);
  }
  long double JohnsonSb::operator()(std::mt19937_64 &g) {
    return(sinh(this->dist(g)) * lambda + xi);
  }
}
