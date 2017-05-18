#pragma once
#include "StatisticalDistribution.h"
#include <array>

namespace StatisticalDistributions {
  using namespace std;
  template<size_t N>
  class Dirichlet : public StatisticalDistribution<array<long double, N> > {
  public:
    Dirichlet(array<long double, N> alphas);
    // See the Wikipedia page for the Dirichlet distribution for the meaning.
    virtual long double pdf(array<long double, N> x);
    virtual long double cdf(array<long double, N> x) {
      return(0); // CDF unimplementable.
    }
    virtual array<long double, N> Inverse(long double x) {
      return(array<long double, N>()); // iCDF unimplementable.
    }
    virtual array<long double, N> operator()(mt19937_64 &g);
  private:
    long double beta;
    const array<long double, N> alphas;
    array<gamma_distribution<long double>, N> dists;
  };
}

#include "Dirichlet.t"
// Because C++ templates must be in headers. It's really annoying.
