#include "Binomial.h"
#include <boost/math/special_functions/beta.hpp>

namespace StatisticalDistributions {

  using namespace boost::math;
  Binomial::Binomial(long n, long double p) : n(n), p(p), dist(n, p) {}
  long double Binomial::pdf(long value) {
    return(std::tgamma(1+n) / std::tgamma(1+value) / std::tgamma(1+n-value)
	   * std::pow(p, value) * std::pow(1-p, n-value));
  }
  long double Binomial::cdf(long value) {
    return(ibeta(n-value, value-1, p));
  }
  long Binomial::Inverse(long double value) {
    return((long)(n*p));
    // too hard. here's the floor of the mean. should be right.
  }
  long Binomial::operator()(std::mt19937_64 &g) {
    return(this->dist(g));
  }
}

