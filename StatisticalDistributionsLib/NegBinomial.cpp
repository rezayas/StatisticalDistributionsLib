#include "NegBinomial.h"
#include <boost/math/special_functions/beta.hpp>

namespace StatisticalDistributions {

  NegBinomial::NegBinomial(long n, long double p) 
    : dist(n, p), GammaPoisson(n, 1 / p - 1) {}
  long NegBinomial::operator()(std::mt19937_64 &g) {
    return(dist(g));
  }
}

