#include <iostream>
#include <string>
using namespace std;
#include "DigitalOption.h"

DigitalOption::DigitalOption() : _strike(0.0), Option() {}

DigitalOption::DigitalOption(double strike, double expiry) : _strike(strike), Option(expiry)
{
	if (strike < 0)
	{
		this->_strike = 0.0;
	}
	if (expiry < 0) { this->expiry = 0.0; }
}


double DigitalOption::payoff()
{
	return Option::payoff();
}

double DigitalOption::payoff(double x)
{
	return Option::payoff(x);
}

double DigitalOption::GetStrike()
{
	return _strike;
}

double DigitalOption::GetExpiry()
{
	return expiry;
}