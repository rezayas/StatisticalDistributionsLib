#include "Gamma.h"

namespace StatisticalDistributions {
  Gamma::Gamma(long double alpha, long double beta, long double shift)
    : dist(alpha, beta), shift(shift), cdist(alpha, beta) {}

  Gamma Gamma::mean_sdev(long double mu, long double sigma) {
    Gamma x((sigma * sigma / mu), (mu * mu / (sigma * sigma)));
    return(x);
  }
  
  long double Gamma::pdf(long double value) {
    return(boost::math::pdf(cdist, value - shift));
  }
  long double Gamma::cdf(long double value) {
    return(boost::math::cdf(cdist, value - shift));
  }
  long double Gamma::Inverse(long double value) {
    return(boost::math::quantile(cdist, value) + shift);
  }
  long double Gamma::operator()(std::mt19937_64 &g) {
    return(this->dist(g));
  }
}
