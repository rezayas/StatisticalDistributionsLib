#pragma once
#include "StatisticalDistribution.h"
#include <array>
#include "Dirichlet.h"

namespace StatisticalDistributions {
  using namespace std;
  template<size_t N>
  class DirichletMultinomial : public StatisticalDistribution<array<long, N> > {
  public:
    inline DirichletMultinomial(const array<long double, N> &alphas,
				long trials) {
      init(alphas, trials);
    }
    void init(const array<long double, N> &, long);
    // The pdf function doesn't bother to check whether the number of trials
    // is right.
    virtual long double pdf(array<long, N> x) const;
    virtual long double cdf(array<long, N> x) const {
      return(0); // CDF unimplementable.
    }
    virtual array<long, N> Inverse(long double x) const {
      return(array<long, N>()); // iCDF unimplementable.
    }
    virtual array<long, N> operator()(mt19937_64 &g) const;
  private:
    long trials;
    long double talpha = 0;
    Dirichlet<N> dist;
    array<long double, N> alphas;
  };
}

#include "DirichletMultinomial.t"
