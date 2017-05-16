#include "ChiSquared.h"

namespace StatisticalDistributions {


  ChiSquared::ChiSquared(long double min, long double max)
    : dist(min, max), min(min), max(max) {}  
  long double ChiSquared::pdf(long double value) {
    if (value< this->min || value > this->max)
      return 0;
    else
      return 1/(this->max-this->min);
  }
  long double ChiSquared::cdf(long double value) {
    if (value < this->min)
      return 0;
    else if (value > this->max)
      return 1;
    else
      return (this->max-value) / (this->max - this->min);
  }
  long double ChiSquared::Inverse(long double value) {
    return(this->min + (this->max - this->min) * value);
  }
  long double ChiSquared::operator()(std::mt19937_64 &g) {
    return(this->dist(g));
  }
}

