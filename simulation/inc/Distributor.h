#ifndef GCW_DISTRIBUTOR_H_
#define GCW_DISTRIBUTOR_H_

class RandomGenerator;

class Distributor
{
public:
    virtual ~Distributor() = default;

    virtual void setup() = 0;

    virtual double operator()(const RandomGenerator &generetor) const = 0;
};

#endif // GCW_DISTRIBUTOR_H_

