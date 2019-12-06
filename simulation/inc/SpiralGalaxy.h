#ifndef GCW_SPIRALGALAXY_H_
#define GCW_SPIRALGALAXY_H_

#include "Galaxy.h"

#include "Geometry.h"

class SpiralGalaxy : public Galaxy
{
public:
    SpiralGalaxy(
            const Vector3D &pos,
            double radiusCore,
            double radiusDisk,
            double ecctyInnerst,
            double ecctyOuterst,
            size_t starsQty
    );
    ~SpiralGalaxy();

    inline double
    getRaiusCore() { return radiusCore; }

    inline double
    getRadiusDisk() { return radiusDisk; }

    inline double
    getEcctyInnerst() { return ecctyInnerst; }

    inline double
    getEcctyOuterst() { return ecctyOuterst; }

    inline size_t
    getStarsQty() override { return starsQty; }

    double getEccentricity(double radius);
    double getAngularOffset(double radius);

private:
    Vector3D pos;

    double radiusCore; // galaxy core radius
    double radiusDisk; // galaxy radius

    double ecctyInnerst; // innermost ellipse eccentricity
    double ecctyOuterst; // outermost ellipse eccentricity

    size_t starsQty; // stars quantity
};

struct Perturbation
{
    Perturbation(double angle, double denom) :
        angleRatio(angle), denominator(denom)
    {}

    double angleRatio;
    double denominator;
};

#endif // GCW_SPIRALGALAXY_H_

