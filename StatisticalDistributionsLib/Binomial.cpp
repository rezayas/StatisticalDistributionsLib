#include "Binomial.h"
#include <boost/math/special_functions/beta.hpp>

namespace StatisticalDistributions {


  Binomial::Binomial(long n, long double p) : dist(n, p), cdist(n, p) {}
  long double Binomial::pdf(long value) const {
    return(boost::math::pdf(cdist, value));
  }
  long double Binomial::cdf(long value) const {
    return(boost::math::cdf(cdist, value));
  }
  long Binomial::Inverse(long double value) const {
    return((long)boost::math::quantile(cdist, value));
  }
  long Binomial::operator()(std::mt19937_64 &g) const {
    return(this->dist(g));
  }
}

