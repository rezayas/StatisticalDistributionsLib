#include "Uniform.h"

namespace StatisticalDistributions
{
	Uniform::Uniform(double min, double max)
	{
		min_ = min;
		max_ = max;
	}

	double Uniform::pdf(double value)
	{
		if (value< min_ || value > max_)
			return 0;
		else
			return 1/(max_-min_);
	}
	double Uniform::cdf(double value)
	{
		if (value < min_)
			return 0;
		else if (value > max_)
			return 1;
		else
			return (max_-value) / (max_ - min_);
	}
	double Uniform::Sample(RNG &rng)
	{
		return min_ + max_ * rng.RND01();
	}
}

