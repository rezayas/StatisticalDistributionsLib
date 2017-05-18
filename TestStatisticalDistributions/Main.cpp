#include "RNG.h"
#include "Uniform.h"
#include <iostream>
#include <array>
#include <numeric>

using namespace StatisticalDistributions;
using namespace std;

int main()
{

  
  RNG myRNG(2135342612);
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
  
}
