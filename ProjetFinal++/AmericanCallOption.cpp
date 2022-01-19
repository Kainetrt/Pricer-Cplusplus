#include <iostream>
#include"AmericanCallOption.h"


AmericanCallOption::AmericanCallOption()
{
	this->type = OptionType::AmericanCall;
}

AmericanCallOption::AmericanCallOption(double s) : AmericanOption(strike)
{
	this->type = OptionType::AmericanCall;
	this->strike = s;
}
AmericanCallOption::AmericanCallOption(double T, double K)
{
	this->type = OptionType::AmericanCall;
	this->strike = K;
}


double AmericanCallOption::payoff(double z)
{
	this->type = OptionType::AmericanCall;
	double K = this->strike;
	double rep = 0.0;;
	if (z >= K)
	{
		rep = z - K;
	}
	return rep;
}