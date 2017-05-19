#include "Poisson.h"
#include "Triangular.h"
#include "UniformDiscrete.h"
#include "Weibull.h"
#include <iostream>
#include <array>
#include <numeric>
#include <vector>

using namespace StatisticalDistributions;
using namespace std;

template<class T, size_t N>
extern void output_xbar_s2(array<T, N> sample);


void testPoisson(mt19937_64 &g) {
  cout << "Testing Poisson:" << endl;
  array<long, 1000> sample;
  long double mu;
  Poisson pois(mu);
  cout << "Enter μ: ";
  cin >> mu;
  for(int i = 0; i < 1000; i++)
    sample[i] = pois(g);
  output_xbar_s2(sample);
  cout << "(Expected: σ² = " << mu
       << ")" << endl;
}

void testTriangular(mt19937_64 &g) {
  cout << "Testing triangular: " << endl;
  array<long double, 1000> sample;
  cout << "Enter min: ";
  long double min, mode, max;
  cin >> min;
  cout << "Enter mode: ";
  cin >> mode;
  cout << "Enter max: ";
  cin >> max;
  Triangular tri(min, max, mode);
  for(int i = 0; i < 1000; i++)
    sample[i] = tri(g);
  output_xbar_s2(sample);
  cout << "(Expected: μ = " << ((min + max + mode) / 3)
       << ", σ² = " << ((min * (min - max - mode) + max * (max - mode) +
			 mode * mode) / 18)
       << ")" << endl;
}

void testUniformDiscrete(mt19937_64 &g) {
  cout << "Testing uniform discrete:" << endl;
  array<long, 1000> sample;
  UniformDiscrete uni(10);
  for(int i = 0; i < 1000; i++)
    sample[i] = uni(g);
  output_xbar_s2(sample);
  cout << "(Expected: μ = 4.5, σ² = 8.25)" << endl;
}

void testWeibull(mt19937_64 &g) {
  cout << "Testing Weibull: " << endl;
  array<long double, 1000> sample;
  cout << "Enter a: ";
  long double a, b;
  cin >> a;
  cout << "Enter b: ";
  cin >> b;
  Weibull wei(a, b);
  for(int i = 0; i < 1000; i++)
    sample[i] = wei(g);
  output_xbar_s2(sample);
  long double x = tgamma(1 + 1/a);
  cout << "(Expected: μ = " << (b * x)
       << ", σ² = " << (b * b * (tgamma(1 + 2/a) - x * x))
       << ")" << endl;
}
