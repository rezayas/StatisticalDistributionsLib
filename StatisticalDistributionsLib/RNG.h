#pragma once
#include <random>

namespace StatisticalDistributions {
  class RNG {
  public:
    RNG(int seed): mt_(seed), seed_(seed) {}
    double RND01() {
      return uniform01(mt_);
    }
    
  private:
    int seed_;
    std::mt19937 mt_;
    std::uniform_real_distribution<double> uniform01;
  };
  
}
