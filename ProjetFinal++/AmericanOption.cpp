#include <iostream>
#include"AmericanOption.h"
using namespace std;


AmericanOption::AmericanOption()
{

}

AmericanOption::AmericanOption(double s)
{
	this->strike = s;
}

bool AmericanOption::isAmericanOption() { return true; }