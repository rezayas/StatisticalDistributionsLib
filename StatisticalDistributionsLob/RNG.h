#pragma once
#include <random>

namespace StatisticalDistributions {
  class RNG {
  public:
    RNG(long seed): mt_(seed), seed_(seed) {}
    long double RND01() {
      return uniform01(mt_);
    }
    std::mt19937_64 mt_;
  private:
    int seed_;
    std::uniform_real_distribution<long double> uniform01;
  };
  
}
