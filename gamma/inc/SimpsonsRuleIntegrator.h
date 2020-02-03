#ifndef GCW_SIMPSONSRULEINTEGRATOR_H_
#define GCW_SIMPSONSRULEINTEGRATOR_H_

#include "Integrator.h"

#include <cstddef>

class SimpsonsRuleIntegrator : public Integrator
{
public:
    SimpsonsRuleIntegrator(ParametricFunction *func=nullptr,
                           size_t stepsQty=1);

    double integrate(double a, double b) const override;
    static
    double integrate(ParametricFunction *func,
                     double a, double b, size_t stepsQty);

    TracedIntegral integrateTraced(double a, double b) const override;
};

#endif // GCW_SIMPSONSRULEINTEGRATOR_H_

