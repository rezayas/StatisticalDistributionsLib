#include "Poisson.h"
#include "Triangular.h"
#include "UniformDiscrete.h"
#include "Weibull.h"
#include <iostream>
#include <array>
#include <numeric>
#include <vector>
#include "sbar.h"

using namespace StatisticalDistributions;
using namespace std;

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
  cout << "Expected: ";
  array<long, 10> lst = {0,1,2,3,4,5,6,7,8,9};
  output_xbar_s2(lst);
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
