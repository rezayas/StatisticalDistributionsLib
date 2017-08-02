#include "../include/StatisticalDistributionsLib/Bernoulli.h"

namespace StatisticalDistributions {

  void Bernoulli::init(long double p) {
    dist = std::bernoulli_distribution(p);
    pcdist = boost::math::bernoulli_distribution<long double, POLROUNDDOWN>(p);
  }
  long double Bernoulli::pdf(long value) const {
    return(boost::math::pdf(pcdist, value));
  }
  long double Bernoulli::cdf(long value) const {
    return(boost::math::cdf(pcdist, value));
  }
  long Bernoulli::Inverse(long double value) const {
    return((bool)boost::math::quantile(pcdist, value));
  }
  long Bernoulli::operator()(std::mt19937_64 &g) const {
    return(this->dist(g));
  }
}

