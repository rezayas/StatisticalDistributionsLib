#include "../include/StatisticalDistributionsLib/Triangular.h"
#include <array>

namespace StatisticalDistributions {


  void Triangular::init(long double min, long double max, long double mode) {
    pcdist = boost::math::triangular_distribution<long double>(min, mode, max);
    std::array<long double, 3> a = {min, mode, max}, b = {0, 1, 0};
    dist = std::piecewise_linear_distribution<long double>(a.begin(),
							   a.end(),
							   b.begin());
  }
  long double Triangular::pdf(long double value) const {
    return(boost::math::pdf(pcdist, value));
  }
  long double Triangular::cdf(long double value) const {
    return(boost::math::cdf(pcdist, value));
  }
  long double Triangular::Inverse(long double value) const {
    return(boost::math::quantile(pcdist, value));
  }
  long double Triangular::operator()(std::mt19937_64 &g) const {
    return(this->dist(g));
  }
}

