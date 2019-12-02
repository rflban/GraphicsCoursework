#ifndef GCW_GALAXY_H_
#define GCW_GALAXY_H_

#include <cstddef>

#include "Geometry.h"

class Galaxy
{
public:
    Galaxy(
            const Vector3D &pos,
            double radiusCore,
            double radiusDisk,
            double ecctyInnerst,
            double ecctyOuterst,
            size_t starsQty
    );
    ~Galaxy();

    inline double
    getRaiusCore() { return radiusCore; }

    inline double
    getRadiusDisk() { return radiusDisk; }

    inline double
    getEcctyInnerst() { return ecctyInnerst; }

    inline double
    getEcctyOuterst() { return ecctyOuterst; }

    inline size_t
    getStarsQty() { return starsQty; }

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

#endif // GCW_GALAXY_H_

