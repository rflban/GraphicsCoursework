#include "MersenneTwisterGenerator.h"

MersenneTwisterGenerator::MersenneTwisterGenerator(unsigned int seed)
{
    baseGenerator = new std::mt19937;
    this->seed(seed);
}

MersenneTwisterGenerator::~MersenneTwisterGenerator()
{
    delete baseGenerator;
}

unsigned int MersenneTwisterGenerator::operator()() const
{
    return (*baseGenerator)();
}

unsigned int MersenneTwisterGenerator::max() const
{
    return baseGenerator->max();
}

unsigned int MersenneTwisterGenerator::min() const
{
    return baseGenerator->min();
}

void MersenneTwisterGenerator::seed(unsigned int s)
{
    baseGenerator->seed(s);
}

