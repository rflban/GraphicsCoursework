#ifndef GCW_GALAXY_H_
#define GCW_GALAXY_H_

#include <cstddef>

class Galaxy
{
public:
    ~Galaxy() = default;

    virtual inline size_t
    getStarsQty() const = 0;

};

#endif // GCW_GALAXY_H_

