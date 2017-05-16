#include "Triangular.h"
#include <array>

namespace StatisticalDistributions {


  Triangular::Triangular(long double min, long double max, long double mode)
    : min(min), max(max), mode(mode) {
    std::array<long double, 3> a = {min, mode, max}, b = {0, 1, 0};
    dist = std::piecewise_linear_distribution<long double>(a.begin(),
							   a.end(),
							   b.begin());
  }
  long double Triangular::pdf(long double value) {
    if (value< this->min || value > this->max)
      return 0;
    else if(value < mode)
      return(2 * (value - min) / (max - min) / (mode - min));
    else
      return(2 * (max - value) / (max - min) / (max - mode));
  }
  long double Triangular::cdf(long double value) {
    if (value < this->min)
      return 0;
    else if (value > this->max)
      return 1;
    else if(value < mode)
      return((value - min) * (value - min) / (max - min) / (mode - min));
    else
      return(1 - (max - value) * (max - value) / (max - min) / (max - mode));
  }
  long double Triangular::Inverse(long double value) {
    if(value < (mode - min) / (max - min))
      return(std::sqrt(value * (max - min) * (mode - min)) + min);
    else
      return(max - std::sqrt((1 - value) * (max - min) * (max - mode)));
  }
  long double Triangular::operator()(std::mt19937_64 &g) {
    return(this->dist(g));
  }
}

