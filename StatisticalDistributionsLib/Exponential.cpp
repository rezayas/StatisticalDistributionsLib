#include "Exponential.h"

namespace StatisticalDistributions
{
  Exponential::Exponential(long double rate) : dist(rate), rate(rate) {}

  long double Exponential::pdf(long double value) {
    return this->rate*exp(-this->rate*value);
  }
  long double Exponential::cdf(long double value) {
    return 1- exp(-this->rate*value);
  }
  long double Exponential::Inverse(long double value) {
    return -log(1 - value) / this->rate;
  }
  long double Exponential::Sample(RNG &rng) {
    return Inverse(rng.RND01());
  }
  long double Exponential::operator()(std::mt19937_64 &g) {
    return(this->dist(g));
  }
}
