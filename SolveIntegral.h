#pragma once
class SolveIntegral
{
protected:
	double left, right;
	double epsilon;
	bool isInitialized = false;

	virtual double function(double x) = 0;
public:
	void initialize();
	virtual void showFunc() = 0;
	double solveLeftRectangles(int& countOfIntervalsToReturn);
	double solveMiddleRectangles(int& countOfIntervalsToReturn);
	double solveRightRectangles(int& countOfIntervalsToReturn);
	double solveTrapezoids(int& countOfIntervalsToReturn);
	double solveSimpson(int& countOfIntervalsToReturn);
};

