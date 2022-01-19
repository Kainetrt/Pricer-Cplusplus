#include "DigitalCallOption.h"
#include <iostream>
#include <ctime>
#include <string>

double DigitalCallOption::payoff(double z)
{
	double K = DigitalCallOption::GetStrike();
	double rep = 0.0;
	if (z >= K)
	{
		rep = 1;
	}
	return rep;
}

double DigitalCallOption::payoff()
{
	double rep = 0.0;
	return rep;
}

DigitalCallOption::DigitalCallOption(double strike, double expiry) : Option(strike, expiry)
{
	this->_strike = strike;
	this->expiry = expiry;
	this->type = OptionType::DigitalCall;
}

DigitalCallOption::DigitalCallOption() : Option()
{
	type = Option::OptionType::DigitalCall;
}

Option::OptionType DigitalCallOption::GetOptionType()
{
	this->type = OptionType::DigitalCall;
	return Option::OptionType::DigitalCall;
}

double DigitalCallOption::GetStrike()
{
	return this->_strike;
}

double DigitalCallOption::GetExpiry()
{
	return this->expiry;
}