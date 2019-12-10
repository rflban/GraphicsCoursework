#ifndef GCW_PARAMETRICFUNCTION_H_
#define GCW_PARAMETRICFUNCTION_H_

class ParametricFunction
{
public:
    virtual ~ParametricFunction() = default;

    virtual double compute(double x) const = 0;
};

#endif // GCW_PARAMETRICFUNCTION_H_

