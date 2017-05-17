#include "RNG.h"
#include "Uniform.h"
#include <iostream>
#include <array>
#include <numeric>

using namespace StatisticalDistributions;
using namespace std;

int main()
{
	RNG myRNG(1);
	array<long double, 4> sample;
	for (int i = 0; i< 4; ++i)
	  sample[i] = myRNG.RND01();

	double sum = std::accumulate(sample.begin(), sample.end(), 0.0);
	double mean = sum / sample.size();
	
	double sq_sum = std::inner_product(sample.begin(), sample.end(),
					   sample.begin(), 0.0);
	double stdev = std::sqrt(sq_sum / sample.size() - mean * mean);

	
	cout << "mean: " << mean << " stdev: " << stdev << endl;
	
	Uniform myUniform(0, 10);

	array<long double, 10> uSamples;
	for (int i = 0; i< 10; ++i)
		uSamples[i] = myUniform.Sample(myRNG);

	
	sum = std::accumulate(uSamples.begin(), uSamples.end(), 0.0);
	mean = sum / uSamples.size();
	
	sq_sum = std::inner_product(uSamples.begin(), uSamples.end(),
					   uSamples.begin(), 0.0);
	stdev = std::sqrt(sq_sum / uSamples.size() - mean * mean);

	
	cout << "mean: " << mean << " stdev: " << stdev << endl;

}
