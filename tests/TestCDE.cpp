#include "ChiSquared.h"
#include "Dirichlet.h"
#include "Empirical.h"
#include "Exponential.h"
#include <iostream>
#include <array>
#include <numeric>
#include <vector>
#include "sbar.h"
#include "CSVImport.h"
using namespace StatisticalDistributions;
using namespace std;

void testChiSquared(mt19937_64 &g) {
  cout << "Testing χ²:" << endl;
  array<long double, 1000> sample;
  long double dof;
  cout << "Enter dof: ";
  cin >> dof;
  ChiSquared csq(dof);
  for(int i = 0; i < 1000; i++)
    sample[i] = csq(g);
  output_xbar_s2(sample);
  cout << "(Expected: μ = " << dof
       << ", σ² = " << (2 * dof)
       << ")" << endl;
}

void testDirichlet(mt19937_64 &g) {
  cout << "Testing Dirichlet: " << endl;
  array<long double, 1000> sample[3];
  array<long double, 3> alpha;
  array<long double, 3> t;
  for(int i = 0; i < 3; i++) {
    cout << "Enter α" << i << ": ";
    cin >> alpha[i];
  }
  long double al0 = alpha[0] + alpha[1] + alpha[2];
  Dirichlet<3> dir(alpha);
  for(int i = 0; i < 1000; i++) {
    t = dir(g);
    for(int j = 0; j < 3; j++)
      sample[j][i] = t[j];
  }   
  for(int i = 0; i < 3; i++) {
    output_xbar_s2(sample[i]);
    cout << "(Expected: μ" << i << " = " << (alpha[i] / al0)
	 << ", σ²" << i << " = "
	 << (alpha[i] * (al0 - alpha[i]) / al0 / al0 / (al0 + 1))
	 << ")" << endl;
  }
}

void testEmpirical(mt19937_64 &g) {
  cout << "Testing empirical: " << endl;
  vector<long double> wts(5);
  int counts[5];
  for(int i = 0; i < 5; i++) {
    cout << "Enter weight for " << i << ": ";
    cin >> wts[i];
    counts[i] = 0;
  }
  Empirical emp(wts);
  for(int i = 0; i < 1000; i++)
    counts[emp(g)]++;
  for(int i = 0; i < 5; i++)
    cout << "Count for " << i << ": " << counts[i] << endl;
}

void testExponential(mt19937_64 &g) {
  cout << "Testing exponential:" << endl;
  array<long double, 1000> sample;
  long double lambda;
  cout << "Enter λ: ";
  cin >> lambda;
  Exponential exp(lambda);
  for(int i = 0; i < 1000; i++)
    sample[i] = exp(g);
  output_xbar_s2(sample);
  cout << "(Expected: μ = " << (1 / lambda)
       << ", σ² = " << (1 / lambda / lambda)
       << ")" << endl;
}

