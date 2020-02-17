#ifndef GCW_SGDISKRADIUSDISTRIBUTOR_H_
#define GCW_SGDISKRADIUSDISTRIBUTOR_H_

#include <cstddef>

#include "Distributor.h"

class SGIntensityFunction;
class Integrator;

class SGDiskRadiusDistributor : public Distributor
{
public:
    SGDiskRadiusDistributor(
        double I0,
        double RECore, double REDisk,
        double radiusCore,
        double radiusMin, double radiusMax,
        size_t stepsQty
    );
    ~SGDiskRadiusDistributor() override;

    void setup() override;

    double operator()(const RandomGenerator &generator) const override;

private:
    struct XYDerivative
    {
        double *X;
        double *Y;
        double *D;

        size_t qty;

        void clear();
        void dump(
            const char *fname,
            const char *csep=",",
            const char *rsep="\n"
        ) const;
    };

    double getRadius(double p) const;

    Integrator *integrator;

    double radiusMin;
    double radiusMax;

    XYDerivative probabilities;
    XYDerivative radiuses;
};

#endif // GCW_SGDISKRADIUSDISTRIBUTOR_H_

