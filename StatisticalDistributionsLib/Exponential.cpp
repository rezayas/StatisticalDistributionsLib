#include "Exponential.h"

namespace StatisticalDistributions
{
  Exponential::Exponential(double rate) : dist(rate), rate(rate) {}

  double Exponential::pdf(double value) {
    return this->rate*exp(-this->rate*value);
  }
  double Exponential::cdf(double value) {
    return 1- exp(-this->rate*value);
  }
  double Exponential::Inverse(double value) {
    return -log(1 - value) / this->rate;
  }
  double Exponential::Sample(RNG &rng) {
    return Inverse(rng.RND01());
  }
  double Exponential::operator()(std::mt19937 &g){
    return(this->dist(g));
  }
}
