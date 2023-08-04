#include "SolveIntegral.h"
#include <iostream>
#include <cmath>

void SolveIntegral::initialize()
{
    std::cout << "Enter left: ";
    std::cin >> left;
    std::cout << "Enter right: ";
    std::cin >> right;
    std::cout << "Enter epsilon: ";
    std::cin >> epsilon;
    isInitialized = true;
}

double SolveIntegral::solveLeftRectangles(int& countOfIntervalsToReturn)
{
    double delta;
    double sum = 0;
    double lengthOfInterval = sqrt(epsilon);

    int countOfIntervals = (right - left) / lengthOfInterval;
    lengthOfInterval = (right - left) / countOfIntervals;
    double before = 0;
    double x = left;
    for (int i = 0; i < countOfIntervals; i++) {
        before += function(x) * lengthOfInterval;
        x += lengthOfInterval;
    }
    do {
        lengthOfInterval /= 2;
        int countOfIntervals = (right - left) / lengthOfInterval;
        sum = 0;
        double x = left;
        for (int i = 0; i < countOfIntervals; i++) {
            sum += function(x) * lengthOfInterval;
            x += lengthOfInterval;
        }
        delta = fabs(before - sum);
        before = sum;
        countOfIntervalsToReturn = countOfIntervals;
    } while (delta > epsilon);
    return sum;
}

double SolveIntegral::solveMiddleRectangles(int& countOfIntervalsToReturn)
{
    double delta;
    double sum = 0;
    double lengthOfInterval = sqrt(epsilon);

    int countOfIntervals = (right - left) / lengthOfInterval;
    lengthOfInterval = (right - left) / countOfIntervals;
    double before = 0;
    double x = left + lengthOfInterval / 2;;
    for (int i = 0; i < countOfIntervals; i++) {
        before += function(x) * lengthOfInterval;
        x += lengthOfInterval;
    }
    do {
        lengthOfInterval /= 2;
        int countOfIntervals = (right - left) / lengthOfInterval;
        sum = 0;
        double x = left + lengthOfInterval / 2;
        for (int i = 0; i < countOfIntervals; i++) {
            sum += function(x) * lengthOfInterval;
            x += lengthOfInterval;
        }
        delta = fabs(before - sum);
        before = sum;
        countOfIntervalsToReturn = countOfIntervals;
    } while (delta > epsilon);
    return sum;
}

double SolveIntegral::solveRightRectangles(int& countOfIntervalsToReturn)
{
    double delta;
    double sum = 0;
    double lengthOfInterval = sqrt(epsilon);

    int countOfIntervals = (right - left) / lengthOfInterval;
    lengthOfInterval = (right - left) / countOfIntervals;
    double before = 0;
    double x = left + lengthOfInterval;
    for (int i = 0; i < countOfIntervals; i++) {
        before += function(x) * lengthOfInterval;
        x += lengthOfInterval;
    }
    do {
        lengthOfInterval /= 2;
        int countOfIntervals = (right - left) / lengthOfInterval;
        sum = 0;
        double x = left + lengthOfInterval;
        for (int i = 0; i < countOfIntervals; i++) {
            sum += function(x) * lengthOfInterval;
            x += lengthOfInterval;
        }
        delta = fabs(before - sum);
        before = sum;
        countOfIntervalsToReturn = countOfIntervals;
    } while (delta > epsilon);
    return sum;
}

double SolveIntegral::solveTrapezoids(int& countOfIntervalsToReturn)
{
    double delta, after;
    double sum = 0;
    double lengthOfInterval = sqrt(epsilon);

    int countOfIntervals = (right - left) / lengthOfInterval;
    lengthOfInterval = (right - left) / countOfIntervals;
    double before = 0;
    double x = left + lengthOfInterval;
    for (int i = 1; i <= countOfIntervals - 1; i++) {
        before += function(x);
        x += lengthOfInterval;
    }
    before = lengthOfInterval * (((function(left) + function(right)) / 2) + sum);
    do {
        lengthOfInterval /= 2;
        int countOfIntervals = (right - left) / lengthOfInterval;
        sum = 0;
        double x = left + lengthOfInterval;
        for (int i = 1; i < countOfIntervals; i++) {
            sum += function(x);
            x += lengthOfInterval;
        }
        after = lengthOfInterval * (((function(left) + function(right)) / 2) + sum);
        delta = fabs(before - after);
        before = after;
        countOfIntervalsToReturn = countOfIntervals;
    } while (delta > epsilon);
    return after;
}

double SolveIntegral::solveSimpson(int& countOfIntervalsToReturn)
{
    double delta;
    double sum = 0;
    double lengthOfInterval = sqrt(epsilon);

    int countOfIntervals = (right - left) / lengthOfInterval;
    lengthOfInterval = (right - left) / countOfIntervals;
    if (countOfIntervals % 2 == 1) {
        countOfIntervals++;
    }
    lengthOfInterval = (right - left) / countOfIntervals;
    double before = 0;
    double x = left;
    for (int i = 0; i < countOfIntervals; i += 2) {
        before += (lengthOfInterval / 3) * (function(x) + 4 * function(x + lengthOfInterval) + function(x + 2 * lengthOfInterval));
        x += 2 * lengthOfInterval;
    }
    do {
        lengthOfInterval /= 2;
        int countOfIntervals = (right - left) / lengthOfInterval;
        if (countOfIntervals % 2 == 1) {
            countOfIntervals++;
        }
        lengthOfInterval = (right - left) / countOfIntervals;
        sum = 0;
        double x = left;
        for (int i = 0; i < countOfIntervals; i += 2) {
            sum += (lengthOfInterval / 3) * (function(x) + 4 * function(x + lengthOfInterval) + function(x + 2 * lengthOfInterval));
            x += 2 * lengthOfInterval;
        }
        delta = fabs(before - sum);
        before = sum;
        countOfIntervalsToReturn = countOfIntervals;
    } while (delta > epsilon);
    return sum;
}
