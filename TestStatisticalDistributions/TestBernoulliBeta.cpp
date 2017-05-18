#include "Bernoulli.h"
#include "Beta.h"
#include <iostream>
#include <array>
#include <numeric>

using namespace StatisticalDistributions;
using namespace std;

int main()
{
  RNG myRNG(2135342612);
  array<long double, 1000> sample;
  int heads = 0;
  Bernoulli bern(.6);
  cout << "Testing Bernoulli:" << endl;
  for(int i = 0; i < 1000; i++)
    if(bern(myRNG.mt_))
      heads++;
  cout << "Heads obtained: " << heads << "; Expected: 600" << endl;
  cout << "Enter α: ";
  long double alpha, beta;
  cin >> alpha;
  cout << "Enter β: ";
  cin >> beta;
  Beta bet(alpha, beta);
  for(int i = 0; i < 1000; i++)
    sample[i] = bet.Sample(myRNG);
  long double mean =
    accumulate(sample.begin(), sample.end(), 0.0) / 1000;
  long double acc = 0;
  for(int i = 0; i < 1000; i++)
	  acc += (sample[i] - mean) * (sample[i] - mean);
  long double variance = acc / 999;
  cout << "mean: " << mean << "; variance: " << variance << endl;
  cout << "(Expected: μ = " << alpha / (alpha + beta) << ", σ² = "
       << alpha * beta / (alpha + beta) / (alpha + beta) / (alpha + beta + 1)
       << ")" << endl;
}
