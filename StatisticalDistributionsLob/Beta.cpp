#include "Beta.h"

namespace StatisticalDistributions {
  Beta::Beta(long double alpha, long double beta,
	     long double scale, long double shift)
    : scale(scale), shift(shift), dist(alpha, beta), gama(alpha), gamb(beta) {}

  Beta Beta::mean_sdev(long double mu, long double sigma) {
    Beta x(boost::math::beta_distribution<long double>::find_alpha(mu,
								   sigma
								    * sigma),
	   boost::math::beta_distribution<long double>::find_beta(mu,
								  sigma
								  * sigma));
    return(x);
  }
  
  long double Beta::pdf(long double value) const {
    return(boost::math::pdf(dist, (value - shift) / scale) / scale);
  }
  long double Beta::cdf(long double value) const {
    return(boost::math::cdf(dist, (value - shift) / scale));
  }
  long double Beta::Inverse(long double value) const {
    return(boost::math::quantile(dist, value) * scale + shift);
  }
  long double Beta::operator()(std::mt19937_64 &g) const {
    long double a = gama(g);
    long double b = gamb(g);
    return(a * scale / (a + b) + shift);
  }
}
