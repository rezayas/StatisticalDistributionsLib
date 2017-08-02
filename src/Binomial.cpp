#include "../include/StatisticalDistributionsLib/Binomial.h"
#include <boost/math/special_functions/beta.hpp>

using namespace std;
namespace StatisticalDistributions {

  void Binomial::init(long n, long double p) {
    pcdist
      = boost::math::binomial_distribution<long double, POLROUNDDOWN>(n, p);
    dist = binomial_distribution<long>(n, p);
  }
  long double Binomial::pdf(long value) const {
    return(boost::math::pdf(pcdist, value));
  }
  long double Binomial::cdf(long value) const {
    return(boost::math::cdf(pcdist, value));
  }
  long Binomial::Inverse(long double value) const {
    return((long)boost::math::quantile(pcdist, value));
  }
  long Binomial::operator()(std::mt19937_64 &g) const {
    return(this->dist(g));
  }
}

