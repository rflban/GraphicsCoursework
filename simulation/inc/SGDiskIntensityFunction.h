#ifndef GCW_SGDISKINTENSITYFUNCTION_H_
#define GCW_SGDISKINTENSITYFUNCTION_H_

#include "ParametricFunction.h"

class SGDiskIntensityFunction : public ParametricFunction
{
public:
    SGDiskIntensityFunction(double I0=0, double RD=0);

    double compute(double x) const override;
    static
    double compute(double R, double I0, double RD);

    inline double getI0() const { return I0; }
    inline void setI0(double I0) { this->I0 = I0; }

    inline double getRD() const { return RD; }
    inline void setRD(double RD) { this->RD = RD; }

private:
    double I0;
    double RD;
};

#endif // GCW_SGDISKINTENSITYFUNCTION_H_

