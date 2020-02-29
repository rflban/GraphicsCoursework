#include "SGStarInitializer.h"

#include "SpiralGalaxy.h"
#include "SGStar.h"

#include "SGDiskRadiusDistributor.h"
#include "NormalDistributor.h"

#include "Random.h"

#include <cmath>

SGStarInitializer::SGStarInitializer() :
    galaxy(nullptr),

    rdistributor(nullptr),
    ndistributor(nullptr),

    rnd(new MersenneTwisterGenerator)
{
}

SGStarInitializer::SGStarInitializer(const SpiralGalaxy *galaxy) :
    galaxy(galaxy),

    rdistributor(nullptr),
    ndistributor(nullptr),

    rnd(new MersenneTwisterGenerator)
{
}

SGStarInitializer::SGStarInitializer(const SpiralGalaxy &galaxy) :
    galaxy(&galaxy),

    rdistributor(nullptr),
    ndistributor(nullptr),

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
    return !(galaxy && rdistributor && ndistributor);
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
    double rMax = rDisk + (rDisk - rCore);

    rdistributor = new SGDiskRadiusDistributor(
        1, rCore / 3, rDisk / 3, rCore, 0, rMax, 1000
    );
    rdistributor->setup();

    ndistributor = new NormalDistributor(0, rCore / 3);
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
    if (ndistributor)
    {
        delete ndistributor;
        ndistributor = nullptr;
    }
}

void SGStarInitializer::operator()(SGStar &star)
{
    distibuteOnDisk(star);
    distibuteVertically(star);
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

void SGStarInitializer::distibuteVertically(SGStar &star)
{
}

