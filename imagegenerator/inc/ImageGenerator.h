#ifndef GCW_IMAGEGENERATOR_H_
#define GCW_IMAGEGENERATOR_H_

#include <cstdio>

class Pixmap;

class ImageGenerator
{
public:
    virtual ~ImageGenerator() = default;

    virtual void generate(FILE *fd, const Pixmap &pic) = 0;
};

#endif // GCW_IMAGEGENERATOR_H_

