#include "Lognormal.h"
#include "Multinomial.h"
#include "NegBinomial.h"
#include "Normal.h"
#include <iostream>
#include <array>
#include <numeric>
#include <vector>
#include <cmath>
#include "sbar.h"

using namespace StatisticalDistributions;
using namespace std;

void testLognormal(mt19937_64 &g) {
  cout << "Testing lognormal:" << endl;
  array<long double, 1000> sample;
  long double mu, sigma;
  cout << "Enter μ: ";
  cin >> mu;
  cout << "Enter σ: ";
  cin >> sigma;
  Lognormal lgn(mu, sigma);
  for(int i = 0; i < 1000; i++)
    sample[i] = lgn(g);
  output_xbar_s2(sample);
  cout << "(Expected: μ = " << exp(mu + sigma * sigma / 2)
       << ", σ² = " << (exp(sigma * sigma) - 1) * exp(2 * mu + sigma * sigma)
       << ")" << endl;
}

void testMultinomial(mt19937_64 &g) {
  cout << "Testing multinomial: " << endl;
  array<long, 1000> sample[3];
  array<long double, 3> wts;
  array<long, 3> t;
  long n;
  for(int i = 0; i < 3; i++) {
    cout << "Enter weight " << i << ": ";
    cin >> wts[i];
  }
  cout << "Enter n: ";
  cin >> n;
  Multinomial<3> mlt(wts, n);
  for(int i = 0; i < 1000; i++) {
    t = mlt(g);
    for(int j = 0; j < 3; j++)
      sample[j][i] = t[j];
  }
  long double twt = wts[0]+wts[1]+wts[2];
  for(int i = 0; i < 3; i++) {
    wts[i] /= twt;
    output_xbar_s2(sample[i]);
    cout << "(Expected: μ" << i << " = " << (n * wts[i])
	 << ", σ²" << i << " = "
	 << (n * wts[i] * (1 - wts[i]))
	 << ")" << endl;
  }
}

void testNegBinomial(mt19937_64 &g) {
  cout << "Testing negative binomial:" << endl;
  array<long, 1000> sample;
  long r;
  long double p;
  cout << "Enter n: ";
  cin >> r;
  cout << "Enter p: ";
  cin >> p;
  NegBinomial nbn(r, p);
  for(int i = 0; i < 1000; i++)
    sample[i] = nbn(g);
  output_xbar_s2(sample);
  cout << "(Expected: μ = " << (p * r / (1-p))
       << ", σ² = " << (p * r / (1-p) / (1-p))
       << ")" << endl;
}

void testNormal(mt19937_64 &g) {
  cout << "Testing normal:" << endl;
  array<long double, 1000> sample;
  long double mu, sigma;
  cout << "Enter μ: ";
  cin >> mu;
  cout << "Enter σ: ";
  cin >> sigma;
  Normal norm(mu, sigma);
  for(int i = 0; i < 1000; i++)
    sample[i] = norm(g);
  output_xbar_s2(sample);
  cout << "(Expected: σ² = " << (sigma * sigma) << ")" << endl;
}
