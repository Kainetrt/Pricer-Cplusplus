#pragma once
#include <iostream>
#include <ctime>
#include "VanillaOption.h"
#include <string>

class CallOption : public VanillaOption
{
public:
	double payoff(double);
	CallOption();
	CallOption(double strike, double expiry);
	OptionType GetOptionType();

private:
	OptionType type;
};