#include "ChiSquared.h"

namespace StatisticalDistributions {


  ChiSquared::ChiSquared(long double dof) : Gamma(dof / 2, 1.0 / 2) {}
}

