#include "SGIntensityFunction.h"

#include "EGIntensityFunction.h"
#include "SGDiskIntensityFunction.h"

SGIntensityFunction::SGIntensityFunction(
        double I0, double k,
        double RD, double radiusCore
        ) :
    I0(I0), k(k),
    RD(RD), radiusCore(radiusCore)
{
}

double SGIntensityFunction::compute(double x) const
{
    return compute(x, I0, k, RD, radiusCore);
}

double SGIntensityFunction::compute(
        double R, double I0,
        double k, double RD,
        double radiusCore
    )
{
    if (R < radiusCore)
    {
        return EGIntensityFunction::compute(R, I0, k);
    }
    else
    {
        return SGDiskIntensityFunction::compute(
            R - radiusCore,
            EGIntensityFunction::compute(R, I0, k),
            RD
        );
    }
}

