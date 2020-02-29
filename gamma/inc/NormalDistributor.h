#ifndef GCW_NORMALDISTRIBUTOR_H_
#define GCW_NORMALDISTRIBUTOR_H_

#include "Distributor.h"

#include <random>

class NormalDistributor : public Distributor
{
public:
    NormalDistributor(double mean = 0, double stddef = 1);
    ~NormalDistributor();

    void setup() override;

    double operator()(const RandomGenerator &generetor) const override;

private:
    std::normal_distribution<> *nd;
};

#endif // GCW_NORMALDISTRIBUTOR

