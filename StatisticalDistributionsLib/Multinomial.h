#pragma once
#include "StatisticalDistribution.h"
#include <array>

namespace StatisticalDistributions {
  template<size_t N>
  class Multinomial : public StatisticalDistribution<array<long, N> > {
  public:
    // The weights will be normalized.
    Multinomial(array<long double, N> weights, long trials);

    // The pdf function doesn't bother to check whether the number of trials
    // is right.
    virtual long double pdf(array<long, N> x) const;
    virtual long double cdf(array<long, N> x) const {
      return(0); // CDF unimplementable.
    }
    virtual std::array<long, N> Inverse(long double x) const {
      return(std::array<long, N>()); // iCDF unimplementable.
    }
    virtual array<long, N> operator()(mt19937_64 &g) const;
  private:
    std::array<long double, N> ps;
    const long trials;
    mutable std::discrete_distribution<long> dist;
  };
}

#include "Multinomial.t"
