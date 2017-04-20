#include "Uniform.h"

namespace StatisticalDistributions
{
	Uniform::Uniform(double min, double max)
	{
		min_ = min;
		max_ = max;
	}

	double Uniform::Sample(RNG &rng)
	{
		return min_ + max_ * rng.RND01();
	}
	double Uniform::pdf(double value)
	{
		return 0;
	}
	double Uniform::cdf(double value)
	{
		return 0;
	}
}

