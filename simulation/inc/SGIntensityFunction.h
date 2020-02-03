#ifndef GCW_SGINTENSITYFUNCTION_H_
#define GCW_SGINTENSITYFUNCTION_H_

#include "ParametricFunction.h"

class SGIntensityFunction : public ParametricFunction
{
public:
    SGIntensityFunction(
        double I0=0,
        double RECore=0, double REDisk=0,
        double radiusCore=0
    );

    double compute(double x) const override;
    static
    double compute(
        double R, double I0,
        double RECore, double REDisk,
        double radiusDisk
    );

    inline double getI0() { return I0; }
    inline void setI0(double I0) { this->I0 = I0; }

    inline double getRECore() { return RECore; }
    inline void setRECore(double RECore) { this->RECore = RECore; }

    inline double getREDisk() { return REDisk; }
    inline void setREDisk(double REDisk) { this->REDisk = REDisk; }

    inline double getRadiusCore() { return radiusCore; }
    inline void setRadiusCore(double radiusCore)
    { this->radiusCore = radiusCore; }

private:
    double I0;
    double RECore;
    double REDisk;

    double radiusCore;
};

#endif // GCW_SGINTENSITYFUNCTION_H_

