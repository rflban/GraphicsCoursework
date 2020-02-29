#ifndef GCW_RANDOM_GENERATOR_H_
#define GCW_RANDOM_GENERATOR_H_

class RandomGenerator
{
public:
    virtual ~RandomGenerator() = default;

    virtual unsigned int operator()() const = 0;

    virtual unsigned int max() const = 0;
    virtual unsigned int min() const = 0;

    virtual void seed(unsigned int s) = 0;
};

#endif // GCW_RANDOM_GENERATOR_H_

