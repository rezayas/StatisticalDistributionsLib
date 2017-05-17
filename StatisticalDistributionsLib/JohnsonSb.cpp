#include "JohnsonSb.h"
#include <boost/math/special_functions/erf.hpp>
#define SQUARE(x) ((x)*(x))

namespace StatisticalDistributions {
  static const long double sqrt2 = sqrt(2);
  using namespace std;
  JohnsonSb::JohnsonSb(long double gamma, long double xi, long double delta, long double lambda)
    : dist(-gamma / delta, delta), gamma(gamma), xi(xi), delta(delta),
      lambda(lambda) {}

  long double JohnsonSb::pdf(long double value) {
    static const long double irt2pi = 1 / sqrt(8 * atan(1.0L));
    long double z = (value - xi) / lambda;
    if(z < 0 || z > 1)
      return(0);
    return(delta * irt2pi / lambda / z / (1 - z)
	   * exp(-SQUARE(gamma + delta * log(z / (1-z)))/2));
  }
  long double JohnsonSb::cdf(long double value) {
    long double z = (value - xi) / lambda;
    if(z < 0)
      return(0);
    if(z > 1)
      return(1);
    return((erf((gamma + delta * log(z / (1-z)))/sqrt(2))
	    + 1) / 2);
  }
  long double JohnsonSb::Inverse(long double value) {
    long double y =
      exp((boost::math::erf_inv(2 * value - 1)*sqrt(2) - gamma)/delta);
    return(y / (y + 1) * lambda + xi);
  }
  long double JohnsonSb::operator()(std::mt19937_64 &g) {
    long double y = exp(dist(g));
    return(y / (y+1) * lambda + xi);
  }
}
