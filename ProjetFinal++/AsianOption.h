#pragma once
#include "Option.h"
#include <vector>
#include <iostream>
using namespace std;

class AsianOption : public Option
{
public:
	AsianOption();
	double payoffPath(std::vector<double>&);
	AsianOption(std::vector<double>);
	std::vector<double> getTimeSteps();
	bool isAsianOption();

private:
	std::vector<double> vect;

};