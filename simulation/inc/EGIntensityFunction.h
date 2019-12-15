#ifndef GCW_EGINTENSITYFUNCTION_H_
#define GCW_EGINTENSITYFUNCTION_H_

#include "ParametricFunction.h"

class EGIntensityFunction : ParametricFunction
{
public:
    EGIntensityFunction(double I0=0, double RE=0);

    double compute(double x) const override;
    static
    double compute(double R, double I0, double RE);

    inline double getI0() const { return I0; }
    inline void setI0(double I0) { this->I0 = I0; }

    inline double getRE() const { return RE; }
    inline void setRE(double RE) { this->RE = RE; }

private:
    double I0;
    double RE;
};

#endif // GCW_EGINTENSITYFUNCTION_H_

