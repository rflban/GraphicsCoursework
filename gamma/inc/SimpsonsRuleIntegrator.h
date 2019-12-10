#ifndef GCW_SIMPSONSRULEINTEGRATOR_H_
#define GCW_SIMPSONSRULEINTEGRATOR_H_

#include "Integrator.h"

class SimpsonsRuleIntegrator : public Integrator
{
public:
    SimpsonsRuleIntegrator(ParametricFunction *func=nullptr);

    double integrate(double a, double b) const override;
    static
    double integrate(ParametricFunction *func, double a, double b);

private:
};

#endif // GCW_SIMPSONSRULEINTEGRATOR_H_

