#include "Uniform.h"

namespace StatisticalDistributions {


  void Uniform::init(long double min, long double max) {
    dist = std::uniform_real_distribution<long double>(min, max);
    pcdist = boost::math::uniform_distribution<long double>(min, max);
  }
  long double Uniform::pdf(long double value) const {
    return(boost::math::pdf(pcdist, value));
  }
  long double Uniform::cdf(long double value) const {
    return(boost::math::cdf(pcdist, value));
  }
  long double Uniform::Inverse(long double value) const {
    return(boost::math::quantile(pcdist, value));
  }
  long double Uniform::operator()(std::mt19937_64 &g) const {
    return(this->dist(g));
  }
}

