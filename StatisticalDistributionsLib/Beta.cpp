#include "Beta.h"
#include <boost/math/special_functions/beta.hpp>

namespace StatisticalDistributions {
  Beta::Beta(long double alpha, long double beta)
    : alpha(alpha), beta(beta), dist(alpha, beta) {}

  Beta Beta::mean_sdev(long double mu, long double sigma) {
    Beta x(boost::math::beta_distribution<long double>::find_alpha(mu, sigma),
	   boost::math::beta_distribution<long double>::find_beta(mu, sigma));
    return(x);
  }
  
  long double Beta::pdf(long double value) {
    return(boost::math::pdf(dist, value));
  }
  long double Beta::cdf(long double value) {
    return(boost::math::cdf(dist, value));
  }
  long double Beta::Inverse(long double value) {
    return(boost::math::quantile(dist, value));
  }
  long double Beta::operator()(std::mt19937_64 &g) {
    return(Inverse(uni(g)));
  }
}
