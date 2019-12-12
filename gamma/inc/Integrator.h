#ifndef GCW_INTEGRATOR_H_
#define GCW_INTEGRATOR_H_

#include <cstddef>

class ParametricFunction;

struct TracedIntegral
{
    double *X;
    double *Y;
    double *I;

    size_t qty;
};

class Integrator
{
public:
    Integrator(ParametricFunction *func, size_t stepsQty=1) :
        func(func), stepsQty(stepsQty)
    {}
    virtual ~Integrator() = default;

    virtual double integrate(double a, double b) const = 0;
    virtual TracedIntegral integrateTraced(double a, double b) const = 0;

    inline ParametricFunction *getFunc() { return func; }
    inline void setFunc(ParametricFunction *func) { this->func = func; }

    inline int getStepsQty() { return stepsQty; }
    inline void setStepsQty(int stepsQty) { this->stepsQty = stepsQty; }

protected:
    ParametricFunction *func;

    size_t stepsQty;
};

#endif // GCW_INTEGRATOR_H_

