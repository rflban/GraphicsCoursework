#ifndef GCW_SGCELESTIAL_H_
#define GCW_SGCELESTIAL_H_

#include "SGObject.h"

class SGCelestial : public SGObject
{
public:
    SGCelestial(SGObject *celestial);
    SGCelestial(const SGCelestial &other);
    SGCelestial(SGCelestial &&temp);
    ~SGCelestial() = default;

    void accept(SGObjectHandler &handler) override;

private:
    SGObject *celestial;

};

#endif // GCW_SGCELESTIAL_H_

