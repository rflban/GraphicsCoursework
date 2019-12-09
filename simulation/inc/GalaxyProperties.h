#ifndef GCW_GALAXYPROPERTIES_H_
#define GCW_GALAXYPROPERTIES_H_

struct Perturbation
{
    Perturbation(double angle, double denom) :
        angleRatio(angle), denominator(denom)
    {}

    double angleRatio;
    double denominator;
};

#endif // GCW_GALAXYPROPERTIES_H_

