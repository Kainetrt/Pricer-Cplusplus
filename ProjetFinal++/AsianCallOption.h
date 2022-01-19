#pragma once
#include <vector>
#include<iostream>
using namespace std;
#include "AsianOption.h"

class AsianCallOption : public AsianOption
{
public:
	AsianCallOption();
	AsianCallOption(std::vector<double>, double);
	double payoff(double);

private:
	double strike;
	std::vector<double> vect;
};
