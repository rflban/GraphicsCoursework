#ifndef GCW_SGVERTICALDISTRIBUTOR_H_
#define GCW_SGVERTICALDISTRIBUTOR_H_

#include "Distributor.h"

#include <random>

class SGVerticalDistributor : public Distributor
{
public:
    SGVerticalDistributor(double radiusCore, double radiusDisk);
    ~SGVerticalDistributor();

    void setup() override;

    double operator()(const RandomGenerator &generator) const override;

private:
    double radiusCore;
    double radiusDisk;

    std::normal_distribution<> *nd;
};

#endif // GCW_SGVERTICALDISTRIBUTOR_H_

