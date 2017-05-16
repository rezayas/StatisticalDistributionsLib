#include "Bernoulli.h"

namespace StatisticalDistributions {


  Bernoulli::Bernoulli(long double p)
    : dist(p), p(p) {}
  long double Bernoulli::pdf(bool value) {
    return(value? p : 1-p);
  }
  long double Bernoulli::cdf(bool value) {
    return(value? 0 : 1-p);
  }
  bool Bernoulli::Inverse(long double value) {
    return(!(value < (1 - p)));
  }
  bool Bernoulli::operator()(std::mt19937_64 &g) {
    return(this->dist(g));
  }
}

