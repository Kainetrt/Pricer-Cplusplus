#pragma once
#include <vector>
#include<iostream>
using namespace std;
#include "AsianOption.h"

class AsianPutOption : public AsianOption
{
public:
	AsianPutOption();
	AsianPutOption(std::vector<double>, double);
	double payoff(double);


private:
	double strike;
};