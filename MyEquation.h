#pragma once
#include "SolveIntegral.h"
class MyEquation :
    public SolveIntegral
{
protected:
    virtual double function(double x) override;
public:
    virtual void showFunc() override;
};

