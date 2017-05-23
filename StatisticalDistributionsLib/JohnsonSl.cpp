#include "JohnsonSl.h"
#include <boost/math/special_functions/erf.hpp>
#define SQUARE(x) ((x)*(x))

namespace StatisticalDistributions {
  static const long double sqrt2 = sqrt(2);
  using namespace std;
  JohnsonSl::JohnsonSl(long double gamma, long double xi, long double delta, long double lambda)
    : dist(-gamma / delta, delta), gamma(gamma), xi(xi), delta(delta),
      lambda(lambda) {}

  long double JohnsonSl::pdf(long double value) {
    static const long double irt2pi = 1 / sqrt(8 * atan(1.0L));
    long double z = (value - xi) / lambda;
    if(z < 0)
      return(0);
    return(delta * irt2pi / lambda / z
	   * exp(-SQUARE(gamma + delta * log(z))/2));
  }
  long double JohnsonSl::cdf(long double value) {
    long double z = (value - xi) / lambda;
    if(z < 0)
      return(0);
    long double ans = (erf((gamma + delta * log(z))/sqrt(2)) + 1) / 2;
    return(lambda < 0? 1-ans : ans);
  }
  long double JohnsonSl::Inverse(long double value) {
    if(lambda < 0)
      value = 1 - value;
    long double y =
      exp((boost::math::erf_inv(2 * value - 1)*sqrt(2) - gamma)/delta);
    return(y * lambda + xi);
  }
  long double JohnsonSl::operator()(std::mt19937_64 &g) {
    long double y = exp(dist(g));
    return(y / (y+1) * lambda + xi);
  }
}
