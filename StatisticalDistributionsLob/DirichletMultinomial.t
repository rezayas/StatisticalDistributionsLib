#include <boost/math/special_functions/beta.hpp>
#include "Multinomial.h"
namespace StatisticalDistributions {

  template<size_t N>
  DirichletMultinomial<N>::DirichletMultinomial(std::array<long double, N> alphas, long trials)
    : trials(trials), dist(alphas), alphas(alphas) {
    for(int i = 0; i < N; i++)
      talpha += alphas[i];
  }
  template<size_t N>
  long double DirichletMultinomial<N>::pdf(std::array<long, N> x) const {
    long tr = 0;
    for(int i = 0; i < N; i++)
      tr += x[i];
    long double prod = tr * boost::math::beta(tr, talpha);
    for(int i = 0; i < N; i++)
      prod /= x[i] * boost::math::beta(x[i], alphas[i]);
    return(prod);
  }
  template<size_t N>
  std::array<long, N> DirichletMultinomial<N>::operator()(std::mt19937_64 &g)
  const {
    Multinomial<N> m(dist(g), n);
    return(m(g));
  }
}

