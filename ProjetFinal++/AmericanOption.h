#pragma once
#include "Option.h"
#include <iostream>
using namespace std;

class AmericanOption : public Option
{
public:
	AmericanOption();
	AmericanOption(double);
	bool isAmericanOption();

private:
	double strike;
};