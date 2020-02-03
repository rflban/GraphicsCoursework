#include "EGIntensityFunction.h"

#include <cmath>

#include "GalaxyProperties.h"

EGIntensityFunction::EGIntensityFunction(double I0, double RE) :
    I0(I0), RE(RE)
{
}

double EGIntensityFunction::compute(double x) const
{
    return compute(x, I0, RE);
}

double EGIntensityFunction::compute(double R, double I0, double RE)
{
    return I0 * exp(-0.02 * pow(R, 0.25));
    return I0 * exp(-2e-12 * pow(R, 0.25));
}

