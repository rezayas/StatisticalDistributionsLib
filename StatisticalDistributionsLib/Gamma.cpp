#include "Gamma.h"
#include <boost/math/special_functions/gamma.hpp>

namespace StatisticalDistributions {
  Gamma::Gamma(long double alpha, long double beta, long double shift)
    : dist(alpha, beta), alpha(alpha), beta(beta), shift(shift) {
    pdfc = 0;
  }

  Gamma Gamma::mean_sdev(long double mu, long double sigma) {
    Gamma x((sigma * sigma / mu), (mu * mu / (sigma * sigma)));
    return(x);
  }
  
  long double Gamma::pdf(long double value) {
    if(pdfc == 0)
      pdfc = 1 / (tgamma(alpha) * pow(beta, alpha));
    if(value - shift < 0)
      return(0);
    return(pdfc * pow(value - shift, alpha - 1) * exp((shift - value) / beta));
  }
  long double Gamma::cdf(long double value) {
    return(boost::math::gamma_p(alpha, (value - shift) / beta));
  }
  long double Gamma::Inverse(long double value) {
    return(boost::math::gamma_p_inv(alpha, value) * beta + shift);
  }
  long double Gamma::operator()(std::mt19937_64 &g) {
    return(this->dist(g));
  }
}
