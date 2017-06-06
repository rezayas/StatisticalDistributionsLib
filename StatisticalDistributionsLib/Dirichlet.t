namespace StatisticalDistributions {

  template<size_t N>
  Dirichlet<N>::Dirichlet(std::array<const long double, N> alphas)
    : beta(-1), alphas(alphas) {
    for(int i = 0; i < N; i++)
      dists[i] = std::gamma_distribution<long double>(alphas[i]);
  }
  template<size_t N>
  long double Dirichlet<N>::pdf(std::array<long double, N> x) const {
    if(beta == -1) {
      long double asum = 0;
      for(int i = 0; i < N; i++) {
	beta *= std::tgamma(alphas[i]);
	asum += alphas[i];
      }
      beta /= std::tgamma(asum);
    }
    long double ans = 1;
    for(int i = 0; i < N; i++)
      ans *= std::pow(x[i], alphas[i] - 1);
    return(ans);
  }
  template<size_t N>
  std::array<long double, N> Dirichlet<N>::operator()(std::mt19937_64 &g)
  const {
    std::array<long double, N> rval;
    long double tot = 0;
    for(int i = 0; i < N; i++)
      tot += rval[i] = dists[i](g);
    for(int i = 0; i < N; i++)
      rval[i] /= tot;
    return(rval);
  }
}

