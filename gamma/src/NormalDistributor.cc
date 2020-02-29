#include "NormalDistributor.h"

#include "RandomGenerator.h"

NormalDistributor::NormalDistributor(double mean, double stddef) :
    nd(new std::normal_distribution<>(mean, stddef))
{
}

void NormalDistributor::setup()
{
}

NormalDistributor::~NormalDistributor()
{
    delete nd;
}

double NormalDistributor::operator()(const RandomGenerator &generetor) const
{
    return (*nd)(generetor);
}

