#include "Triangular.h"

namespace StatisticalDistributions {


  Triangular::Triangular(long double min, long double max)
    : dist(min, max), min(min), max(max) {}  
  long double Triangular::pdf(long double value) {
    if (value< this->min || value > this->max)
      return 0;
    else
      return 1/(this->max-this->min);
  }
  long double Triangular::cdf(long double value) {
    if (value < this->min)
      return 0;
    else if (value > this->max)
      return 1;
    else
      return (this->max-value) / (this->max - this->min);
  }
  long double Triangular::Inverse(long double value) {
    return(this->min + (this->max - this->min) * value);
  }
  long double Triangular::operator()(std::mt19937_64 &g) {
    return(this->dist(g));
  }
}

