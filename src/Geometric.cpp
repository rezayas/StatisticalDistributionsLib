#include "../include/StatisticalDistributionsLib/Geometric.h"

using namespace std;
namespace StatisticalDistributions {

  void Geometric::init(long double p) {
    pcdist = boost::math::geometric_distribution<long double, POLROUNDDOWN>(p);
    dist = geometric_distribution<long>(p);
  }
  long double Geometric::pdf(long value) const {
    return(boost::math::pdf(pcdist, value));
  }
  long double Geometric::cdf(long value) const {
    return(boost::math::cdf(pcdist, value));
  }
  long Geometric::Inverse(long double value) const {
    return((long)boost::math::quantile(pcdist, value));
  }
  long Geometric::operator()(std::mt19937_64 &g) const {
    return(this->dist(g));
  }
}

