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
	array<long double, 4> sample;
	for (int i = 0; i< 4; ++i)
	  sample[i] = myRNG.RND01();

	long double mean =
	  accumulate(sample.begin(), sample.end(), 0.0) / 4;
	long double acc = 0;
	for(int i = 0; i < 4; i++)
	  acc += (sample[i] - mean) * (sample[i] - mean);
	long double stdev = sqrt(acc / 3);
	cout << "mean: " << mean << " stdev: " << stdev << endl;
	
	Uniform myUniform(0, 10);

	array<long double, 10> uSamples;
	for (int i = 0; i< 10; ++i)
		uSamples[i] = myUniform.Sample(myRNG);

	mean = accumulate(uSamples.begin(), uSamples.end(), 0.0) / 10;
	acc = 0;
	for(int i = 0; i < 10; i++)
	  acc += (uSamples[i] - mean) * (uSamples[i] - mean);
	stdev = sqrt(acc / 9);
	
	cout << "mean: " << mean << " stdev: " << stdev << endl;

}
