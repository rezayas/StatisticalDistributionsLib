#include "../include/StatisticalDistributionsLib/JohnsonSu.h"
#include <cmath>

using namespace std;
namespace StatisticalDistributions {
  void JohnsonSu::init(long double mu, long double sigma,
		       long double gamma, long double delta) {
    pdelta = fabs(delta);
    psigma = fabs(sigma);
    pmu = mu;
    pdelta = delta;
    dist = normal_distribution<long double>(-pgamma / pdelta, 1 / pdelta);
    pcdist = boost::math::normal_distribution<long double>(-pgamma / pdelta,
							   1 / pdelta);
  }
  long double JohnsonSu::pdf(long double value) const {
    long double y = (value - pmu) / psigma;
    return(pdelta / psigma * sqrt(1 + y * y) *
	   boost::math::pdf(pcdist, asinh(y)));
  }
  long double JohnsonSu::cdf(long double value) const {
    return(boost::math::cdf(pcdist, asinh((value - pmu)/psigma)));
  }
  long double JohnsonSu::Inverse(long double value) const {
    return(sinh(boost::math::quantile(pcdist, value)) * psigma + pmu);
  }
  long double JohnsonSu::operator()(std::mt19937_64 &g) const {
    return(sinh(this->dist(g)) * psigma + pmu);
  }
}
