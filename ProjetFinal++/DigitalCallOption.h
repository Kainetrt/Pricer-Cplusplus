#pragma once
#include <string>
#include <iostream>
#include "Option.h"

class DigitalCallOption : public Option
{
public:
	DigitalCallOption();
	DigitalCallOption(double strike, double expiry);
	double payoff();
	double payoff(double);
	double GetStrike();
	double GetExpiry();
	Option::OptionType GetOptionType();

private:
	OptionType type;
	double _strike;
	double expiry;
};