#ifndef GCW_PPMGENERATOR_H_
#define GCW_PPMGENERATOR_H_

#include "ImageGenerator.h"

class PPMGenerator : public ImageGenerator
{
public:
    void generate(FILE *fd, const Pixmap &pic) override;
};

#endif // GCW_PPMGENERATOR_H_

