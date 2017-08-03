#include "GammaPoisson.h"

using namespace std;
namespace StatisticalDistributions {

  void GammaPoisson::init(long double alpha, long double beta) {
    pcdist = boost::math::negative_binomial_distribution<long double,
							 POLROUNDDOWN>(alpha,
								       beta /
								       (beta +
									1));
    dist = gamma_distribution<long double>(alpha, beta);
  }
  long double GammaPoisson::pdf(long value) const {
    return(boost::math::pdf(pcdist, value));
  }
  long double GammaPoisson::cdf(long value) const {
    return(boost::math::cdf(pcdist, value));
  }
  long GammaPoisson::Inverse(long double value) const {
    return((long)boost::math::quantile(pcdist, value));
  }
  long GammaPoisson::operator()(std::mt19937_64 &g) const {
    return(poisson_distribution<long>(dist(g))(g)); //UGLY.
  }
}

