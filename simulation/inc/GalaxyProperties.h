#ifndef GCW_GALAXYPROPERTIES_H_
#define GCW_GALAXYPROPERTIES_H_

const double vne = 7.66925;

struct Perturbation
{
    Perturbation(double angle, double denom) :
        angleRatio(angle), denominator(denom)
    {}

    double angleRatio;
    double denominator;
};

#endif // GCW_GALAXYPROPERTIES_H_

