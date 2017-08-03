#include "Lognormal.h"

namespace StatisticalDistributions {
  using namespace std;
  void Lognormal::init(long double mu, long double sigma, long double shift) {
    dist = lognormal_distribution<long double>(mu, sigma);
    pcdist = boost::math::lognormal_distribution<long double>(mu, sigma);
    pshift = shift;
  }

  long double Lognormal::pdf(long double value) const {
    return(boost::math::pdf(pcdist, value - pshift));
  }
  long double Lognormal::cdf(long double value) const {
    return(boost::math::cdf(pcdist, value - pshift));
  }
  long double Lognormal::Inverse(long double value) const {
    return(boost::math::quantile(pcdist, value) + pshift);
  }
  long double Lognormal::operator()(std::mt19937_64 &g) const {
    return(this->dist(g) + pshift);
  }
}
