#include "AsianOption.h"
#include <vector>
#include <iostream>
using namespace std;

AsianOption::AsianOption()
{

}

AsianOption::AsianOption(std::vector<double> v)
{
	this->vect = v;
}

std::vector<double> AsianOption::getTimeSteps()
{
	return vect;
}

double AsianOption::payoffPath(std::vector<double>& v)
{
	int m = v.size();
	double sum = 0;
	for (int k = 0; k < m; k++)
	{
		sum = v[k];
	}
	sum /= m;
	double h = Option::payoff(sum);
	return h;
}

bool AsianOption::isAsianOption()
{
	return true;
}