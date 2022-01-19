#pragma once
using namespace std;
#include <string>
#include <iostream>
#include "Option.h"

class DigitalOption : public Option
{
public:
	DigitalOption();
	DigitalOption(double strike, double expiry);
	double payoff();
	double payoff(double);
	double GetStrike();
	double GetExpiry();

private:
	double _strike;
	double expiry;
};
