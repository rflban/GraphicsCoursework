#include "SGIterator.h"

#include "SpiralGalaxy.h"
#include "SGObject.h"

SGIterator::SGIterator(SpiralGalaxy *galaxy, ptrdiff_t idx) :
    idx(idx), galaxy(galaxy)
{
}

SGIterator::SGIterator(const SGIterator &it) :
    idx(it.idx), galaxy(it.galaxy)
{
}

SGIterator &SGIterator::operator=(const SGIterator &it)
{
    idx = it.idx;
    galaxy = it.galaxy;

    return *this;
}

SGObject &SGIterator::operator*() const
{
    return *galaxy->getObject(idx);
}

SGObject *SGIterator::operator->() const
{
    return galaxy->getObject(idx);
}

SGIterator &SGIterator::operator++()
{
    idx++;

    return *this;
}

SGIterator SGIterator::operator++(int)
{
    idx++;

    return SGIterator(galaxy, idx - 1);
}

bool SGIterator::operator==(const SGIterator &it) const
{
    if (!(*this) && !it)
    {
        return true;
    }

    return idx == it.idx;
}

bool SGIterator::operator!=(const SGIterator &it) const
{
    return !(*this == it);
}

SGIterator::operator bool() const
{
    return galaxy->isExistingObject(idx);
}

