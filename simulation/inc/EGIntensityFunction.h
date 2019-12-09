#ifndef GCW_EGINTENSITYFUNCTION_H_
#define GCW_EGINTENSITYFUNCTION_H_

#include "ParametricFunction.h"

class EGIntensityFunction : ParametricFunction
{
public:
    EGIntensityFunction(double I0=0, double k=0);

    double compute(double x) const override;
    static
    double compute(double R, double I0, double k);

    inline double getI0() const { return I0; }
    inline void setI0(double I0) { this->I0 = I0; }

    inline double getK() const { return k; }
    inline void setK(double k) { this->k = k; }

private:
    double I0;
    double k;
};

#endif // GCW_EGINTENSITYFUNCTION_H_

