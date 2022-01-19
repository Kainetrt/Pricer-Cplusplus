#pragma once
#include <iostream>
#include "BlackScholesPricer.h"

class BlackScholesMCPricer : public BlackScholesPricer
{
public:
	BlackScholesMCPricer();
	BlackScholesMCPricer(Option*, double, double, double);
	double getNbPaths();
	double generate(int);
	std::vector<double> confidenceInterval();

private:
	double nbPaths;
	double initial_price;
	double interest_rate;
	double volatility;
};