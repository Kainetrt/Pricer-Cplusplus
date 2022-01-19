#include "BlackScholesPricer.h"
#include "Option.h"

#pragma region Normal distribution function

/*
* Note: erfc(z/sqrt(2))=P(-z<X<z)
* Z~N(0,1)
* =>P(X<z)=(1/2)(1+erfc(z/sqrt(2)))
*/

//Computing the distribution function using the error function
double normalDistribution(double x) {
	return (1 / 2)(1 + std::erfc(x / std::pow(2, 0.5)));
}

#pragma endregion

//Constructor

BlackScholesPricer::BlackScholesPricer() 
{

}

BlackScholesPricer::BlackScholesPricer(double asset_price, double interest_rate, double volatility) : S(asset_price), r(interest_rate), sigma(volatility)
{
}

BlackScholesPricer::BlackScholesPricer(Option* option, double asset_price, double interest_rate, double volatility) :
	S(asset_price), r(interest_rate), sigma(volatility)
{ //JSP
	this->optionType = option->GetOptionType();
	T = option->GetExpiry();
	K = option->getStrike();
	if (optionType == Option::OptionType::Call) {
		CallOption call_option = CallOption(T, K);
	}
	else {
		if (optionType == Option::OptionType::Put) {
			PutOption put_option = PutOption(T, K);
		}
	};
}

BlackScholesPricer::BlackScholesPricer(DigitalOption* option, double asset_price, double interest_rate, double volatility) :
	S(asset_price), r(interest_rate), sigma(volatility)
{ //JSP
	this->optionType = option->GetOptionType();
	T = option->GetExpiry();
	K = option->getStrike();
	if (this->optionType == Option::OptionType::DigitalCall) {
		this->call_option = CallOption(T, K);
	}
	else {
		if (this->optionType == Option::OptionType::DigitalPut) {
			this->put_option = PutOption(T, K);
		}
	};
}

#pragma region Computing the option price

//For a call
double BlackScholesPricer::computePriceCall(double deadline) {
	double d1 = std::log10(S / K) + (r + std::pow(sigma, 2) / 2) * deadline;
	d1 /= (sigma * std::pow(deadline, 0.5));
	double d2 = d1 - sigma * std::pow(deadline, 0.5);
	double C = normalDistribution(d1) * S - normalDistribution(d2) * K * std::exp(-r * deadline);
	return C;
}

//For a put
double BlackScholesPricer::computePricePut(double deadline) {
	double d1 = std::log10(S / K) + (r + std::pow(sigma, 2) / 2) * deadline;
	d1 /= (sigma * std::pow(deadline, 0.5));
	double d2 = d1 - sigma * std::pow(deadline, 0.5);
	double P = -normalDistribution(-d1) * S + normalDistribution(-d2) * K * std::exp(-r * deadline);
	return P;
}

#pragma endregion

#pragma region Computing the delta

double BlackScholesPricer::computeDelta(double deadline, double price) {
	double d1 = std::log10(S / K) + (r + std::pow(sigma, 2) / 2) * deadline;
	return std::exp(-price * deadline) * normalDistribution(d1);
}
#pragma endregion

double BlackScholesPricer::operator()() {
	if ((this->optionType == Option::OptionType::Call)||(this->optionType ==Option::OptionType::DigitalCall))
	{
		optionPrice = computePriceCall(T);
	}
	else if ((this->optionType == Option::OptionType::Put)||(this->optionType == Option::OptionType::DigitalPut))
	{
		optionPrice = computePricePut(T);
	}
	return optionPrice;
}

double BlackScholesPricer::delta() {
	double price = operator()(); //PAS SUR
	double d1 = std::log10(S / K) + (r + std::pow(sigma, 2) / 2) * T;
	delt = std::exp(-price * T) * normalDistribution(d1);
	return delt;
}
