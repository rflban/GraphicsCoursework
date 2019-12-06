#include <cstdio>
#include <cmath>

#include "Pixmap.h"
#include "Painter.h"
#include "PPMGenerator.h"

#include "Geometry.h"
#include "SpiralGalaxy.h"
#include "SGOrbitCalculator.h"

void drawOrbit(Painter &painter, double a, double b, double angleOffset, const Perturbation &pert, size_t x0, size_t y0);

int main()
{
    Pixmap p(900, 900);
    Painter painter(&p);

    SpiralGalaxy galaxy({0, 0, 0}, 3000, 20000, 0.45, 0.46, 2000);
    double scale_ratio = 400.0 / 20000;

    painter.fillRect(0, 0, 500, 500, {0, 0, 0});

    painter.setColor({255, 0, 0});
    painter.drawEllipse(450, 450, (size_t)(scale_ratio * galaxy.getRaiusCore()), (size_t)(scale_ratio * galaxy.getRaiusCore()));
    painter.setColor({0, 255, 0});
    painter.drawEllipse(450, 450, (size_t)(scale_ratio * galaxy.getRadiusDisk()), (size_t)(scale_ratio * galaxy.getRadiusDisk()));

    painter.setColor({255, 255, 255});

    double dr = 750;
    double dteta = M_PI / 48;
    for (double r = 1.0 / 5 * galaxy.getRaiusCore(), teta = 0; r < galaxy.getRadiusDisk() + 20000; r += dr, teta += dteta)
    {
        double a = r;
        double b = sqrt(a * a - pow(galaxy.getEccentricity(r), 2) * a * a);
        //b = a * galaxy.getEccentricity(r);

        printf("%lu %lu\n", (size_t)(scale_ratio * a), (size_t)(scale_ratio * b));
        //painter.drawEllipse(450, 450, (size_t)(scale_ratio * a), (size_t)(scale_ratio * b), -galaxy.getAngularOffset(r));
        //painter.drawEllipse(450, 450, (size_t)(scale_ratio * a), (size_t)(scale_ratio * b), M_PI/4);
        drawOrbit(painter, scale_ratio * a, scale_ratio * b, galaxy.getAngularOffset(r), {4, 40}, 450, 450);
    }

    ImageGenerator *generator = new PPMGenerator;
    FILE *fd = fopen("test.ppm", "w");

    generator->generate(fd, p);

    delete generator;
    fclose(fd);

    return 0;
}

void drawOrbit(Painter &painter, double a, double b, double angleOffset, const Perturbation &pert, size_t x0, size_t y0)
{
    double h = 1 / std::fmax(a, b);
    double pi_m_2 = 2 * M_PI;

    SGOrbitCalculator calculator(a, b, angleOffset, pert);

    for (double t = 0; t < pi_m_2; t += h)
    {
        Vector2D pos = calculator.calculate(t);

        painter.fillPixel(x0 + (size_t)round(pos.x), y0 + (size_t)round(pos.y));
    }
}

