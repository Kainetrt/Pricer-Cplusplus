#pragma once
#include <string>
#include <iostream>
#include "Option.h"

class VanillaOption : public Option
{
public:
	VanillaOption(double strike, double expiry);
	VanillaOption();
	double GetExpiry();
	double GetStrike();
	double payoff();
	//double payoff(double);


private:
	double _strike;
	double expiry;
};