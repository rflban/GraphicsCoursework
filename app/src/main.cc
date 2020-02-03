#include <cstdio>
#include <random>
#include <ctime>
#include <cmath>

#include "Pixmap.h"
#include "Painter.h"
#include "PPMGenerator.h"

#include "Geometry.h"
#include "SpiralGalaxy.h"
#include "GalaxyProperties.h"
#include "SGOrbitCalculator.h"
#include "SGStarDescriptor.h"

#include "SGRadiusDistributor.h"

void drawOrbit(Painter &painter, double a, double b, double angleOffset, const Perturbation &pert, size_t x0, size_t y0);

int main()
{
    srand(time(0));

    Pixmap p(900, 900);
    Painter painter(&p);

    SpiralGalaxy galaxy({0, 0, 0}, 3000, 20000, 0.45, 0.46, 25000);
    double scale_ratio = 400.0 / 20000;

    painter.fillRect(0, 0, 900, 900, {0, 0, 0});

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

        //painter.drawEllipse(450, 450, (size_t)(scale_ratio * a), (size_t)(scale_ratio * b), -galaxy.getAngularOffset(r));
        //painter.drawEllipse(450, 450, (size_t)(scale_ratio * a), (size_t)(scale_ratio * b), M_PI/4);
        drawOrbit(painter, scale_ratio * a, scale_ratio * b, galaxy.getAngularOffset(r), {4, 40}, 450, 450);
    }

    ImageGenerator *generator = new PPMGenerator;
    FILE *fd = fopen("orbits.ppm", "w");

    generator->generate(fd, p);

    fclose(fd);

    painter.fillRect(0, 0, 900, 900, {0, 0, 0});

    Vector2D pos;
    SGStarDescriptor s;
    for (size_t idx = 0; idx < galaxy.getStarsQty(); idx++)
    {
        s = galaxy.getStars()[idx];
        pos = SGOrbitCalculator::calculate(s.a, s.b, s.angularOffset, {4, 40}, s.angularPos);
        pos = SGOrbitCalculator::calculate(scale_ratio * s.a, scale_ratio * s.b, s.angularOffset, {4, 40}, s.angularPos);

        printf("%lf\n", s.a);

        ubyte c = (ubyte)(round(255 * s.brightness));

        painter.fillPixel(450 + (size_t)round(pos.x), 450 + (size_t)round(pos.y),
                          { c, c, c });
    }

    fd = fopen("stars.ppm", "w");
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

