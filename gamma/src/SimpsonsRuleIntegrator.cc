#include "SimpsonsRuleIntegrator.h"

#include "ParametricFunction.h"

SimpsonsRuleIntegrator::SimpsonsRuleIntegrator(ParametricFunction *func, size_t stepsQty) :
    Integrator(func, stepsQty)
{
}

double SimpsonsRuleIntegrator::integrate(double a, double b) const
{
    return integrate(func, a, b, stepsQty);
}

double SimpsonsRuleIntegrator::integrate(
        ParametricFunction *func,
        double a, double b,
        size_t stepsQty
    )
{
    double h = (b - a) / stepsQty;

    size_t i;
    double x;
    double y = 0;

    for (x = a, i = 0; i < stepsQty; x += h + h, i += 2)
    {
        y += func->compute(x) +
             func->compute(x + h) * 4 +
             func->compute(x + h + h);
    }
    y *= h / 3;

    return y;
}

TracedIntegral SimpsonsRuleIntegrator::integrateTraced(double a, double b) const
{
    size_t tracedQty = (stepsQty >> 1) + (stepsQty & 1); // tq = (sq / 2) + (sq % 2)

    TracedIntegral vals = { new double[tracedQty],
                            new double[tracedQty],
                            new double[tracedQty], 0 };

    double h = (b - a) / stepsQty;
    double h_div_3 = h / 3;
    double h_mul_2 = h + h;

    size_t i;
    double x;
    double s = 0;
    double s_prev = 0;

    for (x = a, i = 0; i < tracedQty; x += h_mul_2, i++)
    {
        s += h_div_3 * (func->compute(x) +
                        func->compute(x + h) * 4 +
                        func->compute(x + h_mul_2));

        vals.X[i] = x + h;
        vals.Y[i] = (s - s_prev) / h_mul_2;
        vals.I[i] = s;

        s_prev = s;
    }

    vals.qty = tracedQty;

    return vals;
}

