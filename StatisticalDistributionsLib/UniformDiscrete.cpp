#include "UniformDiscrete.h"

namespace StatisticalDistributions {


  UniformDiscrete::UniformDiscrete(long low, long high)
    : dist(low, high-1), low(low), high(high) {}
  UniformDiscrete::UniformDiscrete(long n) : dist(0, n-1), low(0), high(n) {}
  long double UniformDiscrete::pdf(long value) {
    return(low <= value && value < high? 1.0L/(high - low) : 0);
  }
  long double UniformDiscrete::cdf(long value) {
    if(value >= high)
      return 1;
    if(value < low)
      return 0;
    return((value - low + 1.0L) / (high - low)
  }
  long UniformDiscrete::Inverse(long double value) {
      return((long)(value * (high - low)) + low);
  }
  long UniformDiscrete::operator()(std::mt19937_64 &g) {
    return(this->dist(g));
  }
}

