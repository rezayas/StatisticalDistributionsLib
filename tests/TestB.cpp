#include "Bernoulli.h"
#include "Beta.h"
#include "BetaBinomial.h"
#include "Binomial.h"
#include <iostream>
#include <array>
#include <numeric>
#include "sbar.h"

using namespace StatisticalDistributions;
using namespace std;

void testBernoulli(mt19937_64 &g) {
  int heads = 0;
  Bernoulli bern(.6);
  cout << "Testing Bernoulli:" << endl;
  for(int i = 0; i < 1000; i++)
    if(bern(g))
      heads++;
  cout << "Heads obtained: " << heads << "; Expected: 600" << endl;
}
void testBeta(mt19937_64 &g) {
  cout << "Testing beta: " << endl;
  array<long double, 1000> sample;
  cout << "Enter α: ";
  long double alpha, beta;
  cin >> alpha;
  cout << "Enter β: ";
  cin >> beta;
  Beta bet(alpha, beta);
  for(int i = 0; i < 1000; i++)
    sample[i] = bet(g);
  output_xbar_s2(sample);
  cout << "(Expected: μ = " << (alpha / (alpha + beta)) << ", σ² = "
       << (alpha * beta / (alpha + beta) / (alpha + beta) / (alpha + beta + 1))
       << ")" << endl;
}

void testBetaBinomial(mt19937_64 &g) {
  cout << "Testing beta-binomial:" << endl;
  array<long, 1000> sample;
  long n;
  cout << "Enter α: ";
  long double alpha, beta;
  cin >> alpha;
  cout << "Enter β: ";
  cin >> beta;
  cout << "Enter n: ";
  cin >> n;
  BetaBinomial betbin(n, alpha, beta);
  for(int i = 0; i < 1000; i++)
    sample[i] = betbin(g);
  output_xbar_s2(sample);
  cout << "(Expected: μ = " << (alpha / (alpha + beta) * n) << ", σ² = "
       << (n * alpha * beta * (alpha + beta + n)
	   / (alpha + beta) / (alpha + beta) / (alpha + beta + 1))
       << ")" << endl;
}

void testBinomial(mt19937_64 &g) {
  cout << "Testing binomial:" << endl;
  array<long, 1000> sample;
  long n;
  long double p;
  cout << "Enter p: ";
	  
  cin >> p;
  cout << "Enter n: ";
  cin >> n;
  Binomial bin(n, p);
  for(int i = 0; i < 1000; i++)
    sample[i] = bin(g);
  output_xbar_s2(sample);
  cout << "(Expected: μ = " << (n * p)
       << ", σ² = " << (n * p * (1-p))
       << ")" << endl;
}
