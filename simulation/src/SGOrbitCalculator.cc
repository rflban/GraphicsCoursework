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

SGOrbitCalculator::SGOrbitCalculator(
        double a, double b,
        double angleOffset, const Perturbation &pert
    ) :
    a(a), b(b), angleOffset(angleOffset),
    pert(new Perturbation(pert))
{
}

SGOrbitCalculator::~SGOrbitCalculator()
{
    delete pert;
}

Vector2D SGOrbitCalculator::calculate(double polarAngle)
{
    return calculate(a, b, angleOffset, *pert, polarAngle);
}

Vector2D SGOrbitCalculator::calculate(
        double a, double b,
        double angularOffset, const Perturbation &pert,
        double polarAngle)
{
    double x, y;
    Vector2D pos;

    x = a * sin(polarAngle);
    y = b * cos(polarAngle);

    if (pert.angleRatio > 0 && pert.denominator > 0)
    {
        x += a / pert.denominator * cos(polarAngle * pert.angleRatio);
        y += b / pert.denominator * sin(polarAngle * pert.angleRatio);
    }

    pos.x = rotateX(x, y, angularOffset);
    pos.y = rotateY(x, y, angularOffset);

    return pos;
}

