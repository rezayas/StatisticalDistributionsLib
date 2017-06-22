#include "Geometric.h"

namespace StatisticalDistributions {

  Geometric::Poisson(long double p) : cdist(p), dist(p) {}
  long double Geometric::pdf(long value) const {
    return(boost::math::pdf(cdist, value));
  }
  long double Geometric::cdf(long value) const {
    return(boost::math::cdf(cdist, value));
  }
  long Geometric::Inverse(long double value) const {
    return((long)boost::math::quantile(cdist, value));
  }
  long Geometric::operator()(std::mt19937_64 &g) const {
    return(this->dist(g));
  }
}

