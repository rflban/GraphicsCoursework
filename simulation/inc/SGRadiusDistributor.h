#ifndef GCW_SGRADIUSDISTRIBUTOR_H_
#define GCW_SGRADIUSDISTRIBUTOR_H_

#include <cstddef>

class SGIntensityFunction;
class Integrator;

class SGRadiusDistributor
{
public:
    SGRadiusDistributor(
        double I0,
        double RECore, double REDisk,
        double radiusCore,
        double radiusMin, double radiusMax,
        size_t stepsQty
    );
    ~SGRadiusDistributor();

    void setup();

    double getRadius(double p);

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

    Integrator *integrator;

    double radiusMin;
    double radiusMax;

    XYDerivative probabilities;
    XYDerivative radiuses;
};

#endif // GCW_SGRADIUSDISTRIBUTOR_H_

