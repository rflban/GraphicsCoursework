#ifndef GCW_SGSTARINITIALIZER_H_
#define GCW_SGSTARINITIALIZER_H_

class SpiralGalaxy;
class SGStar;

class SGDiskRadiusDistributor;
class SGVerticalDistributor;

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

    inline void setStar(SGStar *star)
    { this->star = star; }

    inline void resetStar()
    { this->star = nullptr; }

    inline void setGalaxy(const SpiralGalaxy *galaxy)
    { this->galaxy = galaxy; }

    inline void resetGalaxy()
    { this->galaxy = nullptr; }

private:
    SGStar *star;
    const SpiralGalaxy *galaxy;

    SGDiskRadiusDistributor *rdistributor;
    SGVerticalDistributor *vdistributor;
};

#endif // GCW_SGSTARINITIALIZER_H_

