#include "Gamma.h"
#include "Geometric.h"
#include "JohnsonSu.h"
#include "JohnsonSb.h"
#include "JohnsonSl.h"
#include <iostream>
#include <array>
#include <numeric>
#include <vector>
#include <cmath>
#include "sbar.h"

using namespace StatisticalDistributions;
using namespace std;

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
  cout << "(Expected: μ = " << (alpha * beta)
       << ", σ² = " << (alpha * beta * beta)
       << ")" << endl;
}

void testGeometric(mt19937_64 &g) {
  cout << "Testing geometric:" << endl;
  array<long, 1000> sample;
  long double p;
  cout << "Enter p: ";
  cin >> p;
  Geometric geo(p);
  for(int i = 0; i < 1000; i++)
    sample[i] = geo(g);
  output_xbar_s2(sample);
  cout << "Expected: μ = " << 1 / p - 1
  << ", σ² = " << (1 - p) / p / p << ')' << endl;
}

void testJohnsonSu(mt19937_64 &g) {
  cout << "Testing Su:" << endl;
  array<long double, 1000> sample;
  long double gamma, delta, mu, sigma;
  cout << "Enter μ: ";
  cin >> mu;
  cout << "Enter σ: ";
  cin >> sigma;
  cout << "Enter γ: ";
  cin >> gamma;
  cout << "Enter δ: ";
  cin >> delta;
  JohnsonSu jon(mu, sigma, gamma, delta);
  for(int i = 0; i < 1000; i++)
    sample[i] = jon(g);
  output_xbar_s2(sample);
  long double y = exp(1 / delta / delta);
  cout << "(Expected: μ = " << (mu - sigma * exp(1 / 2 / delta / delta)
				* sinh(gamma / delta))
       << ", σ² = " << (sigma * sigma * (y - 1)
			* (y * cosh(2 * gamma / delta) + 1) / 2)
       << ")" << endl;
}

void testJohnsonSb(mt19937_64 &g) {
  cout << "Testing Sb:" << endl;
  array<long double, 1000> sample;
  long double gamma, delta, mu, sigma;
  cout << "Enter μ: ";
  cin >> mu;
  cout << "Enter σ: ";
  cin >> sigma;
  cout << "Enter γ: ";
  cin >> gamma;
  cout << "Enter δ: ";
  cin >> delta;
  JohnsonSb jon(mu, sigma, gamma, delta);
  for(int i = 0; i < 1000; i++)
    sample[i] = jon(g);
  output_xbar_s2(sample);
}

void testJohnsonSl(mt19937_64 &g) {
  cout << "Testing Sl:" << endl;
  array<long double, 1000> sample;
  long double gamma, delta, mu, sigma;
  cout << "Enter μ: ";
  cin >> mu;
  cout << "Enter σ: ";
  cin >> sigma;
  cout << "Enter γ: ";
  cin >> gamma;
  cout << "Enter δ: ";
  cin >> delta;
  JohnsonSl jon(mu, sigma, gamma, delta);
  for(int i = 0; i < 1000; i++)
    sample[i] = jon(g);
  output_xbar_s2(sample);
  cout << "(Expected: μ = " << (mu + sigma * exp((1 - 2 * gamma * delta)
						 / 2 / delta / delta))
       << ", σ² = " << (exp((1 - 2 * gamma * delta) / delta / delta)
			* (exp(1 / delta / delta) - 1) * sigma * sigma)
       << ")" << endl;
}
