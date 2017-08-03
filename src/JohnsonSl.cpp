#include "../include/StatisticalDistributionsLib/JohnsonSl.h"
#include <cmath>

using namespace std;
namespace StatisticalDistributions {
  void JohnsonSl::init(long double mu, long double sigma,
			    long double gamma, long double delta) {
    pmu = mu;
    psigma = sigma;
    pgamma = gamma;
    pdelta = fabs(delta);
    dist = normal_distribution<long double>(-pgamma / pdelta, 1 / pdelta);
    pcdist = boost::math::normal_distribution<long double>(-pgamma / pdelta,
							   1 / pdelta);
  }
  long double JohnsonSl::pdf(long double value) const {
    long double y = (value - pmu) / pgamma;
    return(pdelta / y * boost::math::pdf(pcdist, log(y)));
  }
  long double JohnsonSl::cdf(long double value) const {
    long double r = boost::math::cdf(pcdist, log((value - pmu) / psigma));
    return(psigma < 0? 1 - r : r);
  }
  long double JohnsonSl::Inverse(long double value) const {
    if(psigma < 0)
      value = 1 - value;
    return(std::exp(boost::math::quantile(pcdist, value)) * psigma + pmu);
  }
  long double JohnsonSl::operator()(std::mt19937_64 &g) const {
    return(std::exp(dist(g)) * psigma + pmu);
  }
}
