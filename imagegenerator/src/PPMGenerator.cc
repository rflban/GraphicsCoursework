#include "PPMGenerator.h"

#include <cstdio>

#include "Pixmap.h"
#include "Pixel.h"

void PPMGenerator::generate(FILE *fd, const Pixmap &pixmap)
{
    fprintf(fd, "P6\n%lu %lu\n255\n", pixmap.getWidth(), pixmap.getHeight());

    for (size_t j = 0; j < pixmap.getHeight(); j++)
        for (size_t i = 0; i < pixmap.getWidth(); i++)
        {
            fwrite(&pixmap[i][j], 1, 3, fd);
        }
}

