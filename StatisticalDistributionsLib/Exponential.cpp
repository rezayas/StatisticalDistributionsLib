#include "Exponential.h"

namespace StatisticalDistributions
{
  Exponential::Exponential(long double rate, long double shift)
    : dist(rate), rate(rate), shift(shift) {}

  long double Exponential::pdf(long double value) {
    return this->rate*exp(-this->rate * (value - this->shift));
  }
  long double Exponential::cdf(long double value) {
    return 1- exp(-this->rate*(value - this->shift));
  }
  long double Exponential::Inverse(long double value) {
    return this->shift - log(1 - value) / this->rate;
  }
  long double Exponential::operator()(std::mt19937_64 &g) {
    return(this->dist(g));
  }
}
