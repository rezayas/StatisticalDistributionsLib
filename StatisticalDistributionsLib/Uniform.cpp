#include "Uniform.h"

namespace StatisticalDistributions {


  Uniform::Uniform(double min, double max)
    : dist(min, max), min(min), max(max) {}  
  double Uniform::pdf(double value) {
    if (value< this->min || value > this->max)
      return 0;
    else
      return 1/(this->max-this->min);
  }
  double Uniform::cdf(double value) {
    if (value < this->min)
      return 0;
    else if (value > this->max)
      return 1;
    else
      return (this->max-value) / (this->max - this->min);
  }
  double Uniform::Inverse(double value) {
    return(this->min + (this->max - this->min) * value);
  }
  double Uniform::Sample(RNG &rng) {
    return this->min + (this->max - this->min) * rng.RND01();
  }
  double Uniform::operator()(std::mt19937 &g) {
    return(this->dist(g));
  }
}

