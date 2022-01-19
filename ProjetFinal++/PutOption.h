#pragma once
#include <iostream>
#include <ctime>
#include "VanillaOption.h"
#include <string>

class PutOption : public VanillaOption
{
public:
	double payoff(double);
	PutOption();
	PutOption(double strike, double expiry);
	OptionType GetOptionType();

private:
	OptionType type;
};
