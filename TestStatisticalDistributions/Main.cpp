#include "RNG.h"
#include "Uniform.h"
#include <iostream>
#include <array>
#include <numeric>

using namespace StatisticalDistributions;
using namespace std;

extern void testBernoulli(mt19937_64 &g);
extern void testBeta(mt19937_64 &g);
extern void testBetaBinomial(mt19937_64 &g);
extern void testBinomial(mt19937_64 &g);
extern void testChiSquared(mt19937_64 &g);
extern void testDirichlet(mt19937_64 &g);
extern void testEmpirical(mt19937_64 &g);
extern void testExponential(mt19937_64 &g);
extern void testGamma(mt19937_64 &g);
extern void testJohnsonSu(mt19937_64 &g);
extern void testJohnsonSb(mt19937_64 &g);
extern void testJohnsonSl(mt19937_64 &g);
extern void testLognormal(mt19937_64 &g);
extern void testMultinomial(mt19937_64 &g);
extern void testNegBinomial(mt19937_64 &g);
extern void testNormal(mt19937_64 &g);

int main() {
  long seed;
  cout << "Enter seed: ";
  cin >> seed;
  RNG myRNG(seed);
  array<long double, 1000> sample;
  for (int i = 0; i< 1000; ++i)
    sample[i] = myRNG.RND01();
  cout << "Testing RNG:" << endl;
  long double mean =
    accumulate(sample.begin(), sample.end(), 0.0) / 1000;
  long double acc = 0;
  for(int i = 0; i < 1000; i++)
	  acc += (sample[i] - mean) * (sample[i] - mean);
  long double stdev = sqrt(acc / 999);
  cout << "mean: " << mean << "; stdev: " << stdev << endl;
  cout << "(Expected: μ = .5, σ = .289)" << endl;
  mt19937_64 &g = myRNG.mt_;

  cout << "Testing Uniform:" << endl;
  Uniform myUniform(0, 10);
  
  for (int i = 0; i< 1000; ++i)
    sample[i] = myUniform.Sample(myRNG);
  
  mean = accumulate(sample.begin(), sample.end(), 0.0) / 1000;
  acc = 0;
  for(int i = 0; i < 1000; i++)
    acc += (sample[i] - mean) * (sample[i] - mean);
  stdev = sqrt(acc / 999);
  
  cout << "mean: " << mean << "; stdev: " << stdev << endl;
  cout << "(Expected: μ = 5, σ = 2.89)" << endl;
  testBernoulli(g);
  testBeta(g);
  testBetaBinomial(g);
  testBinomial(g);
  testChiSquared(g);
  testDirichlet(g);
  testEmpirical(g);
  testExponential(g);
  testGamma(g);
  testJohnsonSu(g);
  testJohnsonSb(g);
  testJohnsonSl(g);
  testLognormal(g);
  testMultinomial(g);
  testNegBinomial(g);
  testNormal(g);
}
