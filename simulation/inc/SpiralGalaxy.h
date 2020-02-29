#ifndef GCW_SPIRALGALAXY_H_
#define GCW_SPIRALGALAXY_H_

#include "Galaxy.h"

#include "SGCelestial.h"
#include "SGObject.h"
#include "SGStar.h"

#include "SGIterator.h"
#include "SGStarDescriptor.h"

#include "Geometry.h"

// Spiral Galaxy <=> SG
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

    using iterator = SGIterator;

    inline double
    getRaiusCore() { return radiusCore; }

    inline double
    getRadiusDisk() { return radiusDisk; }

    inline double
    getEcctyInnerst() { return ecctyInnerst; }

    inline double
    getEcctyOuterst() { return ecctyOuterst; }

    inline size_t
    getStarsQty() const override { return starsQty; }

    inline const SGStarDescriptor *
    getStars() { return stars; }

    double getEccentricity(double radius);
    double getAngularOffset(double radius);

    iterator begin();
    iterator end();

    SGObject *getObject(ptrdiff_t idx);

    bool isExistingObject(ptrdiff_t idx) const;

private:
    Vector3D pos;

    double radiusCore; // galaxy core radius
    double radiusDisk; // galaxy radius

    double ecctyInnerst; // innermost ellipse eccentricity
    double ecctyOuterst; // outermost ellipse eccentricity

    size_t starsQty; // stars quantity

    SGStarDescriptor *stars;
    SGStar *stars_;

    void initStars();
};

#endif // GCW_SPIRALGALAXY_H_

