#include "MyEquation.h"
#include <iostream>

int main(void) {
	MyEquation thisequation;
	int count = 0;
	thisequation.initialize();
	std::cout << "Integral function: ";
	thisequation.showFunc();
	std::cout << '\n';
	std::cout << "Left rectangles method: Integral = " << thisequation.solveLeftRectangles(count) << ", Count of intervals: " << count << '\n';
	std::cout << "Right rectangles method: Integral = " << thisequation.solveRightRectangles(count) << ", Count of intervals: " << count << '\n';
	std::cout << "Middle rectangles method: Integral = " << thisequation.solveMiddleRectangles(count) << ", Count of intervals: " << count << '\n';
	std::cout << "Trapezoids method: Integral = " << thisequation.solveTrapezoids(count) << ", Count of intervals: " << count << '\n';
	std::cout << "Simpson method: Integral = " << thisequation.solveSimpson(count) << ", Count of intervals: " << count << '\n';
}