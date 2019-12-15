#include "SGRadiusDistributor.h"

#include "SimpsonsRuleIntegrator.h"
#include "SGIntensityFunction.h"

SGRadiusDistributor::SGRadiusDistributor(
            double I0,
            double RECore, double REDisk,
            double radiusCore,
            double radiusMin, double radiusMax,
            size_t stepsQty
        ) :
    radiusMin(radiusMin), radiusMax(radiusMax),

    probabilities({ nullptr, nullptr, nullptr, 0 }),
    radiuses({ nullptr, nullptr, nullptr, 0 })
{
    ParametricFunction *func = new SGIntensityFunction(I0, RECore, REDisk, radiusCore);
    integrator = new SimpsonsRuleIntegrator(func, stepsQty);
}

SGRadiusDistributor::~SGRadiusDistributor()
{
    delete integrator->getFunc();
    delete integrator;

    probabilities.clear();
    radiuses.clear();
}

void SGRadiusDistributor::setup()
{
    probabilities.clear();
    radiuses.clear();

    TracedIntegral vals = integrator->integrateTraced(radiusMin, radiusMax);
    size_t stepsQty = integrator->getStepsQty();

    probabilities = { vals.X, vals.I, vals.Y, vals.qty };

    for (size_t i = 0; i < vals.qty; i++)
    {
        probabilities.Y[i] /= probabilities.Y[vals.qty - 1];
        probabilities.D[i] /= probabilities.Y[vals.qty - 1];
    }

    radiuses = { new double[stepsQty - 1],
                 new double[stepsQty - 1],
                 new double[stepsQty - 1], stepsQty - 1 };

    double p = 0;
    double h = 1.0 / stepsQty;
    double radius;
    double radius_prev = 0;

    for (size_t i = 0, j = 0; i < radiuses.qty; i++)
    {
        p += h;

        for (; probabilities.Y[j + 1] <= p; j++);

        radius = probabilities.X[j] +
                 (p - probabilities.Y[j]) / probabilities.D[j];

        radiuses.X[i] = p;
        radiuses.Y[i] = radius;
        radiuses.D[i] = (radius - radius_prev) / h;
    }

    radiuses.dump("radiuses.csv");
}

double SGRadiusDistributor::getRadius(double p)
{
    double h = 1.0 / radiuses.qty;

    int idx = (int)(p / h);
    double delta = p - idx * h;

    return radiuses.Y[idx] + delta * radiuses.D[idx];
}

#include <cstdio>
#define __free_ptr(ptr) if (ptr) delete[] ptr; ptr = nullptr

void SGRadiusDistributor::XYDerivative::clear()
{
    __free_ptr(X);
    __free_ptr(Y);
    __free_ptr(D);

    qty = 0;
}

void SGRadiusDistributor::XYDerivative::dump(
        const char *fname,
        const char *csep,
        const char *rsep
    ) const
{
    if (X && Y && D)
    {
        FILE *fd = fopen(fname, "w");

        fprintf(fd, "X%sY%sD%s", csep, csep, rsep);

        for (size_t i = 0; i < qty; i++)
        {
            fprintf(fd, "%.14lf%s%.14lf%s%.14lf%s",
                    X[i], csep, Y[i], csep, D[i], rsep);
        }

        fclose(fd);
    }
}

