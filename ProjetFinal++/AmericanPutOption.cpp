#include <iostream>
#include"AmericanPutOption.h"

AmericanPutOption::AmericanPutOption()
{
	this->type = OptionType::AmericanPut;
}

AmericanPutOption::AmericanPutOption(double s)
{
	this->type = OptionType::AmericanPut;
	this->strike = s;
}

AmericanPutOption::AmericanPutOption(double T, double K)
{
	this->type = OptionType::AmericanPut;
	this->strike = K;
}

double AmericanPutOption::payoff()
{
	this->type = OptionType::AmericanPut;
	double x = 0.0;
	return x;
}