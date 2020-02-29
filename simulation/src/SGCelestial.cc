#include "SGCelestial.h"

SGCelestial::SGCelestial(SGObject *celestial) :
    celestial(celestial)
{
}

SGCelestial::SGCelestial(const SGCelestial &other)
{
    celestial = other.celestial;
}

SGCelestial::SGCelestial(SGCelestial &&temp)
{
    celestial = temp.celestial;
}

void SGCelestial::accept(SGObjectHandler &handler)
{
    celestial->accept(handler);
}

