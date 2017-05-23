#include "Weibull.h"

namespace StatisticalDistributions {
  Weibull::Weibull(long double a, long double b) : dist(a, b), a(a), b(b) {}

  long double Weibull::pdf(long double value) {
    if(value < 0)
      return(0);
    return(a / b * pow(value / b, a - 1) * exp(-pow(value / b, a)));
  }
  long double Weibull::cdf(long double value) {
    if(value < 0)
      return(0);
    return(1 - exp(-pow(value / b, a)));
  }
  long double Weibull::Inverse(long double value) {
    return(b * pow(-log(1 - value), 1 / a));
  }
  long double Weibull::operator()(std::mt19937_64 &g) {
    return(this->dist(g));
  }
}
