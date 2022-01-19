#include <iostream>
#include <string>
using namespace std;
#include "VanillaOption.h"

VanillaOption::VanillaOption(double strike, double expiry) : _strike(strike), Option(expiry)
{
	if (strike < 0)
	{
		this->_strike = 0.0;
	}
	if (expiry < 0) { this->expiry = 0.0; }
}

VanillaOption::VanillaOption() : _strike(0.0), Option() {}

double VanillaOption::GetExpiry()
{
	return Option::GetExpiry();
}

//enum class OptionType { Call, Put };

double VanillaOption::GetStrike()
{
	return _strike;
}

double VanillaOption::payoff()
{
	return Option::payoff();
}
