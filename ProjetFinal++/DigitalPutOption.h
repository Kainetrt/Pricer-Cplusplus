#pragma once
#include <string>
#include <iostream>
#include "Option.h"

class DigitalPutOption : public Option
{
public:
	DigitalPutOption();
	DigitalPutOption(double strike, double expiry);
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
