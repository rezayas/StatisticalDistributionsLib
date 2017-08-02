#include "../include/StatisticalDistributionsLib/BetaBinomial.h"
#include <boost/math/special_functions/beta.hpp>
#include <boost/math/special_functions/binomial.hpp>

namespace StatisticalDistributions {
  void BetaBinomial::init(long n, long double alpha, long double beta) {
    palpha = alpha;
    pbeta = beta;
    pn = n;
    pdist.init(alpha, beta);
  }
  long double BetaBinomial::pdf(long value) const {
    return(boost::math::binomial_coefficient<long double>(n, value)
	   * boost::math::beta<long double, long double>(value + alpha,
							 n - value + beta)
	   / boost::math::beta<long double, long double>(alpha, beta));
  }
  long double BetaBinomial::cdf(long value) const {
    return 0; //Can't do hypergeometric functions.
  }
  long BetaBinomial::Inverse(long double value) const {
    return 0; //Can't do hypergeometric functions.
  }
  long BetaBinomial::operator()(std::mt19937_64 &g) const {
    return(std::binomial_distribution<long>(n, dist(g))(g));
  }
}

