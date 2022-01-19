#include <vector>
#include <iostream>
#include "AsianCallOption.h"
using namespace std;

AsianCallOption::AsianCallOption()
{
	this->type = OptionType::AsianCall;
	this->strike = 0;
}

AsianCallOption::AsianCallOption(std::vector<double> v, double s) : AsianOption(v)
{
	this->type = OptionType::AsianCall;
	this->strike = s;
}

double AsianCallOption::payoff(double z)
{
	this->type = OptionType::AsianCall;
	double K = this->strike;
	double rep = 0.0;;
	if (z >= K)
	{
		rep = z - K;
	}
	return rep;
}