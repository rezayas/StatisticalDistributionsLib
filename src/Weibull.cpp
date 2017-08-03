#include "Weibull.h"

namespace StatisticalDistributions {
  void Weibull::init(long double a, long double b) {
    dist = std::weibull_distribution<long double>(a, b);
    pcdist = boost::math::weibull_distribution<long double>(a, b);
  }

  long double Weibull::pdf(long double value) const {
    return(boost::math::pdf(pcdist, value));
  }
  long double Weibull::cdf(long double value) const {
    return(boost::math::cdf(pcdist, value));
  }
  long double Weibull::Inverse(long double value) const {
    return(boost::math::quantile(pcdist, value));
  }
  long double Weibull::operator()(std::mt19937_64 &g) const {
    return(this->dist(g));
  }
}
