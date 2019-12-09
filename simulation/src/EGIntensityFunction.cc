#include "EGIntensityFunction.h"

#include <cmath>

EGIntensityFunction::EGIntensityFunction(double I0, double k) :
    I0(I0), k(k)
{
}

double EGIntensityFunction::compute(double x) const
{
    return compute(x, I0, k);
}

double EGIntensityFunction::compute(double R, double I0, double k)
{
    return I0 * exp(-k * pow(R, 0.25));
}

