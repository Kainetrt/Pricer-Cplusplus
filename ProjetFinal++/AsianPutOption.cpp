#include <vector>
#include <iostream>
#include "AsianPutOption.h"
using namespace std;

AsianPutOption::AsianPutOption()
{
	this->type = OptionType::AsianPut;
	this->strike = 0.0;
}

AsianPutOption::AsianPutOption(std::vector<double> v, double s) : AsianOption(v)
{
	this->type = OptionType::AsianPut;
	this->strike = s;
}

double AsianPutOption::payoff(double z)
{
	this->type = OptionType::AsianPut;
	double K = this->strike;
	double rep = 0.0;
	if (K >= z)
	{
		rep = K - z;
	}
	return rep;
}