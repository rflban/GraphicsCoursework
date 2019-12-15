#include "SGIntensityFunction.h"

#include "EGIntensityFunction.h"
#include "SGDiskIntensityFunction.h"

SGIntensityFunction::SGIntensityFunction(
        double I0,
        double RECore, double REDisk,
        double radiusCore
        ) :
    I0(I0),
    RECore(RECore), REDisk(REDisk),
    radiusCore(radiusCore)
{
}

double SGIntensityFunction::compute(double x) const
{
    return compute(x, I0, RECore, REDisk, radiusCore);
}

double SGIntensityFunction::compute(
        double R, double I0,
        double RECore, double REDisk,
        double radiusCore
    )
{
    if (R < radiusCore)
    {
        return EGIntensityFunction::compute(R, I0, RECore);
    }
    else
    {
        return SGDiskIntensityFunction::compute(
            R - radiusCore,
            EGIntensityFunction::compute(R, I0, RECore),
            REDisk
        );
    }
}

