#ifndef GCW_INTEGRATOR_H_
#define GCW_INTEGRATOR_H_

class ParametricFunction;

class Integrator
{
public:
    Integrator(ParametricFunction *func) : func(func) {}
    virtual ~Integrator() = default;

    virtual double integrate(double a, double b) const = 0;

    inline ParametricFunction *getFunc() { return func; }
    inline void setFunc(ParametricFunction *func) { this->func = func; }

protected:
    ParametricFunction *func;
};

#endif // GCW_INTEGRATOR_H_

