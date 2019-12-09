#ifndef GCW_SGINTENSITYFUNCTION_H_
#define GCW_SGINTENSITYFUNCTION_H_

#include "ParametricFunction.h"

class SGIntensityFunction : public ParametricFunction
{
public:
    SGIntensityFunction(
        double I0=0, double k=0,
        double RD=0, double radiusCore=0
    );

    double compute(double x) const override;
    static
    double compute(
        double R, double I0,
        double k, double RD,
        double radiusDisk
    );

    inline double getI0() { return I0; }
    inline void setI0(double I0) { this->I0 = I0; }

    inline double getK() { return k; }
    inline void setK(double k) { this->k = k; }

    inline double getRD() { return RD; }
    inline void setRD(double RD) { this->RD = RD; }

private:
    double I0;
    double k;
    double RD;

    double radiusCore;
};

#endif // GCW_SGINTENSITYFUNCTION_H_

