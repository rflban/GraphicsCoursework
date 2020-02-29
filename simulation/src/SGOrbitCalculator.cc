#include "SGOrbitCalculator.h"

#include <cmath>

#include "Geometry.h"
#include "GalaxyProperties.h"

static inline double rotateX(double x, double y, double teta)
{
    return x * cos(teta) - y * sin(teta);
}

static inline double rotateY(double x, double y, double teta)
{
    return x * sin(teta) + y * cos(teta);
}

Vector2D SGOrbitCalculator::calculate(
        double a, double b,
        double rotationAngle, const Perturbation &pert,
        double azimuth)
{
    double x, y;
    Vector2D pos;

    x = a * sin(azimuth);
    y = b * cos(azimuth);

    if (pert.angleRatio > 0 && pert.denominator > 0)
    {
        x += a / pert.denominator * cos(azimuth * pert.angleRatio);
        y += b / pert.denominator * sin(azimuth * pert.angleRatio);
    }

    pos.x = rotateX(x, y, rotationAngle);
    pos.y = rotateY(x, y, rotationAngle);

    return pos;
}

