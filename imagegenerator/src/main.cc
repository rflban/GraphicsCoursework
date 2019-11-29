#include "Pixmap.h"
#include "Painter.h"
#include "PPMGenerator.h"

#include <cstdio>

int main()
{
    Pixmap p(500, 700);
    Painter painter(&p);

    painter.fillRect(0, 0, 500, 700, {255, 255, 255});
    painter.drawEllipse(250, 250, 150, 100);

    ImageGenerator *generator = new PPMGenerator;
    FILE *fd = fopen("test.ppm", "w");

    generator->generate(fd, p);

    delete generator;
    fclose(fd);

    return 0;
}

