#include "SGVerticalDistributor.h"

#include <cmath>

#include "RandomGenerator.h"

SGVerticalDistributor::SGVerticalDistributor(double radiusCore,
                                             double radiusDisk) :
    radiusCore(radiusCore), radiusDisk(radiusDisk),
    nd(nullptr)
{
}

SGVerticalDistributor::~SGVerticalDistributor()
{
    if (nd)
    {
        delete nd;
    }
}

void SGVerticalDistributor::setup()
{
    if (nd)
    {
        delete nd;
    }

    nd = new std::normal_distribution<>(0, asin(radiusCore / radiusDisk) / 3);
}

double SGVerticalDistributor::operator()(const RandomGenerator &generator) const
{
    return (*nd)(generator);
}

