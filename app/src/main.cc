#include "Pixmap.h"
#include "Painter.h"
#include "PPMGenerator.h"

#include <cstdio>
#include <cmath>

int main()
{
    Pixmap p(500, 500);
    Painter painter(&p);

    painter.fillRect(0, 0, 500, 500, {255, 255, 255});

    double angle = 0;
    for (int a = 5; a <= 200; a += 5)
    {
        painter.drawEllipse(250, 250, a, a * 0.85, angle);
        angle += M_PI / 20;
    }

    ImageGenerator *generator = new PPMGenerator;
    FILE *fd = fopen("test.ppm", "w");

    generator->generate(fd, p);

    delete generator;
    fclose(fd);

    return 0;
}

