#ifndef GCW_SGSTAR_H_
#define GCW_SGSTAR_H_

#include "SGObject.h"

class SGStar : public SGObject
{
public:
    void accept(SGObjectHandler &handler) override;

    inline void setA(double a)
    { this->a = a; }
    inline double getA() const
    { return a; }

    inline void setB(double b)
    { this->b = b; }
    inline double getB() const
    { return b; }

    inline void setC(double c)
    { this->c = c; }
    inline double getC() const
    { return c; }

    inline void setRotationAngle(double alpha)
    { this->rotationAngle = alpha; }
    inline double getRotationAngle() const
    { return rotationAngle; }

    inline void setAzimuth(double alpha)
    { this->azimuth = alpha; }
    inline double getAzimuth() const
    { return azimuth; }

private:
    // semi-axis in SG disk plane, calculates by the de Vaucouleurs law
    double a;
    // semi-axis in SG disk plane, calculates by a and eccentricity
    double b;
    // semi-axis in SG side view plane, calculates by normal distribution
    // c is vertical part of star position, it is const
    double c;

    // rotation angle of star orbit regarding to center
    double rotationAngle;

    // current angular position of star in SG disk plane
    double azimuth;
};

#endif // GCW_SGSTAR_H_

