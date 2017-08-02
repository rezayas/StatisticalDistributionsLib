#include "../include/StatisticalDistributionsLib/NegBinomial.h"

namespace StatisticalDistributions {
  void NegBinomial::init(long n, long double p) {
    dist = std::negative_binomial_distribution<long>(n, p);
    GammaPoisson::init(n, p / (1 - p));
  }
  long NegBinomial::operator()(std::mt19937_64 &g) const {
    return(dist(g));
  }
}

