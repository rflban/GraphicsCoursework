#include "SimpsonsRuleIntegrator.h"

#include "ParametricFunction.h"

SimpsonsRuleIntegrator::SimpsonsRuleIntegrator(ParametricFunction *func) :
    Integrator(func)
{
}

double SimpsonsRuleIntegrator::integrate(double a, double b) const
{
    return integrate(func, a, b);
}

double SimpsonsRuleIntegrator::integrate(ParametricFunction *func, double a, double b)
{
    return 0;
}

