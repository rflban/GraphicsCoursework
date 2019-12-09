#include "SGDiskIntensityFunction.h"

#include <cmath>

SGDiskIntensityFunction::SGDiskIntensityFunction(double I0, double RD) :
    I0(I0), RD(RD)
{
}

double SGDiskIntensityFunction::compute(double x) const
{
    return compute(x, I0, RD);
}

double SGDiskIntensityFunction::compute(double R, double I0, double RD)
{
    return I0 * exp(-R / RD);
}

