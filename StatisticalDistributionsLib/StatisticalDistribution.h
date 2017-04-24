#pragma once
#include "RNG.h"
#include <math.h>

namespace StatisticalDistributions
{
	class StatisticalDistribution
	{
	public:
		StatisticalDistribution() {};
		virtual double pdf(double value)
		{
			return 0;
		}
		virtual double cdf(double value)
		{
			return 0;
		}
		virtual double Inverse(double value)
		{
			return 0;
		}
		virtual double Sample(RNG rng) 
		{
			return 0;
		}

	private:

	};
}