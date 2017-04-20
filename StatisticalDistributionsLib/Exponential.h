#pragma once
#include "Distribution.h"

namespace StatisticalDistributions
{
	class Exponential : public Distribution
	{
	public:
		Exponential(double rate);
		double pdf(double value);
		double cdf(double value);
		double Inverse(double value);
		double Sample(RNG &rng);
	private:
		double rate_;
	};
}