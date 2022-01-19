#include <iostream>
#include <ctime>
#include "CallOption.h"
#include "Option.h"
#include <vector>

Option::Option()
{

};

Option::Option(double x)
{
	this->_expiry = x;
}

Option::Option(double x, double strike)
{
	this->_expiry = x;
	this->strike = strike;
}

double Option::payoff()
{
	return 0.0;
}

double Option::payoff(double x)
{
	return x;
}

double Option::getStrike() 
{
	return this->strike;
}

double Option::GetExpiry()
{
	return _expiry;
}

double Option::payoffPath(std::vector<double> v)
{
	int m = v.size();
	return Option::payoff(v[m]);
}

bool Option::isAsianOption()
{
	return (this->type == OptionType::AsianCall) || (this->type == OptionType::AsianPut);
}

Option::OptionType Option::GetOptionType()
{
	Option::OptionType x = this->type;
	return x;
}

bool Option::isAmericanOption()
{
	return (this->type == OptionType::AmericanCall) || (this->type == OptionType::AmericanPut);
}


