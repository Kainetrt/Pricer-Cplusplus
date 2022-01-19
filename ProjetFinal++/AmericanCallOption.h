#pragma once
#include <iostream>
#include "AmericanOption.h"

class AmericanCallOption : public AmericanOption
{
public:
	AmericanCallOption();
	AmericanCallOption(double);
	double payoff(double);
	AmericanCallOption(double, double);

private:
	double strike;
};