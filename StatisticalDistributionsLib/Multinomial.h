#pragma once
#include "StatisticalDistribution.h"
#include <array>

namespace StatisticalDistributions {
  using namespace std;
  template<size_t N>
  class Multinomial : public StatisticalDistribution<array<long, N> > {
  public:
    // The weights will be normalized.
    Multinomial(array<long double, N> weights, long trials);

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
    array<long double, N> ps;
    const long trials;
    discrete_distribution<long> dist;
  };
}

#include "Multinomial.t"
