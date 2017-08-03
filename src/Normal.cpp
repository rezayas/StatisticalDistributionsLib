#include "Normal.h"

namespace StatisticalDistributions {
  using namespace std;
  void Normal::init(long double mu, long double sigma) {
    dist = std::normal_distribution<long double>(mu, sigma);
    pcdist = boost::math::normal_distribution<long double>(mu, sigma);
  }
  long double Normal::pdf(long double value) const {
    return(boost::math::pdf(pcdist, value));
  }
  long double Normal::cdf(long double value) const {
    return(boost::math::cdf(pcdist, value));
  }
  long double Normal::Inverse(long double value) const {
    return(boost::math::quantile(pcdist, value));
  }
  long double Normal::operator()(std::mt19937_64 &g) const {
    return(this->dist(g));
  }
}
