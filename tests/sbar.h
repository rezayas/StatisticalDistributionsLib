#pragma once
#include <array>
#include <numeric>

template<class T, size_t N>
void output_xbar_s2(std::array<T, N> sample) {
  long double mean =
    std::accumulate(sample.begin(), sample.end(), 0.0) / N;
  long double acc = 0;
  for(int i = 0; i < N; i++)
    acc += (sample[i] - mean) * (sample[i] - mean);
  long double variance = acc / (N-1);
  std::cout << "mean: " << mean << "; variance: " << variance << std::endl;
}
