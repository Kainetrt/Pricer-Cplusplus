#include "DigitalPutOption.h"
#include <iostream>
#include <ctime>
#include <string>

double DigitalPutOption::payoff(double z)
{
	double K = DigitalPutOption::GetStrike();
	double rep = 0.0;
	if (z <= K)
	{
		rep = 1;
	}
	return rep;
}

double DigitalPutOption::payoff()
{
	double K = DigitalPutOption::GetStrike();
	double rep = 0.0;
	return rep;
}

DigitalPutOption::DigitalPutOption(double strike, double expiry) : Option(strike, expiry)
{
	this->_strike = strike;
	this->expiry = expiry;
	this->type = OptionType::DigitalPut;
}

DigitalPutOption::DigitalPutOption() : Option()
{
	type = Option::OptionType::DigitalPut;
}

Option::OptionType DigitalPutOption::GetOptionType()
{
	this->type = Option::OptionType::DigitalPut;
	return this->type;
}

double DigitalPutOption::GetStrike()
{
	return this->_strike;
}

double DigitalPutOption::GetExpiry()
{
	return this->expiry;
}
