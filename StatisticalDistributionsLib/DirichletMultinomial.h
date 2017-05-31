#pragma once
#include "StatisticalDistribution.h"
#include <array>
#include "Dirichlet.h"

namespace StatisticalDistributions {
  using namespace std;
  template<size_t N>
  class DirichletMultinomial : public StatisticalDistribution<array<long, N> > {
  public:
    DirichletMultinomial(array<long double, N> alphas, long trials);

    // The pdf function doesn't bother to check whether the number of trials
    // is right.
    virtual long double pdf(array<long, N> x);
    virtual long double cdf(array<long, N> x) {
      return(0); // CDF unimplementable.
    }
    virtual array<long, N> Inverse(long double x) {
      return(array<long, N>()); // iCDF unimplementable.
    }
    virtual array<long, N> operator()(mt19937_64 &g);
  private:
    const long trials;
    long double talpha = 0;
    Dirichlet<N> dist;
    const array<long double, N> alphas;
  };
}

#include "DirichletMultinomial.t"
