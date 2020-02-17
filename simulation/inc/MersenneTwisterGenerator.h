#ifndef GCW_MERSENNETWISTERGENERATOR_H_
#define GCW_MERSENNETWISTERGENERATOR_H_

#include "RandomGenerator.h"

#include <random>

class MersenneTwisterGenerator : public RandomGenerator
{
public:
    MersenneTwisterGenerator(unsigned int seed = 0);
    ~MersenneTwisterGenerator();

    unsigned int operator()() const override;

    unsigned int max() const override;
    unsigned int min() const override;

    void seed(unsigned int s) override;

private:
    std::mt19937 *baseGenerator;
};

#endif // GCW_MERSENNETWISTERGENERATOR_H_

