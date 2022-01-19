#include "CRRPricer.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include "CRRPricer.h"

CRRPricer::CRRPricer()
{
	BinaryTree<double> x;
	x.setDepth(0);
	this->tree = x;

	this->option = 0;
	this->asset_price = 0; //S0, beginning price
	this->interest_rate = 0; //Interest rate: R
	this->up = 0; //U, up value
	this->down = 0; // D, down value
	this->depth = 0; // number of steps in the binomial tree
	this->closed_form = false;
}

CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate)
{

	{
		if ((up > interest_rate) && (down < interest_rate) && (down > -1) && (asset_price > 0))
		{
			BinaryTree<double> x;
			x.setDepth(0);
			this->tree = x;

			this->option = option;
			this->asset_price = asset_price; //S0, beginning price
			this->interest_rate = interest_rate; //Interest rate: R
			this->up = up; //U, up value
			this->down = down; // D, down value
			this->depth = depth; // number of steps in the binomial tree
			this->closed_form = false;
		}
		else
		{
			BinaryTree<double> x;
			x.setDepth(0);
			this->tree = x;

			this->option = 0;
			this->asset_price = 0; //S0, beginning price
			this->interest_rate = 0; //Interest rate: R
			this->up = 0; //U, up value
			this->down = 0; // D, down value
			this->depth = 0; // number of steps in the binomial tree
			this->closed_form = false;
		}
	}
}



CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double interest_rate, double volatility)
{
	this->option = option;
	this->depth = depth;
	this->asset_price = asset_price;
	this->interest_rate = interest_rate;
	double T = option->Option::GetExpiry();
	double h = T / depth;
	BinaryTree<double> x;
	x.setDepth(depth);
	this->tree = x;
	this->up = exp((interest_rate + (pow(volatility, 2) / 2)) * (h + (volatility * sqrt(h)))) - 1;
	this->down = exp((interest_rate + (pow(volatility, 2) / 2)) * (h - (volatility * sqrt(h)))) - 1;
	this->interest_rate = exp(interest_rate * h) - 1;
}

CRRPricer::CRRPricer(Option* option, double asset_price, double interest_rate, double volatility)
{
	this->option = option;
	this->depth = 1;
	this->asset_price = asset_price;
	this->interest_rate = interest_rate;
	double T = option->Option::GetExpiry();
	double h = T / depth;
	BinaryTree<double> x;
	x.setDepth(depth);
	this->tree = x;
	this->up = exp((interest_rate + (pow(volatility, 2) / 2)) * (h + (volatility * sqrt(h)))) - 1;
	this->down = exp((interest_rate + (pow(volatility, 2) / 2)) * (h - (volatility * sqrt(h)))) - 1;
	this->interest_rate = exp(interest_rate * h) - 1;
}


void CRRPricer::compute()
{
	double q;
	q = (this->interest_rate - this->down) / (this->up - this->down);


	if (this->closed_form = false)
	{
		for (int n = 0; n < this->tree._depth; n++)
		{
			for (int i = 0; i < this->tree._depth; i++)
			{
				double Sn1i1;
				double Sn1i0;
				Sn1i1 = h(n + 1, i + 1);
				Sn1i0 = h(n + 1, i + 1);
				this->tree.setNode(n, i, (q * Sn1i1 + (1 - q) * Sn1i0) / (1 + this->interest_rate));
			}
		}
	}
	else
	{
		double somme = 0.0;
		for (int i = 0; i < this->tree._depth; i++)
		{
			if ((factorial(i) * factorial(this->tree._depth - i)) != 0)
			{
				somme = somme + (factorial(this->tree._depth) / (factorial(i) * factorial(this->tree._depth - i))) * pow(q, i) * pow(1 - q, this->tree._depth - i) * h(this->tree._depth, i);
			}
		}
		this->tree.setNode(0, 0, 1 / pow(1 + this->interest_rate, this->tree._depth));
	}

}

double CRRPricer::get(int n, int i)
{
	return this->tree.getNode(n, i);
}

int CRRPricer::factorial(int n)
{
	int ret = 1;
	while (n > 1)
		ret *= n--;
	return ret;
}

double CRRPricer::h(int n, int i)
{
	return this->asset_price * pow(1 + this->up, i) * pow(1 + this->down, n - i);
}

bool CRRPricer::getExercise(int a, int b)
{
	return true;
}

double CRRPricer::operator()(bool closed_form)
{
	this->closed_form = closed_form;
	compute();
	return get(0, 0);
}