#include "Exponential.h"

namespace StatisticalDistributions
{
	Exponential::Exponential(double rate)
	{
		rate_ = rate;
	}

	double Exponential::pdf(double value)
	{
		return rate_*exp(-rate_*value);
	}
	double Exponential::cdf(double value)
	{
		return 1- exp(-rate_*value);
	}
	double Exponential::Inverse(double value)
	{
		return -log(1 - value) / rate_;
	}
	double Exponential::Sample(RNG &rng)
	{
		return Inverse(rng.RND01());
	}
}