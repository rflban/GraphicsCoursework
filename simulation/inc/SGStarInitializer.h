#ifndef GCW_SGSTARINITIALIZER_H_
#define GCW_SGSTARINITIALIZER_H_

class SpiralGalaxy;
class SGStar;

class SGDiskRadiusDistributor;
class NormalDistributor;

class RandomGenerator;

class SGStarInitializer
{
public:
    SGStarInitializer();
    SGStarInitializer(const SpiralGalaxy &galaxy);
    SGStarInitializer(const SpiralGalaxy *galaxy);

    ~SGStarInitializer();

    void setup();
    void reset();

    bool isReady();
    operator bool();

    void operator()(SGStar &star);

    void distibuteOnDisk(SGStar &star);
    void distibuteVertically(SGStar &star);

    inline void setGalaxy(const SpiralGalaxy *galaxy)
    { this->galaxy = galaxy; }

    inline void resetGalaxy()
    { this->galaxy = nullptr; }

private:
    const SpiralGalaxy *galaxy;

    SGDiskRadiusDistributor *rdistributor;
    NormalDistributor *ndistributor;

    RandomGenerator *rnd;
};

#endif // GCW_SGSTARINITIALIZER_H_

