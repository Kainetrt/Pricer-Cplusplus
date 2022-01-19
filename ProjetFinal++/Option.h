#pragma once
#include <iostream>
#include <ctime>
using namespace std;
#include <string>
#include <vector>

template <class Type, class Allocator = allocator<Type>>
class vector;

class Option
{
public:
	enum class OptionType
	{
		Call,
		Put,
		DigitalCall,
		DigitalPut,
		AmericanCall,
		AmericanPut,
		AsianCall,
		AsianPut
	};
	double payoff(double);
	double payoff();
	double GetExpiry();
	double getStrike();
	double payoffPath(std::vector<double>);
	bool isAsianOption();
	bool isAmericanOption();
	Option::OptionType GetOptionType();
	Option();
	Option(double);
	Option(double, double);
	Option::OptionType type;
private:
	double _expiry;
	double strike;
	time_t Expirency;
};