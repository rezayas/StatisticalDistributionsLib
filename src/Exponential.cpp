#include "../include/StatisticalDistributionsLib/Exponential.h"

using namespace std;
namespace StatisticalDistributions {
  void Exponential::init(long double rate, long double sh) {
    dist = exponential_distribution<long double>(rate);
    pshift = sh;
    pcdist = boost::math::exponential_distribution<long double>(rate);
  }

  long double Exponential::pdf(long double value) const {
    return(boost::math::pdf(pcdist, value - pshift));
  }
  long double Exponential::cdf(long double value) const {
    return(boost::math::cdf(pcdist, value - pshift));
  }
  long double Exponential::Inverse(long double value) const {
    return(boost::math::quantile(pcdist, value) + pshift);
  }
  long double Exponential::operator()(std::mt19937_64 &g) const {
    return(this->dist(g));
  }
}
