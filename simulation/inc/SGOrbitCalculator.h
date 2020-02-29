#ifndef GCW_SGORBITCALCULATOR_H_
#define GCW_SGORBITCALCULATOR_H_

struct Vector2D;
struct Perturbation;

class SGOrbitCalculator
{
public:
    static
    Vector2D calculate(
        double a, double b,
        double rotationAngle, const Perturbation &pert,
        double azimuth
    );
};

#endif // GCW_SGORBITCALCULATOR_H_

