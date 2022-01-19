#include <iostream>
#include <ctime>
#include "PutOption.h"
#include <string>

PutOption::PutOption() : VanillaOption() { type = OptionType::Put; }

PutOption::PutOption(double strike, double expiry) : VanillaOption(strike, expiry)
{
	this->type = OptionType::Put;
}


double PutOption::payoff(double z)
{
	double K = VanillaOption::GetStrike();
	double rep = 0.0;
	if (K >= z)
	{
		rep = K - z;
	}
	return rep;
}


Option::OptionType PutOption::GetOptionType()
{
	return Option::OptionType::Put;
}
