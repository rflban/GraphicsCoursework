#include "SGStarInitializer.h"

#include "SpiralGalaxy.h"
#include "SGStar.h"

#include "SGDiskRadiusDistributor.h"
#include "SGVerticalDistributor.h"

#include "Random.h"

#include <cmath>

SGStarInitializer::SGStarInitializer() :
    galaxy(nullptr),

    rdistributor(nullptr),
    vdistributor(nullptr),

    rnd(new MersenneTwisterGenerator)
{
}

SGStarInitializer::SGStarInitializer(const SpiralGalaxy *galaxy) :
    galaxy(galaxy),

    rdistributor(nullptr),
    vdistributor(nullptr),

    rnd(new MersenneTwisterGenerator)
{
}

SGStarInitializer::SGStarInitializer(const SpiralGalaxy &galaxy) :
    galaxy(&galaxy),

    rdistributor(nullptr),
    vdistributor(nullptr),

    rnd(new MersenneTwisterGenerator)
{
}

SGStarInitializer::~SGStarInitializer()
{
    reset();

    delete rnd;
}

bool SGStarInitializer::isReady()
{
    return !(galaxy && rdistributor && vdistributor);
}

SGStarInitializer::operator bool()
{
    return isReady();
}

void SGStarInitializer::setup()
{
    if (!isReady())
    {
        return; // exception is need
    }

    double rCore = galaxy->getRadiusCore();
    double rDisk = galaxy->getRadiusDisk();

    rdistributor = new SGDiskRadiusDistributor(
        1, rCore / 3, rDisk / 3, rCore, 0, rDisk + (rDisk - rCore), 1000
    );
    rdistributor->setup();
}

void SGStarInitializer::reset()
{
    if (galaxy)
        galaxy = nullptr;

    if (rdistributor)
    {
        delete rdistributor;
        rdistributor = nullptr;
    }
    if (vdistributor)
    {
        delete vdistributor;
        vdistributor = nullptr;
    }
}

void SGStarInitializer::operator()(SGStar &star)
{
    distibuteOnDisk(star);
}

void SGStarInitializer::distibuteOnDisk(SGStar &star)
{
    double radius = (*rdistributor)(*rnd);

    star.setA(radius);
    star.setB(sqrt((radius * radius) *
                   (1 - pow(galaxy->getEccentricity(radius), 2))));

    star.setRotationAngle(galaxy->getRotationAngle(radius));
    star.setAzimuth(2 * M_PI * ((double)(*rnd)() / rnd->max()));
}

