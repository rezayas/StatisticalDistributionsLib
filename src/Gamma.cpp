#include "../include/StatisticalDistributionsLib/Gamma.h"

using namespace std;
namespace StatisticalDistributions {
  void Gamma::init(long double alpha, long double beta, long double shift) {
    pshift = shift;
    dist = gamma_distribution(alpha, beta);
    pcdist = boost::math::gamma_distribution(alpha, beta);
  }

  Gamma Gamma::mean_sdev(long double mu, long double sigma) {
    return(Gamma((sigma * sigma / mu), (mu * mu / (sigma * sigma))));
  }
  
  long double Gamma::pdf(long double value) const {
    return(boost::math::pdf(pcdist, value - pshift));
  }
  long double Gamma::cdf(long double value) const {
    return(boost::math::cdf(pcdist, value - pshift));
  }
  long double Gamma::Inverse(long double value) const {
    return(boost::math::quantile(pcdist, value) + pshift);
  }
  long double Gamma::operator()(std::mt19937_64 &g) const {
    return(this->dist(g) + pshift);
  }
}
