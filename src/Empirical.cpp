#include "Empirical.h"

namespace StatisticalDistributions {


  void Empirical::init(const std::vector<long double> &weights) {
    dist = std::discrete_distribution<long>(weights.begin(), weights.end());
    p.resize(weights.size());
    q.resize(weights.size());
    long double twt = 0;
    for(unsigned long i = 0; i < weights.size(); i++)
      twt += weights[i];
    for(unsigned long i = 0; i < weights.size(); i++)
      p[i] = weights[i] / twt;
    q[0] = p[0];
    for(unsigned long i = 1; i < weights.size(); i++)
      q[i] = p[i] + q[i-1];
  }
  long double Empirical::pdf(long value) const {
    return(value >= 0 && value < p.size()? p[value] : 0);
  }
  long double Empirical::cdf(long value) const {
    if(value < 0)
      return(0);
    if(value >= q.size())
      return(1);
    return(q[value]);
  }
  long Empirical::Inverse(long double value) const {
    unsigned long i;
    for(i = 0; i < q.size(); i++)
      if(q[i] >= value)
	break;
    return i;
  }
  long Empirical::operator()(std::mt19937_64 &g) const {
    return(this->dist(g));
  }
}

