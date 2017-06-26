#include "RNG.h"
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
extern void testGeometric(mt19937_64 &g);
extern void testJohnsonSu(mt19937_64 &g);
extern void testJohnsonSb(mt19937_64 &g);
extern void testJohnsonSl(mt19937_64 &g);
extern void testLognormal(mt19937_64 &g);
extern void testMultinomial(mt19937_64 &g);
extern void testNegBinomial(mt19937_64 &g);
extern void testNormal(mt19937_64 &g);
extern void testPoisson(mt19937_64 &g);
extern void testRNG(RNG &g);
extern void testTriangular(mt19937_64 &g);
extern void testUniform(mt19937_64 &g);
extern void testUniformDiscrete(mt19937_64 &g);
extern void testWeibull(mt19937_64 &g);

int main() {
  long seed;
  cout << "Enter seed: ";
  cin >> seed;
  RNG myRNG(seed);
  mt19937_64 &g = myRNG.mt_;
  testBernoulli(g);
  testBeta(g);
  testBetaBinomial(g);
  testBinomial(g);
  testChiSquared(g);
  testDirichlet(g);
  testEmpirical(g);
  testExponential(g);
  testGamma(g);
  testGeometric(g);
  testJohnsonSu(g);
  testJohnsonSb(g);
  testJohnsonSl(g);
  testLognormal(g);
  testMultinomial(g);
  testNegBinomial(g);
  testNormal(g);
  testPoisson(g);
  testRNG(myRNG);
  testTriangular(g);
  testUniform(g);
  testUniformDiscrete(g);
  testWeibull(g);
}
