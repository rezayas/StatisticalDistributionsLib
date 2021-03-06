#pragma once
#include "StatisticalDistribution.h"
#include <array>

namespace StatisticalDistributions {
	using namespace std;
  template<size_t N>
  class Multinomial : public StatisticalDistribution<array<long, N> > {
  public:
    // The weights will be normalized.
    inline Multinomial(const array<long double, N> &weights, long trials) {
      init(weights, trials);
    }
    void init(const array<long double, N> &, long);
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
    long trials;
    mutable std::discrete_distribution<long> dist;
  };
}

#include "Multinomial.t"
