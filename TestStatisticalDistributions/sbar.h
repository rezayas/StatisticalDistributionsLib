#pragma once
#include <array>
#include <numeric>

template<class T, size_t N>
void output_xbar_s2(array<T, N> sample) {
  long double mean =
    accumulate(sample.begin(), sample.end(), 0.0) / N;
  long double acc = 0;
  for(int i = 0; i < N; i++)
    acc += (sample[i] - mean) * (sample[i] - mean);
  long double variance = acc / (N-1);
  cout << "mean: " << mean << "; variance: " << variance << endl;
}
