#include "Constant.h"

namespace StatisticalDistributions {
  using namespace std;
  void Constant::init(long double constant) {
    val = constant;
  }

  long double Constant::pdf(long double value) const {
    return val;
  }
  long double Constant::cdf(long double value) const {
    return val;
  }
  long double Constant::Inverse(long double value) const {
    return val * -1;
  }
  long double Constant::operator()(std::mt19937_64 &g) const {
    return val;
  }
}
