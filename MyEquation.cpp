#include "MyEquation.h"
#include <iostream>

double MyEquation::function(double x)
{
	return /*sinh(x) / (1 - 2 * x + 3 * x * x)*/x * x + 2 * x + 1;
}

void MyEquation::showFunc()
{
    std::cout << "y = sh(x)/(1-2x+3x^2)";
}
