#include "../include/StatisticalDistributionsLib/UniformDiscrete.h"

namespace StatisticalDistributions {
  void UniformDiscrete::init(long low, long high) {
    dist = std::uniform_int_distribution<long>(low, high);
    plow = low;
    phigh = high;
  }
  long double UniformDiscrete::pdf(long value) const {
    return(plow <= value && value < phigh? 1.0L/(phigh - plow) : 0);
  }
  long double UniformDiscrete::cdf(long value) const {
    if(value >= phigh)
      return 1;
    if(value < plow)
      return 0;
    return((value - plow + 1.0L) / (phigh - plow));
  }
  long UniformDiscrete::Inverse(long double value) const {
      return((long)(value * (phigh - plow)) + plow);
  }
  long UniformDiscrete::operator()(std::mt19937_64 &g) const {
    return(this->dist(g));
  }
}

