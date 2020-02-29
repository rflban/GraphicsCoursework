#include "SGStarInitializer.h"

#include "SpiralGalaxy.h"
#include "SGStar.h"

#include "SGDiskRadiusDistributor.h"
#include "SGVerticalDistributor.h"

#include "Random.h"

SGStarInitializer::SGStarInitializer() :
    star(nullptr),
    galaxy(nullptr),

    rdistributor(nullptr),
    vdistributor(nullptr)
{
}

SGStarInitializer::SGStarInitializer(const SpiralGalaxy *galaxy) :
    star(nullptr),
    galaxy(galaxy),

    rdistributor(nullptr),
    vdistributor(nullptr)
{
}

SGStarInitializer::SGStarInitializer(const SpiralGalaxy &galaxy) :
    star(nullptr),
    galaxy(&galaxy),

    rdistributor(nullptr),
    vdistributor(nullptr)
{
}

SGStarInitializer::~SGStarInitializer()
{
    reset();
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
}

void SGStarInitializer::reset()
{
    if (star)
        star = nullptr;
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

