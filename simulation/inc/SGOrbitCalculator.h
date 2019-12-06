#ifndef GCW_SGORBITCALCULATOR_H_
#define GCW_SGORBITCALCULATOR_H_

struct Vector2D;
struct Perturbation;

class SGOrbitCalculator
{
public:
    SGOrbitCalculator(
        double a, double b,
        double angleOffset, const Perturbation &pert
    );
    ~SGOrbitCalculator();

    Vector2D calculate(double angleOffset);

    static Vector2D calculate(
        double a, double b,
        double angleOffset, const Perturbation &pert,
        double polarAngle
    );

private:
    double a;
    double b;
    double angleOffset;
    Perturbation *pert;
};

#endif // GCW_SGORBITCALCULATOR_H_

