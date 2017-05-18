#include "Gamma.h"
#include "JohnsonSu.h"
#include "JohnsonSb.h"
#include "JohnsonSl.h"
#include <iostream>
#include <array>
#include <numeric>
#include <vector>
#include <cmath>

using namespace StatisticalDistributions;
using namespace std;

template<class T, size_t N>
extern void output_xbar_s2(array<T, N> sample);

void testGamma(mt19937_64 &g) {
  cout << "Testing Γ:" << endl;
  array<long double, 1000> sample;
  long double alpha, beta;
  cout << "Enter α: ";
  cin >> alpha;
  cout << "Enter β: ";
  cin >> beta;
  Gamma gam(alpha, beta);
  for(int i = 0; i < 1000; i++)
    sample[i] = gam(g);
  output_xbar_s2(sample);
  cout << "(Expected: μ = " << alpha * beta
       << ", σ² = " << alpha * beta * beta
       << ")" << endl;
}

void testJohnsonSu(mt19937_64 &g) {
  cout << "Testing Su:" << endl;
  array<long double, 1000> sample;
  long double gamma, xi, delta, lambda;
  cout << "Enter γ: ";
  cin >> gamma;
  cout << "Enter ξ: ";
  cin >> xi;
  cout << "Enter δ: ";
  cin >> delta;
  cout << "Enter λ: ";
  cin >> lambda;
  JohnsonSu jon(gamma, xi, delta, lambda);
  for(int i = 0; i < 1000; i++)
    sample[i] = jon(g);
  output_xbar_s2(sample);
  cout << "(Expected: μ = " << xi - lambda * exp(1 / delta / delta / 2)
    * sinh(gamma / delta)
       << ", σ² = " << lambda * lambda / 2 * (exp(1/delta/delta) - 1)
    * (exp(1/delta/delta) * cosh(2 * gamma / delta) + 1)
       << ")" << endl;
}

void testJohnsonSb(mt19937_64 &g) {
  cout << "Testing Sb:" << endl;
  array<long double, 1000> sample;
  long double gamma, xi, delta, lambda;
  cout << "Enter γ: ";
  cin >> gamma;
  cout << "Enter ξ: ";
  cin >> xi;
  cout << "Enter δ: ";
  cin >> delta;
  cout << "Enter λ: ";
  cin >> lambda;
  JohnsonSb jon(gamma, xi, delta, lambda);
  for(int i = 0; i < 1000; i++)
    sample[i] = jon(g);
  output_xbar_s2(sample);
}

void testJohnsonSl(mt19937_64 &g) {
  cout << "Testing Sl:" << endl;
  array<long double, 1000> sample;
  long double gamma, xi, delta, lambda;
  cout << "Enter γ: ";
  cin >> gamma;
  cout << "Enter ξ: ";
  cin >> xi;
  cout << "Enter δ: ";
  cin >> delta;
  cout << "Enter λ: ";
  cin >> lambda;
  JohnsonSl jon(gamma, xi, delta, lambda);
  for(int i = 0; i < 1000; i++)
    sample[i] = jon(g);
  output_xbar_s2(sample);
}
