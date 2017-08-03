#include "JohnsonSb.h"
#include <cmath>

using namespace std;
namespace StatisticalDistributions {
  void JohnsonSb::init(long double mu, long double sigma,
		       long double gamma, long double delta) {
    pgamma = gamma;
    pdelta = fabs(delta);
    if(sigma < 0)
      mu -= sigma = -sigma;
    pmu = mu;
    psigma = sigma;
    dist = normal_distribution<long double>(-pgamma / pdelta, 1 / delta);
    pcdist = boost::math::normal_distribution<long double>(-pgamma / pdelta,
							  1 / delta);
  }
  long double JohnsonSb::pdf(long double value) const {
    long double z = (value - pmu) / psigma;
    if(z < 0 || z > 1)
      return(0);
    return(boost::math::pdf(pcdist, log(z / (1 - z)))
	   * pdelta / psigma / z / (1 - z));
  }
  long double JohnsonSb::cdf(long double value) const {
    long double z = (value - pmu) / psigma;
    if(z < 0)
      return(0);
    if(z > 1)
      return(1);
    return(boost::math::cdf(pcdist, std::log(z / (1 - z))));
  }
  long double JohnsonSb::Inverse(long double value) const {
    return(psigma / (1 + exp(- boost::math::quantile(pcdist, value))) + pmu);
  }
  long double JohnsonSb::operator()(std::mt19937_64 &g) const {
    return(psigma / (1 + exp(dist(g))) + pmu);
  }
}
