#pragma once
#include <iostream>
#include "AmericanOption.h"

class AmericanPutOption : public AmericanOption
{
public:
	AmericanPutOption();
	AmericanPutOption(double);
	AmericanPutOption(double, double);
	double payoff();

private:
	double strike;
};