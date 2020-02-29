#include "SpiralGalaxy.h"

#include <cmath>
#include <ctime>

#include "SGIterator.h"
#include "SGStar.h"

#include "SGVerticalDistributor.h"
#include "SGDiskRadiusDistributor.h"
#include "MersenneTwisterGenerator.h"

#define rnd() ((double)rand() / RAND_MAX)

SpiralGalaxy::SpiralGalaxy(
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
    starsQty(starsQty),

    stars(new SGStarDescriptor[starsQty]),
    stars_(new SGStar[starsQty])
{
    initStars();
}

SpiralGalaxy::~SpiralGalaxy()
{
    delete[] stars;
    delete[] stars_;
}

void SpiralGalaxy::initStars()
{
    SGDiskRadiusDistributor rd(1, radiusCore / 3, radiusDisk / 3,
                               radiusCore, 0,
                               radiusDisk + (radiusDisk - radiusCore), 1000);
    rd.setup();
    MersenneTwisterGenerator gen(time(NULL));

    for (size_t i = 0; i < starsQty; i++)
    {
        stars[i].a = rd(gen);
        stars[i].b = sqrt(stars[i].a *
                     stars[i].a *
                     (1 - pow(getEccentricity(stars[i].a), 2)));

        stars[i].angularOffset = getAngularOffset(stars[i].a);

        stars[i].azimuth = 2 * M_PI * ((double)gen() / gen.max());
        stars[i].zenith = 0;
        //stars[i].azimuth = 2 * M_PI * (double)rand() / RAND_MAX;

        stars[i].brightness = 0.2 + 0.8 * rnd();
        stars[i].brightness = 0.6 * exp(-stars[i].a / radiusDisk * 3) +
                              0.1 + 0.3 * rnd();
    }
}

double SpiralGalaxy::getEccentricity(double radius)
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

double SpiralGalaxy::getAngularOffset(double radius)
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
        return getAngularOffset(radiusCore) + (radius - radiusCore) /
                                              (radiusDisk - radiusCore) *
                                              M_PI;
    }
    else if (radiusDisk < radius && radius <= 2 * radiusDisk)
    {
        return getAngularOffset(radiusDisk) + (radius - radiusDisk) /
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
        return stars_ + idx;
    }
    else
    {
        return nullptr;
    }
}

