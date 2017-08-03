#include "../include/StatisticalDistributionsLib/Beta.h"
using namespace std;
#define bmbdld boost::math::beta_distribution<long double>
namespace StatisticalDistributions {
  void Beta::init(long double a, long double b,
		  long double sc, long double sh) {
    if(sc < 0) {
      sc = -sc;
      long double t = a;
      a = b;
      b = t;
      sh -= sc;
    }
    gama = gamma_distribution<long double>(a);
    gamb = gamma_distribution<long double>(b);
    pdist = bmbdld(a, b);
    pscale = sc;
    pshift = sh;
  }

  Beta Beta::mean_sdev(long double mu, long double sigma) {
    return(Beta(bmbdld::find_alpha(mu, sigma * sigma),
	        bmbdld::find_beta(mu, sigma * sigma)));
  }
  
  long double Beta::pdf(long double value) const {
    return(boost::math::pdf(pdist, (value - pshift) / pscale) / pscale);
  }
  long double Beta::cdf(long double value) const {
    return(boost::math::cdf(pdist, (value - pshift) / pscale));
  }
  long double Beta::Inverse(long double value) const {
    return(boost::math::quantile(pdist, value) * pscale + pshift);
  }
  long double Beta::operator()(std::mt19937_64 &g) const {
    long double a = gama(g);
    long double b = gamb(g);
    return(a * pscale / (a + b) + pshift);
  }
}
