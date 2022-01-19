#include <iostream>
#include "BlackScholesMCPricer.h"

BlackScholesMCPricer::BlackScholesMCPricer() {}

BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility) : BlackScholesPricer(initial_price, interest_rate, volatility)
{
	this->initial_price = initial_price;
	this->interest_rate = interest_rate;
	this->volatility = volatility;
}

double BlackScholesMCPricer::generate(int nb_paths)
{
	this->nbPaths = nb_paths;
	return 0.0;
}

std::vector<double> BlackScholesMCPricer::confidenceInterval()
{
	double price = this->optionPrice;

	std::vector<double> a{ price - 1.96 * this->sigma,price + 1.96 * this->sigma };
	return a;
}

double BlackScholesMCPricer::getNbPaths()
{
	double x = 0;
	return x;
}

