#pragma once
#include "VanillaOption.h"
#include "Option.h"
#include "PutOption.h"
#include "CallOption.h"
#include "DigitalOption.h"
#include "DigitalCallOption.h"
#include "DigitalPutOption.h"
#include <vector>
#include <cmath>

class BlackScholesPricer
{
public:
	BlackScholesPricer(Option*, double, double, double);
	BlackScholesPricer(DigitalOption*, double, double, double);
	BlackScholesPricer();
	BlackScholesPricer(double, double, double);
	double operator()();
	double delta();
	double optionPrice; //Price of the option
	double sigma; //Volatility
private:
	PutOption put_option;
	CallOption call_option;
	Option::OptionType optionType; //Call or Put
	DigitalPutOption digital_put;
	DigitalCallOption digital_call;
	double K; //Strike price
	double T; //Maturity
	double S; //Underlying price
	double r; //Interest rate
	double delt; //Delta of the option
	double computePriceCall(double);
	double computePricePut(double);
	double computeDelta(double, double);
};

