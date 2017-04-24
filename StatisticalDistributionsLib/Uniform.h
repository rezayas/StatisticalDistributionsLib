#pragma once
#include "StatisticalDistribution.h"

namespace StatisticalDistributions
{
	class Uniform : public StatisticalDistribution
	{
	public:
		Uniform(double min, double max);
		double pdf(double value);
		double cdf(double value);
		double Sample(RNG &rng);
	private:
		double min_;
		double max_;
	};
}