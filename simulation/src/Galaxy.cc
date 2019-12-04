#include "Galaxy.h"

#include <cmath>

Galaxy::Galaxy(
            const Vector3D &pos,
            double radiusCore,
            double radiusDisk,
            double ecctyInnerst,
            double ecctyOuterst,
            size_t starsQty
        ) :
    pos(pos),
    radiusCore(radiusCore),
    radiusDisk(radiusDisk),
    ecctyInnerst(ecctyInnerst),
    ecctyOuterst(ecctyOuterst),
    starsQty(starsQty)
{
}

Galaxy::~Galaxy()
{
}

double Galaxy::getEccentricity(double radius)
{
    if (radius <= 0)
    {
        return 0;
    }
    else if (radius <= radiusCore)
    {
        return 0 + ecctyInnerst * (radius / radiusCore);
    }
    else if (radiusCore < radius && radius <= radiusDisk)
    {
        return ecctyInnerst + (ecctyOuterst - ecctyInnerst) * (radius - radiusCore) / (radiusDisk - radiusCore);
    }
    else if(radiusDisk < radius && radius <= 2 * radiusDisk)
    {
        return ecctyOuterst - ecctyOuterst * (radius - radiusDisk) / radiusDisk;
    }
    else
    {
        return 0;
    }
}

double Galaxy::getAngularOffset(double radius)
{
    if (radius <= 0)
    {
        return 0;
    }
    else if (radius <= radiusCore)
    {
        return 0 + radius / radiusCore * M_PI;
    }
    else if (radiusCore < radius && radius <= radiusDisk)
    {
        return getAngularOffset(radiusCore) + (radius - radiusCore) / (radiusDisk - radiusCore) * M_PI;
    }
    else if (radiusDisk < radius && radius <= 2 * radiusDisk)
    {
        return getAngularOffset(radiusDisk) + (radius - radiusDisk) / radiusDisk * M_PI;
    }
    else
    {
        return 0;
    }
}

