#include "SpiralGalaxy.h"

#include <cmath>
#include <ctime>

#include "SGIterator.h"
#include "SGStar.h"

#include "SGVerticalDistributor.h"
#include "SGDiskRadiusDistributor.h"
#include "MersenneTwisterGenerator.h"
#include "SGStarInitializer.h"

SpiralGalaxy::SpiralGalaxy(
            const Vector3D &pos,
            double radiusCore,
            double radiusDisk,
            double ecctyInnerst,
            double ecctyOuterst,
            size_t starsQty,
            Perturbation pert
        ) :
    pos(pos),
    radiusCore(radiusCore),
    radiusDisk(radiusDisk),
    ecctyInnerst(ecctyInnerst),
    ecctyOuterst(ecctyOuterst),
    starsQty(starsQty),
    pert(pert),

    stars(new SGStar[starsQty])
{
    initStars();
}

SpiralGalaxy::~SpiralGalaxy()
{
    delete[] stars;
}

void SpiralGalaxy::initStars()
{
    SGStarInitializer starInitializer(this);
    starInitializer.setup();

    for (size_t i = 0; i < starsQty; i++)
    {
        starInitializer(stars[i]);
    }
}

double SpiralGalaxy::getEccentricity(double radius) const
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
        return ecctyInnerst + (ecctyOuterst - ecctyInnerst) *
                              (radius - radiusCore) /
                              (radiusDisk - radiusCore);
    }
    else if(radiusDisk < radius && radius <= 2 * radiusDisk)
    {
        return ecctyOuterst - ecctyOuterst *
                              (radius - radiusDisk) /
                              radiusDisk;
    }
    else
    {
        return 0;
    }
}

double SpiralGalaxy::getRotationAngle(double radius) const
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
        return getRotationAngle(radiusCore) + (radius - radiusCore) /
                                              (radiusDisk - radiusCore) *
                                              M_PI;
    }
    else if (radiusDisk < radius && radius <= 2 * radiusDisk)
    {
        return getRotationAngle(radiusDisk) + (radius - radiusDisk) /
                                              radiusDisk * M_PI;
    }
    else
    {
        return 0;
    }
}

SpiralGalaxy::iterator SpiralGalaxy::begin()
{
    return iterator::begin(this);
}

SpiralGalaxy::iterator SpiralGalaxy::end()
{
    return iterator::end(this);
}

bool SpiralGalaxy::isExistingObject(ptrdiff_t idx) const
{
    return (0 <= idx) && ((size_t)idx < getStarsQty());
}

SGObject *SpiralGalaxy::getObject(ptrdiff_t idx)
{
    if (0 <= idx && (size_t)idx < getStarsQty())
    {
        return stars + idx;
    }
    else
    {
        return nullptr;
    }
}

