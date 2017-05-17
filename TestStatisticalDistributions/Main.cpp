#include "RNG.h"
#include "Uniform.h"

using namespace StatisticalDistributions;

int main()
{
	RNG myRNG(1);
	double myRNGSample[4];
	for (int i = 0; i< 4; ++i)
		myRNGSample[i] = myRNG.RND01();

	Uniform myUniform(0, 10);

	double unifSamples[10];
	for (int i = 0; i< 10; ++i)
		unifSamples[i] = myUniform.Sample(myRNG);
}