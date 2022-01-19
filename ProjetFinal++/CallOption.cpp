#include <iostream>
#include <ctime>
#include "CallOption.h"
#include <string>

double CallOption::payoff(double z)
{
	double K = VanillaOption::GetStrike();
	double rep = 0.0;;
	if (z >= K)
	{
		rep = z - K;
	}
	return rep;
}
CallOption::CallOption() : VanillaOption() { type = OptionType::Call; };

CallOption::CallOption(double strike, double expiry) : VanillaOption(strike, expiry)
{
	this->type = OptionType::Call;
}


Option::OptionType CallOption::GetOptionType()
{
	return Option::OptionType::Call;
}
